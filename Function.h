#ifndef FUNCTION_H_

#include <iostream>
#include <fstream>
using namespace std;
#include<string>
using namespace std;

struct User {         //if user is a student, username is student ID
	string userName;  //if user is a academic staff or lecturer, username is short name. Eg: htthanh, tploc, ltathao,...
	string fullName;
	string id;
	string email;
	string mobilePhone;
	int type; //0-student, 1-academic staff, 2-lecturer
	string password;
	string className; //eg: 16CLC1, 16CLC2, 16CTT
	User *next;
};

struct Student {
	string no, ID, name;
	Student *next;
};

void load(const char pathToStudentFile[], Student *&head);

void save(const char pathToSaveFile[], Student *head);
void Login();
void studentMenu();
void acastaffMenu();
void lecturerMenu();

#endif // !FUNCTION_H_

