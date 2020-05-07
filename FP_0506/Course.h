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

string GetFileName();
// Get the file name through the file's directory
// Ex: C:/Users/ADMIN/2019-2020-HK2-19CLC05-CS162-Student.txt

Student* GetStudent(ifstream& fin);
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

void GetCourse_DelStu(Student *&stuHead, int n);
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

bool CheckIn(Student*& stu);
// Student's check-in function

void RF_AStaff_AttList();
// Role Function of an Academic Staff

void RF_Lecturer();
// Role Function of a Lecturer

#endif