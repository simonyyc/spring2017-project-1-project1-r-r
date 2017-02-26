#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include "Baby.h"
#include <iostream>
using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		cout << "Enter maximum number of entries allowed: ";
		cin >> maxData;
		babyData = new Baby[maxData];
		numOfBirths = 0;
	}

	// destructor
	~MedicalRecord() {
		// Deleting all pointers / records
		delete[] babyData;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
			//	cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
		int maxNameCount = 0, previousMax = 0;
		string maxName;
		for (int i = 0; i < numOfBirths; i++) {
			for (int j = 0; j < numOfBirths; j++) {
				if (babyData[i].getName() == babyData[j].getName()) {
					maxNameCount++;
				}//two for loops to check for matching names; matched names cause counter to increment
			}
			if (maxNameCount > previousMax) {
				maxName = babyData[i].getName();
				previousMax = maxNameCount;
				maxNameCount = 0;
			}//check to see if previous most popular name will be overridden
	
		}
		return maxName;
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return numOfBirths; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		int lowBirthWeight = 0;
		for (int i = 0; i < numOfBirths; i++) {
			if (babyData[i].getWeight() < 2500) {
				lowBirthWeight++;
			}
		}
		return lowBirthWeight;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		int nameCount = 0;
		for (int i = 0; i < numOfBirths; i++) {
			if (babyData[i].getName() == s)
				nameCount++;
		}
		return nameCount;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		babyData[numOfBirths] = b;
		numOfBirths++;	
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	
	int numOfBirths; 	//use counter in addEntry to determine
	Baby * babyData; 	//points to dynamic memory array holding the objects
	int maxData; 		//holds inputted value of maximum entries
	
};
