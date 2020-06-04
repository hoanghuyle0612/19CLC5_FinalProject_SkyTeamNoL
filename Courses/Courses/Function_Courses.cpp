#include "Header.h"

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
	f.getline(tmp, 21);
	char* w = strtok(tmp, " /");
	temp->data.DoB.Month = char_to_int(w);
	w = strtok(NULL, " /");
	temp->data.DoB.Day = char_to_int(w);
	w = strtok(NULL, " \n");
	temp->data.DoB.Year = char_to_int(w);
	f >> temp->data.Gender;
	f.ignore(100, '\n');
	f >> temp->data.Status;


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

void LoadStudentList(StudentList*& list,char* Class)
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
		else if(cur!=nullptr)
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
	char* w = strtok(tmp, " /");
	//cout << "word: " << w << endl;
	newCourse->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, " /");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.StartDate.Year = char_to_int(w);


	f.ignore(256, ',');
	f.get(tmp, 20, ',');
	//cout << "tmp:  " << tmp << endl;

	w = strtok(tmp, "/");
	//cout << "word: " << w << endl;
	newCourse->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, " ");
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

void LoadCourses_csvfile(char* Link,CourseList*& list)
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


void Create_Course_Student(CourseList* list,char* AcaYear, char* Semester,char* Class)   // CREATE COURSE FILE WHICH ALLOWS STUDENT MANAGEMENT
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

void Save_Course_Stu_List(CourseList* list,char* AcaYear,char* Semester,char* Class)
{
	CourseList* cur = list;
	while (cur != nullptr)
	{
		Create_Course_Student(cur, AcaYear, Semester, Class);
		cur = cur->pNext;
	}
}

void SaveSchedule(CourseList* list,char* AcaYear,char* Semester,char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + strlen(Class) + 4];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	cout << Link << endl;
	ofstream f;
	f.open(Link);
	if (!f.is_open()) {
		cout << "Cannot create file.\n";
		return;
	} 
	else
	{
		int cnt = CountCourse(list);
		f << cnt;
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
	cout << "Enter class: "; cin.getline(temp, 257, '\n');
	Class = new char[strlen(temp) + 1];
	strcpy_s(Class, strlen(temp) + 1, temp);
	temp[0] = 0;
	cout << "Enter Link: "; cin.getline(temp, 257, '\n');
	Link = new char[strlen(temp) + 1];
	strcpy_s(Link, strlen(temp) + 1, temp);
	LoadCourses_csvfile(Link,list);
	SaveSchedule(list, AcaYear, Semester, Class);
	Save_Course_Stu_List(list, AcaYear, Semester, Class);
}

void CoursesManagement()
{
	system("cls");
	char* AcaYear, * Semester;			//  INPUT ACADEMIC YEAR AND SEMESTER
	char temp[256];
	cout << "Enter Academic year: "; cin.getline(temp, 257, '\n');
	AcaYear = new char[strlen(temp) + 1];
	strcpy_s(AcaYear, strlen(temp) + 1, temp);
	temp[0] = 0;
	cout << "Enter Semester: "; cin.getline(temp, 257, '\n');
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
	cin.getline(temp,256);
	char* w = strtok(temp, " /");
	newCourse->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, " /");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter end date (dd/mm/yyyy): "; 
	cin.getline(temp,256);
	w = strtok(temp, " /");
	newCourse->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, " /");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter Day of week: ";
	cin.getline(newCourse->data.DoW, 10);

	cout << "Enter start hour (hh:mm): ";
	cin.getline(temp, 256);
	w = strtok(temp, " :");
	newCourse->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartHour.m = char_to_int(w);
	temp[0] = '\0';

	cout << "Enter end hour (hh:mm): ";
	cin.getline (temp, 256);
	w = strtok(temp, " :");
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
	char tmp[20] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
		'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', };
	CourseList* newCourse;
	newCourse = new CourseList;
	f.ignore();
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

	f.getline(newCourse->data.Room, 10);

	newCourse->pNext = nullptr;
	return newCourse;
}

