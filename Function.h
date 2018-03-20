#ifndef FUNCTION_H_

#include <iostream>
#include <fstream>
using namespace std;
#include<string>
using namespace std;

struct Student {
	string no, ID, name;
	Student *next;
};

void load(const char pathToStudentFile[], Student *&head);

void save(const char pathToSaveFile[], Student *head);

void studentMenu();
void acastaffMenu();
void lecturerMenu();

#endif // !FUNCTION_H_

