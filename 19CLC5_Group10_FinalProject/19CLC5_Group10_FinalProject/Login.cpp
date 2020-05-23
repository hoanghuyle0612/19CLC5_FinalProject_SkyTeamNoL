// LOGIN FUNCTION

#include "Login.h"

void loadstaff(fstream& f, staff& a)
{
	f.ignore();
	f.getline(a.username, 101);
	f.getline(a.password, 101);
	f.getline(a.fullname, 101);
	f.getline(a.dob, 101);
	f >> a.gender;
	f >> a.type;
}
void loadstaffarray(fstream& f, staff a[], int& n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadstaff(f, a[i]);
	}
}
void loadlecturer(fstream& f, lecturer& b)
{
	f.ignore();
	f.getline(b.username, 101);
	f.getline(b.password, 101);
	f.getline(b.fullname, 101);
	f.getline(b.dob, 101);
	f >> b.gender;
	f >> b.type;
}
void loadlecturerarray(fstream& f, lecturer b[], int& n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadlecturer(f, b[i]);
	}
}
void loadstudent(fstream& f, student& c)
{
	f.ignore();
	f.getline(c.username, 101);
	f.getline(c.password, 101);
	f.getline(c.fullname, 101);
	f >> c.id;
	f.ignore();
	f.getline(c.classname, 11);
	f.getline(c.dob, 101);
	f >> c.gender;
	f >> c.type;
}
void loadstudentarray(fstream& f, student c[], int& n)
{
	f >> n;
	for (int i = 0;i < n;i++)
	{
		loadstudent(f, c[i]);
	}
}

