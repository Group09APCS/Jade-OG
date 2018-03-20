#include "Function.h"

//CS162_PA01
//Group: 09


int main() {
	Student *head = NULL;
	//Ex01
	load("D:\\Students.csv", head);
	//Ex02
	save("D:\\PA01_test.txt", head);

	cin.get(); //dong nay de man hinh console dung lai cho minh xem ket qua, nhan Enter 2 lan la man hinh console bien mat 
	cin.get();
	return 0;
}