void LoadCourses_txtfile(char* Link, CourseList*& list)
{
	CourseList* tmp = nullptr;
	CourseList* cur = list;
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
		f.ignore(256, '\n');
		while (!f.eof())
		{
			if (cur == nullptr)
			{
				cur = LoadCourseNode_txtfile(f);
				list = cur;
			}
			 else
			{
				tmp = LoadCourseNode_txtfile(f);
					cur->pNext = tmp;
					cur = cur->pNext;
			}
		}
		f.close();
	}
}

void AddCourse(char* AcaYear,char* Semester)
{
	CourseList* list = nullptr;
	LecturerList* L_list = nullptr;
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
	if (list == nullptr) return;
	int cnt = CountCourse(list);
	CourseList* cur = list;
	CourseList* p = CreateCourseNode();
	while (cur != nullptr) {
		if (strcmp(cur->data.ID, p->data.ID)==0)
		{
			cout << "\n\t >>>  Course already exist!!!. <<<" << endl;
			return;
		}
		cur = cur->pNext;
	}
	p->data.No = cnt + 1;
	LoadLecturerList(L_list);
	LecturerList* cur2 = L_list;
	while (cur2!= nullptr) {
		if (strcmp(cur2->data.username, p->data.LecturerUser))break;
		cur2 = cur2->pNext;
	}
	if (cur2 == nullptr)
	{
		cout << "Lecturer account does not exist." << endl;
		return;
	}
	strcpy(p->data.LecturerName, cur2->data.fullname);
	strcpy(p->data.LecturerDegree, cur2->data.degree);
	p->data.LecturerGender = cur2->data.gender;

	cur = list;
	if (cur == nullptr) {
		list = p;
	}
	else {
		while (cur && cur->pNext != nullptr) cur = cur->pNext;
		if (cur != nullptr) cur->pNext = p;
	}
	CourseList* cur3 = list;
	while (cur3 != nullptr)
	{
		cout << cur3->data.ID << endl;
		cur3 = cur3->pNext;
	}

	SaveSchedule(list, AcaYear, Semester, Class);

	Save_Course_Stu_List(list, AcaYear, Semester, Class);

	delete_LecturerList(L_list);
	delete_CourseList(list);

}


void EditCourse(char* AcaYear,char* Semester)
{
	char tmp[256];
	char* Course;
	char Class[10];
	cout << "Enter Class: \n\t>";
	cin.getline(Class, 10);
	char Link[256];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	cout << "Which course do you want to edit? \n\t >"; cin.getline(tmp, 256);
	Course = new char[strlen(tmp)];
	strcpy(Course, tmp);
	CourseList* list = nullptr;
	LoadCourses_txtfile(Link,list);
	CourseList* cur_Course = FindCourse(list, Course);
	if (cur_Course == nullptr)
	{
		system("cls");
		cout << "\tCannot find course. " << endl;
		return;
	}
	system("cls");
	cout << "Enter new course's ID: \n\t>"; cin.getline(tmp, 256);
	strcpy(cur_Course->data.ID, tmp);
	cout << "Enter new course's name: \n\t>"; cin.getline(tmp, 256);
	strcpy(cur_Course->data.Name, tmp);
	LecturerList* L_list = nullptr, * cur_Lecturer = nullptr;
	LoadLecturerList(L_list);
	do {
		cout << "Enter lecturer username: \n\t>"; cin.getline(tmp, 256);
		cur_Lecturer = FindLecturer(L_list, tmp);
	} while (cur_Lecturer == nullptr);
	strcpy(cur_Course->data.LecturerUser, tmp);
	strcpy(cur_Course->data.LecturerName, cur_Lecturer->data.fullname);
	strcpy(cur_Course->data.LecturerDegree, cur_Lecturer->data.degree);
	cur_Course->data.LecturerGender = cur_Lecturer->data.gender;
	cout << "Enter new Start day (dd/mm/yyyy): \n\t>"; cin.getline(tmp, 256);
	char* w = strtok(tmp, " /");
	cur_Course->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, " /");
	cur_Course->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.StartDate.Year = char_to_int(w);
	cout << "Enter new End day (dd/mm/yyyy): \n\t>"; cin.getline(tmp, 256);
	w = strtok(w, " /");
	cur_Course->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, " /");
	cur_Course->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.EndDate.Year = char_to_int(w);
	cout << "Enter Day of week (MON / TUE / WED / THU / FRI / SAT / SUN): \n\t> "; cin.getline(tmp, 256);
	strcpy(cur_Course->data.DoW, tmp);
	cout << "Enter new Start hour (hh:mm): "; cin.getline(tmp, 256);
	w = strtok(tmp, " :");
	cur_Course->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.StartHour.m = char_to_int(w);
	cout << "Enter new End houd (hh:mm): \n\t>"; cin.getline(tmp, 256);
	w = strtok(tmp, " :");
	cur_Course->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.EndHour.m = char_to_int(w);
	cout << "Enter new Room: \n\t>"; cin.getline(tmp, 256);
	strcpy(cur_Course->data.Room, tmp);
	SaveSchedule(list, AcaYear, Semester, Class);
	delete_CourseList(list);
	delete_LecturerList(L_list);
}

