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
#include<iomanip>
using namespace std;

struct User {
	int no;
	//if user is a student, username is student ID
	char userName[50];  //if user is a academic staff or lecturer, username is short name. Eg: htthanh, tploc, ltathao,...
	char fullName[50];
	char id[50];
	char email[100];
	char phoneNumber[20];
	int type; //0-student, 1-academic staff, 2-lecturer
	char password[50];
	char className[20]; //eg: 16CLC1, 16CLC2, 16CTT
	User *next;
};
struct Course{
	char c_code[100];    //courseCode?   Eg:CTT008, CS161
	int year;            //academicYear   Eg: 2017-2018
	int semester;
	char c_name[1000];   //courseName?
	char lecname[1000];  //lecturerUserName
	char sdate[1000];    //startDate
	char edate[1000];    //endDate
	char wdate[1000];    //dayOfWeek    Eg: Monday, Tuesday,...
	char ftime[100];     //timeStart    Eg: 7h30?
	char ttime[100];     //timeEnd      Eg: 11h30...
	Course * next;
};
struct Presence{
char c_code[100];   //courseCode
int year;           //academicYear   Eg: 2017-2018
int semester;       //Eg: 1, 2, 3
int studentID;
int week;
};
struct Score{
char c_code[100];   //courseCode
int year;           //academicYear   Eg: 2017-2018     
int semester;       //Eg: 1, 2, 3
int studentID;
float midscore;     //midtermScore
float labscore;     //labScore
float finscore;     //finalScore
};
struct Student {
	int no, ID;
	char name[1000];
	Student *next;
};
struct Class{
	char name[1000];
	Student a;
	Class * next;
};
void load(const char pathToStudentFile[], Student *&head);

void save(const char pathToSaveFile[], Student *head);
void Login();
void studentMenu();
void acastaffMenu();
void lecturerMenu();
void generateid(char name[1000], char Username[]);
void cinData(const char pathToDataFile[], User *head);
int pass();

#endif // !FUNCTION_H_
