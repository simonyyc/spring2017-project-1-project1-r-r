#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

// structure for implementhing linked list
struct Node {
	// Variable to store baby information 
	Baby baby;
	// A next pointer for linked list
	Node * next;
};
class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		head = Null;
		birthCount = 0;
	}

	// destructor
	~MedicalRecord() {
		// Deleting all pointers / records
		while(head)
		{
			Node * current = head;
			head = head->next;
			delete current;
		}
		
	}

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
	string mostPopularName() {
		return "COMPLETE ME"; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return -1; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		return -1; // TO BE COMPLETED
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		return -1; // TO BE COMPLETED
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		// TO BE COMPLETED
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions

};