void login()
{
	std::system("cls");
	cout << "-Login-" << endl << endl;
	int idx;
	int n;
	staff a[100];
	lecturer b[100];
	student c[100];
	char userlogin[100];
	char passlogin[100];
	/*cin.ignore();*/
	cout << "[- Username ----------]" << endl;
	cout << "> "; cin >> userlogin;
	cout << "[- Password ----------]" << endl;
	cout << "> "; cin >> passlogin;
	fstream f;
	f.open("staff.txt");
	if (!f.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		loadstaffarray(f, a, n);
		for (int i = 0;i < n;i++)
		{
			if (a[i].type == 1 && !strcmp(userlogin, a[i].username) && !strcmp(passlogin, a[i].password))
			{
				idx = i;
				/*cout << "Login successfully. Hello staff " << a[i].fullname << "!" << endl;*/
				f.close();
				/*std::system("pause");*/
				Draw_WelCome(a[i].fullname, a[i].gender);
				cin.ignore();
				Menu_Staff(a, idx);
				return;
			}
		}
	}
	fstream f1;
	f1.open("lecturer.txt");
	if (!f.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		loadlecturerarray(f1, b, n);
		for (int i = 0;i < n;i++) {
			if (b[i].type == 1 && !strcmp(userlogin, b[i].username) && !strcmp(passlogin, b[i].password))
			{
				idx = i;
				cout << "Login successfully. Hello lecturer " << b[i].fullname << " !";
				f1.close();
				lecturer_menu(b, idx);
				exit(1);
			}
		}
	}
	fstream f3;
	f3.open("student.txt");
	if (!f.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		loadstudentarray(f3, c, n);
		for (int i = 0;i < n;i++)
		{
			if (c[i].type == 1 && !strcmp(userlogin, c[i].username) && !strcmp(passlogin, c[i].password))
			{
				idx = i;
				cout << "Login successfully. Hello student " << c[i].fullname << " !";
				f3.close();
				student_menu(c, idx);
				exit(1);
			}
		}
	}
	cout << "Incorrect username or password!" << endl;
	std::system("pause");
	login();
}
void main_menu()
{
	int choice;
	cout << "-Main menu-" << endl;
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	cout << "> "; cin >> choice;
	while (choice < 0 || choice > 2)
	{
		cout << "Invalid input. Try again." << endl; 
		cout << "> "; cin >> choice;
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
void logout()
{
	main_menu();
}	

void staffclass_func(staff a[], int& idx)
{
	int choice;
	cout << "Which types do you want?" << endl;
	cout << "1. Import" << endl;
	cout << "2. Add new student to a class" << endl;
	cout << "3. Edit an existing student" << endl;
	cout << "4. Remove a student" << endl;
	cout << "5. Change student in class A to class B" << endl;
	cout << "6. View lists of class" << endl;
	cout << "7. View list of students in a class" << endl;
	cout << "8. Back" << endl;
	cout << "Enter your choice: " << endl;
	cin >> choice;
	while (choice < 0 || choice > 8)
	{
		cout << "Unavailable. Try again" << endl; cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		import(a, idx);
		break;
	}
	case 2:
	{
		add_a_new_student(a, idx);
		break;
	}
	case 3:
	{
		edit_existing_student(a, idx);
		break;
	}
	case 4:
	{
		remove_a_student(a, idx);
		break;
	}
	case 5:
	{
		change_student_classA_to_B(a, idx);
		break;
	}
	case 6:
	{
		list_of_classes(a, idx);
		break;
	}
	case 7:
	{
		list_of_student_in_class(a, idx);
		break;
	}
	case 8:
	{
		staffclass_func(a, idx);
		break;
	}
	}
}

void import(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Import Class- " << endl << endl;
	char currentclassname[15];
	cout << "[- Enter Class you want to import -] "; 
	cout << endl << "> "; cin >> currentclassname;
	char line[100];
	ifstream f("class.txt");
	ofstream fa("temp.txt");
	int n;
	int check = 0;
	f >> n;
	while (f.getline(line, 100))
	{
		if (!strcmp(line, currentclassname))
		{
			cout << "Class already exists." << endl;
			std::system("pause");
			check = 1;
		}
		fa << line << "\n";
	}
	f.close();
	fa.close();
	char line2[100];
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
		ft.getline(line2, 100);
		while (ft.getline(line2, 100))
		{
			fb << line2 << "\n";
		}
		fb << currentclassname << endl;
		fb.close();
		ft.close();
		remove("temp.txt");
		char link[100];
		cout << "[- Enter Class directory ----------] ";
		cout << endl << "> ";  cin >> link;
		fstream f1(link);
		ofstream f2("temp.txt");
		student c[100];
		int count = 0;
		char line3[100];
		char line4[100];
		f1.getline(line4, 100);
		while (f1.getline(line3, 100))
		{
			count++;
			int x = strlen(line3);
			for (int i = 0;i < x;i++)
			{
				if (line3[i] == ';')
				{
					line3[i] = '\n';
				}
				if (line3[i] == '/')
				{
					line3[i] = ' ';
				}
			}
			f2 << line3 << "\n";
		}
		f1.close();
		f2.close();
		ifstream f3("temp.txt");
		for (int i = 0;i < count;i++)
		{
			f3.ignore();
			f3 >> c[i].id;
			f3.ignore();
			f3.getline(c[i].fullname, 100);
			f3.getline(c[i].dob, 100);
			f3.getline(c[i].classname, 100);
			f3 >> c[i].gender;
			f3.ignore();
		}
		f3.close();
		ofstream f4("temp1.txt");
		ifstream f5("temp.txt");
		ifstream f6("student.txt");
		int q;
		f6 >> q;
		char line5[100];
		char line6[100];
		f6.getline(line5, 100);
		while (f6.getline(line6, 100))
		{
			f4 << line6 << "\n";
		}
		f6.close();
		f4.close();
		fstream f7("student.txt");
		f7 << q + count << "\n";
		char line7[100];
		ifstream f8("temp1.txt");
		while (f8.getline(line7, 100))
		{
			f7 << line7 << "\n";
		}
		f4.close();
		f8.close();
		for (int i = 0;i < count;i++)
		{
			f7 << c[i].id << "\n";
			char line8[100];
			strcpy(line8, c[i].dob);
			int k = strlen(line8);
			for (int i = 0;i < strlen(line8);i++)
			{
				if (line8[i] == ' ')
				{
					int j = 0;
					for (int j = i;j < strlen(line8);j++)
					{
						line8[j] = line8[j + 1];
					}
					k--;
				}
			}
			f7 << line8 << "\n";
			f7 << c[i].fullname << "\n";
			f7 << c[i].id << "\n";
			f7 << c[i].classname << "\n";
			f7 << c[i].dob << "\n";
			f7 << c[i].gender << "\n";
			f7 << 1 << "\n";
		}
		f5.close();
		f7.close();
		char tempo[100];
		ofstream fi("temp2.txt");
		fi << "student-";
		fi << currentclassname;
		fi << ".txt";
		fi.close();
		ifstream fo("temp2.txt");
		fo >> tempo;
		fo.close();
		ofstream f9(tempo);
		f9 << count << "\n";
		for (int i = 0;i < count;i++)
		{
			f9 << c[i].id << "\n";
			char line9[100];
			strcpy(line9, c[i].dob);
			int k = strlen(line9);
			for (int i = 0;i < strlen(line9);i++)
			{
				if (line9[i] == ' ')
				{
					int j = 0;
					for (int j = i;j < strlen(line9);j++)
					{
						line9[j] = line9[j + 1];
					}
					k--;
				}
			}
			f9 << line9 << "\n";
			f9 << c[i].fullname << "\n";
			f9 << c[i].id << "\n";
			f9 << c[i].classname << "\n";
			f9 << c[i].dob << "\n";
			f9 << c[i].gender << "\n";
			f9 << 1 << "\n";
		}
		f9.close();
		remove("temp.txt");
		remove("temp1.txt");
		remove("temp2.txt");
		cout << endl;
		cout << "Class imported." << endl;
		std::system("pause");
		Menu_Staff_Class(a, idx);
	}
}
void add_a_new_student(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Add new Student to a Class-" << endl << endl;
	char currentclass[100];
	int choice;
	cout << "-List of available Classes-";
	cout << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	char line222[100];
	f.getline(line222, 100);
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	cout << endl;
	cout << "[- Class ----------------------] ";
	cout << endl << "> ";  cin >> currentclass;
	f.close();
	int type = 1;
	int gender;
	int id;
	char fullname[100];
	char dob[15];
	cout << "[- ID -------------------------] ";
	cout << endl << "> ";  cin >> id;
	cin.ignore();
	cout << "[- Full name ------------------] ";
	cout << endl << "> ";
	cin.getline(fullname, 101);
	cout << "[- Date of Birth (dd/mm/yyyy) -] ";
	cout << endl << "> ";
	cin.getline(dob, 16);
	cout << "[- Gender (0 - F | 1 - M) -----] ";
	cout << endl << "> ";  cin >> gender;
	int check = 0;
	ifstream f1("student.txt");
	char line2[100];
	char line3[100];
	int q;
	f1 >> q;
	ofstream f2("temp.txt");
	_itoa(id, line3, 10);
	f1.ignore();
	while (f1.getline(line2, 100))
	{
		if (!strcmp(line3, line2))
		{
			cout << "Student already exists." << endl;
			std::system("pause");
			check = 1;
		}
		f2 << line2 << "\n";
	}
	f1.close();
	f2.close();
	if (check == 1)
	{
		add_a_new_student(a, idx);
	}
	if (check == 0)
	{
		ofstream f3("student.txt");
		ifstream f4("temp.txt");
		f3 << q + 1 << "\n";
		char line4[100];
		while (f4.getline(line4, 100))
		{
			f3 << line4 << "\n";
		}
		f3 << id << "\n";
		char line5[100];
		strcpy(line5, dob);
		int k = strlen(line5);
		for (int i = 0;i < k;i++)
		{
			if (line5[i] == ' ')
			{
				int j = 0;
				for (int j = i;j < k;j++)
				{
					line5[j] = line5[j + 1];
				}
				k--;
			}
		}
		f3 << line5 << "\n";
		f3 << fullname << "\n";
		f3 << id << "\n";
		f3 << currentclass << "\n";
		f3 << dob << "\n";
		f3 << gender << "\n";
		f3 << type << "\n";
		f4.close();
		f3.close();
		remove("temp.txt");
		char tempo[100];
		ofstream fi("temp2.txt");
		fi << "student-";
		fi << currentclass;
		fi << ".txt";
		fi.close();
		ifstream fo("temp2.txt");
		fo >> tempo;
		fo.close();
		ifstream f5(tempo);
		ofstream f6("temp.txt");
		char line6[100];
		int d;
		f5 >> d;
		f5.ignore();
		while (f5.getline(line6, 100))
		{
			f6 << line6 << "\n";
		}
		f5.close();
		f6.close();
		ofstream f7(tempo);
		ifstream f8("temp.txt");
		f7 << d + 1 << "\n";
		char line7[100];
		while (f8.getline(line7, 100))
		{
			f7 << line7 << "\n";
		}
		f7 << id << "\n";
		char line8[100];
		strcpy(line8, dob);
		int x = strlen(line8);
		for (int i = 0;i < x;i++)
		{
			if (line8[i] == ' ')
			{
				int j = 0;
				for (int j = i;j < x;j++)
				{
					line8[j] = line8[j + 1];
				}
				x--;
			}
		}
		f7 << line8 << "\n";
		f7 << fullname << "\n";
		f7 << id << "\n";
		f7 << currentclass << "\n";
		f7 << dob << "\n";
		f7 << gender << "\n";
		f7 << type << "\n";
		f7.close();
		f8.close();
		remove("temp.txt");
		remove("temp2.txt");
	}
	cout << endl;
	cout << "New Student added." << endl;
	std::system("pause");
	Menu_Staff_Class(a, idx);
}
void edit_existing_student(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Edit an existing Student-" << endl << endl;
	char currentclass[100];
	int choice;
	cout << "-List of available Classes-";
	cout << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	char line22[100];
	f.getline(line22, 100);
	cout << endl;
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	cout << endl;
	cout << "-Current-" << endl;
	cout << "[- Class ----------------------] ";
	cout << endl << "> ";  cin >> currentclass;
	f.close();
	int id;
	char fullname[100];
	char dob[15];
	int gender;
	cout << "[- ID -------------------------] ";
	cout << endl << "> ";  cin >> id;
	cin.ignore();
	cout << "[- Full name ------------------] ";
	cout << endl << "> ";  cin.getline(fullname, 101);
	cout << "[- Date of Birth (dd/mm/yyyy) -] ";
	cout << endl << "> ";  cin.getline(dob, 16);
	cout << "[- Gender (0 - F | 1 - M) -----] ";
	cout << endl << "> ";  cin >> gender;
	/*cout << "You want to edit this student? Yes(1) or no(2)?" << endl;
	cout << "Enter your choice: "; cin >> choice;
	if (choice == 1)
	{*/
	char currentfullname[100];
	char currentdob[15];
	int currentgender;
	cin.ignore();
	cout << endl;
	cout << "-Edit-" << endl;
	cout << "[- Full name ------------------]";
	cout << endl << "> "; cin.getline(currentfullname, 100);
	cout << "[- Date of Birth (dd/mm/yyyy) -]";
	cout << endl << "> "; cin.getline(currentdob, 15);
	cout << "[- Gender (0 - F | 1 - M) -----]";
	cout << endl << "> "; cin >> currentgender;
	ifstream f4("student.txt");
	ofstream f5("temp_student.txt");
	if (!f4.is_open() || !f5.is_open())
	{
		cout << "Error opening files!" << endl;
	}
	char temp[100];
	char tempo[100];
	int s;
	int count = 0;
	f4 >> s;
	f5 << s << "\n";
	f4.ignore();
	while (f4.getline(temp, 100))
	{
		f5 << temp << "\n";
		char linea[100];
		_itoa(id, linea, 10);
		if (!strcmp(temp, linea))
		{
			count++;
			f4.getline(tempo, 100);
			strcpy(tempo, currentdob);
			int x = strlen(tempo);
			for (int i = 0;i < x;i++)
			{
				if (tempo[i] == ' ')
				{
					int j = 0;
					for (int j = i;j < x;j++)
					{
						tempo[j] = tempo[j + 1];
					}
					x--;
				}
			}
			if (count == 1)
			{
				f5 << tempo << "\n";
				char line3[100];
				f4.getline(line3, 100);
				strcpy(line3, currentfullname);
				f5 << line3 << "\n";
				f5 << id << "\n";
				f5 << currentclass << "\n";
				f5 << currentdob << "\n";
				f5 << currentgender << "\n";
				f5 << 1 << "\n";
				f4.ignore();
				for (int i = 0;i < 5;i++)
				{
					char lind[100];
					f4.getline(lind, 100);
				}
			}
		}
	}
	f4.close();
	f5.close();
	fstream newFile("student.txt");
	if (!newFile)
	{
		cout << "Cannot edit Student." << endl;
		return;
	}
	newFile.close();
	if (remove("student.txt") == 0)
	{
		cout << "Editing..." << endl;
	}
	if (rename("temp_student.txt", "student.txt") == 0)
	{
		cout << "Student edited successfully!" << endl;
	}
	char temp1[100];
	ofstream fi("temp.txt");
	fi << "student-";
	fi << currentclass;
	fi << ".txt";
	fi.close();
	ifstream fo("temp.txt");
	fo >> temp1;
	fo.close();
	remove("temp.txt");
	ifstream f7(temp1);
	ofstream f6("temp_student.txt");
	if (!f7.is_open() || !f6.is_open())
	{
		cout << "Cannot open file." << endl;
	}
	char temp2[100];
	char tempo1[100];
	int e;
	int cou = 0;
	f7 >> e;
	f6 << e << "\n";
	f7.ignore();
	while (f7.getline(temp2, 100))
	{
		f6 << temp2 << "\n";
		char linea1[100];
		_itoa(id, linea1, 10);
		if (!strcmp(temp2, linea1))
		{
			cou++;
			f7.getline(tempo1, 100);
			strcpy(tempo1, currentdob);
			int p = strlen(tempo1);
			for (int i = 0;i < p;i++)
			{
				if (tempo1[i] == ' ')
				{
					int j = 0;
					for (int j = i;j < p;j++)
					{
						tempo1[j] = tempo1[j + 1];
					}
					p--;
				}
			}
			if (cou == 1)
			{
				f6 << tempo1 << "\n";
				char line31[100];
				f7.getline(line31, 100);
				strcpy(line31, currentfullname);
				f6 << line31 << "\n";
				f6 << id << "\n";
				f6 << currentclass << "\n";
				f6 << currentdob << "\n";
				f6 << currentgender << "\n";
				f6 << 1 << "\n";
				f7.ignore();
				for (int i = 0;i < 5;i++)
				{
					char lind1[100];
					f7.getline(lind1, 100);
				}
			}
		}
	}
	f7.close();
	f6.close();
	fstream newFile1(temp1);
	if (!newFile1)
	{
		cout << "Cannot open file." << endl;
		return;
	}
	newFile1.close();
	if (remove(temp1) == 0)
	{
		cout << "Editing..." << endl;
	}
	if (rename("temp_student.txt", temp1) == 0)
	{
		cout << "Student edited succesfully!" << endl;
	}
	std::system("pause");
	Menu_Staff_Class(a, idx);
	/*}*/
	/*if (choice == 2)
	{
		Menu_Staff_Class(a, idx);
	}*/
}
void remove_a_student(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Remove a Student-" << endl << endl;
	char currentclass[100];
	int choice;
	cout << "-List of available Classes-";
	cout << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	char line2[100];
	f.getline(line2, 100);
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	cout << "[- Class ----------------------]";
	cout << endl << "> "; cin >> currentclass;
	f.close();
	int id;
	char fullname[100];
	char dob[15];
	int gender;
	cout << "[- ID -------------------------] ";
	cout << endl << "> ";
	cin >> id;
	cin.ignore();
	cout << "[- Full name ------------------] ";
	cout << endl << "> ";
	cin.getline(fullname, 101);
	cout << "[- Date of Birth (dd/mm/yyyy) -] ";
	cout << endl << "> ";
	cin.getline(dob, 16);
	cout << "[- Gender (0 - F | 1 - M) -----] ";
	cout << endl << "> ";
	cin >> gender;
	/*cout << "You want to remove this student? Yes(1) or no(2)?" << endl;
	cout << "Enter your choice: "; cin >> choice;*/
	/*if (choice == 1)
	{*/
		ifstream f4("student.txt");
		ofstream f5("temp_student.txt");
		if (!f4.is_open() || !f5.is_open())
		{
			cout << "Error opening files!" << endl;
		}
		char temp[100];
		char tempo[100];
		int s;
		int count = 0;
		f4 >> s;
		f5 << s - 1 << "\n";
		f4.ignore();
		while (f4.getline(temp, 100))
		{
			f5 << temp << "\n";
			char linea[100];
			_itoa(id, linea, 10);
			if (!strcmp(temp, linea))
			{
				count++;
				f4.getline(tempo, 100);
				strcpy(tempo, dob);
				int x = strlen(tempo);
				for (int i = 0;i < x;i++)
				{
					if (tempo[i] == ' ')
					{
						int j = 0;
						for (int j = i;j < x;j++)
						{
							tempo[j] = tempo[j + 1];
						}
						x--;
					}
				}
				f5 << tempo << "\n";
				if (count == 2)
				{
					f5 << currentclass << "\n";
					f5 << dob << "\n";
					f5 << gender << "\n";
					f5 << 0 << "\n";
					f4.ignore();
					for (int i = 0;i < 5;i++)
					{
						char lind[100];
						f4.getline(lind, 100);
					}
				}
			}
		}
		f4.close();
		f5.close();
		fstream newFile("student.txt");
		if (!newFile)
		{
			cout << "File cannot open" << endl;
			return;
		}
		newFile.close();
		if (remove("student.txt") == 0)
		{
			cout << "Processing changing" << endl;
		}
		if (rename("temp_student.txt", "student.txt") == 0)
		{
			cout << "Successfully" << endl;
		}
		char temp1[100];
		ofstream fi("temp.txt");
		fi << "student-";
		fi << currentclass;
		fi << ".txt";
		fi.close();
		ifstream fo("temp.txt");
		fo >> temp1;
		fo.close();
		remove("temp.txt");
		ifstream f7(temp1);
		ofstream f6("temp_student.txt");
		if (!f7.is_open() || !f6.is_open())
		{
			cout << "Error opening files!" << endl;
		}
		char temp2[100];
		char tempo1[100];
		int e;
		int cou = 0;
		f7 >> e;
		f6 << e - 1 << "\n";
		f7.ignore();
		while (f7.getline(temp2, 100))
		{
			f6 << temp2 << "\n";
			char linea1[100];
			_itoa(id, linea1, 10);
			if (!strcmp(temp2, linea1))
			{
				cou++;
				f7.getline(tempo1, 100);
				strcpy(tempo1, dob);
				int p = strlen(tempo1);
				for (int i = 0;i < p;i++)
				{
					if (tempo1[i] == ' ')
					{
						int j = 0;
						for (int j = i;j < p;j++)
						{
							tempo1[j] = tempo1[j + 1];
						}
						p--;
					}
				}
				f6 << tempo1 << "\n";
				if (cou == 2)
				{
					f6 << currentclass << "\n";
					f6 << dob << "\n";
					f6 << gender << "\n";
					f6 << 0 << "\n";
					f7.ignore();
					for (int i = 0;i < 5;i++)
					{
						char lind1[100];
						f7.getline(lind1, 100);
					}
				}
			}
		}
		f7.close();
		f6.close();
		fstream newFile1(temp1);
		if (!newFile1)
		{
			cout << "File cannot open" << endl;
			return;
		}
		newFile1.close();
		if (remove(temp1) == 0)
		{
			cout << "Removing Student..." << endl;
		}
		if (rename("temp_student.txt", temp1) == 0)
		{
			cout << "Student removed." << endl;
		}
		std::system("pause");
	/*}*/
	Menu_Staff_Class(a, idx);
}
void change_student_classA_to_B(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Change a Student's Class-" << endl << endl;
	char currentclass[100];
	int choice;
	cout << "-List of available Classes-";
	cout << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	char line2[100];
	f.getline(line2, 100);
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	cout << "[- Class ----------------------]";
	cout << endl << "> ";  cin >> currentclass;
	f.close();
	int id;
	char fullname[100];
	char dob[15];
	int gender;
	cout << "[- ID -------------------------]";
	cout << endl << "> ";  cin >> id;
	cin.ignore();
	cout << "[- Full name ------------------] ";
	cout << endl << "> ";  cin.getline(fullname, 101);
	cout << "[- Date of Birth (dd/mm/yyyy) -] ";
	cout << endl << "> ";  cin.getline(dob, 16);
	cout << "[- Gender (0 - F | 1 - M) -----] ";
	cout << endl << "> ";  cin >> gender;
	/*if (choice == 1)
	{*/
		char futureclass[15];
		cin.ignore();
		cout << "[- New Class ------------------]";
		cout << endl << "> "; cin.getline(futureclass, 15);
		ifstream f4("student.txt");
		ofstream f5("temp_student.txt");
		if (!f4.is_open() || !f5.is_open())
		{
			cout << "Cannot change Class." << endl;
		}
		char temp[100];
		char tempo[100];
		int s;
		int count = 0;
		f4 >> s;
		f5 << s << "\n";
		f4.ignore();
		while (f4.getline(temp, 100))
		{
			f5 << temp << "\n";
			char linea[100];
			_itoa(id, linea, 10);
			if (!strcmp(temp, linea))
			{
				count++;
				f4.getline(tempo, 100);
				strcpy(tempo, dob);
				int x = strlen(tempo);
				for (int i = 0;i < x;i++)
				{
					if (tempo[i] == ' ')
					{
						int j = 0;
						for (int j = i;j < x;j++)
						{
							tempo[j] = tempo[j + 1];
						}
						x--;
					}
				}
				if (count == 1)
				{
					f5 << tempo << "\n";
				}
				if (count == 2)
				{
					f5 << futureclass << "\n";
					f5 << dob << "\n";
					f5 << gender << "\n";
					f5 << 1 << "\n";
					for (int i = 0;i < 15;i++)
						f4.ignore();
				}
			}
		}
		f4.close();
		f5.close();
		fstream newFile("student.txt");
		if (!newFile)
		{
			cout << "Cannot change Class." << endl;
			return;
		}
		newFile.close();
		if (remove("student.txt") == 0)
		{
			/*cout << "Changing Class..." << endl;*/
		}
		if (rename("temp_student.txt", "student.txt") == 0)
		{
			/*cout << "Successfully" << endl;*/
		}
		char temp1[100];
		ofstream fi("temp.txt");
		fi << "student-";
		fi << currentclass;
		fi << ".txt";
		fi.close();
		ifstream fo("temp.txt");
		fo >> temp1;
		fo.close();
		remove("temp.txt");
		ifstream f7(temp1);
		ofstream f6("temp_student.txt");
		if (!f7.is_open() || !f6.is_open())
		{
			cout << "Cannot change Class." << endl;
		}
		char temp2[100];
		char tempo1[100];
		int e;
		int cou = 0;
		f7 >> e;
		int g = e - 1;
		f6 << g << "\n";
		f7.ignore();
		while (f7.getline(temp2, 100))
		{
			f6 << temp2 << "\n";
			char linea1[100];
			_itoa(id, linea1, 10);
			if (!strcmp(temp2, linea1))
			{
				cou++;
				f7.getline(tempo1, 100);
				strcpy(tempo1, dob);
				int p = strlen(tempo1);
				for (int i = 0;i < p;i++)
				{
					if (tempo1[i] == ' ')
					{
						int j = 0;
						for (int j = i;j < p;j++)
						{
							tempo1[j] = tempo1[j + 1];
						}
						p--;
					}
				}
				if (cou == 1)
				{
					f6 << tempo1 << "\n";
				}
				if (cou == 2)
				{
					f6 << futureclass << "\n";
					f6 << dob << "\n";
					f6 << gender << "\n";
					f6 << 0 << "\n";
					for (int i = 0;i < 15;i++)
						f7.ignore();
				}
			}
		}
		f7.close();
		f6.close();
		fstream newFile1(temp1);
		if (!newFile1)
		{
			cout << "File cannot open" << endl;
			return;
		}
		newFile1.close();
		if (remove(temp1) == 0)
		{
			/*cout << "Processing changing" << endl;*/
		}
		if (rename("temp_student.txt", temp1) == 0)
		{
			/*cout << "Successfully" << endl;*/
		}
		char future[100]; ofstream fi1("temp.txt");	fi1 << "student-";	fi1 << futureclass;	fi1 << ".txt";	fi1.close();
		ifstream fo1("temp.txt");	fo1 >> future;	fo1.close();	remove("temp.txt");
		char cur[100];
		ofstream fi2("temp.txt");	fi2 << "student-";	fi2 << currentclass;	fi2 << ".txt";	fi2.close();
		ifstream fo2("temp.txt");	fo2 >> cur;	fo2.close();	remove("temp.txt");
		student c[100];
		int nol = 0;
		ifstream f12(cur);
		char cline[100];
		while (f12.getline(cline, 100))
		{
			nol++;
		}
		f12.close();
		ofstream f8("temp_student.txt");
		ifstream f9(cur);
		int index = 0;
		int flag = 0;
		int nuol = (nol - 1) / 8;
		char tr[100];
		f9.getline(tr, 100);
		for (int i = 0;i < nuol;i++)
		{
			f9.ignore();
			f9.getline(c[i].username, 101);
			f9.getline(c[i].password, 101);
			f9.getline(c[i].fullname, 101);
			f9 >> c[i].id;
			f9.ignore();
			f9.getline(c[i].classname, 11);
			f9.getline(c[i].dob, 101);
			f9 >> c[i].gender;
			f9 >> c[i].type;
		}

		for (int i = 0;i < nuol;i++)
		{
			if (id == c[i].id && !strcmp(fullname, c[i].fullname))
			{
				flag++;
				if (flag == 1)
				{
					index = i;
				}
			}
		}
		f9.close();
		ifstream f10(future);
		char line9[100];
		int num;
		f10 >> num;
		f10.ignore();
		if (id == c[index].id)
		{
			f8 << num + 1 << "\n";
			while (f10.getline(line9, 100))
			{
				f8 << line9 << "\n";
			}
			f8.close();
			f10.close();
			ofstream f11("temp_student.txt", ios::app);
			f11 << c[index].username << "\n";
			f11 << c[index].password << "\n";
			f11 << c[index].fullname << "\n";
			f11 << c[index].id << "\n";
			f11 << c[index].classname << "\n";
			f11 << c[index].dob << "\n";
			f11 << c[index].gender << "\n";
			f11 << 1 << "\n";
			f11.close();
		}
		f9.close();
		remove(future);
		rename("temp_student.txt", future);
		cout << endl;
		cout << "Changed Student's Class successfully!" << endl;
		std::system("pause");
		/*if (press == 1)
		{
			staffclass_func(a, idx);
		}*/
	/*}*/
	Menu_Staff_Class(a, idx);
}
void list_of_classes(staff a[], int& idx)
{
	cout << "List of classes: " << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	char line2[100];
	f.getline(line2, 100);
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	int press;
	cout << "Enter 1 to back: "; cin >> press;
	if (press == 1)
	{
		staffclass_func(a, idx);
	}
}
void list_of_student_in_class(staff a[], int& idx)
{
	char currentclass[100];
	cout << "Which class?";
	cout << endl;
	ifstream f("class.txt");
	char line1[100];
	int n;
	f >> n;
	while (f.getline(line1, 100))
	{
		cout << line1 << endl;
	}
	cout << "Enter class: "; cin >> currentclass;
	char temp[100];
	ofstream fi("temp.txt");
	fi << "student-";
	fi << currentclass;
	fi << ".txt";
	fi.close();
	ifstream fo("temp.txt");
	fo >> temp;
	fo.close();
	ifstream f2(temp);
	char line[100];
	while (f2.getline(line, 100))
	{
		cout << line << endl;
	}
	f2.close();
	remove("temp.txt");
	int press;
	cout << "Enter 1 to back: "; cin >> press;
	if (press == 1)
	{
		staffclass_func(a, idx);
	}
}

