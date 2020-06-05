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
	/*f.getline(tmp, 21);*/
	/*char* w = strtok(tmp, " /");
	temp->data.DoB.Month = char_to_int(w);
	w = strtok(tmp, " /");
	temp->data.DoB.Day = char_to_int(w);
	w = strtok(tmp, " \n");
	temp->data.Status = char_to_int(w);*/
	//char * w = strtok(tmp, " /");
	//for (int i = 0; w != NULL; i++) {
	//	if (i == 1) temp->data.DoB.Month = char_to_int(w);
	//	else if (i == 0) temp->data.DoB.Day = char_to_int(w);
	//	else temp->data.DoB.Year = char_to_int(w);
	//	w = strtok(NULL, " /");
	//}
	f >> temp->data.DoB.Day >> temp->data.DoB.Month
		>> temp->data.DoB.Year;
	
	f >> temp->data.Gender >> temp->data.Status;
	/*f.ignore(100, '\n');*/


	temp->pNext = nullptr;

	
	return temp;
}

int StudentCount(StudentList* list)
{
	int cnt = 0;
	StudentList* cur = list;
	while (cur != nullptr)
	{
		if (cur->data.Status == 1) cnt++;
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
	int n; char ntemp[50];
	n = 0;
	for (int i = 0; !f.eof(); i++) {
		f.getline(ntemp, 50);
		if (i > 0 && i % 8 == 0) n++;
	}
	f.close();
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot open file.\n";
		return;
	}
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
//void CreateAcaYear(char* AcaYear, char* Semester)
//{
//	ofstream fout;
//	fout.open("Semester.txt");
//	if (!fout.is_open())
//	{
//		cout << "Cannot create file.\n";
//		return;
//	}
//	fout << 1 << endl;
//	fout << AcaYear << endl;
//	fout << Semester << endl;
//	fout.close();
//}

AcY* GetAcaYear(ifstream &fin) {
	AcY* ay = new AcY;
	fin >> ay->Year >> ay->Sem;
	ay->yNext = nullptr;
	fin.ignore();
	return ay;
}

void GetAcaYearList(ifstream &fin, AcY*& ayHead) {
	AcY* ay = GetAcaYear(fin);
	ayHead = ay;
	AcY* aycur = ay;
	while (!fin.eof()) {
		ay = GetAcaYear(fin);
		aycur->yNext = ay;
		aycur = aycur->yNext;
	}
}

void DelAcaYearList(AcY*& ayHead) {
	AcY* aycur = ayHead;
	while (aycur != nullptr) {
		AcY* aydel = aycur;
		aycur = aycur->yNext;
		delete aydel;
	}
	ayHead = nullptr;
}

void CreateAcaYear() {
	std::system("cls");
	cout << "-Create Academic Year-" << endl << endl;
	char AcaYear[20];
	cout << "[- Academic Year (XXXX-XXXX) -]";
	cout << endl << "> ";
	cin.getline(AcaYear, 20);
	while (AcaYear[4] != '-') {
		cout << "Invalid input." << endl;
		cout << "> "; cin.getline(AcaYear, 20);
	}
	char Semester[10];
	cout << "[- Semester (HKX) ------------]";
	cout << endl << "> ";
	cin.getline(Semester, 10);
	ifstream fin("Semester.txt");
	if (!fin.is_open()) {
		cout << "Cannot create Academic Year." << endl;
		std::system("pause");
		return;
	}
	int n; fin >> n; fin.ignore();
	AcY* ayHead = nullptr;
	GetAcaYearList(fin, ayHead);
	fin.close();
	ofstream fout;
	fout.open("Semester.txt");
	if (!fout.is_open()) {
		cout << "Cannot create Academic Year." << endl;
		std::system("pause");
		return;
	}
	fout << n + 1 << endl;
	AcY* aycur = ayHead;
	while (aycur != nullptr) {
		fout << aycur->Year << endl << aycur->Sem << endl;
		aycur = aycur->yNext;
	}
	fout << AcaYear << endl << Semester;
	fout.close();
	DelAcaYearList(ayHead);
	cout << endl << "Academic Year created successfully." << endl << endl;
	cout << "[- Set as current Semester? --]";
	int color[] = { 15, 11 };
	int i[] = { 1, 0 };
	int ptr = 0;
	int KeyPressed = 0;
	while (KeyPressed != 13) {
		cls();

		cout << "-Create Academic Year-" << endl << endl;
		cout << "[- Academic Year (XXXX-XXXX) -]";
		cout << endl << "> " << AcaYear << endl;
		cout << "[- Semester (HKX) ------------]";
		cout << endl << "> " << Semester << endl;
		cout << endl << "Academic Year created successfully." << endl << endl;
		cout << "[- Set as current Semester? --]" << endl;

		SetColor(color, i[0]);
		if (ptr == 0) cout << "> "; else cout << "  ";
		cout << "Yes";
		cout << "\t";
		SetColor(color, i[1]);
		if (ptr == 1) cout << "> "; else cout << "  ";
		cout << "No";
		cout << endl;

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 1;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 1) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		SetColor(color, 0);
	}

	if (ptr == 0) {
		fout.open("CurrentSemester.txt");
		if (!fout.is_open()) {
			cout << "Cannot set as current Semester." << endl;
		} else {
			fout << AcaYear << endl << Semester;
			fout.close();
			cout << "Current Semester set succesfully." << endl;
		}
	}
	std::system("pause");
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

void LoadCourses_csvfile(char* Link, CourseList*& list)
{
	ifstream f;
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot open file.\n";
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
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
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
		f << cur->data.ID << endl;
		f << cur->data.Pwd << endl;
		f << cur->data.Name << endl;
		f << cur->data.DoB.Year << " ";
		if (cur->data.DoB.Month < 10) f << "0";
		f << cur->data.DoB.Month << " ";
		if (cur->data.DoB.Day < 10) f << "0";
		f << cur->data.DoB.Day << endl;
		f << cur->data.Class << endl;
		f << cur->data.Status << endl;
		f << -1 << endl;    //midterm
		f << -1 << endl;	//final
		f << -1 << endl;	//bonus
		f << -1 << endl;	//total
		Date tmp_day = list->data.StartDate;
		Date tmp_day_end = list->data.EndDate;
		Hour Start_Hour = list->data.StartHour;
		Hour End_Hour = list->data.EndHour;
		while (true)
		{
			if (tmp_day.Year > tmp_day_end.Year) break;
			if ((tmp_day.Year == tmp_day_end.Year) && 
				(tmp_day.Month > tmp_day_end.Month)) break;
			if ((tmp_day.Month == tmp_day_end.Month) &&
				(tmp_day.Day > tmp_day_end.Day)) break;
			f << tmp_day.Year << " ";
			if (tmp_day.Month < 10) f << "0";
			f << tmp_day.Month << " ";
			if (tmp_day.Day < 10) f << "0";
			f << tmp_day.Day << " ";
			if (Start_Hour.h < 10) f << "0";
			f << Start_Hour.h << " ";
			if (Start_Hour.m < 10) f << "0";
			f << Start_Hour.m << " ";
			if (End_Hour.h < 10) f << "0";
			f << End_Hour.h << " ";
			if (End_Hour.m < 10) f << "0";
			f << End_Hour.m << " " << -1 << endl;
			tmp_day = PlusDay(tmp_day, 7);   // change day to next week date
		}
		f << "-";
		cur = cur->pNext;
	}


}

