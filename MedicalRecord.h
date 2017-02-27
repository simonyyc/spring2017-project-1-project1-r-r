#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include "Baby.h"
#include <iostream>

using namespace std;

// A structure for implementing linked list
struct Node {
	Baby baby;																// Variable to store baby information
	Node * next;															// A next pointer for linked list
};

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		head = NULL;
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
		Node * current = head;
		string popularName = "";					// Most popular name
		int popularCount = 0;						// Storing count of most popular name
		while(current)
		{
			string tempName = current->baby.getName();				// Temporary stored name
			int tempCount = 0;						// Temporary storing count for comparison
			// Checking all names in list
			if(popularCount == 0 || tempName.compare(popularName) != 0) {
				tempCount = numberOfBabiesWithName(tempName);		// Calling function to get no. of babies with name
				// Updating popular Name and Count if new popular is found
				if(tempCount > popularCount) {
					popularCount = tempCount;
					popularName = tempName;
				}
			}
			current = current->next;
		}
		return popularName; // Most popular name
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return birthCount; // TO BE COMPLETED
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		Node * current = head;
		int lowWeight = 0;
		while(current)
		{
			if(current->baby.getWeight() < 2500)
				lowWeight++;
			current = current->next;
		}
		return lowWeight; // Babies with lower weight
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		Node * current = head;
		int babyName = 0;
		while(current)
		{
			if(current->baby.getName().compare(s) == 0)
				babyName++;
			current = current->next;
		}
		return babyName; // Babies with given name
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		Node * newNode = new Node;
		newNode->baby = b;
		newNode->next = NULL;
		birthCount++;
		// If list is empty
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node * current = head;
			while(current)
			{
				// Find last item in list
				if(current->next == NULL)
				{
					current->next = newNode;
					return;
				}
				current = current->next;
			}
		}
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	
	Node * head;															// Starting point of linked list
	int birthCount;															// Count of total nodes / babies
	
};
