// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Sign-in-app.cpp
// Last Modification Date: 5/1/2022
// Author1 and ID and Group: Monaem Tarek
// Author2 and ID and Group: Magdy Ibrahim
// Author3 and ID and Group: Youssef Ihab
// Teaching Assistant: xxxxx xxxxx
// Purpose: ..............

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <conio.h>

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

void save_new_user(fstream& file, char name[100], string& id, string& email, string& username, string& password, string& phone) {

	file.close();
	// open the file and write data into it and then close it
	file.open(name, ios_base::binary | ios_base::out | ios_base::in);

	// set position to the end of file
	file.seekp(0, ios::end);

	file << id << " ";
	file << email << " ";
	file << password << " ";
	file << username << " ";
	file << phone << "\n";
	cout << "User added successfully.\n";
	file.close();
}

// return true if the Id exists before
bool is_id_exist(string& id) {

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
bool is_email_exist(string& email) {

	for (int i = 0; i < 100; i++)
	{
		if (email == usersArr[i].Email)
		{
			return 1;
		}
	}
	return 0;
}

// take a valid name and return it
string take_valid_userName() {
	string name;
	regex name_ex;
	smatch match;

	name_ex = "^([a-z|A-Z]{3,20})((_){1,3})?([a-z|A-Z]{1,20})?$";
	cout << "Enter your name:\n";
	cin >> name;

	while (!regex_match(name, match, name_ex))
	{
		cout << "----Wrong input. Please enter a valid name (only letters without spaces only '_' between two names----\n";
		cin >> name;
	}
	return name;
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
		cout << "---- Wrong input. Please enter a valid id (from 1 to 8 digits) only----\n";
		cin >> id;
	}
	return id;
}
//__________________________________________________________________________________________________
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
//_________________________________________________________________________________________________
// take a valid phone
string take_valid_phone() {
	string phone;
	regex phone_ex;
	smatch match;

	phone_ex = "^(01)(0|1|2|5)([0-9]{8})$";
	cout << "Enter your phone:\n";
	cin >> phone;

	while (!regex_match(phone, match, phone_ex))
	{
		cout << "----Wrong input. Please enter a valid phone number (starts with '01' and followed by {0, 1, 2 or 5} and 8 digits)----\n";
		cin >> phone;
	}
	return phone;
}
//______________________________________________________________________________________________
string encrypt_pass(string& pass) {
    const int letterCount = 'z' - 'a' + 1;
    for (auto &letter: pass) {
        if (!isalpha(letter)) {
            continue;
        }
        const bool isUpper = isupper(letter);
        const char baseOffset = isUpper ? 'A' : 'a';
        const auto distanceFromAlphabetStart = letter - baseOffset;
        letter = (baseOffset + letterCount - 1) - distanceFromAlphabetStart;
    }

	return pass;

}
//________________________________________________________________________________________________
string decrypt_pass(string& pass) {
	/*
	--------------------------------------------------        *  code  *          ------------------------------------------------------------------
	*/

	return pass;
}
//_______________________________________________________________________________________________
// take a valid pass
string take_valid_pass() {
    cout
    <<"1.Your password must be at least 8 characters long.\n\n\n"
    <<"2.It must contain at least one character that is not a letter, such as a digit.\n\n\n"
    <<"3.The following special characters can be used in passwords\n\n\n"
    <<" ---------------------------------------------------------------\n"
    <<"| curly brackets {} |round brackets () |square brackets []      |\n"
    <<"| hash #            |colon:            |semi-colon ;            |\n"
    <<"| comma ,           |full-stop .       |question mark ?         |\n"
    <<"| exclamation mark !|bar or pip |      |ampersand &             |\n"
    <<"| underscore _      |backtick `        |tilde ~                 |\n"
    <<"| at @              |dollar $          |percent %               |\n"
    <<"| slash /           |backslash \        |arithmetic symbols =+-* |\n"
    <<"| caret ^           |single quote '    |double quotes \"         |\n"
    <<" ---------------------------------------------------------------\n\n\n";
//______________________________________________________________________________________________
	string pass;
	string pass2;
	regex pass_ex;
	smatch match;
	pass_ex = "(?=^.{8,}$)(?=.*\d)(?=.*[!@#$%^&*]+)(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$";    // --------------------------------------  *  type regex here  *   --------------------------------------------------------------
	cout << "Enter a strong password:\n";
    int ch;
    ch = getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout<<'*';
        ch =getch();
    }
    cout<<endl;
	while (!regex_match(pass, match, pass_ex))
	{
	    cout << "Your Password is weak \n";
        int ch;
        ch = getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout<<'*';
            ch =getch();
        }
        cout<<endl;
    }
//________________________________________________________________________________________
	// to make the user input the password two times
    cout<<"Enter the Password again :\n";
    ch = getch();
    while (ch != 13)
    {
    pass2.push_back(ch);
    cout<<'*';
    ch =getch();
    }
    cout<<endl;
    if (pass2 == pass)
    {
        cout<<"";
    }
    else
    {
        cout<<"Please try again!!! The passwords are not identical!!!\n";
        take_valid_pass();
    }
    // encrypt the password
    pass = encrypt_pass(pass);
//__________________________________________________________________________________________________
	// return the encrypted password
	return pass;
}
//---------------------------------------------------------------------------------------------------------------------------------------
// fuction to get user's info and check if it's valid or not and then save the data if valid
void registerNewAcc(fstream& file, char name[100]) {

	cout << "register..\n";
	string id, email, username, password, phone;

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

	// get a valid name
	username = take_valid_userName();

	// get a valid phone
	phone = take_valid_phone();

	// get strong pass
	password = take_valid_pass();

	// save the info to the file
	save_new_user(file, name, id, email, username, password, phone);

}

void sign_in(){
    string iD , password;


	cout<<"enter user's iD: ";
	cin>>iD;

	cout<<"enter user's password: ";
	cin>> password;

	for (int i=0; i<100 ; i++ ){
        if(iD == usersArr[i].Id && password==usersArr[i].Password){
            cout<< "successful login, welcome "<< usersArr[i].User_name << endl;
            break;
        }
        else if (i== 99){

        cout<< "wrong iD or Password , try again ! \n";
        cout<<"enter user's iD: ";
        cin>>iD;

        cout<<"enter user's password: ";
        cin>> password;

        for (int i=0; i<100 ; i++ ){
            if(iD == usersArr[i].Id && password==usersArr[i].Password){
                cout<< "successful login, welcome "<< usersArr[i].User_name << endl;
                break;
            }
            else if(i == 99){
                    cout<< "wrong iD or Password , try again ! \n";
                    cout<<"enter user's iD: ";
                    cin>>iD;

                    cout<<"enter user's password: ";
                    cin>> password;

                for (int i=0; i<100 ; i++ ){
                    if(iD == usersArr[i].Id && password==usersArr[i].Password){
                        cout<< "successful login, welcome "<< usersArr[i].User_name << endl;
                        break;
                    }
                    else if(i == 99){
                        cout<<"you are denied access to the system !";
                        break;
                    }

                }

            }


        }

        }
	}
}

//
void login(fstream& file, char name[100]) {
	cout << "login..\n";
	sign_in();
}

//
void changePass(fstream& file, char name[100]) {
	cout << "change pass..\n";
	/*
	--------------------------------------------------        * code *        -------------------------------------------------------------------
	*/

}
