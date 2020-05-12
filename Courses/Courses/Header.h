#define _CRT_SECURE_NO_WARNINGS
#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
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


//STUDENT STRUCT
//===========================================
struct Student {				
	char ID[10];
	char Pwd[20];
	char Name[30];
	char MSSV[10];
	Date DoB;
	char Class[10];
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
CourseList* CreateCourseNode(ifstream& f);
void LoadCourses(char* Link, CourseList*& list);
int CountCourse(CourseList* list);
void SaveSchedule(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Create_Course_Student(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Save_Course_Stu_List(CourseList* list, char* AcaYear, char* Semester, char* Class);
void ImportCourses(char* AcaYear, char* Semester);
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

int char_to_int(char* s);
#endif