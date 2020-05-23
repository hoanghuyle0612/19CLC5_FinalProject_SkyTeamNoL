// LOGIN HEADER

#include "General.h"

struct staff {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int gender;
	int type;
};

struct lecturer {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int gender;
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

void loadstaff(fstream& f, staff& a);
void loadstaffarray(fstream& f, staff a[], int& n);
void loadlecturer(fstream& f, lecturer& b);
void loadlecturerarray(fstream& f, lecturer b[], int& n);
void loadstudent(fstream& f, student& c);
void loadstudentarray(fstream& f, student c[], int& n);
void login();
void main_menu();
void import(staff a[], int& idx);
void add_a_new_student(staff a[], int& idx);
void edit_existing_student(staff a[], int& idx);
void remove_a_student(staff a[], int& idx);
void change_student_classA_to_B(staff a[], int& idx);
void list_of_classes(staff a[], int& idx);
void list_of_student_in_class(staff a[], int& idx);
void academic_staff(staff a[], int& idx);
void academic_lecturer(lecturer b[], int& idx);
void academic_student(student c[], int& idx);
void view_profile_student(student c[], int& idx);
void view_profile_lecturer(lecturer b[], int& idx);
void view_profile_staff(staff a[], int& idx);
void changepassword_staff(staff a[], int& idx);
void changepassword_lecturer(lecturer b[], int idx);
void changepassword_student(student c[], int idx);
void logout();
void staff_menu(staff a[], int& idx);
void lecturer_menu(lecturer b[], int& idx);
void student_menu(student c[], int& idx);


void Menu_Staff(staff a[], int& idx);
void Menu_Staff_Class(staff a[], int& idx);
void Draw_WelCome(char name[], int gender);