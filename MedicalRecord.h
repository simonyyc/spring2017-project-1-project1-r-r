#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include "Baby.h"
using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord();

	// destructor
	~MedicalRecord();

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName();

	// return the number of baby records loaded from the text file
	int numberOfBirths();

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight();

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s);
private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b);
	int numOfBirths; //use counter in addEntry to determine
	Baby* dataKeep; //points to dynamic memory array holding the objects
	int maxBirth; //holds inputted value of maximum entries


};

MedicalRecord::MedicalRecord() {
	maxBirth = 100000;
	dataKeep = new Baby[maxBirth];
	numOfBirths = 0;
}//ask user to input maximum number

MedicalRecord::~MedicalRecord() {
	delete[] dataKeep;
}//delete the array

string MedicalRecord::mostPopularName() {
	int maxNameCount = 0, previousMax = 0;
	string maxName;
	for (int i = 0; i < numOfBirths; i++) {
		for (int j = 0; j < numOfBirths; j++) {
			if (dataKeep[i].getName() == dataKeep[j].getName()) {
				maxNameCount++;
			}//two for loops to check for matching names; matched names cause counter to increment
		}
		if (maxNameCount > previousMax) {
			maxName = dataKeep[i].getName();
			previousMax = maxNameCount;
			maxNameCount = 0;
		}//check to see if previous most popular name will be overridden

	}
	return maxName;
}

int MedicalRecord::numberOfBirths() {
	return numOfBirths;
}//return the numOfBirths based on number of entries added into array

int MedicalRecord::numberOfBabiesWithLowBirthWeight() {
	int lowBirthWeight = 0;
	for (int i = 0; i < numOfBirths; i++) {
		if (dataKeep[i].getWeight() < 2500) {
			lowBirthWeight++;
		}
	}
	return lowBirthWeight;
}//loop to see if weight matches criteria

int MedicalRecord::numberOfBabiesWithName(string s) {
	int numSameName = 0;
	for (int i = 0; i < numOfBirths; i++) {
		if (dataKeep[i].getName() == s)
			numSameName++;
	}
	return numSameName;
}//loop to see if name matches criteria

void MedicalRecord::addEntry(Baby b) {
	dataKeep[numOfBirths] = b;
	numOfBirths++;
}