void academic_lecturer(lecturer b[], int& idx)
{
	int choice;
	cout << "Which types you want?" << endl;
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
	cout << "Which types you want?" << endl;
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
	fstream f;
	loadstudentarray(f, c, idx);
	cout << "ID: " << c[idx].id << endl;
	cout << "Full name: " << c[idx].fullname << endl;
	cout << "Date of birth: " << c[idx].dob << endl;
	cout << "Class: " << c[idx].classname << endl;
	cout << "Gender: " << c[idx].gender << endl;
	cout << "Type: " << c[idx].type << endl;
}
void view_profile_lecturer(lecturer b[], int& idx)
{
	fstream f;
	loadlecturerarray(f, b, idx);
	cout << "Full name: " << b[idx].fullname << endl;
	cout << "Date of birth: " << b[idx].dob << endl;
	cout << "Gender: " << b[idx].gender << endl;
	cout << "Type: " << b[idx].type << endl;
}
void view_profile_staff(staff a[], int& idx)
{
	int bsize = strlen(a[idx].fullname) + 20;
	fstream f;
	loadstaffarray(f, a, idx);
	std::system("cls");
	cout << "-Profile - Academic Staff-" << endl << endl;
	/*cout << "[Full name] " << a[idx].fullname << endl;
	cout << "[DoB] ";
	for (int i = 0; i < 10; i++) {
		if (i == 2 || i == 5) cout << "/";
		else cout << a[idx].dob[i];
	}
	cout << endl;
	cout << "[Gender] ";
	if (a[idx].gender == 0) cout << "Female";
	else cout << "Male";
	cout << endl;
	cout << "[Type] " << a[idx].type << endl;
	cout << endl;*/
	/*std::system("pause");
	Menu_Staff(a, idx);*/

	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < bsize; j++) {
				if (j == 0 || j == bsize - 1) {
					if (i == 0 || i == 8) {
						if (j == 0) cout << "[";
						else if (j == bsize - 1) cout << "]";
					}
					else cout << "|";
				}
				else cout << "-";
			}/*
			if (i != 0 && i != 8) cout << "|";*/
		} else {
			cout << "|";
			if (i == 1) {
				cout << " Full Name | " << a[idx].fullname;
				for (int j = 0;	j < bsize - 14 - strlen(a[idx].fullname) -1; j++) {
					cout << " ";
				}
				cout << "|";
			} else if (i == 3) {
				cout << " DoB       | ";
				for (int j = 0; j < strlen(a[idx].dob); j++) {
					if (j == 2 || j == 5) cout << "/";
					else cout << a[idx].dob[j];
				}
				for (int j = 0; j < bsize - 14 - strlen(a[idx].dob) - 1; j++) {
					cout << " ";
				}
				cout << "|";
			} else if (i == 5) {
				cout << " Gender    | ";
				char gentemp[2][7] = { "Female", "Male" };
				cout << gentemp[a[idx].gender];
				for (int j = 0; j < bsize - 14
					-strlen(gentemp[a[idx].gender]) - 1; j++) {
					cout << " ";
				}
				cout << "|";
			} else {
				cout << " Type      | " << a[idx].type;
				for (int j = 0; j < bsize - 15 - 1; j++) {
					cout << " ";
				}
				cout << "|";
			}
		}
		cout << endl;
	}
	cout << endl;
	std::system("pause");
	Menu_Staff(a, idx);
}

