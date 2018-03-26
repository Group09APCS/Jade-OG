#ifndef FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<string>
#include <Windows.h>
#include<math.h>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

struct User {         //if user is a student, username is student ID
	string userName;  //if user is a academic staff or lecturer, username is short name. Eg: htthanh, tploc, ltathao,...
	string fullName;
	string ID;
	string email;
	string mobilePhone;
	string type; //0-student, 1-academic staff, 2-lecturer
	string password;
	string className; //eg: 16CLC1, 16CLC2, 16CTT
	User *next;
};
struct Student {
	string no, ID, fullName, email, sclass;
	Student *next;
};

void load(Student *&head);

void save(const char pathToSaveFile[], Student *head);
void Login();
void studentMenu();
void acastaffMenu();
void lecturerMenu();
void generateid(char name[1000], char Username[]);
int pass();

#endif // !FUNCTION_H_
