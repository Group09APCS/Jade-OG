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

void studentMenu()
{
	cout << "\n\n  _________________________STUDENT DATABASE_________________________";
	cout << "\n\n 1: Check - in ";
	cout << "\n\n 2: View score for a course ";
	cout << "\n\n 3: Schedule ";
	cout << "\n\n 4: View your info ";
	cout << "\n\n 5: Change password ";
	cout << "\n\n 6: Log out ";
	cout << "\n\n 7: Exit ";

}
void Login()
{
	char user[1000],pass[1000];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"	********************************************************************************************"<<endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout<<"						FINAL PROJECT"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"	********************************************************************************************"<<endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout<<"	          @@HH00                      00                            MM@@HH      @@HH00"<<endl;
	cout<<"	            @@                        HH                          WW      HH  WW"<<endl;
	cout<<"	            MM      WWOOMM            @@    WWOOMM                00      @@  00"<<endl;
	cout<<"	            OO            MM    00WWOOMM  HH      MM              HH      MM  HH        "<<endl;
	cout<<"	            WW      HH00WWOO  @@      OO  @@HH00WWOO    HH00WW    @@      OO  @@    WWOO"<<endl;
	cout<<"	    OO      00    MM      WW  MM      WW  MM                      MM      WW  MM      WW"<<endl;
	cout<<"	      OOMM@@        MM@@HH00    MM@@HH00    MM@@HH                  MM@@HH      MM@@HH"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"	********************************************************************************************"<<endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout<<"					STUDENT MANAGEMENT SYSTEM"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"	********************************************************************************************"<<endl;
	cout<<"						<<LOGIN>>"<<endl;
	cout<<"					Enter UserName: "<<endl;//khi co code cua Giang thi xoa cai endl
	//cin>>user;
	cout<<"					Enter Password: "<<endl;
	//cin>>pass;
	//them code kiem tra vao,sai bat nhap lai
	system("pause");
	system("cls");
	cout<<"______________________________________________________WELCOME___________________________________________________________"<<endl;
	int choice;
	do
	{
		cout << endl
		<< " 1 - Show the menu.\n"
		<< " 2 - View info.\n"
		<< " 4 - Change password.\n"
		<< " 5 - Exit.\n"
		<< " What do you want to do: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			//code 
			break;
			case 2:
			//code 
			break;
			case 3:
			//code
			break;
			case 4:
			//code
			break;
			case 5:
			cout << "End of Program.\n";
			break;
			default:
			cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
			break;
		}	

	}
	while (choice <1&&choice>5);
}

void acastaffMenu()
{
	int choice;
	cout << "\n\n  _________________________ACADEMIC STAFF DATABASE_________________________";
	cout << "\n\n 1: Student Management ";
	cout << "\n\n 2: Classes Management ";
	cout << "\n\n 3: Courses ";
	cout << "\n\n 4: Courses Schedule ";
	cout << "\n\n 5: Search for available course ";
	cout << "\n\n 6: Scoreboard ";
	cout << "\n\n 7: Your info ";
	cout << "\n\n 8: Change password ";
	cout << "\n\n 9: Log out ";
	cout << "\n\n 10: Exit ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "\n\n 1: Import A Class ";
		cout << "\n\n 2: Add New Student ";
		cout << "\n\n 3: Edit Student ";
		cout << "\n\n 4: Remove Student ";
		break;
	}
	case 2:
	{
		cout << "\n\n 1: Import A Class ";
		cout << "\n\n 2: Create New Class ";
		cout << "\n\n 3: View List Classes ";
		cout << "\n\n 4: View List of Student in Class ";
		break;
	}
	case 3:
	{
		cout << "\n\n 1: Import A Course ";
		cout << "\n\n 2: Add New Course ";
		cout << "\n\n 3: View List Courses ";
		cout << "\n\n 4: Edit Courses ";
		cout << "\n\n 5: Remove Courses ";
		break;
	}
	case 4:
	{
			cout << "\n\n 1: Import Courses' Schedules ";
			cout << "\n\n 2: Add New Courses' Schedule ";
			cout << "\n\n 3: View List Courses' Schedules ";
			cout << "\n\n 4: Edit Courses' Schedules ";
			cout << "\n\n 5: Remove Courses' Schedules ";
			break;
	}
	case 5:
	{
		cout << "\n\n 1: Search & View Attendance List ";
		cout << "\n\n 2: Export Attendance List";
		break;
	}
	case 6:
	{
		cout << "\n\n 1: Search & View Scoreboard ";
		cout << "\n\n 2: Export Scoreboard";
		break;
	}
	case 7:
	{
		cout << "\n\n Nothing here ";
		break;
	}
	case 8:
	{
		cout << "\n\n Nothing here ";
		break;
	}
	case 9:
	{
		cout << "\n\n Nothing here ";
		break;
	}
	case 10:
	{
		cout << "\n\n Nothing here ";
		break;
	}
	}
}
void lecturerMenu()
{
	cout << "\n\n  _________________________LECTURER DATABASE_________________________";
	cout << "\n\n 1: Scoreboard ";
	cout << "\n\n 2: Edit Grade ";
	cout << "\n\n 3: Your info ";
	cout << "\n\n 4: Change password ";
	cout << "\n\n 5: Log out ";
	cout << "\n\n 6: Exit ";
}
