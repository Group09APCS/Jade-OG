#include "Function.h"

//Ex01
void load(const char pathToStudentFile[], Student *&head) {
	ifstream fin(pathToStudentFile);
	if (!fin.is_open()) {
		return;
	}
	Student *cur = NULL;

	while (fin.good()) {
		if (head == NULL) {
			head = new Student;
			getline(fin, head->no, ',');
			getline(fin, head->ID, ',');
			//getline(fin, head->name, ','); 
			head->name = "";  //Dong dau tien: "Class 17APCS1" nen head->no = Class, head->ID = 17APCS1, head->name = ""
			cout << head->no << "  " << head->ID << "  ";   //cai nay de minh xem ket qua ma khong can mo file 
			head->next = NULL;
			cur = head;
		}
		else {
			cur->next = new Student;
			cur = cur->next;
			getline(fin, cur->no, ',');
			getline(fin, cur->ID, ',');
			getline(fin, cur->name, ' ');// vi trong file .csv sau ten khong co dau phay
			cout << cur->no << "  " << cur->ID << "  " << cur->name;
			cur->next = NULL;
		}
	}
	fin.close();
}

//Ex02
void save(const char pathToSaveFile[], Student *head) {
	ofstream fout(pathToSaveFile);
	if (!fout.is_open()) {
		return;
	}
	Student *cur = head;
	while (cur->next != NULL) {
		fout << cur->no << "  " << cur->ID << "  " << cur->name << "  ";
		cur = cur->next;
	}
	if (cur->next == NULL) {
		fout << cur->no << "  " << cur->ID << "  " << cur->name << "  ";
	}

	fout.close();
}
bool login(const char username[], const char password[])
{
	char a[10];
	cout << "Welcome! This program is used to manage student records!!!" << endl;
	cout << "First, have you got an account? (y for yes and n for no)" << endl;
	cin.get(a, 9, '\n');
}