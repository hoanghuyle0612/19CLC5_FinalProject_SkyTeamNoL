// MAIN

#include "Course.h"

int main() {
	Student* stuHead;
	int n = 0;
	string fName = GetFileName();
	if (!GetCourse(stuHead, n, fName)) return 0;
	
	int ans = -1;
	while (ans != 3) {

		cout << "Select next option" << endl;
		cout << "0 - View Course's Student list" << endl;
		cout << "1 - View Course's Attendance list" << endl;
		cout << "2 - Edit a Student's score" << endl;
		cout << "3 - Back" << endl;
		cout << "Input: "; cin >> ans;
		while (ans < 0 || ans > 3) {
			cout << "Invalid input" << endl;
			cout << "Input: "; cin >> ans;
		}
		system("cls");
		switch (ans) {
			case 0:
				ShowCourse(stuHead, n);
				system("pause");
			break;
			case 1:
				while (ans != 2) {
					ShowAttList(stuHead, n);
					cout << "Select next option" << endl;
					cout << "0 - Export Attendance List" << endl;
					cout << "1 - Edit an Attendance" << endl;
					cout << "2 - Back" << endl;
					cout << "Input: "; cin >> ans;

					while (ans < 0 || ans > 2) {
						cout << "Invalid input" << endl;
						cout << "Input: "; cin >> ans;
					}

					switch (ans) {
						case 0:
							if (ExportAttList(stuHead, n, fName));
						break;
						case 1:
							EditAtt(stuHead, n, fName);
						break;
					}
					system("cls");
				}
				ans = -1;
			break;
			case 2:
				EditScore(stuHead, n, fName);
			break;
		}
		system("cls");

	}

	GetCourse_DelStu(stuHead, n);

	return 0;
}