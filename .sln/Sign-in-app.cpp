// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: xxxxxx.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: xxxxx xxxxx
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........

#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <regex>
#include <fstream>
#include "users.h"
using namespace std;

// the text file to store and read from it
fstream dataFile;

// name of the file
char name[100];

// take the text file name and try to open it
void openDataFile() {

	cout << "Enter an exist data file name:\n";
	cin >> name;
	strcat_s(name, ".txt");

	// open in read mode and don't create new files if doesn't exist
	dataFile.open(name, ios_base::binary | ios_base::out | ios_base::in);

	// handle any wrong names or files doesn't exist
	while (!dataFile.is_open())
	{
		cout << "----Couldn't open the file. try again----\n";
		cout << "Do you want to create new file ?  \n(y) to create new one.  (n) to try opening file again. \n";
		char choice;
		cin >> choice;
		// create a new file and open it in write mode
		if (choice == 'y')
		{
			cout << "Enter the new file name:\n";
			cin >> name;
			strcat_s(name, ".txt");
			dataFile.open(name, ios::app);
		}
		else
		{	// try to open exist file again
			cout << "Enter an exist data file name:\n";
			cin >> name;
			strcat_s(name, ".txt");
			dataFile.open(name, ios_base::binary | ios_base::out | ios_base::in);
		}
	}

	cout << "Opened file succesfully.\n";
}

// print the menu
void showMenu() {
	cout <<"\n---select option to apply:---\n"
		"(1) Register new account \n" <<
		"(2) Login \n" <<
		"(3) Change password \n" <<
		"(4) Exit \n";
}

// take option to execute and return false only if choice is (4)exit
bool takeInput() {

	cout << "enter an option: \n";
	int option;
	
	cin >> option;
	// handle any non integer inputs
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "----Wrong input! enter numbers only. try again----\n";
		cin >> option;
	}

	
	if (option == 1)
	{
		registerNewAcc(dataFile, name);
	}
	else if (option == 2)
	{
		
		login(dataFile, name);
	}
	else if (option == 3) 
	{	
		changePass(dataFile, name);
	}
	else if (option == 4) return 0;
	else {
		cout << "----Wrong input! try again----\n";
	}

	return 1;
}


int main()
{
	// open the text file
	openDataFile();

	fillUsersArr(dataFile, name);

	// show the menu and take an input  while choice != (4)exit
	bool run = true;
	do
	{
		showMenu();
		run = takeInput();

	} while (run);
	
	// close the text file 
	dataFile.close();
}

