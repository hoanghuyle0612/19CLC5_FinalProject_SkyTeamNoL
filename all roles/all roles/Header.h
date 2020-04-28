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
	int sex;
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
void changepassword_staff(staff a[], int& idx);
void changepassword_lecturer(lecturer b[], int& idx);
void changepassword_student(student c[], int& idx);
void logout();
void staff_menu(staff a[], int& idx);
void lecturer_menu(lecturer b[], int& idx);
void student_menu(student c[], int& idx);
#endif