void changepassword_staff(staff a[], int& idx)
{
	std::system("cls");
	cout << "-Change password-" << endl << endl;
	int n;
	/*char currentusername[100];*/
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	cout << "[- Current Password -----]" << endl;
	cout << "> "; cin >> currentpass;
	while (strcmp(currentpass, a[idx].password))
	{
		cout << "Incorrect password." << endl;
		std::system("pause");
		std::system("cls");
		cout << "-Change password-" << endl << endl;
		cout << "[- Current Password -----]" << endl;
		cout << "> "; cin >> currentpass;
	}
	cout << "[- New Password ---------]" << endl;
	cout << "> "; cin >> newpass1;
	cout << "[- Confirm New Password -]" << endl;
	cout << "> "; cin >> newpass2;
	while (strcmp(newpass1, newpass2))
	{
		cout << "Passwords don't match." << endl;
		std::system("pause");
		std::system("cls");
		cout << "-Change password-" << endl << endl;
		cout << "[- Current Password -----]" << endl;
		cout << "> " << currentpass << endl;
		cout << "[- New Password ---------]" << endl;
		cout << "> "; cin >> newpass1;
		cout << "[- Confirm New Password -]" << endl;
		cout << "> "; cin >> newpass2;
	}
	/*cout << "Enter username to make sure: "; 
	cin >> currentusername;*/
	ifstream f1("staff.txt");
	if (!f1.is_open())
	{
		cout << "Cannot change password." << endl;
	} else {
		ofstream f2("temp_staff.txt");
		if (!f2.is_open()) {
			cout << "Cannot change password." << endl; 
		} else {
			char temp[100];
			char tempo[100];
			while (f1.getline(temp, 100))
			{
				f2 << temp << "\n";	
				if (!strcmp(temp, a[idx].username))
				{
					f1.getline(tempo, 100);
					strcpy(tempo, newpass1);
					strcpy(a[idx].password, newpass1);
					f2 << tempo << "\n";
				}
			}
			f2.close();
			/*fstream newFile("staff.txt");
			if (!newFile.is_open())
			{
				cout << "Cannot open file." << endl;
			} else {
				newFile.close();
			}*/
		}
		f1.close();
		if (remove("staff.txt") == 0)
		{
			cout << "Changing password..." << endl;
		}
		else cout << "Cannot change password." << endl;
		if (rename("temp_staff.txt", "staff.txt") == 0)
		{
			cout << "Password changed successfully!" << endl;
		}
		else cout << "Cannot change password." << endl;
	}
	std::system("pause");
	Menu_Staff(a, idx);
}
void changepassword_lecturer(lecturer b[], int idx)
{
	int n;
	char currentusername[100];
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	cout << "Enter your current password: ";
	cin >> currentpass;
	while (strcmp(currentpass, b[idx].password))
	{
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin >> currentpass;
	}
	cout << "Enter new password: ";
	cin >> newpass1;
	cout << "Enter new password again: ";
	cin >> newpass2;
	while (strcmp(newpass1, newpass2))
	{
		cout << "Unmatched. Try again." << endl;
		cout << "Enter new password: ";
		cin >> newpass1;
		cout << "Enter new password again: ";
		cin >> newpass2;
	}
	cout << "Enter username to make sure: "; cin >> currentusername;
	ifstream f1("lecturer.txt");
	ofstream f2("temp_lecturer.txt");
	if (!f1.is_open() || !f2.is_open())
	{
		cout << "Error opening files!" << endl;
	}
	char temp[100];
	char tempo[100];
	while (f1.getline(temp, 100))
	{
		f2 << temp << "\n";
		if (!strcmp(temp, b[idx].username))
		{
			f1.getline(tempo, 100);
			strcpy(tempo, newpass1);
			f2 << tempo << "\n";
		}
	}
	f1.close();
	f2.close();
	fstream newFile("lecturer.txt");
	if (!newFile)
	{
		cout << "File cannot open" << endl;
		return;
	}
	newFile.close();
	if (remove("lecturer.txt") == 0)
	{
		cout << "Processing changing" << endl;
	}
	if (rename("temp_lecturer.txt", "lecturer.txt") == 0)
	{
		cout << "Successfully" << endl;
	}
}
void changepassword_student(student c[], int idx)
{
	int n;
	char currentusername[100];
	char newpass1[100];
	char newpass2[100];
	char currentpass[100];
	cout << "Enter your current password: ";
	cin >> currentpass;
	while (strcmp(currentpass, c[idx].password))
	{
		cout << "Uncorrect password." << endl;
		cout << "Enter your current password: ";
		cin >> currentpass;
	}
	cout << "Enter new password: ";
	cin >> newpass1;
	cout << "Enter new password again: ";
	cin >> newpass2;
	while (strcmp(newpass1, newpass2))
	{
		cout << "Unmatched. Try again." << endl;
		cout << "Enter new password: ";
		cin >> newpass1;
		cout << "Enter new password again: ";
		cin >> newpass2;
	}
	cout << "Enter username to make sure: "; cin >> currentusername;
	ifstream f1("student.txt");
	ofstream f2("temp_student.txt");
	if (!f1.is_open() || !f2.is_open())
	{
		cout << "Error opening files!" << endl;
	}
	char temp[100];
	char tempo[100];
	int count = 0;
	while (f1.getline(temp, 100))
	{
		f2 << temp << "\n";
		if (!strcmp(temp, c[idx].username))
		{
			count++;
			if (count == 1)
			{
				f1.getline(tempo, 100);
				strcpy(tempo, newpass1);
				f2 << tempo << "\n";
			}
		}
	}
	f1.close();
	f2.close();
	fstream newFile("student.txt");
	if (!newFile)
	{
		cout << "File cannot open" << endl;
		return;
	}
	newFile.close();
	if (remove("student.txt") == 0)
	{
		cout << "Processing changing" << endl;
	}
	if (rename("temp_student.txt", "student.txt") == 0)
	{
		cout << "Successfully" << endl;
	}
	char tempq[100];
	ofstream fi("temp.txt");
	fi << "student-";
	fi << c[idx].classname;
	fi << ".txt";
	fi.close();
	ifstream fo("temp.txt");
	fo >> tempq;
	fo.close();
	remove("temp.txt");
	ifstream f3(tempq);
	ofstream f4("temp_student.txt");
	if (!f3.is_open() || !f4.is_open())
	{
		cout << "Error opening files!" << endl;
	}
	char temp1[100];
	char tempo1[100];
	int count1 = 0;
	while (f3.getline(temp1, 100))
	{
		f4 << temp1 << "\n";
		if (!strcmp(temp1, c[idx].username))
		{
			count1++;
			if (count1 == 1)
			{
				f3.getline(tempo1, 100);
				strcpy(tempo1, newpass1);
				f4 << tempo1 << "\n";
			}
		}
	}
	f3.close();
	f4.close();
	fstream newFile1(tempq);
	if (!newFile1)
	{
		cout << "File cannot open" << endl;
		return;
	}
	newFile1.close();
	if (remove(tempq) == 0)
	{
		cout << "Processing changing" << endl;
	}
	if (rename("temp_student.txt", tempq) == 0)
	{
		cout << "Successfully" << endl;
	}
}

void academic_staff(staff a[], int& idx)
{
	int choice;
	cout << "Which types you want?" << endl;
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
	switch (choice)
	{
		case 1:
		{
			staffclass_func(a, idx);
			break;
		}
		case 5:
		{
			staff_menu(a, idx);
			break;
		}
	}
}

void staff_menu(staff a[], int& idx)
{
	int choice;
	cout << endl;
	std::system("cls");
	cout << "-Select next option-" << endl;
	cout << "1. Academic" << endl;
	cout << "2. View profile" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Log out" << endl;
	cout << "> "; cin >> choice;
	while (choice < 0 || choice > 4)
	{
		cout << "Invalid input. Try again." << endl; 
		cout << "> "; cin >> choice;
	}
	std::system("cls");
	switch (choice) {
		case 1:
		{
			academic_staff(a, idx);
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
	cout << endl;
	cout << "Which types you want?" << endl;
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
		academic_lecturer(b, idx);
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
	cout << endl;
	cout << "Which types you want?" << endl;
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
		view_profile_student(c, idx);
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