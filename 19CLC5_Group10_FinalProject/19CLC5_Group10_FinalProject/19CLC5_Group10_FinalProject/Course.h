// COURSE HEADER

#ifndef _COURSE_H_
#define _COURSE_H_
#define FILELINES 20

#include "AttendanceList.h"

struct Student_Course {
	int no;
	int id, by, bm, bd, active;
	string name, pass, clss;
	float sc_mid, sc_fin, sc_lab, sc_ave; // score
	// midterm, final, lab, average
	AttDay* dHead;
	Student_Course* stuNext;
};

struct Date {
	int Day;
	int Month;
	int Year;
};

struct Hour {
	int h;  //hour
	int m;  //minute
};

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

//A.STAFF & LECTURER (Course.cpp)
//==========================================================
/////////////////////////////////////////////////////////////


string GetFileName(string Sem, char* Link);
// Get the file name through the file's directory
// Ex: C:/Users/ADMIN/2019-2020-HK2-19CLC05-CS162-Student.txt

Student_Course* GetStudentFile(ifstream& fin);
// Get all information of a student from a Course .txt file

void ShowAttDay(Student_Course* stu);
// Get all attendance days of a student

void ShowCourse(Student_Course* stuHead, int n);
// Print out a Course

void ShowAttList(Student_Course* stuHead, int n);
// Print out attendance list of a Course

bool ExportAttList(Student_Course* stuHead, int n, string fName);
// Export the attendance list to a .csv file

void EditAtt(Student_Course*& stuHead, int n, string fName);
// Edit an attendance day's status

void SaveEdit(Student_Course* stuHead, int n, string fName);
// Save the attendance edit to the 

void GetCourse_DelStu(Student_Course*& stuHead, int& n);
// Free heap memory used to store students' data

bool GetCourse(Student_Course*& stuHead, int& n, string fName);
// View a Course

void ShowScoreBoard(Student_Course* stuHead, int n);
// Show scoreboard of a course

void ShowScore(Student_Course* stu);
// Show score of a Student_Course

void EditScore(Student_Course*& stuHead, int n, string fName);
// Edit score of a Student_Course

bool ImportScoreBoard(Student_Course*& stuHead, int n, string fName);
// Import a Course's Scoreboard

void ShowCourseList(string Sem, char* Link);
// Show Semester's list of Courses



//STUDENT (Student.cpp)
//==========================================================
////////////////////////////////////////////////////////////


bool CheckIn(Student_Course*& stu);
// Student's Check-in function

void CheckInRes(Student_Course* stu);
// Check if the Student is present or not on the last day

Student_Course* GetStudent(Student_Course* stuHead, int id);
// Get Student using a provided ID



//FUNCTION FOR EACH ROLE (RoleFunction.cpp)
//==========================================================
////////////////////////////////////////////////////////////


void RF_AStaff_AttList(string Sem, char* Link);
// Role Function of an Academic Staff

void RF_Lecturer(string Sem, char* Link);
// Role Function of a Lecturer

void RF_Student(string Sem, char* Link);
// Role Function of a Student

#endif