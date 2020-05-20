// ACADEMIC STAFF - COURSE

#include "Course.h"

//STUDENT FUNCTIONS
//======================================================================
StudentList* CreateStudentNode(ifstream& f)
{
	StudentList* temp;
	temp = new StudentList;
	char tmp[20] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
		'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', };
	f.ignore(100, '\n');
	f.getline(temp->data.ID, 10);
	f.getline(temp->data.Pwd, 20);
	f.getline(temp->data.Name, 30);
	f.getline(temp->data.MSSV, 10);
	f.getline(temp->data.Class, 10);
	f >> temp->data.DoB.Year;
	/*f.ignore(100, ' ');*/
	f >> temp->data.DoB.Month;
	/*f.ignore(100, ' ');*/
	f >> temp->data.DoB.Day;
	f.ignore(100, '\n');
	f >> temp->data.Status;
	f.ignore(100, '\n');

	temp->pNext = nullptr;
	return temp;
}

int StudentCount(StudentList* list)
{
	int cnt = 0;
	StudentList* cur = list;
	while (cur != nullptr)
	{
		cnt++;
		cur = cur->pNext;
	}
	return cnt;
}

void LoadStudentList(StudentList*& list, char* Class)
{
	StudentList* cur = list;
	ifstream f;
	char Link[256] = "Student-";
	strcat(Link, Class);
	strcat(Link, ".txt");
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot open file.\n";
		return;
	}
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		if (cur == nullptr)
		{
			StudentList* p = CreateStudentNode(f);
			list = p;
			cur = list;

		}
		else if (cur != nullptr)
		{
			StudentList* temp = CreateStudentNode(f);
			cur->pNext = temp;
			cur = cur->pNext;
		}
	}
	f.close();
}
//=======================================================================


// COURSE FUNCTIONS
//===============================================================================
void CreateAcaYear(char* AcaYear, char* Semester)
{
	ofstream fout;
	fout.open("Semester.txt");
	if (!fout.is_open())
	{
		cout << "Cannot create file.\n";
		return;
	}
	fout << 1 << endl;
	fout << AcaYear << endl;
	fout << Semester << endl;
	fout.close();
}

int char_to_int(char* s)
{
	int n = atoi(s);
	return n;
}


CourseList* LoadCourseNode(ifstream& f)   //CREATE A NODE OF COURSE
{

	char tmp[20] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
		'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', };
	CourseList* newCourse;
	newCourse = new CourseList;
	f >> newCourse->data.No;
	if (newCourse->data.No < 0) return nullptr;
	f.ignore(100, ',');
	f.get(newCourse->data.ID, 15, ',');
	f.ignore(100, ',');
	f.get(newCourse->data.Name, 100, ',');
	f.ignore(100, ',');
	f.get(newCourse->data.Class, 10, ',');
	f.ignore(100, ',');
	f.get(newCourse->data.LecturerUser, 15, ',');
	f.ignore(100, ',');
	f.get(newCourse->data.LecturerName, 30, ',');
	f.ignore(100, ',');
	f.get(newCourse->data.LecturerDegree, 20, ',');
	f.ignore(100, ',');
	f >> newCourse->data.LecturerGender;
	f.ignore(100, ',');

	f.get(tmp, 20, ',');
	//cout << "word: " << tmp << endl;
	char* w = strtok(tmp, "/");
	//cout << "word: " << w << endl;
	newCourse->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.StartDate.Year = char_to_int(w);


	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	//cout << "tmp:  " << tmp << endl;

	w = strtok(tmp, "/");
	//cout << "word: " << w << endl;
	newCourse->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.EndDate.Year = char_to_int(w);

	f.ignore(256, ',');
	f.get(newCourse->data.DoW, 10, ',');

	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	newCourse->data.StartHour.h = char_to_int(tmp);

	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	newCourse->data.StartHour.m = char_to_int(tmp);

	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	newCourse->data.EndHour.h = char_to_int(tmp);

	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	//cout << "word: " << tmp << endl;
	newCourse->data.EndHour.m = char_to_int(tmp);

	f.ignore(256, ',');
	f.get(newCourse->data.Room, '\n');

	newCourse->pNext = nullptr;
	return newCourse;
}

void LoadCourses_csvfile(char* Link, CourseList*& list)
{
	ifstream f;
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Find cannot found.\n";
		return;
	}
	else {

		f.ignore(256, '\n');
		CourseList* cur = nullptr;

		if (list == nullptr)
		{
			list = LoadCourseNode(f);
			cur = list;
		}
		while (!f.eof())
		{
			if (cur != nullptr)
			{

				CourseList* temp = LoadCourseNode(f);
				cur->pNext = temp;
				cur = cur->pNext;
			}
		}
		f.close();
	}

}

int CountCourse(CourseList* list) {
	int cnt = 0;
	CourseList* cur = list;
	while (cur != nullptr)
	{
		cnt++;
		cur = cur->pNext;
	}
	return cnt;
}