void Create_Course_Student_Single(CourseList* list, char* AcaYear, char* Semester)   // CREATE COURSE FILE WHICH ALLOWS STUDENT MANAGEMENT
{
	StudentList* st_list = nullptr;
	LoadStudentList(st_list, list->data.Class);
	char Link[256];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, list->data.Class);
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
		f << cur->data.ID << endl;
		f << cur->data.Pwd << endl;
		f << cur->data.Name << endl;
		f << cur->data.DoB.Year << " ";
		if (cur->data.DoB.Month < 10) f << "0";
		f << cur->data.DoB.Month << " ";
		if (cur->data.DoB.Day < 10) f << "0";
		f << cur->data.DoB.Day << endl;
		f << cur->data.Class << endl;
		f << cur->data.Status << endl;
		f << -1 << endl;    //midterm
		f << -1 << endl;	//final
		f << -1 << endl;	//bonus
		f << -1 << endl;	//total
		Date tmp_day = list->data.StartDate;
		Date tmp_day_end = list->data.EndDate;
		Hour Start_Hour = list->data.StartHour;
		Hour End_Hour = list->data.EndHour;
		while (true)
		{
			if (tmp_day.Year > tmp_day_end.Year) break;
			if ((tmp_day.Year == tmp_day_end.Year) &&
				(tmp_day.Month > tmp_day_end.Month)) break;
			if ((tmp_day.Month == tmp_day_end.Month) &&
				(tmp_day.Day > tmp_day_end.Day)) break;
			f << tmp_day.Year << " ";
			if (tmp_day.Month < 10) f << "0";
			f << tmp_day.Month << " ";
			if (tmp_day.Day < 10) f << "0";
			f << tmp_day.Day << " ";
			if (Start_Hour.h < 10) f << "0";
			f << Start_Hour.h << " ";
			if (Start_Hour.m < 10) f << "0";
			f << Start_Hour.m << " ";
			if (End_Hour.h < 10) f << "0";
			f << End_Hour.h << " ";
			if (End_Hour.m < 10) f << "0";
			f << End_Hour.m << " " << -1 << endl;
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
		Create_Course_Student(cur, AcaYear, Semester, Class);
		cur = cur->pNext;
	}
}

void SaveSchedule(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + 15 + 7];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
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
			f << cur->data.StartHour.h << " " << cur->data.StartHour.m << endl;
			f << cur->data.EndHour.h << " " << cur->data.EndHour.m << endl;
			f << cur->data.Room << endl;
			cur = cur->pNext;
		}
		f.close();
	}
}

