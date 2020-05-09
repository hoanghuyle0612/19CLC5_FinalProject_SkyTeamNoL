// Role Function

#include "Course.h"

void RF_AStaff_AttList(string Sem, char * Link) {
	int ans = -1;
	Student* stuHead;
	int n = 0;
	string fName = GetFileName(Sem, Link);
	std::system("cls");
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
			std::system("cls");
			n = 0;
			cin.ignore();
			fName = GetFileName(Sem, Link);
			fNameStu = fName + "Student";
			fNameScB = fName + "Scoreboard";
			if (!GetCourse(stuHead, n, fNameStu)) return;
		}

		switch (ans) {
			case 2:
				std::system("cls");
				ShowAttList(stuHead, n);
				break;
			case 3:
				if (ExportAttList(stuHead, n, fNameStu))
					cout << "Export complete" << endl;
				else cout << "Export failed" << endl;
				break;
		}
		if (ans != 1 && ans != 0) 
			std::system("pause");
		std::system("cls");
		ans = -1;
	}
	GetCourse_DelStu(stuHead, n);
}

void RF_Lecturer(string Sem, char * Link) {
	int ans = -1;
	Student* stuHead;
	int n = 0;
	string fName = GetFileName(Sem, Link);
	string fNameStu = fName + "Student";
	string fNameScB = fName + "Scoreboard";
	if (!GetCourse(stuHead, n, fNameStu)) return;
	std::system("cls");
	while (ans != 0) {

		cout << "-LECTURER - Select next option-" << endl;
		cout << "0 - Cancel" << endl;
		cout << "1 - Change Course" << endl;
		cout << "2 - View list of Students" << endl;
		cout << "3 - Attendance list options" << endl;
		cout << "4 - Scoreboard options" << endl;
		cout << "5 - View Semester's list of Courses" << endl;

		cout << "> "; cin >> ans;
		while (ans < 0 || ans > 5) {
			cout << "Invalid input." << endl;
			cout << "> "; cin >> ans;
		}
		if (ans == 0) return;
		cout << endl;

		if (ans == 1) {
			std::system("cls");
			cin.ignore();
			n = 0;
			fName = GetFileName(Sem, Link);
			fNameStu = fName + "Student";
			fNameScB = fName + "Scoreboard";
			if (!GetCourse(stuHead, n, fNameStu)) return;
		}

		switch (ans) {
		case 2:
			std::system("cls");
			ShowCourse(stuHead, n);
			break;
		case 3:
			ans = -1;
			while (ans != 0) {
				
				std::system("cls");
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
						std::system("cls");
						ShowAttList(stuHead, n);
						break;
					case 2:
						std::system("cls");
						ShowAttList(stuHead, n);
						EditAtt(stuHead, n, fNameStu);
						break;
				}
				if (ans != 0)
					std::system("pause");
				std::system("cls");
				ans = -1;
			}
			break;
		case 4:
			ans = -1;
			while (ans != 0) {

				std::system("cls");
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
					std::system("cls");
					ShowScoreBoard(stuHead, n);
					break;
				case 2:
					std::system("cls");
					EditScore(stuHead, n, fNameScB);
					break;
				case 3:
					if (ImportScoreBoard(stuHead, n, fNameScB))
						cout << "Import complete" << endl;
					else cout << "Import failed" << endl;
					break;
				}
				if (ans != 0 && ans != 2)
					std::system("pause");
				std::system("cls");
				ans = -1;
			}
			break;
		case 5:
			std::system("cls");
			ShowCourseList(Sem, Link);
			break;
		}
		if (ans != 1 && ans != 0)
			std::system("pause");
		std::system("cls");
		ans = -1;
	}
	GetCourse_DelStu(stuHead, n);
}

void RF_Student(string Sem, char * Link) {
	cout << "Enter your ID: ";
	int ID; cin >> ID;
	while (ID < 10000000 || ID > 999999999) {
		cout << "Invalid input" << endl;
		cout << "> "; cin >> ID;
	}
	int ans = -1;
	Student* stu = nullptr;
	Student* stuHead;
	int n = 0;
	string fName, fNameStu, fNameScB;
	while (stu == nullptr) {
		fName = GetFileName(Sem, Link);
		fNameStu = fName + "Student";
		fNameScB = fName + "Scoreboard";
		if (!GetCourse(stuHead, n, fNameStu)) return;
		stu = GetStudent(stuHead, ID);
		if (stu == nullptr) {
			cout << "You haven't enrolled in this Course" << endl;
			std::system("pause");
		}
		std::system("cls");
	}
	while (ans != 0) {

		cout << "-STUDENT - Select next option-" << endl;
		cout << "0 - Cancel" << endl;
		cout << "1 - Change Course" << endl;
		cout << "2 - Check-in" << endl;
		cout << "3 - View Check-in result" << endl;
		cout << "4 - " << endl;
		cout << "5 - View Score" << endl;

		cout << "> "; cin >> ans;
		while (ans < 0 || ans > 5) {
			cout << "Invalid input." << endl;
			cout << "> "; cin >> ans;
		}
		if (ans == 0) return;
		cout << endl;

		if (ans == 1 || stu == nullptr) {
			std::system("cls");
			fName = GetFileName(Sem, Link);
			fNameStu = fName + "Student";
			fNameScB = fName + "Scoreboard";
			if (!GetCourse(stuHead, n, fNameStu)) return;
			stu = GetStudent(stuHead, ID);
			cout << "You haven't enrolled in this Course" << endl;
		}

		switch (ans) {
			case 2:
				if (CheckIn(stu)) {
					cout << "Check-in successful" << endl;
				} else {
					cout << "Check-in failed" << endl;
				}
				cout << endl;
				ShowAttDay(stu);
				break;
			case 3:
				std::system("cls");
				ShowAttDay(stu);
				break;
			case 5:
				std::system("cls");
				ShowScore(stu);
				break;
		}
		if (ans != 1 && ans != 0)
			std::system("pause");
		std::system("cls");
		ans = -1;
	}
	GetCourse_DelStu(stuHead, n);
}