void Create_Course_Student(CourseList* list, char* AcaYear, char* Semester, char* Class)   // CREATE COURSE FILE WHICH ALLOWS STUDENT MANAGEMENT
{
	StudentList* st_list = nullptr;
	LoadStudentList(st_list, Class);
	char Link[256];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, "-");
	strcat(Link, list->data.ID);
	strcat(Link, "-");
	strcat(Link, "Student.txt");
	ofstream f;
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot create file\n";
		return;
	}
	f << StudentCount(st_list);
	StudentList* cur = st_list;
	while (cur != nullptr)
	{
		f << endl;
		f << st_list->data.ID << endl;
		f << st_list->data.Pwd << endl;
		f << st_list->data.Name << endl;
		f << st_list->data.DoB.Year << " " << st_list->data.DoB.Month << " " << st_list->data.DoB.Day << endl;
		f << st_list->data.Class << endl;
		f << st_list->data.Status << endl;
		f << -1 << endl;    //midterm
		f << -1 << endl;	//final
		f << -1 << endl;	//bonus
		f << -1 << endl;	//total
		Date tmp_day = list->data.StartDate;
		Hour Start_Hour = list->data.StartHour;
		Hour End_Hour = list->data.EndHour;
		for (int i = 0; i < 10; i++)
		{
			f << tmp_day.Year << " " << tmp_day.Month << " " << tmp_day.Day << " " << Start_Hour.h
				<< " " << Start_Hour.m << " " << End_Hour.h << " " << End_Hour.m << " " << -1 << endl;
			tmp_day = PlusDay(tmp_day, 7);   // change day to next week date
		}
		f << "-";
		cur = cur->pNext;
	}


}

void Save_Course_Stu_List(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	CourseList* cur = list;
	while (cur != nullptr)
	{
		Create_Course_Student(list, AcaYear, Semester, Class);
		cur = cur->pNext;
	}
}

void SaveSchedule(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + strlen(Class) + 4];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	ofstream f;
	f.open(Link);
	if (!f.is_open()) {
		cout << "Cannot create file.\n";
		return;
	}
	else
	{
		int cnt = CountCourse(list);
		f << cnt << endl;
		CourseList* cur = list;
		while (cur != nullptr) {
			f << endl;
			f << cur->data.ID << endl;
			f << cur->data.Name << endl;
			f << cur->data.Class << endl;
			f << cur->data.LecturerUser << endl;
			f << cur->data.LecturerName << endl;
			f << cur->data.LecturerDegree << endl;
			f << cur->data.LecturerGender << endl;
			f << cur->data.StartDate.Year << " " << cur->data.StartDate.Month << " " << cur->data.StartDate.Day << endl;
			f << cur->data.EndDate.Year << " " << cur->data.EndDate.Month << " " << cur->data.EndDate.Day << endl;
			f << cur->data.DoW << endl;
			f << cur->data.StartHour.h << ":" << cur->data.StartHour.m << endl;
			f << cur->data.EndHour.h << ":" << cur->data.EndHour.m << endl;
			f << cur->data.Room << endl;
			cur = cur->pNext;
		}
		f.close();
	}
}

void ImportCourses(char* AcaYear, char* Semester)    // 3.2 import courses and save schedule
{
	CourseList* list;
	char temp[256], * Class, * Link;
	cout << "Enter class: "; cin.getline(temp, 256, '\n');
	Class = new char[strlen(temp) + 1];
	strcpy_s(Class, strlen(temp) + 1, temp);
	temp[0] = 0;
	cout << "Enter Link: "; cin.getline(temp, 256, '\n');
	Link = new char[strlen(temp) + 1];
	strcpy_s(Link, strlen(temp) + 1, temp);
	LoadCourses_csvfile(Link, list);
	SaveSchedule(list, AcaYear, Semester, Class);
	Save_Course_Stu_List(list, AcaYear, Semester, Class);
}

void CoursesManagement()
{
	system("cls");
	char* AcaYear, * Semester;			//  INPUT ACADEMIC YEAR AND SEMESTER
	char temp[256];
	cout << "Enter Academic year: "; cin.getline(temp, 256, '\n');
	AcaYear = new char[strlen(temp) + 1];
	strcpy_s(AcaYear, strlen(temp) + 1, temp);
	temp[0] = 0;
	cout << "Enter Semester: "; cin.getline(temp, 256, '\n');
	Semester = new char[strlen(temp) + 1];
	strcpy_s(Semester, strlen(temp) + 1, temp);
	CreateAcaYear(AcaYear, Semester);		// SAVE ACADEMIC YEAR AND SEMESTER INTO FILE 
	ImportCourses(AcaYear, Semester);

}

