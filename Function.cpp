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
		cout << "					Do u want to create a new account? \n";
		cout << "					1.YES \n";
		cout << "					2.NO \n";
		cin >> t;
		/*switch (t)
		{
		case 1:
		{

			cout << "					Please input your fullname: ";
			getline(cin, name);
			while (cur->next)
				cur = cur->next;
			cur->next = new User;
			cur = cur->next;
			cur->fullName = name;

			generateid(name, Username);
			cur->userName = Username;
			int a = pass();
			int x = log(a) / log(10) + 1;
			for (int i = x; i > 0; i--)
			{
				cur->password[i] = a / pow(10, i - 1) + 48;
			}
			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;
			cout << "					Please set a new password: ";
			getline(cin, password);
			cout << "					Your username: " << cur->userName << endl;
			cout << "					Your password: " << cur->password << endl;
			break;
		}
		case 2:
		{
			cout << "					See you next time \n";
			return;
		}
		}*/
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
		return;
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
		acastaffMenu();
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
		cin >> password;
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
				cin >> password;
			}

		}
		if (check == true)
		{
			cout << " Pls enter your new password: \n";
			cin >> password;
			cur->password = password;
			cout << " Pls enter your new password again: \n";
			cin >> password;
			while (password != cur->password)
				cin >> password;
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

		else exit(0);
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

/*void generateid(string name, string Username)
{
	int i1 = 1, a;
	Username[0] = tolower(name[0]);
	for ( unsigned int i = 0; i < name.length; ++i)
	{
		if (name[i] == ' ')
			a = i;
	}

	for (unsigned int i = 0; i < (name.length); ++i)
	{
		if (name[i] == ' ')
		{
			Username[i1] = tolower(name[i + 1]);
			++i1;
		}
	}

	i1--;

	while (a < name.length)
	{
		Username[i1] = tolower(name[a + 1]);
		i1++; a++;
	}
}
*/
int pass()
{
	srand(time(NULL));
	int a = rand();
	return a;
}
void viewinfo()
{
	
}
//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
void acastaffMenu()
{
	system("cls");
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
		cout << "\n\n 3: Edit Student ";
		cout << "\n\n 4: Remove Student ";
		cout << "\n\n What do you want to do: ";
		cin >> newchoice;
		if (newchoice == 1)
		{
			string cl;
			cout << "\n\n What class you want to import? \n";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			getline(cin, cl);
			while (cl != "1" && cl != "2")
				getline(cin, cl);
			Student *head = NULL;
			if (cl == "1") cl = "17CTT1.csv";
			else cl = "17CTT2.csv";
			importstudentfromfile(head,cl);
		}
		else
			break;
		break;
	}
	case 2:
	{	system("cls");
		cout << "\n\n 1: Import A Class ";
		cout << "\n\n 2: Create New Class ";
		cout << "\n\n 3: View List Classes ";
		cout << "\n\n 4: View List of Student in Class ";
		break;
	}
	case 3:
	{	system("cls");
		cout << "\n\n 1: Import A Course ";
		cout << "\n\n 2: Add New Course ";
		cout << "\n\n 3: View List Courses ";
		cout << "\n\n 4: Edit Courses ";
		cout << "\n\n 5: Remove Courses ";
		break;
	}
	case 4:
	{	system("cls");
		cout << "\n\n 1: Import Courses' Schedules ";
		cout << "\n\n 2: Add New Courses' Schedule ";
		cout << "\n\n 3: View List Courses' Schedules ";
		cout << "\n\n 4: Edit Courses' Schedules ";
		cout << "\n\n 5: Remove Courses' Schedules ";
		break;
	}
	case 5:
	{	system("cls");
		cout << "\n\n 1: Search & View Attendance List ";
		cout << "\n\n 2: Export Attendance List";
		break;
	}
	case 6:
	{	system("cls");
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
void importstudentfromfile(Student *&head, string cl) {
	ifstream fin(cl);
	if (!fin.is_open()) {
		return;
	}
	Student *cur = NULL;

	while (fin.good()) {
		if (head == NULL) {
			head = new Student;
			getline(fin, head->no, ',');
			getline(fin, head->ID, ',');
			getline(fin, head->fullName, ',');
			getline(fin, head->email, ',');
			getline(fin, head->sclass, ' ');
			head->next = NULL;
			cur = head;
		}
		else {
			cur->next = new Student;
			cur = cur->next;
			getline(fin, cur->no, ',');
			getline(fin, cur->ID, ',');
			getline(fin, cur->fullName, ',');
			getline(fin, cur->email, ',');
			getline(fin, cur->sclass);
			cur->next = NULL;
		}
	}
	fin.close();
}
