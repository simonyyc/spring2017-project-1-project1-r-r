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
		Node * current = head;
		// Temporary stored name
		string popularName = "";
		// Storing count of most popular name
		int popularCount = 0;
		while(current)
			// Temporary stored name
			string tempNaame = current->baby.getName();
			// Temporary storing count for comparison
			int tempCount = 0;
			// Checking all names in list
			if(popularCount == 0 || temp.compare(popularNama) != 0) {
				// Calling function to get no. of babies with name
				tempCount = numberOfBabiesWithName(tempName);
				// Updating popular Name and Count if new popular is found
				if(tempCount > popularCount) {
					popularCount = tempCount;
					popularName = tempName;
				}
			}
			current = current->next;
		}
				
		// Most popular name		
		return popularName;
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return birthCount; 
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight(string s) {
		Node * current = head;
		int lowWeight = 0;
		while(current)
		{
			if(current->baby.getWeight() < 2500)
				lowWeight++;
			current = current->next;
		}
		// Babies with lower weight
		return lowWeight; 
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
		// Babies with given name
		return babyName; 
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
	Node * head;
	int birthCount;
};
