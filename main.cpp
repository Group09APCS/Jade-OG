#include "Function.h"

//CS162_PA01
//Group: 09


int main() {

	//Student *head = NULL; 
	User *head = NULL;
	cinData("D:\\user.csv", head);       //thay "D:\\user.csv" bang duong dan den file user.csv tren laptop cua cac ong
	system("color 0A");
	Login();
	acastaffMenu();
	system("pause");
	return 0;
}