void SaveSchedule_AllCourse(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + 15 + 7];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-AllCourses.txt");
	char* LinkTemp;
	LinkTemp = new char[strlen(AcaYear) + strlen(Semester) + 20 + 7];
	strcpy(LinkTemp, "Files/Course/");
	strcat(LinkTemp, AcaYear);
	strcat(LinkTemp, "-");
	strcat(LinkTemp, Semester);
	strcat(LinkTemp, "-AllCourses-temp.txt");
	

	int TotalCourse = 0;
	ifstream fin;

	// Temporary file
	fin.open(Link);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
	} else {
		ofstream fout;
		fout.open(LinkTemp);
		if (!fout.is_open()) {
			cout << "Cannot create file." << endl;
			fin.close();
			return;
		} else {
			char line[50];
			for (int i = 0; i < 2; i++)
				fin.getline(line, 50);
			int no_line = 0;
			while (!fin.eof()) { 
				fin.getline(line, 50);
				fout << line;
				if (!fin.eof()) fout << endl;
			}
			fout.close();
		}
		fin.close();
	}

	// Get total number of Courses before importing new Courses
	fin.open(Link);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	} else {
		fin >> TotalCourse;
		fin.close();
	}

	// Rewrite the file
	
	fin.open(LinkTemp);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	} else {
		ofstream fout;
		fout.open(Link);
		if (!fout.is_open()) {
			cout << "Cannot create file." << endl;
			fin.close();
			return;
		} else {
			fout << (TotalCourse + CountCourse(list));
			fout << endl << endl;
			char line[50];
			
			if (TotalCourse != 0) {
				while (!fin.eof()) {
					fin.getline(line, 50);
					fout << line << endl;
				}
			}
			fout.close();
		}
		fin.close();
	}
	remove(LinkTemp);

	// Write the new Courses into the file
	ofstream f;
	f.open(Link, ios::app);
	if (!f.is_open()) {
		cout << "Cannot create/open file.\n";
		return;
	}
	else
	{
		/*int cnt = CountCourse(list);
		f << cnt << endl;*/
		CourseList* cur = list;
		while (cur != nullptr) {
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
			f << cur->data.StartHour.h << " " << cur->data.StartHour.m << endl;
			f << cur->data.EndHour.h << " " << cur->data.EndHour.m << endl;
			f << cur->data.Room << endl;
			if (cur->pNext != nullptr) f << endl;
			cur = cur->pNext;
		}
		f.close();
	}
}

void SaveSchedule_AllCourse_Single(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + 15 + 7];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-AllCourses.txt");
	char* LinkTemp;
	LinkTemp = new char[strlen(AcaYear) + strlen(Semester) + 20 + 7];
	strcpy(LinkTemp, "Files/Course/");
	strcat(LinkTemp, AcaYear);
	strcat(LinkTemp, "-");
	strcat(LinkTemp, Semester);
	strcat(LinkTemp, "-AllCourses-temp.txt");


	int TotalCourse = 0;
	ifstream fin;

	// Temporary file
	fin.open(Link);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
	}
	else {
		ofstream fout;
		fout.open(LinkTemp);
		if (!fout.is_open()) {
			cout << "Cannot create file." << endl;
			fin.close();
			return;
		}
		else {
			char line[50];
			for (int i = 0; i < 2; i++)
				fin.getline(line, 50);
			int no_line = 0;
			while (!fin.eof()) {
				fin.getline(line, 50);
				fout << line;
				if (!fin.eof()) fout << endl;
			}
			fout.close();
		}
		fin.close();
	}

	// Get total number of Courses before importing new Courses
	fin.open(Link);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	else {
		fin >> TotalCourse;
		fin.close();
	}

	// Rewrite the file

	fin.open(LinkTemp);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	else {
		ofstream fout;
		fout.open(Link);
		if (!fout.is_open()) {
			cout << "Cannot create file." << endl;
			fin.close();
			return;
		}
		else {
			fout << TotalCourse + 1;
			fout << endl << endl;
			char line[50];

			if (TotalCourse != 0) {
				while (!fin.eof()) {
					fin.getline(line, 50);
					fout << line << endl;
				}
			}
			fout.close();
		}
		fin.close();
	}
	remove(LinkTemp);

	// Write the new Course into the file
	ofstream f;
	f.open(Link, ios::app);
	if (!f.is_open()) {
		cout << "Cannot create/open file.\n";
		return;
	}
	else
	{
		/*int cnt = CountCourse(list);
		f << cnt << endl;*/
		CourseList* cur = list;
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
		f << cur->data.StartHour.h << " " << cur->data.StartHour.m << endl;
		f << cur->data.EndHour.h << " " << cur->data.EndHour.m << endl;
		f << cur->data.Room << endl;
		if (cur->pNext != nullptr) f << endl;
		f.close();
	}
}

