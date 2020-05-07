// Role Function

#include "Course.h"

void RF_AStaff_AttList() {
	int ans = -1;
	Student* stuHead;
	int n = 0;
	string fName = GetFileName();
	system("cls");
	string fNameStu = fName + "Student";
	string fNameScB = fName + "Scoreboard";
	if (!GetCourse(stuHead, n, fNameStu)) return;
	while (ans != 0) {

		cout << "-ACADEMIC STAFF - Select next option-" << endl;
		cout << "0 - Cancel" << endl;
		cout << "1 - Change Course" << endl;
		cout << "2 - View Attendance list" << endl;
		cout << "3 - Export Attendance list" << endl;
		
		cout << "> "; cin >> ans;
		while (ans < 0 || ans > 3) {
			cout << "Invalid input." << endl;
			cout << "> "; cin >> ans;
		}
		if (ans == 0) return;
		cout << endl;

		if (ans == 1) {
			system("cls");
			n = 0;
			cin.ignore();
			fName = GetFileName();
			fNameStu = fName + "Student";
			fNameScB = fName + "Scoreboard";
			if (!GetCourse(stuHead, n, fNameStu)) return;
		}

		switch (ans) {
			case 2:
				system("cls");
				ShowAttList(stuHead, n);
				break;
			case 3:
				if (ExportAttList(stuHead, n, fNameStu))
					cout << "Export complete" << endl;
				else cout << "Export failed" << endl;
				break;
		}
		if (ans != 1) 
			system("pause");
		system("cls");
		ans = -1;
	}
	GetCourse_DelStu(stuHead, n);
}

void RF_Lecturer() {
	int ans = -1;
	Student* stuHead;
	int n = 0;
	string fName = GetFileName();
	system("cls");
	string fNameStu = fName + "Student";
	string fNameScB = fName + "Scoreboard";
	if (!GetCourse(stuHead, n, fNameStu)) return;
	while (ans != 0) {

		cout << "-LECTURER - Select next option-" << endl;
		cout << "0 - Cancel" << endl;
		cout << "1 - Change Course" << endl;
		cout << "2 - View list of Students" << endl;
		cout << "3 - Attendance list options" << endl;
		cout << "4 - Scoreboard options" << endl;

		cout << "> "; cin >> ans;
		while (ans < 0 || ans > 4) {
			cout << "Invalid input." << endl;
			cout << "> "; cin >> ans;
		}
		if (ans == 0) return;
		cout << endl;

		if (ans == 1) {
			system("cls");
			cin.ignore();
			n = 0;
			fName = GetFileName();
			fNameStu = fName + "Student";
			fNameScB = fName + "Scoreboard";
			if (!GetCourse(stuHead, n, fNameStu)) return;
		}

		switch (ans) {
		case 2:
			system("cls");
			ShowCourse(stuHead, n);
			break;
		case 3:
			ans = -1;
			while (ans != 0) {
				
				system("cls");
				cout << "-LECTURER - Attendance list-" << endl;
				cout << "0 - Cancel" << endl;
				cout << "1 - View Attendance list" << endl;
				cout << "2 - Edit an Attendance" << endl;
			
				cout << "> "; cin >> ans;
				while (ans < 0 || ans > 2) {
					cout << "Invalid input." << endl;
					cout << "> "; cin >> ans;
				}
				cout << endl;
				if (ans == 0) break;

				switch (ans) {
					case 1:
						system("cls");
						ShowAttList(stuHead, n);
						break;
					case 2:
						system("cls");
						ShowAttList(stuHead, n);
						EditAtt(stuHead, n, fNameStu);
						break;
				}
				if (ans != 0)
					system("pause");
				system("cls");
				ans = -1;
			}
			break;
		case 4:
			ans = -1;
			while (ans != 0) {

				system("cls");
				cout << "-LECTURER - Scoreboard-" << endl;
				cout << "0 - Cancel" << endl;
				cout << "1 - View Scoreboard" << endl;
				cout << "2 - Edit a Student's Score" << endl;
				cout << "3 - Import Scoreboard" << endl;

				cout << "> "; cin >> ans;
				while (ans < 0 || ans > 3) {
					cout << "Invalid input." << endl;
					cout << "> "; cin >> ans;
				}
				cout << endl;
				if (ans == 0) break;

				switch (ans) {
				case 1:
					system("cls");
					ShowScoreBoard(stuHead, n);
					break;
				case 2:
					system("cls");
					EditScore(stuHead, n, fNameScB);
					break;
				case 3:
					if (ImportScoreBoard(stuHead, n, fNameScB))
						cout << "Import complete" << endl;
					else cout << "Import failed" << endl;
					break;
				}
				if (ans != 0 && ans != 2)
					system("pause");
				system("cls");
				ans = -1;
			}
			break;
		}
		if (ans != 1 && ans != 0)
			system("pause");
		system("cls");
		ans = -1;
	}
	GetCourse_DelStu(stuHead, n);
}
