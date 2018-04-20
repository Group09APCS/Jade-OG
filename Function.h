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
#include<iomanip>
#include <time.h>
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

struct Course {
	string courseCode;
	string academicYear; //eg: 2017 - 2018
	string semester;
	string courseName;
	string lecturerName;
	string startDate;
	string endDate;
	string dayOfWeek;    //schedule: Monday, Tuesday,...
	string startHour;    //eg: 7h30
	string endHour;      //eg: 11h30
	Course *next;
};

struct Score {
	string courseCode;
	string academicYear;  //eg: 2017-2018
	int semester;
	string id;            //student id
	float midtermScore;
	float labScore;
	Score *next;
};

struct Schedule {
	string courseCode;
	string dayOfWeek;   //eg: Mon, Tue, Wed
	string startDate;
	string endDate;
	string startHour;    //eg: 7h30
	string endHour;      //eg: 11h30
	Schedule *next;
};

struct Presence {
	string courseCode;
	string academicYear;
	int semester;
	int checkIn[105][11]; //0 = absent, 1 = not absent
	string frame[105][11];
	Presence *next;
};

//THIS AREA IS USED FOR MENU, AUTHORIZED PERSONNEL ONLY!!!
//******************USER MENU*********************
void Import(User *&head);
void Login(User *&head);
void showMenu(User *&head, User *&cur);
void save(string pathToSaveFile, User *&head);
void changepass(User *&head, User *&cur);



//SOME STUFF HERER
void generateid(string&name, string&Username);
int pass();
/*void save(const char pathToSaveFile[], Student *head);*/




//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
//*****ACADEMIC STAFF*****
void importstudentfromfile(Student *&head, string cl);
void acastaffMenu(User *&head, User*&cur);
//7
void addnewstudent(Student *&head, string scs);
//8
void editastudent(Student *&head1, Student *&head2, string scs, string unscs);
void newclass();
void changeclass(Student  *&head1, Student *&head2);
void printout(Student *&head, const string file);
void removestudent(Student*&head, string name);
void findstudent(Student*&cur, Student* head, string name);
//12. View list of classes
void listOfClass(User *head);
bool duplicateCheck(int numberOfClass, string classes[], string curClass);
//PRINT OUT COURSE
void printcout(Course *&chead, const string file);
//13. View list of students in a class
void listOfStudent(User *head, string curClass); // call example: listOfStudent(head, "17CTT1")
												 //15. Add a new course
void addanewcourse(Course *&chead, string filename);
//16. Edit an existing course
void editcourse(Course *&chead, string filename);
//17. Remove a course
void removeCourse(Course *&head, string courseToRemove);   //use courseCode for courseToRemove
void importcoursefromfile(Course* &chead, string filename);
//18. View list of courses
void viewcourse(Course*&chead, string f);
//19. Import courses' schedules from a csv file
void importschedulefromfile(Schedule* &shead, string filename);
//20. Add a course schedule
void addnewcourseschedule(Schedule* shead, string filename);
//21.Edit a course schedule
void editcourseschedule(Schedule* shead, string filename);
//22. Remove a course schedule
void removeacourseschedule(Schedule* shead, string filename);
void findcourseschedule(Schedule* shead, string filename, string name, Schedule* &cur);

//23
void viewcourseschedule(Schedule * &head, string filename);
//24. Search and view attendance list of a course
void loadPresence(string pathToPresenceFile, Presence *&presenceHead, string *presenceLabel);
void viewAttendance(string courseCode, Presence *presenceHead);
//25. Export Attendance list:
void exportPresence(string exportFileName, Presence *presenceHead);
//26. Search and view scoreboard of a course
void viewScore(string courseCode, Score *scoreHead);
//27. Export a scoreboard to a csv file
void exportScore(const char exportFileName[], string courseCode, Score *scoreHead);

//THIS AREA IS USED FOR STUDENT, AUTHORIZED PERSONNEL ONLY!!!
//*****STUDENT*****
void studentMenu(User *&head, User *&cur);
//33. View his / her scores of a course
void viewyourScore(string courseCode, Score *scoreHead, string id);



//THIS AREA IS USED FOR LECTURER, AUTHORIZED PERSONNEL ONLY!!!
//*****LECTURER*****
void lecturerMenu();
//28
void ImportScore(Score *&head, string sc);
//29
void EditGrade(Score *&head);
//30
void viewscore(Score *head);
//31
void checkin(Course*chead, User *Uhead);

#endif // !FUNCTION_H_