CourseList* FindCourse(CourseList* list,char* Course)
{
	CourseList* cur = list;
	while (cur != nullptr)
	{
		if (strcmp(Course, cur->data.ID) == 0)
		{
			return cur;
		}
		cur = cur->pNext;
	}
	return nullptr;
}

void RemoveStudentFromCourse(char* AcaYear, char* Semester,char* Class)
{
	char StudentID[10], CourseID[10], tmp[256];
	cout << "Enter Course's ID: "; cin.getline(CourseID, 10);
	cout << "Enter Student's ID: "; cin.getline(StudentID, 10);
	char Link[256];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, "-");
	strcat(Link, CourseID);
	strcat(Link, "-Student.txt");
	fstream f;
	f.open(Link,ios::in|ios::out);
	if (!f.is_open())
	{
		cout << "Cannot load student list." << endl;
		return;
	}
	bool flag = false;
	while (!f.eof())
	{
		f.getline(tmp, 256);
		if (strcmp(tmp, StudentID) == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Cannot find student." << endl;
		return;
	}

	f.ignore(256, '\n');
	f.ignore(256, '\n');
	f.ignore(256, '\n');
	f.ignore(256, '\n');
	cout << f.tellg() << endl;
	int pos = f.tellg();
	f.seekp(pos,ios::beg);
	f << 0;
	if (flag == true) cout << "Remove successfully." << endl;
	f.close();
}

StudentList* Load_Stu_Node_FromCourse(ifstream& f)
{
	StudentList* temp;
	temp = new StudentList;
	char tmp[20];
	f.ignore(100, '\n');
	f.getline(temp->data.ID, 10);
	f.getline(temp->data.Pwd, 20);
	f.getline(temp->data.Name, 30);
	f.getline(temp->data.MSSV, 10);
	f.getline(temp->data.Class, 10);
	f.getline(tmp, 21);
	char* w = strtok(tmp, " /");
	temp->data.DoB.Month = char_to_int(w);
	w = strtok(NULL, " /");
	temp->data.DoB.Day = char_to_int(w);
	w = strtok(NULL, " \n");
	temp->data.DoB.Year = char_to_int(w);
	f >> temp->data.Status;
	f.ignore(100, '\n');

	temp->pNext = nullptr;
	return temp;
}