void SaveSchedule_AllCourse_Rewrite(CourseList* list, char* AcaYear, char* Semester, char* Class)
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + 15 + 7];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-AllCourses.txt");


	int TotalCourse = 0;
	ifstream fin;

	// Write the new Courses into the file
	ofstream f;
	f.open(Link);
	if (!f.is_open()) {
		cout << "Cannot create/open file.\n";
		return;
	}
	else
	{
		f << CountCourse(list) << endl << endl;
		CourseList* cur = list;
		while (cur != nullptr) {
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
			f << cur->data.StartHour.h << " " << cur->data.StartHour.m << endl;
			f << cur->data.EndHour.h << " " << cur->data.EndHour.m << endl;
			f << cur->data.Room << endl;
			if (cur->pNext != nullptr) f << endl;
			cur = cur->pNext;
		}
		f.close();
	}
}

void ImportCourses(char* AcaYear, char* Semester)    // 3.2 import courses and save schedule
{
	std::system("cls");
	cout << "-Import Courses from a .csv file-" << endl << endl;
	/*cin.ignore();*/
	CourseList* list = nullptr;
	char temp[256], * Class, * Link;
	cout << "[- Class -----]"; cout << endl << "> ";
	cin.getline(temp, 256, '\n');
	Class = new char[strlen(temp) + 1];
	strcpy_s(Class, strlen(temp) + 1, temp);
	temp[0] = 0;
	/*cout << "[- File ------]"; cout << endl << "> ";
	cin.getline(temp, 256, '\n');*/
	Link = new char[15 + 8 +strlen(Class) + 4 + 1];
	strcpy(Link, "Files/Course/Courses-");
	strcat(Link, Class);
	strcat(Link, ".csv");
	/*strcpy_s(Link, strlen(temp) + 1, temp);*/

	LoadCourses_csvfile(Link, list);
	SaveSchedule(list, AcaYear, Semester, Class);
	SaveSchedule_AllCourse(list, AcaYear, Semester, Class);
	Save_Course_Stu_List(list, AcaYear, Semester, Class);

	delete[]Link; delete[]Class;

	cout << "Courses imported." << endl;
	std::system("pause");
}

//void CoursesManagement()
//{
//	system("cls");
//	char* AcaYear, * Semester;			//  INPUT ACADEMIC YEAR AND SEMESTER
//	char temp[256];
//	cout << "Enter Academic year: "; cin.getline(temp, 256, '\n');
//	AcaYear = new char[strlen(temp) + 1];
//	strcpy_s(AcaYear, strlen(temp) + 1, temp);
//	temp[0] = 0;
//	cout << "Enter Semester: "; cin.getline(temp, 256, '\n');
//	Semester = new char[strlen(temp) + 1];
//	strcpy_s(Semester, strlen(temp) + 1, temp);
//	CreateAcaYear(AcaYear, Semester);		// SAVE ACADEMIC YEAR AND SEMESTER INTO FILE 
//	ImportCourses(AcaYear, Semester);
//
//}

CourseList* CreateCourseNode()  // Create Course Node by typing in 
{
	CourseList* newCourse;
	newCourse = new CourseList;
	char temp[256];
	cout << "[- Course ID -----------------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.ID, 15);
	cout << "[- Course Name ---------------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.Name, 100);
	cout << "[- Course Class --------------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.Class, 10);
	cout << "[- Lecturer Username ---------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.LecturerUser, 15);
	cout << "[- Lecturer Name -------------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.LecturerName, 30);
	cout << "[- Lecturer Degree -----------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.LecturerDegree, 20);
	cout << "[- Lecturer Gender (0 - F | 1 - M) -]";
	cout << endl << "> ";
	cin >> newCourse->data.LecturerGender;
	cin.ignore();

	cout << "[- Start Date (dd/mm/yyyy) ---------]";
	cout << endl << "> ";
	cin.getline(temp, 256);
	char* w = strtok(temp, "/");
	newCourse->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "[- End Date (dd/mm/yyyy) -----------]";
	cout << endl << "> ";
	cin.getline(temp, 256);
	w = strtok(temp, "/");
	newCourse->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndDate.Year = char_to_int(w);
	temp[0] = '\0';

	cout << "[- Day of Week ---------------------]";
	cout << endl << "> ";
	cin.getline(newCourse->data.DoW, 10);

	cout << "[- Start Hour (hh:mm) --------------]";
	cout << endl << "> ";
	cin.getline(temp, 256);
	w = strtok(temp, ":");
	newCourse->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartHour.m = char_to_int(w);
	temp[0] = '\0';

	cout << "[- End Hour (hh:mm) ----------------]";
	cout << endl << "> ";
	cin.getline(temp, 256);
	w = strtok(temp, ":");
	newCourse->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndHour.m = char_to_int(w);

	cout << "[- Room ----------------------------]";
	cout << endl << "> ";
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
	f.getline(newCourse->data.ID, 15);
	f.getline(newCourse->data.Name, 100);
	f.getline(newCourse->data.Class, 10);
	f.getline(newCourse->data.LecturerUser, 15);
	f.getline(newCourse->data.LecturerName, 30);
	f.getline(newCourse->data.LecturerDegree, 20);
	f >> newCourse->data.LecturerGender;
	f.ignore();
	//f.getline(tmp, 20);
	////cout << "word: " << tmp << endl;
	//char* w = strtok(tmp, " ");
	////cout << "word: " << w << endl;
	//newCourse->data.StartDate.Year = char_to_int(w);
	//w = strtok(NULL, " ");
	//newCourse->data.StartDate.Month = char_to_int(w);
	//w = strtok(NULL, "\n");
	//newCourse->data.StartDate.Day = char_to_int(w);
	f >> newCourse->data.StartDate.Year >> newCourse->data.StartDate.Month >> newCourse->data.StartDate.Day;
	f.ignore();
	f >> newCourse->data.EndDate.Year >> newCourse->data.EndDate.Month >> newCourse->data.EndDate.Day;
	f.ignore();
	/*f.getline(tmp, 20);
	w = strtok(tmp, " ");
	newCourse->data.EndDate.Year = char_to_int(w);
	w = strtok(NULL, " ");
	newCourse->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndDate.Day = char_to_int(w);*/

	f.getline(newCourse->data.DoW, 10);
	f >> newCourse->data.StartHour.h >> newCourse->data.StartHour.m;
	f.ignore();
	f >> newCourse->data.EndHour.h >> newCourse->data.EndHour.m;
	f.ignore();
	/*f.getline(tmp, 20);
	w = strtok(tmp, " :");
	newCourse->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.StartHour.m = char_to_int(w);

	f.getline(tmp, 20);
	w = strtok(tmp, " :");
	newCourse->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	newCourse->data.EndHour.m = char_to_int(w);*/

	f.getline(newCourse->data.Room,11);

	newCourse->pNext = nullptr;
	f.ignore();
	return newCourse;
}

