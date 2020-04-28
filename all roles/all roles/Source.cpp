// source.cpp
#include "Header.h"
void loadstaff(ifstream& f, staff& a)
{
	f.ignore();
	f.getline(a.username, 101);
	f.getline(a.password, 101);
	f.getline(a.fullname, 101);
	f.getline(a.dob, 101);
	f >> a.sex;
	f >> a.type;
}
void loadstaffarray(ifstream& f, staff a[], int&n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadstaff(f, a[i]);
	}
}
void loadlecturer(ifstream& f, lecturer& b)
{
	f.ignore();
	f.getline(b.username, 101);
	f.getline(b.password, 101);
	f.getline(b.fullname, 101);
	f.getline(b.dob, 101);
	f >> b.sex;
	f >> b.type;
}
void loadlecturerarray(ifstream& f, lecturer b[],int&n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadlecturer(f, b[i]);
	}
}
void loadstudent(ifstream& f, student& c)
{
	f.ignore();
	f.getline(c.username, 101);
	f.getline(c.password, 101);
	f.getline(c.fullname, 101);
	f.getline(c.classname, 11);
	f >> c.id;
	f.ignore();
	f.getline(c.dob, 101);
	f >> c.sex;
	f >> c.type;
}
void loadstudentarray(ifstream& f, student c[], int& n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadstudent(f, c[i]);
	}
}
void login()
{
	int idx;
	int n;
	staff a[100];
	lecturer b[100];
	student c[100];
	char userlogin[100];
	char passlogin[100];
	cout << "Username: ";
	cin.getline(userlogin, 101);
	cout << "Password: ";
	cin.getline(passlogin, 101);
	ifstream f;
	f.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\staff.txt");
	if (!f.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{

		loadstaffarray(f, a, n);
		for (int i = 0;i < n;i++)
		{
			if (!strcmp(userlogin, a[i].username) && !strcmp(passlogin, a[i].password))
			{
				idx = i;
				cout << "Login successfully. Hello staff " << a[i].fullname << "!";
				staff_menu(a, idx);
			}
		}
		f.close();
		f.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\lecturer.txt");
		if (!f.is_open())
		{
			cout << "Can not open file" << endl;
		}
		else
		{
			loadlecturerarray(f, b, n);
			for (int i = 0;i < n;i++) {
				if (!strcmp(userlogin, b[i].username) && !strcmp(passlogin, b[i].password))
				{
					idx = i;
					cout << "Login successfully. Hello lecturer " << b[i].fullname << " !";
					lecturer_menu(b, idx);
				}
			}
			f.close();
			f.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\student.txt");
			if (!f.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else
			{
				loadstudentarray(f, c, n);
				for (int i = 0;i < n;i++)
				{
					if (!strcmp(userlogin, c[i].username) && !strcmp(passlogin, c[i].password))
					{
						idx = i;
						cout << "Login successfully. Hello student " << c[i].fullname << " !";
						student_menu(c, idx);
					}
					else main_menu();
				}
				f.close();
			}
		}


	}
}
void main_menu()
{
	int choice;
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 2)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		login();
	}
	case 2:
	{
		exit(1);
	}
	}
}
void academic_staff(staff a[], int& idx)
{
	int choice;
	cout << "Which types you want?";
	cout << "1. Class" << endl;
	cout << "2. Course" << endl;
	cout << "3. Scoreboard" << endl;
	cout << "4. Attendance list" << endl;
	cout << "5. Back" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 5)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
}
void academic_lecturer(lecturer b[], int& idx)
{
	int choice;
	cout << "Which types you want?";
	cout << "1. View list of courses in the current semester" << endl;
	cout << "2. View list of students of a course" << endl;
	cout << "3. View attendance list of a course" << endl;
	cout << "4. Edit an attendance" << endl;
	cout << "5. Import scoreboard of a course" << endl;
	cout << "6. Edit grade of a student" << endl;
	cout << "7. View a scoreboard" << endl;
	cout << "8. Back" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 7)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
}
void academic_student(student c[], int& idx)
{
	int choice;
	cout << "Which types you want?";
	cout << "1. Checkin" << endl;
	cout << "2. View checkin result" << endl;
	cout << "3. View schedules" << endl;
	cout << "4. View your scores of a course" << endl;
	cout << "5. Back" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 5)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
}
void view_profile_student(student c[], int& idx)
{
	ifstream f;
	loadstudentarray(f, c, idx);
	cout << c[idx].id << endl;
	cout << c[idx].fullname << endl;
	cout << c[idx].dob << endl;
	cout << c[idx].classname << endl;
	cout << c[idx].sex << endl;
}
void view_profile_lecturer(lecturer b[], int& idx)
{
	
	ifstream f;
	loadlecturerarray(f, b, idx);
	cout << b[idx].fullname << endl;
	cout << b[idx].dob << endl;
	cout << b[idx].sex << endl;
}
void view_profile_staff(staff a[], int& idx)
{
	ifstream f;
	loadstaffarray(f, a, idx);
	cout << a[idx].fullname << endl;
	cout << a[idx].dob << endl;
	cout << a[idx].sex << endl;
}
void savenewpassword_staff(ofstream& f, staff a[], int idx)
{
	f << a[idx].password;
}
void savenewpassword_lecturer(ofstream& f, lecturer b[], int idx)
{
	f << b[idx].password;
}
void savenewpassword_student(ofstream& f, student c[], int idx)
{
	f << c[idx].password;
}
void changepassword_staff(staff a[], int& idx)
{
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	ofstream file2;
	file2.open("staff.txt");
	if (!file2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
		while (currentpass == a[idx].password)
		{
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
			while (newpass1 == newpass2)
			{
				savenewpassword_staff(file2, a, idx);
			}
			cout << "Unmatched. Try again." << endl;
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
		}
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
	}
	file2.close();
}
void changepassword_lecturer(lecturer b[], int& idx)
{
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	ofstream file2;
	file2.open("lecturer.txt");
	if (!file2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
		while (currentpass == b[idx].password)
		{
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
			while (newpass1 == newpass2)
			{
				savenewpassword_lecturer(file2, b, idx);
			}
			cout << "Unmatched. Try again." << endl;
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
		}
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
	}
	file2.close();
}
void changepassword_student(student c[], int& idx)
{
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	ofstream file2;
	file2.open("student.txt");
	if (!file2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		cout << endl;
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
		while (currentpass == c[idx].password)
		{
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
			while (newpass1 == newpass2)
			{
				savenewpassword_student(file2, c, idx);
			}
			cout << "Unmatched. Try again." << endl;
			cout << "Enter new password: ";
			cin.getline(newpass1, 101);
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
		}
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin.getline(currentpass, 101);
	}
	file2.close();
}
void logout()
{
	main_menu();
}
void staff_menu(staff a[], int& idx)
{
	int choice;
	cout << "1. Academic" << endl;
	cout << "2. View profile" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Log out" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 4)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		academic_staff(a,idx);
		break;
	}
	case 2:
	{
		view_profile_staff(a, idx);
		break;
	}
	case 3:
	{
		changepassword_staff(a, idx);
		break;
	}
	case 4:
	{
		logout();
		break;
	}
	}
}
void lecturer_menu(lecturer b[], int& idx)
{
	int choice;
	cout << "1. Academic" << endl;
	cout << "2. View profile" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Log out" << endl;
	cout << "Which types you want?";
	cin >> choice;
	while (choice < 0 || choice > 7)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		academic_lecturer(b,idx);
		break;
	}
	case 2:
	{
		view_profile_lecturer(b, idx);
		break;
	}
	case 3:
	{
		changepassword_lecturer(b, idx);
		break;
	}
	case 4:
	{
		logout();
		break;
	}
	}
}
void student_menu(student c[], int& idx)
{
	int choice;
	cout << "1. Academic" << endl;
	cout << "2. View profile" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Log out" << endl;
	cout << "Which types you want?";
	cin >> choice;
	while (choice < 0 || choice > 7)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		academic_student(c, idx);
	}
	case 2:
	{
		view_profile_student(c,idx);
		break;
	}
	case 3:
	{
		changepassword_student(c, idx);
		break;
	}
	case 4:
	{
		logout();
		break;
	}
	}
}