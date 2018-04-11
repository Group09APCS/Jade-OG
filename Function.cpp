#include "Function.h"
/*
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
*/
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
void Import(User *&head)
{
	// Import the users from csv file
	ifstream fin;
	fin.open("user.csv");
	if (!fin.is_open()) {
		return;
	}
	User * cur = NULL;
	head = new User;
	getline(fin, head->userName, ',');
	getline(fin, head->fullName, ',');
	getline(fin, head->ID, ',');
	getline(fin, head->email, ',');
	getline(fin, head->mobilePhone, ',');
	getline(fin, head->type, ',');
	getline(fin, head->password, ',');
	getline(fin, head->className, ' ');
	head->next = NULL;
	cur = head;
	while (fin.good())
	{
		cur->next = new User;
		cur = cur->next;
		getline(fin, cur->userName, ',');
		getline(fin, cur->fullName, ',');
		getline(fin, cur->ID, ',');
		getline(fin, cur->email, ',');
		getline(fin, cur->mobilePhone, ',');
		getline(fin, cur->type, ',');
		getline(fin, cur->password, ',');
		getline(fin, cur->className);
	}
	cur->next = NULL;
	fin.close();
}
void Login(User *&head)
{
	system("cls");
	int choice;
	string name, Username, password;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "						FINAL PROJECT" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "	          @@HH00                      00                            MM@@HH      @@HH00" << endl;
	cout << "	            @@                        HH                          WW      HH  WW" << endl;
	cout << "	            MM      WWOOMM            @@    WWOOMM                00      @@  00" << endl;
	cout << "	            OO            MM    00WWOOMM  HH      MM              HH      MM  HH        " << endl;
	cout << "	            WW      HH00WWOO  @@      OO  @@HH00WWOO    HH00WW    @@      OO  @@    WWOO" << endl;
	cout << "	    OO      00    MM      WW  MM      WW  MM                      MM      WW  MM      WW" << endl;
	cout << "	      OOMM@@        MM@@HH00    MM@@HH00    MM@@HH                  MM@@HH      MM@@HH" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "					STUDENT MANAGEMENT SYSTEM" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "	********************************************************************************************" << endl;
	cout << "						<<LOGIN>>" << endl;
	cout << "					Enter UserName: ";
	bool check = false;
	int t = 0;
	User * cur = head->next;
	for (int i = 0; i < 3; i++)
	{
		cur = head->next;
		getline(cin, Username);
		while (cur)
		{
			if (Username == cur->userName)
			{
				check = true;
				break;
			}
			cur = cur->next;
		}
		if (check == true)
			break;
		else
			cout << "					Mismatched! " << 3 - i << " time(s) remain:";

	}
	if (check == false)
	{
		system("cls");
		cur = head;
		cout << "					Do u want to create a new account? \n";
		cout << "					1.YES \n";
		cout << "					2.NO \n";
		cout << "					What do you want to do: ";
		cin >> t;
		switch (t)
		{
		case 1:
		{

			cout << "					Please input your fullname: ";
			cin.ignore();
			getline(cin, name);
			while (cur->next)
				cur = cur->next;
			cur->next = new User;
			cur = cur->next;
			cur->fullName = name;

			generateid(name, Username);
			cur->userName = Username;
			cout << "					Choose your password: ";
			password.clear();
			getline(cin, password);
			cur->password = password;
			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;
			/*cout << "					Please set a new password: ";
			getline(cin, password);

			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;*/
			break;
		}
		case 2:
		{
			cout << "					See you next time \n";
			exit(0);
		}
		}
	}
	cout << "					Enter Password: ";
	check = false;
	t = 0;
	for (int i = 0; i < 3; i++)
	{
		getline(cin, password);
		if (password == cur->password)
		{
			check = true;
			break;
		}
		else cout << "					" << 3 - i << "time(s) to try";
	}
	if (check == false)
		exit(0);
	showMenu(head, cur);
}
void showMenu(User *&head, User *&cur)
{
	bool check = false;
	int choice;
	string password;
	system("cls");
	cout << "______________________________________________________WELCOME___________________________________________________________" << endl;

	cout << endl
		<< " 1 - Show the menu.\n"
		<< " 2 - View info.\n"
		<< " 3 - Change password.\n"
		<< " 4 - Exit.\n"
		<< " What do you want to do: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	if (cur->type == "1")
		acastaffMenu(head, cur);
	if (cur->type == "0")
		studentMenu();
	if (cur->type == "2")
		lecturerMenu();
	break;
	}
	case 2:
	{
		cout << " User Name: " << cur->userName << endl;
		cout << " Full Name: " << cur->fullName << endl;
		cout << " ID: " << cur->ID << endl;
		cout << " Email: " << cur->email << endl;
		cout << " Phone: " << cur->mobilePhone << endl;
		cout << " Type: " << cur->type << endl;
		cout << " Password: " << cur->password << endl;
		cout << " Class: " << cur->className << endl;
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{showMenu(head, cur);
		break;
		}
		case 2:
		{
			cout << " SEEYA!.\n";
			exit(0);
			break;
		}
		default:
		{
			cout << " Not a Valid Choice. \n"
				<< " Choose again.\n";
			break;
		}
		}
	}
	case 3:
	{
		cout << " Pls enter your old password: \n";
		cin.ignore();
		getline(cin, password);
		check = false;
		for (int i = 0; i < 3; i++)
		{
			if (password == cur->password)
			{
				check = true;
				break;
			}
			if (password != cur->password)
			{
				cout << " Mismatched! " << 3 - i << " time(s) remain: \n";
				check = false;
				getline(cin, password);
			}

		}
		if (check == true)
		{
			cout << " Pls enter your new password: \n";
			getline(cin, password);
			cur->password = password;
			cout << " Pls enter your new password again: \n";
			getline(cin, password);
			while (password != cur->password)
				getline(cin, password);
			cur->password = password;
			cout << " Complete! Your password has been changed! \n";
			cout << " 1 - Return to the menu.\n";
			cout << " 2 - Exit. \n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{showMenu(head, cur);
			break;
			}
			case 2:
			{
				cout << "SEEYA!.\n";
				exit(0);
				break;
			}
			default:
			{
				cout << "Not a Valid Choice. \n"
					<< "Choose again.\n";
				break;
			}
			}

		}

		else {
			Login(head);
		}
		break;
	}
	case 4:
	{
		cout << "SEEYA!.\n";
		exit(0);
		break;
	}
	default:
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
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