void LoadCourses_txtfile(char* Link, CourseList*& list)
{
	CourseList* tmp, * cur = list;
	ifstream f;
	f.open(Link);
	if (!f.is_open())
	{
		cout << "Cannot open file." << endl;
		return;
	}
	else {
		int n;
		f >> n;
		f.ignore(2);
		cur = LoadCourseNode_txtfile(f);
		list = cur;
		while (!f.eof())
		{
				tmp = LoadCourseNode_txtfile(f);
				cur->pNext = tmp;
				cur = cur->pNext;
		}
		f.close();
	}
}

void AddCourse(char* AcaYear, char* Semester)
{
	std::system("cls");
	cout << "-Add Course-" << endl << endl;

	CourseList* list = nullptr;
	char Class[10];
	cout << "[- Class -----]"; cout << endl << "> ";
	cin.getline(Class, 10);
	char Link[256];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	LoadCourses_txtfile(Link, list);
	int cnt = CountCourse(list);
	CourseList* cur = list;
	while (true) {
		if (cur->pNext != nullptr)
			cur = cur->pNext;
		else break;
	}
	CourseList* p = CreateCourseNode();
	cur->pNext = p;
	p->data.No = cnt + 1;
	SaveSchedule(list, AcaYear, Semester, Class);
	SaveSchedule_AllCourse_Single(p, AcaYear, Semester, Class);
	Create_Course_Student(p, AcaYear, Semester, Class);
	cout << endl << "New Course added." << endl;
	std::system("pause");
	/*Save_Course_Stu_List(list, AcaYear, Semester, Class);*/

}

