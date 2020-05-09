// COURSE HEADER

#ifndef _COURSE_H_
#define _COURSE_H_
#define FILELINES 20

#include "AttendanceList.h"

struct Student {
	int no;
	int id, by, bm, bd, active;
	string name, pass, clss;
	float sc_mid, sc_fin, sc_lab, sc_ave; // score
	// midterm, final, lab, average
	AttDay* dHead;
	Student* stuNext;
};



 //A.STAFF & LECTURER (Course.cpp)
 //==========================================================
/////////////////////////////////////////////////////////////


string GetFileName(string Sem, char * Link);
// Get the file name through the file's directory
// Ex: C:/Users/ADMIN/2019-2020-HK2-19CLC05-CS162-Student.txt

Student* GetStudentFile(ifstream& fin);
// Get all information of a student from a Course .txt file

void ShowAttDay(Student* stu);
// Get all attendance days of a student

void ShowCourse(Student *stuHead, int n);
// Print out a Course

void ShowAttList(Student* stuHead, int n);
// Print out attendance list of a Course

bool ExportAttList(Student* stuHead, int n, string fName);
// Export the attendance list to a .csv file

void EditAtt(Student*& stuHead, int n, string fName);
// Edit an attendance day's status

void SaveEdit(Student* stuHead, int n, string fName);
// Save the attendance edit to the 

void GetCourse_DelStu(Student *&stuHead, int &n);
// Free heap memory used to store students' data

bool GetCourse(Student *&stuHead, int &n, string fName);
// View a Course

void ShowScoreBoard(Student* stuHead, int n);
// Show scoreboard of a course

void ShowScore(Student* stu);
// Show score of a Student

void EditScore(Student*& stuHead, int n, string fName);
// Edit score of a Student

bool ImportScoreBoard(Student*& stuHead, int n, string fName);
// Import a Course's Scoreboard

void ShowCourseList(string Sem, char* Link);
// Show Semester's list of Courses



//STUDENT (Student.cpp)
//==========================================================
////////////////////////////////////////////////////////////


bool CheckIn(Student*& stu);
// Student's Check-in function

void CheckInRes(Student* stu);
// Check if the Student is present or not on the last day

Student* GetStudent(Student* stuHead, int id);
// Get Student using a provided ID



//FUNCTION FOR EACH ROLE (RoleFunction.cpp)
//==========================================================
////////////////////////////////////////////////////////////


void RF_AStaff_AttList(string Sem, char * Link);
// Role Function of an Academic Staff

void RF_Lecturer(string Sem, char* Link);
// Role Function of a Lecturer

void RF_Student(string Sem, char* Link);
// Role Function of a Student

#endif