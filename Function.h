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

//Ex01
void load(const char pathToStudentFile[], Student *&head);

//Ex02
void save(const char pathToSaveFile[], Student *head);

#endif // !FUNCTION_H_