void EditCourse(char* AcaYear, char* Semester)
{
	std::system("cls");
	cout << "-Edit Course-" << endl;
	cout << endl << "-Old Course-" << endl << endl;
	char tmp[256];
	char* Course;
	char Class[10];
	cout << "[- Class -----]";
	cout << endl << "> ";
	cin.getline(Class, 10);
	char Link[256];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	cout << "[- Course ----]";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	Course = new char[strlen(tmp)];
	strcpy(Course, tmp);
	CourseList* list = nullptr;
	LoadCourses_txtfile(Link, list);
	CourseList* cur_Course = FindCourse(list, Course, Class);
	if (cur_Course == nullptr)
	{
		/*system("cls");*/
		cout << "Cannot find course." << endl;
		delete_CourseList(list);
		std::system("pause");
		return;
	}
	/*system("cls");*/
	cout << endl << "-New Course-" << endl << endl;
	cout << "[- ID ---------]"; 
	cout << endl << "> "; 
	cin.getline(tmp, 256);
	strcpy(cur_Course->data.ID, tmp);
	cout << "[- Name -------]"; 
	cout << endl << "> "; 
	cin.getline(tmp, 256);
	strcpy(cur_Course->data.Name, tmp);
	LecturerList* L_list = nullptr, * cur_Lecturer = nullptr;
	LoadLecturerList(L_list);
	bool f_first = true;
	do {
		if (f_first) f_first = false;
		else {
			cout << "Cannot find Lecturer." << endl;
		}
		cout << "[- Lecturer ---]";
		cout << endl << "> "; 
		cin.getline(tmp, 256);
		cur_Lecturer = FindLecturer(L_list, tmp);
	} while (cur_Lecturer == nullptr);
	strcpy(cur_Course->data.LecturerUser, tmp);
	strcpy(cur_Course->data.LecturerName, cur_Lecturer->data.fullname);
	strcpy(cur_Course->data.LecturerDegree, cur_Lecturer->data.degree);
	cur_Course->data.LecturerGender = cur_Lecturer->data.gender;
	cout << "[- Start Date -] (dd/mm/yyyy)";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	char* w = strtok(tmp, "/");
	cur_Course->data.StartDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	cur_Course->data.StartDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.StartDate.Year = char_to_int(w);
	tmp[0] = '\0';
	cout << "[- End Date ---] (dd/mm/yyyy)";
	cout << endl << "> "; 
	cin.getline(tmp, 256);
	w = strtok(tmp, "/");
	cur_Course->data.EndDate.Day = char_to_int(w);
	w = strtok(NULL, "/");
	cur_Course->data.EndDate.Month = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.EndDate.Year = char_to_int(w);
	tmp[0] = '\0';
	cout << "[- DoW --------] (MON/TUE/WED/THU/FRI/SAT/SUN)";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	strcpy(cur_Course->data.DoW, tmp);
	cout << "[- Start Hour -] (hh:mm)";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	w = strtok(tmp, " :");
	cur_Course->data.StartHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.StartHour.m = char_to_int(w);
	cout << "[- End Hour ---] (hh:mm)";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	w = strtok(tmp, " :");
	cur_Course->data.EndHour.h = char_to_int(w);
	w = strtok(NULL, "\n");
	cur_Course->data.EndHour.m = char_to_int(w);
	cout << "[- Room -------]";
	cout << endl << "> ";
	cin.getline(tmp, 256);
	strcpy(cur_Course->data.Room, tmp);
	SaveSchedule(list, AcaYear, Semester, Class);

	// Save to AllCourses.txt
	char LinkAC[256];
	strcpy(LinkAC, "Files/Course/");
	strcat(LinkAC, AcaYear);
	strcat(LinkAC, "-");
	strcat(LinkAC, Semester);
	strcat(LinkAC, "-AllCourses.txt");
	CourseList* listAC;
	LoadCourses_txtfile(LinkAC, listAC);
	CourseList* cur_CourseAC = FindCourse(listAC, Course, Class);
	strcpy(cur_CourseAC->data.ID, cur_Course->data.ID);
	strcpy(cur_CourseAC->data.Name, cur_Course->data.Name);
	strcpy(cur_CourseAC->data.LecturerUser, cur_Course->data.LecturerUser);
	strcpy(cur_CourseAC->data.LecturerName, cur_Course->data.LecturerName);
	strcpy(cur_CourseAC->data.LecturerDegree, cur_Course->data.LecturerDegree);
	cur_CourseAC->data.LecturerGender = cur_Course->data.LecturerGender;
	cur_CourseAC->data.StartDate = cur_Course->data.StartDate;
	cur_CourseAC->data.EndDate = cur_Course->data.EndDate;
	cur_CourseAC->data.StartHour = cur_Course->data.StartHour;
	/*cur_CourseAC->data.EndHour.h = cur_Course->data.EndHour.h;
	cur_CourseAC->data.EndHour.m = cur_Course->data.EndHour.m;*/
	strcpy(cur_CourseAC->data.DoW, cur_Course->data.DoW);
	cur_CourseAC->data.EndHour = cur_Course->data.EndHour;
	strcpy(cur_CourseAC->data.Room, cur_Course->data.Room);

	SaveSchedule_AllCourse_Rewrite(listAC, AcaYear, Semester, Class);
	
	// Rewrite the Course File
	char CourseFileRemoved[256];
	strcpy(CourseFileRemoved, "Files/Course/");
	strcat(CourseFileRemoved, AcaYear); strcat(CourseFileRemoved, "-");
	strcat(CourseFileRemoved, Semester);strcat(CourseFileRemoved, "-");
	strcat(CourseFileRemoved, Class); strcat(CourseFileRemoved, "-");
	strcat(CourseFileRemoved, Course); strcat(CourseFileRemoved, "-Student.txt");
	remove(CourseFileRemoved);
	Create_Course_Student_Single(cur_Course, AcaYear, Semester);

	delete_CourseList(list);
	delete_CourseList(listAC);
	delete_LecturerList(L_list);

	cout << endl << "Course edited." << endl;
	std::system("pause");
}

