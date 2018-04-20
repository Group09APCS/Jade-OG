#include "Function.h"
//SAVE USER
void save(string pathToSaveFile, User *&head) {
	ofstream fout(pathToSaveFile);
	if (!fout.is_open()) {
		return;
	}

	User *cur = head;
	while (cur) {
		fout << cur->userName << "," << cur->fullName << "," << cur->ID << "," << cur->email << "," << cur->mobilePhone
			<< "," << cur->type << "," << cur->password << "," << cur->className << endl;
		cur = cur->next;
	}
	fout.close();
}
void changepass(User *&head, User *&cur)
{
	system("cls");
	cout << " Pls enter your old password: \n";
	cin.ignore();
	string password;
	bool check = false;
	getline(cin, password);
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
		save("user.csv", head);

	}

	else {
		Login(head);
	}
}


//IMPORT USER
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
//LOGIN
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
	for (int i = 0; i <= 3; i++)
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
			cout << "					Mismatched! " << 3 - i << " time(s) remain: ";

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
	for (int i = 0; i <= 3; i++)
	{
		getline(cin, password);
		if (password == cur->password)
		{
			check = true;
			break;
		}
		else cout << "					" << 3 - i << "time(s) to try: ";
	}
	if (check == false)
		exit(0);
	showMenu(head, cur);
}
//SHOW MENU
void showMenu(User *&head, User *&cur)
{
	bool check = false;
	int choice;
	string password;
	system("cls");
	cout << "\n\n______________________________________________________WELCOME_________________________________________________________" << endl;

	cout << endl
		<< "\n\n 1 - Show the menu."
		<< "\n\n 2 - View info."
		<< "\n\n 3 - Change password."
		<< "\n\n 4 - Exit."
		<< "\n\n What do you want to do: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{	if (cur->type == "1")
		acastaffMenu(head, cur);
	if (cur->type == "0")
		studentMenu(head, cur);
	if (cur->type == "2")
		lecturerMenu(head,cur);
	break;
	}
	case 2:
	{
		system("cls");
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
		changepass(head, cur);
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		save("user.csv", head);
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
		break;

	}
	case 4:
	{
		system("cls");
		cout << "SEEYA!.\n";
		return;
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}
	}
}
//STUDENT MENU
void studentMenu(User *&head, User *&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________STUDENT DATABASE_________________________";
	cout << "\n\n 1: Check - in ";
	cout << "\n\n 2: View Check - in Result ";
	cout << "\n\n 3: View score for a course ";
	cout << "\n\n 4: Schedule ";
	cout << "\n\n 5: View your info ";
	cout << "\n\n 6: Change password ";
	cout << "\n\n 7: Return ";
	cout << "\n\n 8: Log out ";
	cout << "\n\n 9: Exit ";
	cout << "\n\n What do you want to do: ";
	cin.ignore();
	cin >> choice;
	int newchoice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		Course * chead = NULL;
		importcoursefromfile(chead, "course.csv");
		checkin(chead, cur);
		break;
	}
	case 2:
	{
		Presence * phead = NULL;
		string *presenceLabel = new string[5];
		loadPresence("presence.csv", phead, presenceLabel);
		viewcheckin(phead, cur);
		break;
	}
	case 3:
	{
		system("cls");
		Score * schead = NULL;
		ImportScore(schead, "score.csv");
		cout << "Which course do you want to view its score? (Enter the courseCode):";
		string str;
		cin.ignore();
		getline(cin, str);
		string id;
		id = cur->ID;
		viewyourScore(str, schead, id);
		cout << "Done!";
		break;
	}
	case 4:
	{
		Schedule * schead = NULL;
		importschedulefromfile(schead, "course.csv");
		viewcourseschedule(schead, "course.csv");
		break;
	}
	case 5:
	{
		system("cls");
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
		break;
	}
	case 6:
	{
		changepass(head, cur);
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		save("user.csv", head);
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

		break;
	}
	case 7:
	{
		showMenu(head, cur);
		break;
	}
	case 8:
	{
		cin.ignore();
		Login(head);
		break;
	}
	case 9:
	{
		exit(0);
	}
	default:
	{
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}

	}
	system("pause");
	studentMenu(head, cur);
}
//LECTURER MENU
void lecturerMenu(User *&head, User *&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________LECTURER DATABASE_________________________";
	cout << "\n\n 1: Scoreboard ";
	cout << "\n\n 2: Edit Grade ";
	cout << "\n\n 3: Your info ";
	cout << "\n\n 4: Change password ";
	cout << "\n\n 5: Return ";
	cout << "\n\n 6: Log out ";
	cout << "\n\n 7: Exit ";
	cout << "\n\n What do you want to do: ";
	cin.ignore();
	cin >> choice;
	int newchoice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		string crse;
		cout << "Which course do you want?: \n";
		cin >> crse;
		string coursename = "score_";
		coursename += crse;
		coursename += ".csv";
		Score *head = NULL;
		ImportScore(head, coursename);
		viewscore(head);
		break;
	}
	case 2:
	{
		system("cls");
		string crse;
		cout << "Which course do you want?: ";
		cin >> crse;
		string coursename = "score_";
		coursename += crse;
		coursename += ".csv";
		Score *head = NULL;
		ImportScore(head, coursename);
		EditGrade(head);
		break;
	}
	case 3:
	{
		system("cls");
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
		break;
	}
	case 4:
	{
		changepass(head, cur);
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		save("user.csv", head);
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

		break;
	}
	case 5:
	{
		showMenu(head, cur);
		break;
	}
	case 6:
	{
		cin.ignore();
		Login(head);
	}
	case 7:
	{
		exit(0);
		break;
	}
	default:
	{
		cout << "Nothing here";
		break;
	}

	}
	system("pause");
	lecturerMenu(head, cur);
}
//GENERATEID =
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
//PASS (NOT YET COMPLETED)
int pass()
{
	srand(time(NULL));
	int a = rand();
	return a;
}
//THIS AREA IS USED FOR ACADEMIC STAFF, AUTHORIZED PERSONNEL ONLY!!!
//ACADEMIC STAFF MENU
void acastaffMenu(User *&head, User*&cur)
{
	system("cls");
	int choice;
	cout << "\n\n  _________________________ACADEMIC STAFF DATABASE_________________________";
	cout << "\n\n 1: Student Management ";
	cout << "\n\n 2: Courses ";
	cout << "\n\n 3: Courses Schedule ";
	cout << "\n\n 4: Search for attendance list ";
	cout << "\n\n 5: Scoreboard ";
	cout << "\n\n 6: View your info ";
	cout << "\n\n 7: Change password ";
	cout << "\n\n 8: Return ";
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
		cout << "\n\n 3: Edit An Existing Student ";
		cout << "\n\n 4: Remove A Student ";
		cout << "\n\n 5: Change Students From Class A to Class B ";
		cout << "\n\n 6: Add A New Empty Class ";
		cout << "\n\n 7: View list of classes ";
		cout << "\n\n 8: View list of student in a class ";
		cout << "\n\n What do you want to do: ";
		Student * head1 = NULL;
		Student *head2 = NULL;
		importstudentfromfile(head1, "17CTT1.csv");
		importstudentfromfile(head2, "17CTT2.csv");
		cin >> newchoice;
		switch (newchoice) {
			//6. Import students of a class from a csv file
		case 1:
		{
			system("cls");
			string cl;
			cout << "\n\n Which class you want to import? \n";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			getline(cin, cl);
			while (cl != "1" && cl != "2")
				getline(cin, cl);
			cout << "Successful! Return to menu... \n";
			showMenu(head, cur);
		}
		//7. Add a new student to a class
		case 2:
		{
			system("cls");
			cout << "\n\n In which class do you want to add new student? ";
			cout << "\n\n 1: 17CTT1 ";
			cout << "\n\n 2: 17CTT2 ";
			int cls;
			cin >> cls;
			string css;
			if (cls == 1)
			{
				css = "17CTT1";
				addnewstudent(head1, css);
				printout(head1, "17CTT1.csv");
			}
			if (cls == 2)
			{
				css = "17CTT2";
				addnewstudent(head2, css);
				printout(head2, "17CTT1.csv");
			}
			acastaffMenu(head, cur);
			break;
		}
		//8. Edit an existing student
		case 3:
		{
			system("cls");
			int Choice2;
			Student* cur1 = NULL;
			cout << "\n\n In which class do you want to edit a student?" << endl;
			cout << "\n\n 1: 17CTT1\n";
			cout << "\n\n 2: 17CTT2\n";
			cin >> Choice2;
			if (Choice2 == 1)
			{
				string scs = "17CTT1.csv";
				string unscs = "17CTT2.csv";
				editastudent(head1, head2, scs, unscs);
			}
			if (Choice2 == 2)
			{
				string scs = "17CTT2.csv";
				string unscs = "17CTT1.csv";
				editastudent(head2, head1, scs, unscs);
			}
			acastaffMenu(head, cur);
		}
		//9. Remove a student
		case 4:
		{
			system("cls");
			int Choicex;
			cout << "\n\n In which class do you want to remove a student?" << endl;
			cout << "\n\n 1: 17CTT1\n";
			cout << "\n\n 2: 17CTT2\n";
			cin >> Choicex;
			string name;
			cout << "\n\n Which student you want to remove? ";
			cin.ignore();
			getline(cin, name, '\n');
			switch (Choicex) {
			case 1:
			{
				removestudent(head1, name);
				printout(head1, "17CTT1.csv");
				cout << "Done!" << endl;
				break;
			}
			case 2:
			{
				removestudent(head2, name);
				printout(head2, "17CTT2.csv");
				cout << "Done!" << endl;
				break;
			}
			default:
			{
				cout << "Error!\n";
				break;
			}
			}
			acastaffMenu(head, cur);
		}
		//10. Change Class (Binh sua lai nha)
		case 5:
		{
			changeclass(head1, head2);
			break;
		}
		//11. Add a new empty class
		case 6:
		{
			system("cls");
			newclass();
			acastaffMenu(head, cur);
			break;
		}
		//12. View list of classes (Phuong sua lai nha)
		case 7:
		{
			listOfClass(head);
			system("pause");
			acastaffMenu(head, cur);
			break;
		}
		//13. View list of students in a class
		case 8:
		{
			system("cls");
			cout << " Pls enter the name of the class: ";
			string nme;
			cin.ignore();
			getline(cin, nme);
			listOfStudent(head, nme);
		}
		break;
		}
	}
	//***************************   COURSE   ***************************
	case 2:
	{
		system("cls");
		cout << "\n\n 1: Import A Course ";
		cout << "\n\n 2: Add New Course ";
		cout << "\n\n 3: View List Courses ";
		cout << "\n\n 4: Edit Courses ";
		cout << "\n\n 5: Remove Courses ";
		cout << "\n\n What do you want to do: ";
		Course * chead = NULL;
		importcoursefromfile(chead, "course.csv");
		cin >> choice;
		switch (choice)
		{
			//14. Import courses from a csv file
		case 1:
		{
			system("cls");
			Course * chead = NULL;
			importcoursefromfile(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//15. Add a new course
		case 2:
		{
			system("cls");
			addanewcourse(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//16. Edit an existing course
		case 4:
		{
			system("cls");
			editcourse(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//17. Remove a course
		case 5:
		{
			system("cls");
			cout << "Pls enter the course of code you want to remove: ";
			string c;
			cin.ignore();
			getline(cin, c);
			removeCourse(chead, c);
			printcout(chead, "course.csv");
			acastaffMenu(head, cur);
			break;
		}
		//18. View list of courses
		case 3:
		{
			system("cls");
			viewcourse(chead, "course.csv");
			system("pause");
			acastaffMenu(head, cur);
			break;
		}
		}
	}
	//*************************** SCHEDULE *****************************
	case 3:
	{	system("cls");
	cout << "\n\n 1: Import Courses' Schedules ";
	cout << "\n\n 2: Add New Courses' Schedule ";
	cout << "\n\n 3: View List Courses' Schedules ";
	cout << "\n\n 4: Edit Courses' Schedules ";
	cout << "\n\n 5: Remove Courses' Schedules ";
	cout << "\n\n What do you want to do: ";
	Schedule * shead = NULL;
	importschedulefromfile(shead, "course.csv");
	int richchoi;
	cin >> richchoi;
	switch (richchoi)
	{
	case 1:
	{
		shead = NULL;
		importschedulefromfile(shead, "course.csv");
		cout << "Done!";
		break;
	}
	case 2:
	{
		addnewcourseschedule(shead, "course.csv");
		cout << "Done!";
		break;
	}
	case 3:
	{
		viewcourseschedule(shead, "course.csv");
		cout << "Done!";
		break;
	}
	case 4:
	{
		editcourseschedule(shead, "course.csv");
		cout << "Done!";
		break;
	}
	case 5:
	{
		removeacourseschedule(shead, "course.csv");
		cout << "Done!";
		break;
	}
	}
	system("pause");
	acastaffMenu(head, cur);
	}
	//**************************** PRESENCE ****************************
	case 4:
	{
		system("cls");
		cout << "\n\n 1: Search and view attendance list of a course ";
		cout << "\n\n 2: Export attendance list to a csv file ";
		cout << "\n\n What do you want to do: ";
		int nchoice;
		Presence *presenceHead = NULL;
		string *presenceLabel = new string[5];
		cin >> nchoice;
		loadPresence("presence.csv", presenceHead, presenceLabel);
		switch (nchoice)
		{
		case 1:
		{
			viewAttendance("Nope", presenceHead);
			cout << "Done!";
			break;
		}
		case 2:
		{
			exportPresence("exportAttendance.csv", presenceHead);
			cout << "Done!";
			break;
		}
		default:
		{
			cout << " Invalid Choice!";
			break;
		}
		}
		system("pause");
		acastaffMenu(head, cur);
	}
	//**************************** SCORE *******************************
	case 5:
	{
		system("cls");
		cout << "\n\n 1: Search and view scoreboard of a course ";
		cout << "\n\n 2: Export a scoreboard to a csv file ";
		cout << "\n\n What do you want to do: ";
		int rchoice;
		cin >> rchoice;
		Score * schead = NULL;
		ImportScore(schead, "score.csv");
		switch (rchoice)
		{
		case 1:
		{
			cout << "Which course do you want to view its score? (Enter the courseCode):";
			string str;
			cin.ignore();
			getline(cin, str);
			viewScore(str, schead);
			cout << "Done!";
			break;
		}
		case 2:
		{
			cout << "Which course do you want to export its score? (Enter the courseCode):";
			string str;
			cin.ignore();
			getline(cin, str);
			exportScore("score1.csv", str, schead);
			cout << "Done!";
			break;
		}
		default:
		{
			cout << "Invalid Choice";
			break;
		}
		}
		system("pause");
		acastaffMenu(head, cur);
	}
	case 6:
	{
		system("cls");
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
		break;
	}
	case 7:
	{
		changepass(head, cur);
		cout << " 1 - Return to the menu.\n";
		cout << " 2 - Exit. \n";
		save("user.csv", head);
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

		break;
	}
	case 8:
	{
		showMenu(head, cur);
		break;
	}
	case 9:
	{
		cin.ignore();
		Login(head);
		break;
	}
	case 10:
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
//PRINT OUT STUDENT
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
	fout.close();
}
//FIND STUDENT
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
//6
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
//7
void addnewstudent(Student *&head, string scs)
{
	Student * cu = head;
	while (cu->next != NULL)
		cu = cu->next;
	cu->next = new Student;
	cu = cu->next;
	cout << "Pls enter student ID: ";
	string id;
	cin.ignore();
	getline(cin, id);
	cu->ID = id;
	cout << "Pls enter student Full name";
	string fullname;
	getline(cin, fullname);
	cu->fullName = fullname;
	cout << "Pls enter student email";
	string smail;
	getline(cin, smail);
	cu->email = smail;
	cu->sclass = scs;
	cu->next = NULL;
}
//8
void editastudent(Student *&head1, Student *&head2, string scs, string unscs)
{

	Student* cur1 = NULL;
	string name;
	system("cls");
	cout << "Which student you want edit?\n";
	cin.ignore();
	getline(cin, name);
	cout << "\n What do you want to edit?\n";
	cout << "1: Student ID\ n";
	cout << "2: Student Name \n";
	cout << "3: Email \n";
	cout << "4: Class \n";
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
		printout(head1, scs);
		break;
	}
	case 2:
	{
		cout << "Please enter the new student name: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur1->fullName = str;
		printout(head1, scs);
		cout << "Done!" << endl;
		break;
	}
	case 3:
	{
		cout << "Please enter the new student email: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur1->email = str;
		printout(head1, scs);
		cout << "Done!" << endl;
		break;
	}
	case 4:
	{
		cin.ignore();
		getline(cin, str, '\n');
		changeclass(head1, head2);
		printout(head1, scs);
		printout(head2, unscs);
		cout << "Done!" << endl;
		break;
	}
	default:
	{
		cout << "Error!\n";
		break;
	}
	}
}
//9
void removestudent(Student *&head, string name)
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
			if (cur == NULL)
				cur2->next = NULL;
			else cur2->next = cur->next;
			delete cur;
			cur = NULL;
		}
	}
}
//10
void changeclass(Student  *&head1, Student *&head2)
{
	string studentID;
	cout << "Please input ID of the student that you want to change class from 17CTT1 to 17CTT2:";
	cin.ignore();
	getline(std::cin, studentID);
	Student*cur = head1;
	if (studentID.compare(cur->ID) == 0)
	{
		Student *temp = cur;
		head1 = cur->next;
		delete temp;
	}
	else
	{
		while (studentID.compare(cur->next->ID) != 0 && cur->next != NULL)
		{
			cur = cur->next;
		}
		if (cur->next == NULL&&studentID.compare(cur->next->ID) != 0)
		{
			cout << "That student is not in this class";
		}
		else
		{
			{

				Student *temp = new Student;
				temp = cur->next;
				cur->next = cur->next->next;
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
					cur2->sclass = "17CTT2";
					cur2->next = NULL;
					cout << "Added student in the end of the class";
				}
				else
				{
					Student *temp2 = new Student;
					temp2->ID = temp->ID;
					temp2->fullName = temp->fullName;
					temp2->email = temp->email;
					temp2->sclass = "17CTT2";
					temp2->next = cur2->next;
					cur2->next = temp2;
					cur2 = cur2->next;
					cout << "Done!";
				}
				delete temp;
			}

		}
	}
	printout(head1, "1.csv");
	printout(head2, "2.csv");
	system("pause");
}
//11
void newclass()
{
	string classname;
	ofstream fout;
	cout << "Please input the name of the new class:";
	cin.ignore();
	getline(cin, classname);
	classname.append(".csv");
	fout.open(classname);
	fout.close();
	cout << "Done!";
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
		if (!strcmp(classes[i].c_str(), curClass.c_str())) {
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
		if (!strcmp(cur->className.c_str(), curClass.c_str())) {
			cout << cur->fullName << endl;
			cur = cur->next;
		}
		if (cur->next == NULL) {
			cout << cur->fullName << endl;
		}
	}
}
//PRINT OUT COURSE
void printcout(Course *&chead, const string file)
{
	ofstream fout;
	fout.open(file);
	Course * cur = chead;
	while (cur)
	{
		fout << cur->courseCode << "," << cur->academicYear << ","
			<< cur->semester << "," << cur->courseName << "," << cur->lecturerName << ","
			<< cur->startDate << "," << cur->endDate << "," << cur->dayOfWeek << ","
			<< cur->startHour << "," << cur->endHour << endl;
		cur = cur->next;
	}
	fout.close();
}
//FIND COURSE
void findcourse(Course *&cur, Course *&chead, string name)
{
	cur = chead;
	if (chead->courseName == name)
		return;
	else
	{
		while (cur != NULL && cur->courseName != name)
			cur = cur->next;
	}
}
//14. Import courses from a csv file
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
			getline(fin, chead->courseCode, ',');
			getline(fin, chead->academicYear, ',');
			getline(fin, chead->semester, ',');
			getline(fin, chead->courseName, ',');
			getline(fin, chead->lecturerName, ',');
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
			cur = cur->next;
			getline(fin, cur->courseCode, ',');
			getline(fin, cur->academicYear, ',');
			getline(fin, cur->semester, ',');
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
//15. Add a new course
void addanewcourse(Course *&chead, string filename)
{
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
	getline(cin, str, '\n');
	cur1->academicYear = str;
	cout << "Pls input courseSemester: ";
	getline(cin, str, '\n');
	cur1->semester = str;
	cout << "Pls input courseName: ";
	getline(cin, str, '\n');
	cur1->courseName = str;
	cout << "Pls input lecturerName: ";
	getline(cin, str, '\n');
	cur1->lecturerName = str;
	cout << "Pls input startDate: ";
	getline(cin, str, '\n');
	cur1->startDate = str;
	cout << "Pls input endDate: ";
	getline(cin, str, '\n');
	cur1->endDate = str;
	cout << "Pls input dayOfWeek: ";
	getline(cin, str, '\n');
	cur1->dayOfWeek = str;
	cout << "Pls input startHour: ";
	getline(cin, str, '\n');
	cur1->startHour = str;
	cout << "Pls input endHour: ";
	getline(cin, str, '\n');
	cur1->endHour = str;
	cur1->next = NULL;
	printcout(chead, "course.csv");
}
//16. Edit an existing course
void editcourse(Course *&chead, string filename)
{
	Course* cur = NULL;
	string name;
	system("cls");
	cout << "Which course do you want edit?\n";
	cin.ignore();
	getline(cin, name);
	cout << "\n What do you want to edit?\n";
	cout << "1: Course Code \n";
	cout << "2: Academic Year \n";
	cout << "3: Semester \n";
	cout << "4: Course Name \n";
	cout << "5: Lecturer Name \n";
	cout << "6: Start Date \n";
	cout << "7: End Date \n";
	cout << "8: Date Of Week \n";
	cout << "9: Start Hour \n";
	cout << "10: End Hour \n";
	int Choice1;
	cin >> Choice1;
	string str;
	findcourse(cur, chead, name);
	switch (Choice1)
	{
	case 1:
	{
		cout << "Please enter new Course Code: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->courseCode = str;
		cout << "Done!" << endl;
		printcout(chead, "course.csv");
		break;
	}
	case 2:
	{
		cout << "Please enter the new Academic Year: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->academicYear = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 3:
	{
		cout << "Please enter the new Semester: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->semester = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 4:
	{
		cout << "Please enter the new Course Name: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->courseName = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 5:
	{
		cout << "Please enter the new :ecturer Name: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->lecturerName = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 6:
	{
		cout << "Please enter the new Start Date: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->startDate = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 7:
	{
		cout << "Please enter the new End Date: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->endDate = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 8:
	{
		cout << "Please enter the new Day of Week: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->dayOfWeek = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 9:
	{
		cout << "Please enter the new Start Hour: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->startHour = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	case 10:
	{
		cout << "Please enter the new End Hour: ";
		cin.ignore();
		getline(cin, str, '\n');
		cur->endHour = str;
		printcout(chead, "course.csv");
		cout << "Done!" << endl;
		break;
	}
	default:
	{
		cout << "Error!\n";
		break;
	}
	}
}
//17. Remove a course
void removeCourse(Course *&head, string courseToRemove) {  //use courseCode for courseToRemove
	Course *cur = head;
	while (cur->next->next != NULL) {
		if (cur->next->courseCode == courseToRemove) {
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
	if (cur->next->next == NULL
		&& cur->next->courseCode == courseToRemove) {
		cur->next = NULL;
	}
}
//18. View list of courses
void viewcourse(Course*&chead, string f)
{
	int i = 0;
	Course * cur = chead;
	while (cur)
	{
		cout << "Course[" << i << "]: " << endl;
		cout << "Course Code: ";
		cout << cur->courseCode << endl;
		cout << "Course Name: ";
		cout << cur->courseName << endl;
		cout << "Lecturer Name: ";
		cout << cur->lecturerName << endl;
		cur = cur->next;
		i++;
	}
}

//19. import courses' schedule from a csv file
void importschedulefromfile(Schedule *& shead, string filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		return;
	}
	string str;
	Schedule *cur = NULL;
	while (fin.good()) {
		if (shead == NULL) {
			shead = new Schedule;
			getline(fin, shead->courseCode, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
			getline(fin, shead->startDate, ',');
			getline(fin, shead->endDate, ',');
			getline(fin, shead->dayOfWeek, ',');
			getline(fin, shead->startHour, ',');
			getline(fin, shead->endHour);
			shead->next = NULL;
			cur = shead;
		}
		else {
			cur->next = new Schedule;
			cur = cur->next;
			getline(fin, cur->courseCode, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
			getline(fin, str, ',');
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

//20. Add a course schedule
void addnewcourseschedule(Schedule * shead, string filename)
{
	Schedule* cur1 = shead;
	string str;
	while (cur1->next != NULL)
	{
		cur1 = cur1->next;
	}
	cur1->next = new Schedule;
	cur1 = cur1->next;
	cout << "Pls input Course Code: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->courseCode = str;
	cout << "Pls input Start Date: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->startDate = str;
	cout << "Pls input End Date: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->endDate = str;
	cout << "Pls input Day of week: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->dayOfWeek = str;
	cout << "Pls input Start Hour: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->startHour = str;
	cout << "Pls input End Hour: ";
	cin.ignore();
	getline(cin, str, '\n');
	cur1->endHour = str;
	cur1->next = NULL;
}

//21. Edit a course schedule
void editcourseschedule(Schedule * shead, string filename)
{
	Schedule* cur1 = NULL;
	string name, str;
	cout << "Please input the Course Code you want to edit: ";
	getline(cin, name, '\n');
	cin.ignore(1000, '\n');
	findcourseschedule(shead, filename, name, cur1);
	cur1 = cur1->next;
	cout << "What do you want to edit?\n";
	cout << "1: Course code\n";
	cout << "2: Start date\n";
	cout << "3: End date\n";
	cout << "4: Day of week\n";
	cout << "5: Start hour\n";
	cout << "6: End hour\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Please inpute new course code: ";
		getline(cin, str, '\n');
		cin.ignore(1000, '\n');
		cur1->courseCode = str;
		break;
	}
	case 2:
	{
		cout << "Please input new start date: ";
		getline(cin, str, '\n');
		cin.ignore(1000, '\n');
		cur1->startDate = str;
		break;
	}
	case 3:
	{
		cout << "Please input new end date: ";
		getline(cin, str, '\n');
		cur1->endDate = str;
		break;
	}
	case 4:
	{
		cout << "Please input new day of week: ";
		getline(cin, str, '\n');
		cin.ignore(1000, '\n');
		cur1->dayOfWeek = str;
		break;
	}
	case 5:
	{
		cout << "Please input new start hour: ";
		getline(cin, str, '\n');
		cin.ignore(1000, '\n');
		cur1->startHour = str;
		break;
	}
	case 6:
	{
		cout << "Please input new end hour: ";
		getline(cin, str, '\n');
		cin.ignore(1000, '\n');
		cur1->endHour = str;
		break;
	}
	}
}

void findcourseschedule(Schedule * shead, string filename, string name, Schedule* &cur)
{
	cur = shead;
	if (cur->courseCode == name)
		return;
	else
	{
		while (cur->next != NULL && cur->next->courseCode != name)
		{
			cur = cur->next;
		}
	}
}

//22. Remove a course schedule
void removeacourseschedule(Schedule * shead, string filename)
{
	Schedule* cur1 = NULL;
	string name, str;
	cout << "Please input the Course Code you want to remove: ";
	getline(cin, name, '\n');
	cin.ignore(1000, '\n');
	findcourseschedule(shead, filename, name, cur1);
	Schedule* cur2 = cur1;
	cur2->next = cur1->next;
	delete cur1;
	cur1 = cur2;
}
//23. View Schedule
void viewcourseschedule(Schedule * &head, string filename)
{
	Schedule *cur = head;
	cout << "What day is today? \n (Mon for Monday,...)";
	string  day;
	getline(cin, day);
	while (day != "Mon" && day != "Tue" && day != "Wed" && day != "Thu" && day != "Fri" && day != "Sat" && day != "Sun")
	{
		cout << "Again \n";
		getline(cin, day);
	}
	while (cur != NULL)
	{
		if (cur->dayOfWeek == day)
		{
			cout << "Course Code:" << cur->courseCode << endl;
			cout << "Day:" << cur->dayOfWeek << endl;
			cout << "Start Hour:" << cur->startHour << endl;
			cout << "End Hour:" << cur->endHour << endl;
		}
		cur = cur->next;
	}
}
//******************************ATTENDANCE LIST*******************************
//IMPORT
//24. Search and view attendance list of a course
void loadPresence(string pathToPresenceFile, Presence *&presenceHead, string *presenceLabel) {
	ifstream fin;
	fin.open(pathToPresenceFile);
	if (!fin.is_open()) {
		return;
	}
	int x1 = 0, y1 = 0, x2 = 1, y2 = 1;  //x1, y1 for frame and x2, y2 for check-in number
	Presence *cur = NULL;
	char comma; //to skip the comma when read checkIn number
	while (fin.good()) {
		for (int i = 0; i < 4; ++i) {
			getline(fin, *(presenceLabel + i), ',');
			if (i == 3)
				getline(fin, *(presenceLabel + i), '\n');
		}
		string temp;
		if (presenceHead == NULL) {
			presenceHead = new Presence;
			getline(fin, presenceHead->courseCode, ',');
			getline(fin, presenceHead->academicYear, ',');
			fin >> presenceHead->semester;
			getline(fin, temp, '\n');
			for (int y1 = 0; y1 < 11; ++y1) {
				getline(fin, presenceHead->frame[x1][y1], ',');
				if (y1 == 10) {
					getline(fin, presenceHead->frame[x1][y1], '\n');
				}
			}
			cout << endl;

			for (int x1 = 1; x1 < 105; ++x1) {
				getline(fin, presenceHead->frame[x1][y1], ',');

				for (int y2 = 0; y2 < 10; ++y2) {
					fin >> presenceHead->checkIn[x2][y2];
					fin >> comma; //just to skip comma
				}
				getline(fin, temp, '\n');
			}
			cur = presenceHead;
			cur->next = NULL;
		}
	}
	fin.close();
}

void viewAttendance(string courseCode, Presence *presenceHead) { //ask user for courseCode they want to to view attendance list                                                             
	cout << "This is the Attendance List for the course: "
		<< courseCode << endl
		<< "Academic year: " << presenceHead->academicYear << endl
		<< "Semester: " << presenceHead->semester << endl;

	int x1 = 0, y1 = 0, x2 = 1, y2 = 1;  //x1, y1 for frame and x2, y2 for check-in number
	for (int y1 = 0; y1 < 11; ++y1) {
		cout << setw(10) << presenceHead->frame[x1][y1] << " ";
		/*if (y1 == 10) {
		cout << presenceHead->frame[x1][y1] << " ";
		}*/
	}
	cout << endl;
	for (int x1 = 1; x1 < 53; ++x1) {
		cout << setw(10) << presenceHead->frame[x1][y1] << " ";
		for (int y2 = 0; y2 < 10; ++y2) {
			cout << setw(10) << presenceHead->checkIn[x2][y2] << " ";
		}
		cout << endl;
	}
}

//25. Export Attendance list:

void exportPresence(string exportFileName, Presence *presenceHead) {
	ofstream fout;
	fout.open(exportFileName);
	if (!fout.is_open())
		return;
	fout << "This is the Attendance List for the course: "
		<< presenceHead->courseCode << endl
		<< "Academic year: " << presenceHead->academicYear << endl
		<< "Semester: " << presenceHead->semester << endl;

	int x1 = 0, y1 = 0, x2 = 1, y2 = 1;  //x1, y1 for frame and x2, y2 for check-in number
	for (int y1 = 0; y1 < 11; ++y1) {
		fout << setw(10) << presenceHead->frame[x1][y1] << " ";
		/*if (y1 == 10) {
		cout << presenceHead->frame[x1][y1] << " ";
		}*/
	}
	fout << endl;
	for (int x1 = 1; x1 < 53; ++x1) {
		fout << setw(10) << presenceHead->frame[x1][y1] << " ";
		for (int y2 = 0; y2 < 10; ++y2) {
			fout << setw(10) << presenceHead->checkIn[x2][y2] << " ";
		}
		fout << endl;
	}
	fout.close();
}

//26. Search and view scoreboard of a course
void viewScore(string courseCode, Score *scoreHead) { //ask user to input courseCode they want to view score
	Score *cur = scoreHead;
	cout << "Scoreboard of " << courseCode << " course, " << "semester " << cur->semester
		<< ", academic year: " << cur->academicYear << endl;
	cout << setw(10) << "ID" << setw(20) << "Midterm Score" << setw(20) << "Lab Score" << endl;
	while (cur->next != NULL) {
		if (!strcmp(cur->courseCode.c_str(), courseCode.c_str())) {
			cout << setw(10) << cur->id << setw(20) << cur->midtermScore << setw(20) << cur->labScore << endl;
		}
		cur = cur->next;
	}
	if (cur->next == NULL && (!strcmp(cur->courseCode.c_str(), courseCode.c_str()))) {
		cout << setw(10) << cur->id << setw(20) << cur->midtermScore << setw(20) << cur->labScore << endl;
	}
}

//27. Export a scoreboard to a csv file
void exportScore(const char exportFileName[], string courseCode, Score *scoreHead) { //ask user to input courseCode whose score they want to export
	ofstream fout;
	fout.open(exportFileName);
	if (!fout.is_open())
		return;
	Score *cur = scoreHead;
	fout << "Scoreboard of " << courseCode << " course, " << "semester " << cur->semester
		<< ", academic year: " << cur->academicYear << endl;
	fout << setw(10) << "ID" << setw(10) << "Midterm Score" << setw(10) << "Lab Score" << endl;
	while (cur->next != NULL) {
		if (!strcmp(cur->courseCode.c_str(), courseCode.c_str())) {
			fout << setw(10) << cur->id << setw(10) << cur->midtermScore << setw(10) << cur->labScore << endl;
		}
		cur = cur->next;
	}
	if (cur->next == NULL && (!strcmp(cur->courseCode.c_str(), courseCode.c_str()))) {
		fout << setw(10) << cur->id << setw(10) << cur->midtermScore << setw(10) << cur->labScore << endl;
	}
	fout.close();
}

//28Import score 
void ImportScore(Score *&head, string sc)
{
	ifstream fin(sc);
	if (!fin.is_open()) {
		return;
	}
	string notuse, trash;
	string temp1, temp2;
	int temp3;
	Score *cur = NULL;
	getline(fin, notuse);
	getline(fin, temp1, ',');
	getline(fin, temp2, ',');
	fin >> temp3;
	while (fin.good())
	{
		if (head == NULL) {
			head = new Score;
			head->courseCode = temp1;
			head->academicYear = temp2;
			head->semester = temp3;
			getline(fin, notuse);
			getline(fin, notuse);
			getline(fin, head->id, ',');
			fin >> head->midtermScore;
			fin.ignore(10, ',');
			fin >> head->labScore;
			fin.ignore(10, '\n');
			head->next = NULL;
			cur = head;
		}
		else
		{
			cur->next = new Score;
			cur = cur->next;
			cur->courseCode = temp1;
			cur->academicYear = temp2;
			cur->semester = temp3;
			getline(fin, cur->id, ',');
			fin >> cur->midtermScore;
			fin.ignore(10, ',');
			fin >> cur->labScore;
			getline(fin, trash);
			cur->next = NULL;
		}
	}
	fin.close();
}
//29
void EditGrade(Score *&head)
{
	string temp;
	cout << "Which student do you want to edit his/her grade?(input student ID)" << endl;
	getline(cin, temp);
	Score *cur;
	int grade;
	cur = head;
	while (temp != cur->id&&cur != NULL)
	{
		cur = cur->next;
	}
	if (cur == NULL)
		cout << "That student ID is not exist in system" << endl;
	else
	{
		int choice;
		cout << "Which grade do you want to edit?" << endl;
		cout << "1.midterm score\n";
		cout << "2.lap score\n";
		cout << "your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string exit;
			do {
				cout << "Please enter the new grade: ";
				cin >> grade;
				cur->midtermScore = grade;
				cout << "Midterm score of " << cur->id << " is " << cur->midtermScore << endl;
				cout << "Is that correct? yes/no";
				getline(cin, exit);
			} while (exit != "yes"&&exit != "YES"&&exit != "Yes");
			break;
		}
		case 2:
		{
			string exit;
			do {
				cout << "Please enter the new grade: ";
				cin >> grade;
				cur->labScore = grade;
				cout << "Lap score of " << cur->id << " is " << cur->labScore << endl;
				cout << "Is that correct? yes/no";
				getline(cin, exit);
			} while (exit != "yes"&&exit != "YES"&&exit != "Yes");
			break;
		}
		default:
		{
			cout << "You enter something but nothing happen.\n";
			cout << "You feel something wrong with this program\n";
			cout << "Program's turn\n";
			cout << "Program uses <<SELFDESTRUCT>>\n";
			cout << "You lost all your data\n";
			cout << "Game over";
			break;
		}

		}
	}
}
//30
void viewscore(Score *head)
{
	Score *cur = head;
	while (cur != NULL)
	{
		cout << "ID: " << cur->id << endl;
		cout << "Course code: " << cur->courseCode << endl;
		cout << "Year: " << cur->academicYear << endl;
		cout << "Semester: " << cur->semester << endl;
		cout << "Midterm core: " << cur->midtermScore << endl;
		cout << "Lab Score: " << cur->labScore << endl;
		cur = cur->next;
	}
}
//31
void checkin(Course*chead, User *Uhead)
{
	Course *cur = chead;
	string Ccode;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int day = ltm->tm_wday;
	string wday;

	if (day == 0)
		wday = "Sun";
	else if (day == 1)
		wday = "Mon";
	else if (day == 2)
		wday = "Tue";
	else if (day == 3)
		wday = "Wed";
	else if (day == 4)
		wday = "Thu";
	else if (day == 5)
		wday = "Fri";
	else if (day == 6)
		wday = "Sat";
	string shour = to_string(ltm->tm_hour) + "h";
	if (ltm->tm_min<10)
		shour += "0" + to_string(ltm->tm_min);
	else
		shour += to_string(ltm->tm_min);
	while (cur != NULL)
	{
		if (cur->dayOfWeek == wday)
			if (shour<cur->endHour&&shour>cur->startHour)
			{
				Ccode = cur->courseCode;
				break;
			}
		cur = cur->next;
	}
	if (cur == NULL)
		cout << "You don't have class today,CHILL\n";
	else {
		string coursename = "presence_";
		coursename += Ccode;
		coursename += ".csv";
		Presence *pHead = NULL;
		string *presenceLabel = new string[5];
		loadPresence(coursename, pHead, presenceLabel);
		Presence *pcur = pHead;
		string ID = Uhead->ID;
		int i = 0;
		if (pcur != NULL)
		{
			while (pcur->frame[i][0] != ID)
				i++;
			if (pcur->checkIn[i][10] == 0)
			{
				pcur->checkIn[i][10] = 1;
				cout << "Welcome to class " << Ccode << endl;
			}
			else
			{
				cout << "Stop checkin this class you idiots!!!\n";
			}
			system("pause");
		}
		exportPresence(coursename, pHead);
	}
}
//32
void viewcheckin(Presence *phead, User *Uhead)
{
	string ID = Uhead->ID;
	Presence * pcur = phead;
	int i = 0;
	if (pcur != NULL)
	{
		while (pcur->frame[i][0] != ID)
			i++;
		for (int j = 0; j < 10; j++)
		{
			cout << setw(10) << "Week[" << j << "]: ";
			if (pcur->checkIn[i][j] == 1)
				cout << setw(10) << "In class" << endl;
			else cout << setw(10) << "Absent" << endl;
		}
		system("pause");
	}
}
//33. View his / her scores of a course
void viewyourScore(string courseCode, Score *scoreHead, string id)
{
	Score * cur = scoreHead;
	while (cur->next != NULL) {
		if (!strcmp(cur->courseCode.c_str(), courseCode.c_str()) && !strcmp(cur->id.c_str(), id.c_str())) {
			cout << setw(10) << "ID" << setw(10) << "Midterm" << setw(10) << "Lab" << endl;
			cout << setw(10) << cur->id << setw(10) << cur->midtermScore << setw(10) << cur->labScore << endl;
		}
		cur = cur->next;
	}
}


