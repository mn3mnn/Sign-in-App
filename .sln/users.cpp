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
#include <fstream>
#include <regex>

using namespace std;

struct Users {
	string Id, User_name, Email, Password, Phone;
	

};

// array of struct users 
Users usersArr[100];

// load the data from the file into the users array of struct
void fillUsersArr(fstream& file, char name[100]) {

	file.close();
	// open the file and load the data and then close it
	file.open(name, ios_base::binary | ios_base::out | ios_base::in);

	int i = 0;
	while (!file.eof())
	{
		file >> usersArr[i].Id;

		file >> usersArr[i].User_name;

		file >> usersArr[i].Password;

		file >> usersArr[i].Email;

		file >> usersArr[i].Phone;

		// move to next user
		++i;
	}
	file.close();
}

void save_new_user(fstream& file, char name[100], string& id, string& email, string username, string password, string phone) {

	// open the file and write data into it and then close it
	file.open(name, ios_base::binary | ios_base::out | ios_base::in);

	// set position to the end of file
	file.seekp(0, ios::end);

	file << id << " ";
	file << email << " ";
	file << password << " ";
	file << username << " ";
	file << phone << " ";
	cout << "User added successfully.\n";
	file.close();
}

// return true if the Id exists before 
bool is_id_exist(string id) {

	for (int i = 0; i < 100; i++)
	{
		if (id == usersArr[i].Id)
		{
			return 1;
		}
	}
	return 0;
}

// return true if the email exists before 
bool is_email_exist(string email) {

	for (int i = 0; i < 100; i++)
	{
		if (email == usersArr[i].Email)
		{
			return 1;
		}
	}
	return 0;
}

// take a valid id which is = from 1 to 8 digits only
string take_valid_id() {
	string id;
	regex id_ex;
	smatch match;

	id_ex = "(^[0-9]{1,8}$)";
	cout << "Enter your Id:\n";
	cin >> id;

	while (!regex_match(id, match, id_ex))
	{
		cout << "---- Wrong input. Please enter a valid id (from 1 to 8 digits) only ----\n";
		cin >> id;
	}
	return id;
}

// take a valid email 
string take_valid_email() {
	string email;
	regex email_ex;
	smatch match;

	email_ex = "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$";
	cout << "Enter your email:\n";
	cin >> email;

	while (!regex_match(email, match, email_ex))
	{
		cout << "---- Wrong input. Please enter a valid email ----\n";
		cin >> email;
	}
	return email;
}

//--------------------------------------------------------------------------------------------
// fuction to get user's info and check if it's valid or not and then save the data if valid
void registerNewAcc(fstream& file, char name[100]) {

	cout << "register..\n";
	string id, email, username, password, phone = "";

	// take a valid id 
	id = take_valid_id();
	// check if the id is already exist 
	while (is_id_exist(id))
	{
		cout << "----id already exist try another one----\n";
		id = take_valid_id();
	}

	// take a valid email
	email = take_valid_email();
	// check if the email is used before
	while (is_email_exist(email))
	{
		cout << "----email already exist try another one----\n";
		email = take_valid_email();
	}
	// save the info to the file
	save_new_user(file, name, id, email, username, password, phone);

}

void login(fstream& file, char name[100]) {
	cout << "login..\n";
	
}

void changePass(fstream& file, char name[100]) {
	cout << "change pass..\n";
}
