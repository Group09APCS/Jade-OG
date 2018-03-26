#include "Function.h"

//CS162_PA01
//Group: 09


int main() {

	//Student *head = NULL; 
	User *head = NULL;
	cinData("user.csv", head);    
	system("color 0A");
	Login();
	acastaffMenu();
	system("pause");
	return 0;
}
