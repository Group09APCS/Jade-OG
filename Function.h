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
	char userName[1000];  //if user is a academic staff or lecturer, username is short name. Eg: htthanh, tploc, ltathao,...
	char fullName[1000];
	char id;
	char email;
	char mobilePhone;
	int type; //0-student, 1-academic staff, 2-lecturer
	char password[100];
	char className; //eg: 16CLC1, 16CLC2, 16CTT
	User *next;
};
struct Course{
	char c_code[100];
	int year;
	int semester;
	char c_name[1000];
	char lecname[1000];
	char sdate[1000];
	char edate[1000];
	char wdate[1000];
	char ftime[100];
	char ttime[100];
	Course * next;
}
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
void generateid(char name[1000], char Username[]);
int pass();

#endif // !FUNCTION_H_
