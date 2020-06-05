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

struct CourseSchedule {
	string id, name, clss, lecturer, dow, room, lecid;
	int sd, sm, sy, ed, em, ey, sHr, sMin, eHr, eMin;
	CourseSchedule* cNext;
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
	int Status, Gender;
};

struct StudentList {
	Student data;
	StudentList* pNext;
};

struct Lecturer {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	char degree[20];
	int gender;
};

struct LecturerList {
	Lecturer data;
	LecturerList* pNext;
};

// COURSE FUNCTIONS
//====================================================================================
//void CoursesManagement();
//void CreateAcaYear(char* AcaYear, char* Semester);
CourseList* LoadCourseNode(ifstream& f);
CourseList* CreateCourseNode();
void LoadCourses_csvfile(char* Link, CourseList*& list);
int CountCourse(CourseList* list);
void SaveSchedule(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Create_Course_Student(CourseList* list, char* AcaYear, char* Semester, char* Class);
void Save_Course_Stu_List(CourseList* list, char* AcaYear, char* Semester, char* Class);
void ImportCourses(char* AcaYear, char* Semester);
void AddCourse(char* AcaYear, char* Semester);
void EditCourse(char* AcaYear, char* Semester);
void RemoveCourse(char* AcaYear, char* Semester);
void LoadCourses_txtfile(char* Link, CourseList*& list);
CourseList* FindCourse(CourseList* list, char* Course, char *Class);
LecturerList* FindLecturer(LecturerList* list, char* username);
void LoadLecturerList(LecturerList*& list);
void delete_CourseList(CourseList*& list);
void delete_LecturerList(LecturerList*& list);
//=====================================================================================


//  ACADEMIC YEAR FUNCTION
//===============================================
void SetColor(int color[], int i);
void CreateAcaYear();


//  COURSE STUDENT FUNCTION
//===============================================
void AddAStudentToCourse(char* AcaYear, char* Semester);
void RemoveStudentFromCourse(char* AcaYear, char* Semester);
//===============================================


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


void delete_StudentList(StudentList*& list);


//A.STAFF & LECTURER (Course.cpp)
//==========================================================
/////////////////////////////////////////////////////////////


string GetFileName(string Sem, char* Link);
// Get the file name through the file's directory
// Ex: C:/Users/ADMIN/2019-2020-HK2-19CLC05-CS162-Student.txt

int CourseAttDay(ifstream& fin);
// Get total days of a course

Student_Course* GetStudentFile(ifstream& fin, int n);
// Get all information of a student from a Course .txt file

void ShowAttDay(Student_Course* stu, int ADNo);
// Get all attendance days of a student

void ShowCourse(Student_Course* stuHead, int n);
// Print out a Course

void ShowAttList(Student_Course* stuHead, int n, int ADNo);
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

void ShowScoreSolo(Student_Course* stu);
// Show score of one Student_Course only

void EditScore(Student_Course*& stuHead, int n, string fName);
// Edit score of a Student_Course

bool ImportScoreBoard(Student_Course*& stuHead, int n, string fName);
// Import a Course's Scoreboard

void ShowCourseList(string Sem, char* Link);
// Show Semester's list of Courses

CourseSchedule* GetCourseSchedule(ifstream& fin);
// Get Course

void DrawScheduleCourse(CourseSchedule* crs);
// Draw Course for Schedule

void ShowSchedule(string Sem, char* Link, int id);
// Show Student's Schedule

void DeleteScheduleList(CourseSchedule*& cHead, int n);
// Delete Schedule List

void ShowCourseListLec(string Sem, char* Link, string lecid);
// Show List of Courses of a Lecturer

//STUDENT (Student.cpp)
//==========================================================
////////////////////////////////////////////////////////////


bool CheckIn(Student_Course*& stu);
// Student's Check-in function

void CheckInRes(Student_Course* stu);
// Check if the Student is present or not on the last day

Student_Course* GetStudent(Student_Course* stuHead, int id);
// Get Student using a provided ID


// MENU FUNCTIONS
//==========================================

void Menu_EditScore(Student_Course*& stu, int n);

void Advance_ShowScoreBoard(string YearSem);

void Advance_ExportScoreBoard(string YearSem);

void Advance_ImportScoreBoard(string YearSem);

void Advance_EditScore(string YearSem);

void Advance_ShowAttList(string YearSem);

void Advance_ExportAttList(string YearSem);

void Advance_EditAtt(string YearSem);

void Advance_ShowCourse(string YearSem);

void Advance_CheckIn(string YearSem, int id);

void Advance_CheckInRes(string YearSem, int id);

void Advance_StuShowScore(string YearSem, int id);

#endif