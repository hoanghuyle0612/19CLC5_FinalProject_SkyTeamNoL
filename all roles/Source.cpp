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
	f >> b.gender;
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
	cin >> userlogin;
	cout << "Password: ";
	cin >> passlogin;
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
void staffclass_func(staff a[])
{
	int choice;
	cout << "Which types you want?";
	cout << "1. Import" << endl;
	cout << "2. Add new student to a class" << endl;
	cout << "3. Edit an existing student" << endl;
	cout << "4. Remove a student" << endl;
	cout << "5. Change students" << endl;
	cout << "6. View lists of class" << endl;
	cout << "7. View list of students in a class" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 5)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
}
void import(staff a[], int& idx)
{
	char currentclassname[15];
	cout << "Which class do you want to import?" << endl;
	cout << "Class: "; cin >> currentclassname;
	char temp[100];
	ifstream f("class.txt");
	ofstream fa("temp.txt");
	int n;
	int check = 0;
	f >> n;
	while (f.getline(temp, 100))
	{
		if (!strcmp(temp, currentclassname))
		{
			cout << "Class existed" << endl;
			check = 1;
		}
		fa << temp << "\n";
	}
	f.close();
	fa.close();
	char qq[100];
	if (check == 1)
	{
		import(a, idx);
	}
	if (check == 0)
	{
		ofstream fb("class.txt");
		ifstream ft("temp.txt");
		n = n + 1;
		fb << n << endl;
		ft.getline(qq, 100);
		while (ft.getline(qq, 100))
		{
			fb << qq << "\n";
		}
		fb << currentclassname << endl;
		fb.close();
		ft.close();
		remove("temp.txt");
		char link[100];
		cout << "Enter link: "; cin >> link;
		fstream f1(link);
		ofstream f2("dur.txt");
		fstream f3("student.txt");
		student c[100];
		int q;
		f3 >> q;
		int count = 0;
		char cur[100];
		char first[100];
		f1.getline(first, 100);
		while (f1.getline(cur, 100))
		{
			count++;
			q++;
			for (int i = 0;i < strlen(cur);i++)
			{
				if (cur[i] == ';')
				{
					cur[i] = '\n';
				}
				if (cur[i] == '/')
				{
					cur[i] = ' ';
				}
			}
			f2 << cur << "\n";
		}
		f1.close();
		f2.close();
		f3.close();
		fstream fv("dur.txt");
		fv >> count;
		for (int i = 0;i < count;i++)
		{
			int num;
			f1 >> num;
			f1 >> c[i].id;
			f1.getline(c[i].fullname, 100);
			f1.getline(c[i].dob, 100);
			f1.getline(c[i].classname, 100);
			f1 >> c[i].gender;
		}
		fv.close();
		ofstream fc("temp.txt");
		fstream fx("student.txt");
		char sec[100];
		while (fx.getline(sec, 100))
		{
			fc << sec << "\n";
		}
		fc.close();
		fx.close();
		ofstream fz("dur.txt");
		ofstream fs("student.txt");
		ifstream fd("temp.txt");
		char aa[100];
		fs << q << endl;
		fd.getline(aa, 100);
		while (fd.getline(aa, 100))
		{
			fs << aa << "\n";
		}
		for (int i = 0;i < count;i++)
		{
			fs << c[i].id << "\n";
			
			fs << c[i].fullname << "\n";
			fs << c[i].classname << "\n";
			fs << c[i].id << "\n";
			fs << c[i].dob << "\n";
			fs << c[i].gender << "\n";
			fs << 1 << "\n";
		}
		fz.close();
		fs.close();
		fd.close();
	}
}
void add_new_student_to_a_class(ofstream& f, staff a[])
{
	char classname[10];
	int choice;
	cout << "Which class do you want to add?";
	cin >> classname;
	int type = 3;
	int sex;
	int id;
	char fullname[100];
	char dob[15];
	cout << "Enter ID: "; cin >> id;
	cout << "Enter full name: "; cin.getline(fullname, 101);
	cout << "Enter date of birth: "; cin.getline(dob, 16);
	cout << "Sex: "; cin >> sex;
	fstream f;
	f.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\student.txt", ios::app);
	f << id << endl;
	f << dob << endl;
	f << fullname << endl;
	f << classname << endl;
	f << id;
	f << dob << endl;
	f << type << endl;
}
void import(staff a[])
{

}
void import(staff a[])
{

}
void import(staff a[])
{

}
void import(staff a[])
{

}
void import(staff a[])
{

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
	
}
void savenewpassword_lecturer(ofstream& f, lecturer b[], int idx)
{
	f << b[idx].password;
}
void savenewpassword_student(ofstream& f, student c[], int idx)
{
	f << c[idx].password;
}
void changepassword_staff()
{
	staff a[100];
	int idx;
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	ofstream file2;
	cout << "Enter your current password: ";
	cin >> currentpass;
	if (currentpass == a[idx].password)
	{
		cout << "Enter new password: ";
		cin >> newpass1;
		cout << "Enter new password again: ";
		cin >> newpass2;
		if (newpass1 == newpass2)
		{
			ifstream f1("C:\\Users\\THUTHAO\\source\\repos\\all roles\\staff.txt");
			ofstream f2("C:\\Users\\THUTHAO\\source\\repos\\all roles\\temp_staff.txt");
			if (!f1 || !f2)
			{
				cout << "Error opening files!" << endl;
			}

			char temp[100];
			while (f1 >> temp)
			{
				if (!strcmp(temp,a[idx].password)) 
				{
					strcpy(temp, newpass1);
				}
				f2 << temp << "\n";
			}
			f1.close();
			f2.close();
			char oldfile[] = "C:\\Users\\THUTHAO\\source\\repos\\all roles\\temp_staff.txt";
			char newfile[] = "C:\\Users\\THUTHAO\\source\\repos\\all roles\\staff.txt";
			rename(oldfile, newfile);
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
    file2.close();
}
void changepassword_lecturer(lecturer b[], int& idx)
{
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	ofstream file2;
	file2.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\lecturer.txt");
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
	file2.open("C:\\Users\\THUTHAO\\source\\repos\\all roles\\student.txt");
	if (!file2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		cout << endl;
		cout << "Enter your current password: ";
		cin >> currentpass;
		while (currentpass == c[idx].password)
		{
			cout << "Enter new password: ";
			cin >> currentpass;
			cout << "Enter new password again: ";
			cin.getline(newpass2, 101);
			while (newpass1 == newpass2)
			{
				savenewpassword_student(file2, c, idx);
			}
			cout << "Unmatched. Try again." << endl;
			cout << "Enter new password: ";
			cin >> newpass1;
			cout << "Enter new password again: ";
			cin >> newpass2;
		}
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin >> currentpass;
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
		changepassword_staff();
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