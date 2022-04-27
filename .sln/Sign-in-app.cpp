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
#include <array>
#include <regex>
#include "users.h"
using namespace std;

// print the menu
void showMenu() {
	cout << "(1) Register new account \n" <<
		"(2) Login \n" <<
		"(3) Change password \n" <<
		"(4) Exit \n";
}
// take option to execute and return false only if choice is (4)exit
bool takeInput() {
	
	cout << "enter option to execute: \n";
	int option;
	
	cin >> option; 

	if (option == 1) registerNewAcc();
	else if (option == 2) login();
	else if (option == 3) changePass();
	else if (option == 4) return 0;
	else {
		cout << "wrong input try again \n";
	}

	return 1;
}

int main()
{
	// show the menu and take input while choice != (4)exit
	bool run = true;
	do
	{
		showMenu();
		run = takeInput();

	} while (run);
	
}