void RemoveACourse(char* AcaYear, char* Semester, char* Class)
{
	char Link[256];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	ifstream fin;
	fin.open(Link);
	if (!fin.is_open())
	{
		cout << "Cannot load courses of class " << Class << endl;
		return;
	}
	CourseList* list = nullptr;
	LoadCourses_txtfile(Link, list);
	if (list == nullptr)
	{
		return;
	}
	char CourseID[10];
	cout << "Enter Course's ID you want to delete. \n\t>"; cin.getline(CourseID, 10);
	CourseList* cur_Course = list;
	CourseList* prev_Course = nullptr;
	bool flag = false;
	while (cur_Course != nullptr)
	{
		if (strcmp(CourseID, cur_Course->data.ID) == 0)
		{
			flag = true;
			break;
		}
		prev_Course = cur_Course;
		cur_Course = cur_Course->pNext;
	}
	if (flag == false)
	{
		cout << "Cannot find Course by ID! " << endl;
		return;
	}
	else
	{
		if (prev_Course == nullptr)
		{
			list = list->pNext;
			delete cur_Course;
		}
		else
		{
			prev_Course->pNext = cur_Course->pNext;
			delete cur_Course;
		}
	}
	SaveSchedule(list, AcaYear, Semester, Class);
	Link[strlen(Link) - 4] = '\0';
	strcat(Link, "-");
	strcat(Link, CourseID);
	strcat(Link, "-Student.txt");
	if (remove(Link)) cout << "Remove Course successfully." << endl;
}

char* CreateLinkCourse_Stu(char* AcaYear, char* Semester, char* Class,char* CourseID)  // create link, if there isnt courseid in link type 0
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + strlen(Class) + 5];
	strcpy(Link, AcaYear);
	strcat(Link,"-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	if (CourseID != NULL)
	{
		strcat(Link, "-");
		strcat(Link, CourseID);
		strcat(Link, "-Student.txt");
	}else
	strcat(Link, ".txt");
	return Link;
}

void AddAStudentToCourse(char* AcaYear, char* Semester)
{
	char StudentID[10], CourseID[10];
	cout << "Enter Student's ID:\n\t>"; cin.getline(StudentID, 10);
	StudentList* curStudent = FindStudent(StudentID);
	if (curStudent == nullptr)
	{
		cout << "Student does not exist." << endl;
		return;
	}
	cout << "Enter Course's ID: \n\t>"; cin.getline(CourseID, 10);
	char Class[10];
	cout << "Enter Class: \n\t>"; cin.getline(Class, 10);
	CourseList* list = nullptr;
	fstream f;
	LoadCourses_txtfile(CreateLinkCourse_Stu(AcaYear, Semester, Class, 0), list);
	CourseList* cur_Course = list;
	while (cur_Course != nullptr)
	{
		if (strcmp(cur_Course->data.ID, CourseID) == 0) break;
		cur_Course = cur_Course->pNext;
	}

	f.open(CreateLinkCourse_Stu(AcaYear, Semester, Class, CourseID), ios::in | ios::out);
	if (!f.is_open())
	{
		cout << "Cannot open file 1." << endl;
		return;
	}
	int cnt = 0;
	char tmp[256];
	while (!f.eof())
	{
		f.getline(tmp, 256);
		if (strcmp(tmp, "-") == 0) cnt++;
	}
	f.seekp(0, ios::beg);
	f << cnt++;
	f.seekg(0, ios::end);
	f << endl;
	f << curStudent->data.ID << endl;
	f << curStudent->data.Pwd << endl;
	f << curStudent->data.Name << endl;
	f << curStudent->data.DoB.Year << " " << curStudent->data.DoB.Month << " " << curStudent->data.DoB.Day << endl;
	f << curStudent->data.Class << endl;
	f << curStudent->data.Status << endl;
	f << -1 << endl;    //midterm
	f << -1 << endl;	//final
	f << -1 << endl;	//bonus
	f << -1 << endl;	//total
	Date tmp_day = cur_Course->data.StartDate;
	Hour Start_Hour = cur_Course->data.StartHour;
	Hour End_Hour = cur_Course->data.EndHour;
	for (int i = 0; i < 10; i++)
	{
		f << tmp_day.Year << " " << tmp_day.Month << " " << tmp_day.Day << " " << Start_Hour.h
			<< " " << Start_Hour.m << " " << End_Hour.h << " " << End_Hour.m << " " << -1 << endl;
		tmp_day = PlusDay(tmp_day, 7);   // change day to next week date
	}
	f << "-";
	f.close();
	delete_CourseList(list);
	delete curStudent;
}

