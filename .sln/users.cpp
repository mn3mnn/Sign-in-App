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
#include <regex>

using namespace std;

struct Users {
	string Id, User_name, Email, Password;
	
	Users(string id, string user_name, string email, string password) {
		Id = id;
		User_name = user_name;
		Email = email;
		Password = password;
	}
};

void registerNewAcc() {
	cout << "register\n";
}

void login() {
	cout << "login\n";
}

void changePass() {
	cout << "change pass\n";
}


