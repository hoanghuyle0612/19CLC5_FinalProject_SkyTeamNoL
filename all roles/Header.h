// Header.h
#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct staff {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int sex;
	int type;
};
struct lecturer {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int sex;
	int type;
};
struct student {
	char username[100];
	char password[100];
	char fullname[100];
	char classname[10];
	int id;
	char dob[20];
	int gender;
	int type;
};
//struct nodestaff
//{
//	staff data;
//	struct NODE* next;
//};
//struct nodelecturer
//{
//	lecturer data;
//	struct NODE* next;
//};

//struct nodestudent
//{
//	student data;
//	struct NODE* next;
//};
void loadstaff(ifstream& f, staff& a);
void loadstaffarray(ifstream& f, staff a[], int& n);
void loadlecturer(ifstream& f, lecturer& b);
void loadlecturerarray(ifstream& f, lecturer b[], int& n);
void loadstudent(ifstream& f, student& c);
void loadstudentarray(ifstream& f, student c[], int& n);
void login();
void main_menu();
void academic_staff(staff a[], int& idx);
void academic_lecturer(lecturer b[], int& idx);
void academic_student(student c[], int& idx);
void view_profile_student(student c[], int& idx);
void view_profile_lecturer(lecturer b[], int& idx);
void view_profile_staff(staff a[], int& idx);
void savenewpassword_staff(ofstream& f, staff a[], int idx);
void savenewpassword_lecturer(ofstream& f, lecturer b[], int idx);
void savenewpassword_student(ofstream& f, student c[], int idx);
void changepassword_staff();
void changepassword_lecturer(lecturer b[], int& idx);
void changepassword_student(student c[], int& idx);
void logout();
void staff_menu(staff a[], int& idx);
void lecturer_menu(lecturer b[], int& idx);
void student_menu(student c[], int& idx);
#endif
char line9[100];
int num;
f10 >> num;
f10.ignore();
f8 << num + 1 << "\n";
while (f10.getline(line9, 100))
{
	f8 << line9 << "\n";
}
f8.close();
f10.close();
int index = 0;
ofstream f11("temp_student.txt", ios::app);
f11 << id << "\n";
char line10[100];
for (int i = 0;i < num;i++)
{
	f9.ignore();
	f9.getline(c[i].username, 100);
	f9.getline(c[i].password, 100);
	f9.getline(c[i].fullname, 100);
	f9 >> c[i].id;
	f9.ignore();
	f9.getline(c[i].classname, 100);
	f9.getline(c[i].dob, 100);
	f9 >> c[i].gender;
	f9 >> c[i].type;
}
while (f9.getline(line10, 100))
{
	char line11[100];
	itoa(id, line11, 10);
	if (!strcmp(line10, line11))
	{
		for (int i = 0;i < num;i++)
		{
			char line12[100];
			itoa(c[i].id, line12, 10);
			if (!strcmp(line10, line12))
			{
				index = i;
			}
		}
	}
}
f11 << c[index].username << "\n";
f11 << c[index].password << "\n";
f11 << c[index].fullname << "\n";
f11 << c[index].id << "\n";
f11 << c[index].classname << "\n";
f11 << c[index].dob << "\n";
f11 << c[index].gender << "\n";
f11 << 1 << "\n";
f11.close();
f9.close();
remove(temp3);
rename("temp_student.txt", temp3);