StudentList* FindStudent(char* StudentID)
{
	StudentList* list = nullptr;
	ifstream fi;
	fi.open("student.txt");
	if (!fi.is_open())
	{
		cout << "Cannot open file 2." << endl;
		return nullptr;
	}
	int n;
	fi >> n;
	StudentList* cur = list;
	for (int i = 0; i < n; i++)
	{
		if (cur == nullptr)
		{
			StudentList* p = CreateStudentNode(fi);
			list = p;
			cur = list;

		}
		else if (cur != nullptr)
		{
			StudentList* temp = CreateStudentNode(fi);
			cur->pNext = temp;
			cur = cur->pNext;
		}
	}
	fi.close();
	cur = list;
	while (cur != nullptr)
	{
		if (strcmp(StudentID, cur->data.ID) == 0) {
			break;
		}
		cur = cur->pNext;
	}
	if (cur == nullptr)
	{
		cout << "cannot find student." << endl;
		return nullptr;
	}
	StudentList* curStudent = new StudentList;
	strcpy(curStudent->data.ID, cur->data.ID);
	strcpy(curStudent->data.Pwd, cur->data.Pwd);
	strcpy(curStudent->data.Name, cur->data.Name);
	strcpy(curStudent->data.MSSV, cur->data.MSSV);
	strcpy(curStudent->data.Class, cur->data.Class);
	curStudent->data.DoB = cur->data.DoB;
	curStudent->data.Gender = cur->data.Gender;
	curStudent->data.Status = cur->data.Status;
	curStudent->pNext = nullptr;
	delete_StudentList(list);
	return curStudent;

}

//=========================================================================================



//   DATE HANDLE FUNCTION
//=====================================================================================

bool IsLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;
	else return false;
}

int DayInMonth(int Month,int Year) {
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) return 31;
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) return 30;
	if (Month == 2 && IsLeapYear(Year) == true) return 29;
	else return 28;
}

Date PlusDay(Date init_Date, int plus_day){
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

//====================================================================================
LecturerList* LoadLecturerNode(ifstream& f)
{
	LecturerList* b = nullptr;
	b = new LecturerList;
	f.ignore(256, '\n');
	f.getline(b->data.username, 101);
	if (b->data.username == NULL) return NULL;
	f.getline(b->data.password, 101);
	f.getline(b->data.fullname, 101);
	f.getline(b->data.dob, 101);
	f.getline(b->data.degree, 20);
	f >> b->data.gender;

	b->pNext = nullptr;
	return b;
}
void LoadLecturerList(LecturerList*& list)
{
	ifstream fin;
	fin.open("lecturer.txt");
	if (!fin.is_open())
	{
		cout << "Can not open file" << endl;
		return;
	}
	else
	{
		LecturerList* cur = list;
		while (!fin.eof())
		{
			if (cur == nullptr)
			{
				list = LoadLecturerNode(fin);
				cur = list;
			}
			else
			{
				LecturerList* p;
				p = LoadLecturerNode(fin);
				cur->pNext = p;
				cur = cur->pNext;
			}
		}
		fin.close();
	}
}

LecturerList* FindLecturer(LecturerList* list, char* username) //find lecturer by username
{
	LecturerList* cur = list;
	while (cur != nullptr)
	{
		if (strcmp(username, cur->data.username) == 0) return cur;
		cur = cur->pNext;
	}
	return nullptr;
}

void delete_LecturerList(LecturerList*& list)
{
	if (list == nullptr) return;
	LecturerList* cur = list;
	while (list != nullptr)
	{
		list = list->pNext;
		delete cur;
		cur = list;
	}
}

void delete_CourseList(CourseList*& list)
{
	if (list == nullptr) return;
	CourseList* cur = list;
	while (list != nullptr)
	{
		list = list->pNext;
		delete cur;
		cur = list;
	}
}

void delete_StudentList(StudentList*& list)
{
	if (list == nullptr) return;
	StudentList* cur = list;
	while (list != nullptr)
	{
		list = list->pNext;
		delete cur;
		cur = list;
	}
}