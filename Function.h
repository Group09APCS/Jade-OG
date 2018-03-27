#ifndef FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<string>
#include <string.h>
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
	string  ID, fullName, email, sclass;
	Student *next;
};

//THIS AREA IS USED FOR MENU, AUTHORIZED PERSONNEL ONLY!!!
//******************USER MENU*********************
void Import(User *&head);
void Login(User *&head);
void showMenu(User *&head, User *&cur);





//SOME STUFF HERER
void generateid(string&name, string&Username);
int pass();
/*void save(const char pathToSaveFile[], Student *head);*/




//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
//*****ACADEMIC STAFF*****
void importstudentfromfile(Student *&head, string cl);
void acastaffMenu(User *&head, User*&cur);
void newclass();
void changeclass(Student  *&head1, Student *&head2);




//THIS AREA IS USED FOR STUDENT, AUTHORIZED PERSONNEL ONLY!!!
//*****STUDENT*****
void studentMenu();




//THIS AREA IS USED FOR LECTURER, AUTHORIZED PERSONNEL ONLY!!!
//*****LECTURER*****
void lecturerMenu();



#endif // !FUNCTION_H_