void RemoveCourse(char *AcaYear, char* Semester) {
	std::system("cls");
	cout << "-Remove Course-" << endl << endl;
	char Class[10], Course[25];
	cout << "[- Class -----]";
	cout << endl << "> ";
	cin.getline(Class, 10);
	cout << "[- Course ----]";
	cout << endl << "> ";
	cin.getline(Course, 25);
	char Link[256];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, ".txt");
	ifstream fin;
	fin.open(Link);
	if (!fin.is_open())
	{
		cout << "Cannot load courses of class " << Class << "." << endl;
		std::system("pause");
		return;
	}
	CourseList* list = nullptr;
	LoadCourses_txtfile(Link, list);
	if (list == nullptr)
	{
		cout << "No Course available." << endl;
		std::system("pause");
		return;
	}
	CourseList* cur_Course = list;
	CourseList* prev_Course = nullptr;
	bool flag = false;
	while (cur_Course != nullptr)
	{
		if (strcmp(Course, cur_Course->data.ID) == 0)
		{
			flag = true;
			break;
		}
		prev_Course = cur_Course;
		cur_Course = cur_Course->pNext;
	}
	if (flag == false)
	{
		cout << "Cannot find Course." << endl;
		return;
	}
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
	fin.close();
	SaveSchedule(list, AcaYear, Semester, Class);
	Link[strlen(Link) - 4] = '\0';
	strcat(Link, "-");
	strcat(Link, Course);
	strcat(Link, "-Student.txt");

	// All Course
	char LinkAC[256];
	strcpy(LinkAC, "Files/Course/");
	strcat(LinkAC, AcaYear);
	strcat(LinkAC, "-");
	strcat(LinkAC, Semester);
	strcat(LinkAC, "-AllCourses.txt");
	ifstream finAC;
	finAC.open(Link);
	if (!finAC.is_open())
	{
		cout << "Cannot load courses of class " << Class << "." << endl;
		std::system("pause");
		return;
	}
	CourseList* listAC = nullptr;
	LoadCourses_txtfile(LinkAC, listAC);
	if (listAC == nullptr)
	{
		cout << "No Course available." << endl;
		std::system("pause");
		return;
	}
	CourseList* cur_CourseAC = listAC;
	CourseList* prev_CourseAC = nullptr;
	bool flagAC = false;
	while (cur_CourseAC != nullptr)
	{
		if (strcmp(Course, cur_CourseAC->data.ID) == 0)
		{
			flagAC = true;
			break;
		}
		prev_CourseAC = cur_CourseAC;
		cur_CourseAC = cur_CourseAC->pNext;
	}
	if (flagAC == false)
	{
		cout << "Cannot find Course." << endl;
		return;
	}
	if (prev_CourseAC == nullptr)
	{
		listAC = listAC->pNext;
		delete cur_CourseAC;
	}
	else
	{
		prev_CourseAC->pNext = cur_CourseAC->pNext;
		delete cur_CourseAC;
	}
	finAC.close();
	SaveSchedule_AllCourse_Rewrite(listAC, AcaYear, Semester, Class);

	if (remove(Link) == 0) cout << "Course removed.";
	else cout << "Failed to remove Course.";
	cout << endl;
	std::system("pause");
}

