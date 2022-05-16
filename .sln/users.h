#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void registerNewAcc(fstream& file, char name[100]);

string sign_in(fstream& file, char name[100]);

void changePass(fstream& file, char name[100]);

void fillUsersArr(fstream& file, char name[100]);
