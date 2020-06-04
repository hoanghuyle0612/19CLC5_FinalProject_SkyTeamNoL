#define _CRT_SECURE_NO_WARNINGS
#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

// DATE STRUCT
//================================
struct Date {
	int Day;
	int Month;
	int Year;
};

struct Hour {
	int h;  //hour
	int m;  //minute
};
//================================
struct lecturer {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	char degree[20];
	int gender;

};
struct LecturerList {
	lecturer data;
	LecturerList* pNext;
};

//STUDENT STRUCT
//===========================================
struct Student {				
	char ID[10];
	char Pwd[20];
	char Name[30];
	char MSSV[10];
	Date DoB;
	char Class[10];
	int Gender;
	int Status; 
};				

struct StudentList {
	Student data;
	StudentList* pNext;
};
//=============================================



struct Course {
	int No;
	char ID[15];
	char Name[100];
	char Class[10];
	char LecturerUser[15];
	char LecturerName[30];
	char LecturerDegree[20];
	int LecturerGender;
	Date StartDate;
	Date EndDate;
	char DoW[10];  //Day of week
	Hour StartHour;
	Hour EndHour;
	char Room[10];
};

struct CourseList {
	Course data;
	CourseList* pNext;
};

// COURSE FUNCTIONS
//====================================================================================
void CoursesManagement();
void CreateAcaYear(char* AcaYear,char* Semester);
CourseList* LoadCourseNode(ifstream& f);
CourseList* CreateCourseNode();
void LoadCourses_csvfile(char* Link, CourseList*& list);
int CountCourse(CourseList* list);
void SaveSchedule(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Create_Course_Student(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Save_Course_Stu_List(CourseList* list, char* AcaYear, char* Semester, char* Class);
void ImportCourses(char* AcaYear, char* Semester);
void AddCourse(char* AcaYear, char* Semester);
void LoadCourses_txtfile(char* Link, CourseList*& list);
void delete_CourseList(CourseList*& list);
void EditCourse(char* AcaYear, char* Semester);
CourseList* FindCourse(CourseList* list, char* Course);
void RemoveStudentFromCourse(char* AcaYear, char* Semeste,char* Class);
void RemoveACourse(char* AcaYear, char* Semester, char* Class);
char* CreateLinkCourse_Stu(char* AcaYear, char* Semester, char* Class, char* CourseID);
void AddAStudentToCourse(char* AcaYear, char* Semester);



void CreateLecturer();

//=====================================================================================


//  DATE FUNCTION
//===============================================
bool IsLeapYear(int year);
int DayInMonth(int Month, int Year);
Date PlusDay(Date init_Date, int plus_day);
//==============================================
StudentList* CreateStudentNode(ifstream& f);
void LoadStudentList(StudentList*& list, char* Class);
int StudentCount(StudentList* list);
void delete_StudentList(StudentList*& list);
StudentList* Load_Stu_Node_FromCourse(ifstream& f);
StudentList* FindStudent(char* StudentID);

LecturerList* LoadLecturerNode(ifstream& f);
void LoadLecturerList(LecturerList*& list);
void delete_LecturerList(LecturerList*& list);
LecturerList* FindLecturer(LecturerList* list, char* username);
int char_to_int(char* s);



#endif