void generateid(string&name, string&Username)
{
	int i = name.length() - 1;
	int p = 0, k = 1;
	string add;
	Username.clear();
	int n = i;
	for (int j = 0; j < n; j++)
		name[j] = tolower(name[j]);
	Username = name[0];
	while (name[i] != ' ')
	{
		i--;
	}
	i++;
	for (int j = i; j <= n; j++)
	{
		add += name[j];
	}
	for (int t = 0; t < i - 1; t++)
	{
		if (name[t] == ' ')
		{
			Username += name[t + 1];
		}
	}
	Username += add;
}

int pass()
{
	srand(time(NULL));
	int a = rand();
	return a;
}
//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
void acastaffMenu(User *&head, User*&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________ACADEMIC STAFF DATABASE_________________________";
	cout << "\n\n 1: Student Management ";
	cout << "\n\n 2: Courses ";
	cout << "\n\n 3: Courses Schedule ";
	cout << "\n\n 4: Search for available course ";
	cout << "\n\n 5: Scoreboard ";
	cout << "\n\n 6: Return ";
	cout << "\n\n 7: Log out ";
	cout << "\n\n 8: Exit ";
	cout << "\n\n What do you want to do: ";
	cin >> choice;
	int newchoice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n 1: Import Students Of A Class From A CSV File ";
		cout << "\n\n 2: Add New Student ";
		cout << "\n\n 3: Edit An Existing Student ";
		cout << "\n\n 4: Remove A Student ";
		cout << "\n\n 5: Change Students From Class A to Class B ";
		cout << "\n\n 6: Add A New Empty Class ";
		cout << "\n\n 7: Create New Class ";
		cout << "\n\n 8: View List of Student in Class ";
		cout << "\n\n What do you want to do: ";
		Student * head1 = NULL;
		Student *head2 = NULL;
		importstudentfromfile(head1, "17CTT1.csv");
		importstudentfromfile(head2, "17CTT2.csv");
		cin >> newchoice;
		switch (newchoice) {
		case 1:
		{
			string cl;
			cout << "\n\n Which class you want to import? \n";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			getline(cin, cl);
			while (cl != "1" && cl != "2")
				getline(cin, cl);
			Student *top = NULL;
			if (cl == "1") cl = "17CTT1.csv";
			else cl = "17CTT2.csv";
			importstudentfromfile(top, cl);
			cout << "Successful! Return to menu... \n";
			showMenu(head, cur);
		}
		case 2:
		{
			cout << "Nothing here \n";
			break;
		}
		case 3:
		{
			int Choice2;
			Student* cur1 = NULL;
			cout << "In which class do you want to edit a student?" << endl;
			cout << "1: 17CTT1\n";
			cout << "2: 17CTT2\n";
			cin >> Choice2;
			string name;
			cout << "Which student you want edit?\n";
			cin.ignore();
			getline(cin, name,'\n');
			switch (Choice2)
			{
			case 1:
			{
				Student * head1 = NULL;
				Student *head2 = NULL;
				importstudentfromfile(head1, "17CTT1.csv");
				importstudentfromfile(head2, "17CTT2.csv");
				cout << "\n What do you want to edit?\n";
				cout << "1: student ID\n";
				cout << "2: student name\n";
				cout << "3: class\n";
				int Choice1;
				cin >> Choice1;
				string str;
				findstudent(cur1, head1, name);
				switch (Choice1)
				{
				case 1:
				{
					cout << "Please enter new student ID: ";
					cin.ignore();
					getline(cin, str, '\n');
					cur1->ID = str;
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head,cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				case 2:
				{
					cout << "Please enter the new student name: ";
					cin.ignore();
					getline(cin, str, '\n');
					cur1->fullName = str;
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head, cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				case 3:
				{
					cin.ignore();
					getline(cin, str, '\n');
					changeclass(head1, head2);
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head, cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				default:
				{
					cout << "Error!\n";
					break;
				}
				}
			}
			case 2:
			{
				Student * head1 = NULL;
				Student *head2 = NULL;
				importstudentfromfile(head1, "17CTT1.csv");
				importstudentfromfile(head2, "17CTT2.csv");
				cout << "\n What do you want to edit?\n";
				cout << "1: student ID\n";
				cout << "2: student name\n";
				cout << "3: class\n";
				int Choice1;
				cin >> Choice1;
				string str;
				findstudent(cur1, head2, name);
				switch (Choice1)
				{
				case 1:
				{
					cout << "Please input the new student ID: ";
					cin.ignore();
					getline(cin, str, '\n');
					cur1->ID = str;
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head, cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				case 2:
				{
					cout << "Please input the new student name: " << endl;
					cin.ignore();
					getline(cin, str, '\n');
					cur1->fullName = str;
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head, cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				case 3:
				{
					cin.ignore();
					getline(cin, str, '\n');
					changeclass(head1, head2);
					cout << "Done!" << endl;
					cout << "1. Show menu\n";
					cout << "2. Exit\n";
					cin >> Choice1;
					switch (Choice1) {
					case 1:
					{
						showMenu(head, cur);
						break;
					}
					case 2:
					{
						exit(0);
						break;
					}
					}
					break;
				}
				default:
				{
					cout << "Error!\n";
					break;
				}
				}
			}
			}
		case 4:
		{
			Student * head1 = NULL;
			Student *head2 = NULL;
			importstudentfromfile(head1, "17CTT1.csv");
			importstudentfromfile(head2, "17CTT2.csv");
			int Choicex;
			cout << "In which class do you want to remove a student?" << endl;
			cout << "1: 17CTT1\n";
			cout << "2: 17CTT2\n";
			cin >> Choicex;
			string name;
			cout << "\n Which student you want to remove?";
			cin.ignore();
			getline(cin, name, '\n');
			switch (Choicex) {
			case 1:
			{
				removestudent(head1, name);
				cout << "Done!" << endl;
				cout << "1. Show menu\n";
				cout << "2. Exit\n";
				cin >> Choicex;
				switch (Choicex) {
				case 1:
				{
					showMenu(head, cur);
					break;
				}
				case 2:
				{
					exit(0);
					break;
				}
				}
				break;
			}
			case 2:
			{
				removestudent(head2, name);
				cout << "Done!" << endl;
				cout << "1. Show menu\n";
				cout << "2. Exit\n";
				cin >> Choicex;
				switch (Choicex) {
				case 1:
				{
					showMenu(head, cur);
					break;
				}
				case 2:
				{
					exit(0);
					break;
				}
				}
				break;
			}
			}
			break;
		}
		case 5:
		{
			Student * head1 = NULL;
			Student *head2 = NULL;
			importstudentfromfile(head1, "17CTT1.csv");
			importstudentfromfile(head2, "17CTT2.csv");
			changeclass(head1, head2);
			break;
		}
		case 7:
		{
			newclass();
			break;
		}
		break;
		}
	}
	case 2:
	{	system("cls");
	cout << "\n\n 1: Import A Course ";
	cout << "\n\n 2: Add New Course ";
	cout << "\n\n 3: View List Courses ";
	cout << "\n\n 4: Edit Courses ";
	cout << "\n\n 5: Remove Courses ";
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			Course* chead = NULL;
			importcoursefromfile(chead, "course.csv");
			Course* cur1 = chead;
			string str;
			while (cur1->next != NULL)
			{
				cur1 = cur1->next;
			}
			cur1->next = new Course;
			cur1 = cur1->next;
			cout << "Pls input courseCode: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->courseCode = str;
			cout << "Pls input academicYear: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->academicYear = str;
			cout << "Pls input courseName: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->courseName = str;
			cout << "Pls input lecturerName: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->lecturerName = str;
			cout << "Pls input startDate: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->startDate = str;
			cout << "Pls input endDate: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->endDate = str;
			cout << "Pls input dayOfWeek: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->dayOfWeek = str;
			cout << "Pls input startHour: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->startHour = str;
			cout << "Pls input endHour: ";
			cin.ignore();
			getline(cin, str, '\n');
			cur1->endHour = str;
			cur->next = NULL;
			cout << "Done!" << endl;
			cout << "1. Show menu\n";
			cout << "2. Exit\n";
			cin >> choice;
			switch (choice) {
			case 1:
			{
				showMenu(head, cur);
				break;
			}
			case 2:
			{
				exit(0);
				break;
			}
			}
			break;
		}
	}
	}
	break;
	}
	case 3:
	{	system("cls");
	cout << "\n\n 1: Import Courses' Schedules ";
	cout << "\n\n 2: Add New Courses' Schedule ";
	cout << "\n\n 3: View List Courses' Schedules ";
	cout << "\n\n 4: Edit Courses' Schedules ";
	cout << "\n\n 5: Remove Courses' Schedules ";
	break;
	}
	case 4:
	{	system("cls");
	cout << "\n\n 1: Search & View Attendance List ";
	cout << "\n\n 2: Export Attendance List";
	break;
	}
	case 5:
	{	system("cls");
	cout << "\n\n 1: Search & View Scoreboard ";
	cout << "\n\n 2: Export Scoreboard";
	break;
	}
	case 6:
	{
		showMenu(head, cur);
		break;
	}
	case 7:
	{
		cin.ignore();
		Login(head);
		break;
	}
	case 8:
	{
		exit(0);
		break;
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}
	}
}
void importstudentfromfile(Student *&head, string cl) {
	ifstream fin(cl);
	if (!fin.is_open()) {
		return;
	}
	Student *cur = NULL;
	while (fin.good()) {
		if (head == NULL) {
			head = new Student;
			getline(fin, head->ID, ',');
			getline(fin, head->fullName, ',');
			getline(fin, head->email, ',');
			getline(fin, head->sclass);
			head->next = NULL;
			cur = head;
		}
		else {
			cur->next = new Student;
			cur = cur->next;
			getline(fin, cur->ID, ',');
			getline(fin, cur->fullName, ',');
			getline(fin, cur->email, ',');
			getline(fin, cur->sclass);
			cur->next = NULL;
		}
	}
	fin.close();
}
void newclass()
{
	string classname;
	ofstream fout;
	cout << "Please input the name of the new class:";
	getline(cin, classname);
	classname.append(".csv");
	fout.open(classname);
	fout.close();
}

void changeclass(Student  *&head1, Student *&head2)
{
	string studentID;
	cout << "Please input ID of the student that you want to change class:";
	cin.ignore();
	getline(std::cin, studentID);
	Student*cur = head1;
	while (studentID.compare(cur->ID) != 0 && cur != NULL)
	{
		cur = cur->next;
	}
	if (cur == NULL)
	{
		cout << "That student is not in this class";
	}
	else
	{
		{
			Student *temp = new Student;
			temp = cur;
			cur = cur->next;

			Student*cur2 = head2;
			while (studentID.compare(cur2->ID)<0 && cur2->next != NULL)
				cur2 = cur2->next;
			if (cur2->next == NULL)
			{
				cur2->next = new Student;
				cur2 = cur2->next;
				cur2->ID = temp->ID;
				cur2->fullName = temp->fullName;
				cur2->email = temp->email;
				cur2->sclass = temp->sclass;
				cur2->next = NULL;
				cout << "Added student in the end of the class";
			}
			else
			{
				Student *temp2 = new Student;
				temp2->ID = temp->ID;
				temp2->fullName = temp->fullName;
				temp2->email = temp->email;
				temp2->sclass = temp->sclass;
				temp2->next = cur->next;
				cur2->next = temp2;
				cur2 = cur2->next;
				cout << "Done!";
			}
			delete temp;
		}

	}
	printout(head1, "1.csv");
	printout(head2, "2.csv");
	system("pause");
}
void printout(Student *&head, const string file)
{
	ofstream fout;
	fout.open(file);
	Student * cur = head;
	while (cur)
	{
		fout << cur->ID << "," << cur->fullName << "," << cur->email << "," << cur->sclass << endl;
		cur = cur->next;
	}

}


//12. View list of classes
void listOfClass(User *head) {
	User *cur = head->next;
	string classes[50];
	int numberOfClass = 0;
	cout << "List of Classes:\n";
	while (cur->next != NULL) {
		if (!duplicateCheck(numberOfClass, classes, cur->className)) {
			classes[numberOfClass++] = cur->className;
		}
		cur = cur->next;
	}
	/*if (cur->next == NULL && (!duplicateCheck(numberOfClass, classes, cur->className))) {
	classes[numberOfClass++] = cur->className;
	}*/
	for (int i = 0; i < numberOfClass - 1; ++i) {
		cout << classes[i] << endl;
	}
}

bool duplicateCheck(int numberOfClass, string classes[], string curClass) {
	if (numberOfClass == 0) {
		return false;
	}
	for (int i = 0; i < numberOfClass; ++i) {
		if (classes[i] == curClass) {
			return true;
		}
	}
	return false;
}

//13. View list of students in a class
void listOfStudent(User *head, string curClass) {
	cout << "List of students in the class " << curClass << " :" << endl;
	User *cur = head->next;
	while (cur->next != NULL) {
		if (cur->className == curClass) {
			cout << cur->fullName << endl;
			cur = cur->next;
		}
		if (cur->next == NULL) {
			cout << cur->fullName << endl;
		}
	}
}

void importcoursefromfile(Course * &chead, string filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		return;
	}
	Course *cur = NULL;
	while (fin.good()) {
		if (chead == NULL) {
			chead = new Course;
			fin >> chead->No;
			getline(fin, chead->courseCode, ',');
			getline(fin, chead->academicYear, ',');
			fin >> chead->semester;
			getline(fin, chead->courseName, ',');
			getline(fin, chead->lecturerName,',');
			getline(fin, chead->startDate, ',');
			getline(fin, chead->endDate, ',');
			getline(fin, chead->dayOfWeek, ',');
			getline(fin, chead->startHour, ',');
			getline(fin, chead->endHour);
			chead->next = NULL;
			cur = chead;
		}
		else {
			cur->next = new Course;
			fin >> cur->No;
			cur = cur->next;
			getline(fin, cur->courseCode, ',');
			getline(fin, cur->academicYear, ',');
			fin >> cur->semester;
			getline(fin, cur->courseName, ',');
			getline(fin, cur->lecturerName, ',');
			getline(fin, cur->startDate, ',');
			getline(fin, cur->endDate, ',');
			getline(fin, cur->dayOfWeek, ',');
			getline(fin, cur->startHour, ',');
			getline(fin, cur->endHour);
			cur->next = NULL;
		}
	}
	fin.close();
}

void removestudent(Student * head, string name)
{
	Student* cur = head;
	if (cur->fullName == name)
	{
		head = head->next;
		delete cur;
		cur = NULL;
	}
	else
	{
		while (cur != NULL && cur->next != NULL && cur->next->fullName != name)
		{
			cur = cur->next;
		}
		if (cur == NULL)
			return;
		else
		{
			Student* cur2 = cur;
			cur = cur->next;
			if(cur==NULL)
				cur2->next = NULL;
			else cur2->next = cur->next;
			delete cur;
			cur = NULL;
		}
	}
}

//17. Remove a course
void removeCourse(Course *head, string courseToRemove) {  //use courseCode for courseToRemove
	Course *cur = head;
	while (cur->next->next != NULL) {
		if (cur->next->courseCode == courseToRemove) {
			cout << cur->next->courseCode;
			cur->next = cur->next->next;
		}
	}
	if (cur->next->next == NULL
		&& cur->next->courseCode == courseToRemove) {
		cur->next = NULL;
	}
}

void findstudent(Student * &cur, Student * head, string name)
{
	cur = head;
	if (head->fullName == name)
		return;
	else
	{
		while (cur != NULL && cur->fullName != name)
			cur = cur->next;
	}
}
