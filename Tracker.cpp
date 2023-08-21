//Evan Barnes
//CS210 7-3 Project 3 submission
#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

//class
class Tracker {
private:
	map<string, int> frequency;

public:
	//constructor
	Tracker() {
		//read input file
		ifstream inFile("CS210_Project_Three_Input_File.txt");
		string item;
		while (inFile >> item) {
			frequency[item]++;
		}
		//close input file
		inFile.close();
	}

	//get frequency of item
	int getFrequency(const string& item) {
		return frequency[item];
	}

	//print list of items with their frequencies
	void displayFrequencyList() {
		for (const auto& itemPair : frequency) {
			cout << itemPair.first << " " << itemPair.second << endl;
		}
	}
	//print list of items with *'s for frequencies (histogram)
	void displayHistogramList() {
		for (const auto& itemPair : frequency) {
			cout << itemPair.first << " ";
			for (int i = 0; i < itemPair.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

	//list and frequency to backup data/output file (frequency.dat)
	void backupData() {
		ofstream outFile("frequenc.dat");
		for (const auto& itemPair : frequency) {
			outFile << itemPair.first << " " << itemPair.second << endl;
		}
		//close output file
		outFile.close();
	}
};

//define main
int main() {
	Tracker tracker;
	int userChoice;

	//display menu options
	do {
		cout << "Menu Options:" << endl;
		cout << "1. Search item frequency" << endl;
		cout << "2. Print list of item frequencies" << endl;
		cout << "3. Print histogram of item frequencies" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your option: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1: {
			string item;
			cout << "Enter the item your looking for: ";
			cin >> item;
			cout << "Frequency of " << item << ": " << tracker.getFrequency(item) << endl;
			break;
		}
		case 2:
			tracker.displayFrequencyList();
			break;
		case 3:
			tracker.displayHistogramList();
			break;
		case 4:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
		}

		cout << endl;
	} while (userChoice != 4);
	return 0;
}