CourseList* FindCourse(CourseList* list, char* Course, char *Class)
{
	CourseList* cur = list;
	while (cur != nullptr)
	{
		if ((strcmp(Course, cur->data.ID) == 0) &&
			(strcmp(Class, cur->data.Class) == 0))
		{
			return cur;
		}
		cur = cur->pNext;
	}
	return nullptr;
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
//=========================================================================================


//   STUDENT
//=========================================================================================

char* CreateLinkCourse_Stu(char* AcaYear, char* Semester, char* Class, char* CourseID)  // create link, if there isnt courseid in link type 0
{
	char* Link;
	Link = new char[strlen(AcaYear) + strlen(Semester) + strlen(Class) + 5];
	strcpy(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	if (CourseID != NULL)
	{
		strcat(Link, "-");
		strcat(Link, CourseID);
		strcat(Link, "-Student.txt");
	}
	else
		strcat(Link, ".txt");
	return Link;
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

void RemoveStudentFromCourse(char* AcaYear, char* Semester)
{
	std::system("cls");
	cout << "-Remove Student From Course-" << endl << endl;
	char StudentID[10], Class[10], CourseID[10], tmp[256];
	cout << "[- Class ------]";
	cout << endl << "> ";
	cin.getline(Class, 10);
	cout << "[- Course -----]";
	cout << endl << "> ";
	cin.getline(CourseID, 10);
	cout << "[- Student ID -]";
	cout << endl << "> ";
	cin.getline(StudentID, 10);
	char Link[256];
	strcpy(Link, "Files/Course/");
	strcat(Link, AcaYear);
	strcat(Link, "-");
	strcat(Link, Semester);
	strcat(Link, "-");
	strcat(Link, Class);
	strcat(Link, "-");
	strcat(Link, CourseID);
	strcat(Link, "-Student.txt");
	fstream f;
	f.open(Link, ios::in | ios::out);
	if (!f.is_open())
	{
		cout << "Cannot load student list." << endl;
		std::system("pause");
		return;
	}
	bool flag = false;
	int n; f >> n; f.ignore();
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
		std::system("pause");
		f.close();
		return;
	}

	f.ignore(256, '\n');
	f.ignore(256, '\n');
	f.ignore(256, '\n');
	f.ignore(256, '\n');
	int pos = f.tellg();
	f.seekp(pos, ios::beg);
	f << 0;
	f.seekp(0, ios::beg);
	f << n - 1;
	if (flag == true) cout << "Student removed successfully." << endl;
	else cout << "Student removal failed." << endl;
	f.close();
	std::system("pause");
}

void AddAStudentToCourse(char* AcaYear, char* Semester)
{
	std::system("cls");
	cout << "-Add Student to Course-" << endl << endl;
	char StudentID[10], CourseID[10];
	cout << "[- Student ID ---]"; 
	cout << endl << "> ";
	cin.getline(StudentID, 10);
	StudentList* curStudent = FindStudent(StudentID);
	if (curStudent == nullptr)
	{
		cout << "Student does not exist." << endl;
		std::system("pause");
		return;
	}
	char Class[10];
	cout << "[- Class --------]";
	cout << endl << "> ";
	cin.getline(Class, 10);
	cout << "[- Course ID ----]";
	cout << endl << "> ";
	cin.getline(CourseID, 10);
	CourseList* list = nullptr;
	fstream f;
	char f_Link[256] = { "Files/Course/" };
	char f_Link_AC[256];
	strcpy(f_Link_AC, f_Link);
	strcat(f_Link_AC, AcaYear);	strcat(f_Link_AC, "-");
	strcat(f_Link_AC, Semester);
	strcat(f_Link_AC, "-AllCourses.txt");
	strcat(f_Link, CreateLinkCourse_Stu(AcaYear, Semester, Class, CourseID));
	
	ifstream fin;
	fin.open(f_Link);
	if (!fin.is_open()) {
		cout << "Cannot add Student to Course." << endl;
		std::system("pause");
		return;
	}
	int AttDayNo = CourseAttDay(fin) - 11;
	fin.close();
	LoadCourses_txtfile(f_Link_AC, list);
	CourseList* cur_Course = list;
	while (cur_Course->pNext != nullptr)
	{
		if (strcmp(cur_Course->data.ID, CourseID) == 0) break;
		cur_Course = cur_Course->pNext;
	}
	int cnt = 0;
	fin.open(f_Link);
	fin >> cnt;
	fin.close();
	f.open(f_Link, ios::in | ios::out);
	if (!f.is_open())
	{
		cout << "Cannot open file." << endl;
		return;
	}
	/*char tmp[256];
	while (!f.eof())
	{
		f.getline(tmp, 256);
		if (strcmp(tmp, "-") == 0) cnt++;
	}*/
	f.seekp(0, ios::beg);
	f << cnt + 1;
	f.close();
	/*f.seekp(0, ios::end);*/
	ofstream fout;
	fout.open(f_Link, ios::app);
	if (!fout.is_open()) {
		cout << "Cannot add Student to Course." << endl;
		std::system("pause");
		return;
	}
	fout << endl;
	fout << curStudent->data.ID << endl;
	fout << curStudent->data.Pwd << endl;
	fout << curStudent->data.Name << endl;
	fout << curStudent->data.DoB.Year << " " << curStudent->data.DoB.Month << " " << curStudent->data.DoB.Day << endl;
	fout << curStudent->data.Class << endl;
	fout << curStudent->data.Status << endl;
	fout << -1 << endl;    //midterm
	fout << -1 << endl;	//final
	fout << -1 << endl;	//bonus
	fout << -1 << endl;	//total
	Date tmp_day = cur_Course->data.StartDate;
	Hour Start_Hour = cur_Course->data.StartHour;
	Hour End_Hour = cur_Course->data.EndHour;
	for (int i = 0; i < AttDayNo; i++)
	{
		fout << tmp_day.Year << " " << tmp_day.Month << " " << tmp_day.Day << " " << Start_Hour.h
			<< " " << Start_Hour.m << " " << End_Hour.h << " " << End_Hour.m << " " << -1 << endl;
		tmp_day = PlusDay(tmp_day, 7);   // change day to next week date
	}
	fout << "-";
	/*f.close();*/
	fout.close();
	delete_CourseList(list);
	delete curStudent;
	cout << "Student added to Course successfully." << endl;
	std::system("pause");
}


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



LecturerList* LoadLecturerNode(ifstream& f)
{
	LecturerList* b = nullptr;
	b = new LecturerList;
	f.getline(b->data.username, 101);
	if (b->data.username == NULL) return NULL;
	f.getline(b->data.password, 101);
	f.getline(b->data.fullname, 101);
	f.getline(b->data.dob, 101);
	f.getline(b->data.degree, 20);
	f >> b->data.gender; f.ignore();
	f.ignore(256, '\n');

	b->pNext = nullptr;
	return b;
}

void LoadLecturerList(LecturerList*& list)
{
	ifstream fin;
	fin.open("lecturer.txt");
	if (!fin.is_open())
	{
		cout << "Cannot open file." << endl;
		std::system("pause");
		return;
	}
	else
	{
		fin.ignore(256, '\n');
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