CourseList* CreateCourseNode()  // Create Course Node by typing in 
{
	CourseList* newCourse;
	newCourse = new CourseList;
	char temp[256];
	cout << "Enter course's ID: ";
	cin.getline(newCourse->data.ID, 15);
	cout << "Enter course's name: ";
	cin.getline(newCourse->data.Name, 100);
	cout << "Enter class: ";
	cin.getline(newCourse->data.Class, 10);
	cout << "Enter Lecturer user: ";
	cin.getline(newCourse->data.LecturerUser, 15);

	cout << "Enter start date (dd/mm/yyyy): ";
	cin.getline(temp, 256);
	char* w = strtok(temp, " ");
	newCourse->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter end date (dd/mm/yyyy): ";
	cin.getline(temp, 256);
	w = strtok(temp, " ");
	newCourse->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter Day of week: ";
	cin.getline(newCourse->data.DoW, 10);

	cout << "Enter start hour (hh:mm): ";
	cin.getline(temp, 256);
	w = strtok(temp, " ");
	newCourse->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartHour.m = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter end hour (hh:mm): ";
	cin.getline(temp, 256);
	w = strtok(temp, " ");
	newCourse->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndHour.m = char_to_int(w);

	cout << "Enter room: ";
	cin.getline(newCourse->data.Room, 10);

	newCourse->pNext = nullptr;
	return newCourse;
}

CourseList* LoadCourseNode_txtfile(ifstream& f)
{
	f.ignore(256, '\n');
	char tmp[20] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
		'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', };
	CourseList* newCourse;
	newCourse = new CourseList;
	f.getline(newCourse->data.ID, 15);
	f.getline(newCourse->data.Name, 100);
	f.getline(newCourse->data.Class, 10);
	f.getline(newCourse->data.LecturerUser, 15);
	f.getline(newCourse->data.LecturerName, 30);
	f.getline(newCourse->data.LecturerDegree, 20);
	f >> newCourse->data.LecturerGender;
	f.ignore(256, '\n');
	f.getline(tmp, 20);
	//cout << "word: " << tmp << endl;
	char* w = strtok(tmp, " ");
	//cout << "word: " << w << endl;
	newCourse->data.StartDate.Year = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartDate.Day = char_to_int(w);

	f.getline(tmp, 20);
	w = strtok(tmp, " ");
	newCourse->data.EndDate.Year = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndDate.Day = char_to_int(w);

	f.getline(newCourse->data.DoW, 10);

	f.getline(tmp, 20);
	w = strtok(tmp, " :");
	newCourse->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartHour.m = char_to_int(w);

	f.getline(tmp, 20);
	w = strtok(tmp, " :");
	newCourse->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndHour.m = char_to_int(w);

	f.get(newCourse->data.Room, '\n');

	newCourse->pNext = nullptr;
	return newCourse;
}

void LoadCourses_txtfile(char* Link, CourseList*& list)
{
	CourseList* tmp, * cur = list;
	ifstream f;
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot open file" << endl;
		return;
	}
	else {
		int n;
		f >> n;
		while (!f.eof())
		{
			if (cur == nullptr) cur = LoadCourseNode_txtfile(f);
			else if (cur != nullptr) {
				tmp = LoadCourseNode_txtfile(f);
				cur->pNext = tmp;
				cur = cur->pNext;
			}
		}
		f.close();
	}
}

void AddCourse(char* AcaYear, char* Semester)
{
	CourseList* list;
	char Class[10];
	cout << "Enter Class: ";
	cin.getline(Class, 10);
	char Link[256];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	LoadCourses_txtfile(Link, list);
	int cnt = CountCourse(list);
	CourseList* cur = list;
	while (cur->pNext != nullptr) cur = cur->pNext;
	CourseList* p = CreateCourseNode();
	cur->pNext = p;
	p->data.No = cnt + 1;
	SaveSchedule(list, AcaYear, Semester, Class);
	Save_Course_Stu_List(list, AcaYear, Semester, Class);

}
//=========================================================================================



//   DATE HANDLE FUNCTION
//=====================================================================================

bool IsLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;
	else return false;
}

int DayInMonth(int Month, int Year) {
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) return 31;
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) return 30;
	if (Month == 2 && IsLeapYear(Year) == true) return 29;
	else return 28;
}

Date PlusDay(Date init_Date, int plus_day) {
	Date temp = init_Date;
	temp.Day += plus_day;
	while (temp.Day > 365)
	{
		temp.Day -= 365;
		if (IsLeapYear(temp.Year)) temp.Day--;
		temp.Year++;
	}
	while (temp.Day > DayInMonth(temp.Month, temp.Year))
	{
		if (temp.Month == 12)
		{
			temp.Day -= 31;
			temp.Month = 1;
			temp.Year++;
			continue;
		}
		temp.Day -= DayInMonth(temp.Month, temp.Year);
		temp.Month++;
	}
	return temp;


	/*if (IsLeapYear(temp.Year))
	{
		while (temp.Day > 366)
		{
			temp.Day -= 366;
			temp.Year++;
		}
		while (temp.Day > DayInMonth(temp.Month,temp.Year))
		{
			temp.Day -= DayInMonth(temp.Month,temp.Year);
			temp.Month++;
		}
	}
	else {


	}*/

}