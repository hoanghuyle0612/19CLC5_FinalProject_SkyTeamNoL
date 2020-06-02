// COURSE FUNCTION

#include "Course.h"
#define COURSELINE 14

string GetFileName(string Sem, char* Link) {

	cout << "-Enter Course's file-" << endl << endl;

	const int lim = 100;

	char Class[lim], Course[lim];
	/*cin.ignore();*/
	cout << "[- Class -----]" << endl;
	cout << "> "; cin.getline(Class, lim);
	/*while (strlen(Class) + 1 != Class_lim) {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Class, lim);
	}*/
	cout << "[- Course ----]" << endl;
	cout << "> "; cin.getline(Course, lim);
	/*while (strlen(Course) + 1 != Course_lim) {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Course, lim);
	}*/

	// Get file link



	// Search for the file

	string fClass(Class), fCourse(Course), fLink(Link);
	string fHead(Sem + "-");
	string fName(fLink + fHead + fClass + "-" + fCourse + "-");

	return fName;
}

int CourseAttDay(ifstream& fin) {
	/*char temp[30]; int cnt = -1, line = 0;
	while (true) {
		fin.getline(temp, 30);
		if (line < 11 || temp[0] != '-') {
			cnt++;
			line++;
		}
		else return cnt;
	}*/
	string Line; int cnt = -1, line = 0;
	while (true) {
		getline(fin, Line);
		cnt++;
		line++;
		if (Line == "-") return cnt;
	}
}

Student_Course* GetStudentFile(ifstream& fin, int n) {
	Student_Course* stu = new Student_Course;
	fin >> stu->id;
	fin.ignore(); // 01
	getline(fin, stu->pass); // 02
	getline(fin, stu->name); // 03
	fin >> stu->by >> stu->bm >> stu->bd;
	fin.ignore(); // 04
	getline(fin, stu->clss); // 05
	fin >> stu->active;
	fin.ignore(); // 06
	fin >> stu->sc_mid >> stu->sc_fin >> stu->sc_lab
		>> stu->sc_ave;
	fin.ignore(); // 07 08 09 10
	AttDay* d = CreateDay(fin);
	stu->dHead = d; // 11
	AttDay* dcur = d;
	for (int i = 1; i < n; i++) {
		d = CreateDay(fin);
		dcur->dNext = d;
		dcur = dcur->dNext;
	} // 11 --> 19

	string temp; getline(fin, temp);
	return stu;
}

void ShowAttDay(Student_Course* stu, int ADNo) {
	int width = 1 + 10 + 1 + (5 + 1) * ADNo;
	for (int i = 0; i < width; i++) {
		if (i == 0 || i == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "| " << stu->id;
	cout << " |  ";
	AttDay* dcur = stu->dHead;
	for (int i = 0; i < ADNo; i++) {
		if (dcur->pre == 1) cout << "v";
		else cout << " ";
		cout << "  |";
		if (i < ADNo - 1) cout << "  ";
		dcur = dcur->dNext;
	} cout << endl;

	/*cout << "[" << stu->id << "]" << endl;
	cout << stu->name << endl;
	AttDay* dcur = stu->dHead;
	while (dcur != nullptr) {
		if (dcur->ad < 10) cout << "0";
		cout << dcur->ad << "/";
		if (dcur->am < 10) cout << "0";
		cout << dcur->am << "/" << dcur->ay << ": ";
		if (dcur->pre == 1) cout << "v";
		cout << endl;
		dcur = dcur->dNext;
	}*/
}

void ShowAttList(Student_Course* stuHead, int n, int ADNo) {
	Student_Course* stucur = stuHead;

	int width = 1 + 10 + 1 + (5 + 1) * ADNo;
	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;

	cout << "|    ID    |";
	AttDay* dcur = stucur->dHead;
	for (int i = 0; i < ADNo; i++) {
		if (dcur->ad < 10) cout << "0";
		cout << dcur->ad << "/";
		if (dcur->am < 10) cout << "0";
		cout << dcur->am << "|";
		dcur = dcur->dNext;
	} cout << endl;

	for (int i = 0; i < n; i++) {

		ShowAttDay(stucur, ADNo);
		if (i < n - 1) stucur = stucur->stuNext;
	}

	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
}

bool ExportAttList(Student_Course* stuHead, int n, string fName) {
	ofstream fout;
	fout.open(fName + ".csv");
	if (!fout.is_open()) {
		cout << "Cannot create/open file." << endl << endl;
		return false;
	}
	else {
		fout << "ID,Student,";
		AttDay* dcur = stuHead->dHead;
		while (dcur != nullptr) {
			fout << "=\"";
			if (dcur->ad < 10) fout << "0";
			fout << dcur->ad << "/";
			if (dcur->am < 10) fout << "0";
			fout << dcur->am << "/" << dcur->ay << "\",";
			dcur = dcur->dNext;
		} fout << endl;
		Student_Course* stucur = stuHead;
		for (int i = 0; i < n; i++) {
			fout << stucur->id << "," << stucur->name << ",";
			dcur = stucur->dHead;
			while (dcur != nullptr) {
				if (dcur->pre == -1)
					fout << " ,";
				else fout << "v,";
				dcur = dcur->dNext;
			} fout << endl;
			if (i < n - 1) stucur = stucur->stuNext;
		}
	}
	return true;
}

void EditAtt(Student_Course*& stuHead, int n, string fName) {
	cout << "-Edit Attendance-" << endl << endl;

	int idcur;
	cout << "[- ID ----------------]" << endl;
	cout << "> "; cin >> idcur;
	while (idcur < 10000000 || idcur > 99999999) {
		cout << "Invalid input" << endl;
		cout << "> "; cin >> idcur;
	}
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		if (stucur->id == idcur) break;
		if (i < n - 1) stucur = stucur->stuNext;
		else {
			cout << "Cannot find ID" << endl << endl;
			return;
		}
	}
	AttDay* dcur = stucur->dHead;
	char dtemp[11]; int ddtemp, dmtemp, dytemp;
	cout << "[- Date (dd/mm/yyyy) -]" << endl;
	cout << "> "; cin >> dtemp;
	while (dtemp[2] != '/' && dtemp[5] != '/') {
		cout << "Invalid input" << endl;
		cout << "> "; cin >> dtemp;
	}
	ddtemp = ((int)dtemp[0] - 48) * 10 + ((int)dtemp[1] - 48);
	dmtemp = ((int)dtemp[3] - 48) * 10 + ((int)dtemp[4] - 48);
	dytemp = ((int)dtemp[6] - 48) * 1000 + ((int)dtemp[7] - 48) * 100
		+ ((int)dtemp[8] - 48) * 10 + ((int)dtemp[9] - 48);
	while (dcur != nullptr) {
		if (ddtemp == dcur->ad && dmtemp == dcur->am
			&& dytemp == dcur->ay) break;
		dcur = dcur->dNext;
	}
	if (dcur == nullptr) {
		cout << "Cannot find date." << endl << endl;
		return;
	}
	if (dcur->pre == -1) dcur->pre = 1;
	else dcur->pre = -1;
	cout << "Edit complete." << endl;
	SaveEdit(stuHead, n, fName);
	cin.ignore();
}

void SaveEdit(Student_Course* stuHead, int n, string fName) {
	ofstream fout;
	fout.open(fName + ".txt");
	if (!fout.is_open()) {
		cout << "Cannot open file for saving." << endl;
	}
	else {
		fout << n << endl;
		Student_Course* stucur = stuHead;
		for (int i = 0; i < n; i++) {
			fout << stucur->id << endl;
			fout << stucur->pass << endl;
			fout << stucur->name << endl;
			fout << stucur->by << " ";
			if (stucur->bm < 10) fout << "0";
			fout << stucur->bm << " ";
			if (stucur->bd < 10) fout << "0";
			fout << stucur->bd << endl;
			fout << stucur->clss << endl;
			fout << stucur->active << endl;
			fout << stucur->sc_mid << endl;
			fout << stucur->sc_fin << endl;
			fout << stucur->sc_lab << endl;
			fout << stucur->sc_ave << endl;
			AttDay* dcur = stucur->dHead;
			while (dcur != nullptr) {
				fout << dcur->ay << " ";
				if (dcur->am < 10) fout << "0";
				fout << dcur->am << " ";
				if (dcur->ad < 10) fout << "0";
				fout << dcur->ad << " ";
				if (dcur->sHr < 10) fout << "0";
				fout << dcur->sHr << " ";
				if (dcur->sMin < 10) fout << "0";
				fout << dcur->sMin << " ";
				if (dcur->eHr < 10) fout << "0";
				fout << dcur->eHr << " ";
				if (dcur->eMin < 10) fout << "0";
				fout << dcur->eMin << " ";
				fout << dcur->pre << endl;
				dcur = dcur->dNext;
			}
			fout << "-" << endl;
			if (i < n - 1)
				stucur = stucur->stuNext;
		}
		fout.close();
	}
}

bool GetCourse(Student_Course*& stuHead, int& n, string fName) {
	if (stuHead != nullptr) GetCourse_DelStu(stuHead, n);
	ifstream fin;
	fin.open(fName + ".txt");
	int AttDayNo = 0;
	if (fin.is_open()) {
		AttDayNo = CourseAttDay(fin) - 11;
		fin.close();
	}
	else {
		return false;
	}
	fin.open(fName + ".txt");
	if (!fin.is_open()) {
		/*cout << "Cannot open file." << endl;*/
		return false;
	}
	else {
		fin >> n;
		string temp; getline(fin, temp);
		Student_Course* stu = GetStudentFile(fin, AttDayNo);
		while (stu->active == 0)
			stu = GetStudentFile(fin, AttDayNo);
		stuHead = stu;
		Student_Course* stucur = stu;
		while (!fin.eof()) {
			stu = GetStudentFile(fin, AttDayNo);
			while (stu->active == 0)
				stu = GetStudentFile(fin, AttDayNo);
			stucur->stuNext = stu;
			stucur = stucur->stuNext;
		}
		fin.close();
	}
	return true;
};

void ShowCourse(Student_Course* stuHead, int n) {
	int width = 1 + 10 + 1 + 30 + 1 + 12 + 1 + 12 + 1 + 8 + 1;
	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
	cout << "|    ID    |             Name             |   Class    |    DoB     | Active |" << endl;

	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < width; i++) {
			if (i == 0 || i == width - 1) cout << "|";
			else cout << "-";
		} cout << endl;
		cout << "| " << stucur->id << " | ";
		cout << stucur->name;
		for (int i = 0; i < 29 - stucur->name.length(); i++) cout << " ";
		cout << "| " << stucur->clss;
		for (int i = 0; i < 11 - stucur->clss.length(); i++) cout << " ";
		cout << "| ";
		if (stucur->bd < 10) cout << "0";
		cout << stucur->bd << "/";
		if (stucur->bm < 10) cout << "0";
		cout << stucur->bm << "/" << stucur->by << " | ";
		cout << "  ";
		if (stucur->active == 1) cout << "v";
		else cout << " ";
		cout << "    |";
		cout << endl;
		if (i < n - 1) stucur = stucur->stuNext;



		/*cout << "[" << stucur->id << "]" << endl;
		cout << stucur->name << endl;
		if (stucur->bd < 10) cout << "0";
		cout << stucur->bd << "/";
		if (stucur->bm < 10) cout << "0";
		cout << stucur->bm << "/" << stucur->by << endl;
		cout << stucur->clss << endl;
		if (i < n - 1) stucur = stucur->stuNext;
		cout << endl;*/
	}

	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
}

void ShowScoreBoard(Student_Course* stuHead, int n) {

	int width = 1 + 10 + 1 + 30 + 1 + 9 + 1 + 9 + 1 + 9 + 1 + 9 + 1;
	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
	cout << "|    ID    |             Name             |   Mid   |  Final  |  Bonus  | Average |" << endl;

	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		ShowScore(stucur);
		if (i < n - 1) {
			stucur = stucur->stuNext;
		}
	}
	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
}

int ScoreLength(float sc) {
	int length = 0;
	float sc_floor = floor(sc);
	float sc_redun = sc - sc_floor;
	while (sc_redun - floor(sc_redun) > 0) {
		sc_redun *= 10;
	}
	int sc_floor_int = static_cast<int> (sc_floor);
	int sc_redun_int = static_cast<int> (sc_redun);
	if (sc_redun_int > 0) {
		length++;
		string sc_redun_str = to_string(sc_redun_int);
		length += sc_redun_str.length();
	}
	string sc_floor_str = to_string(sc_floor_int);
	length += sc_floor_str.length();
	return length;
}

void ShowScore(Student_Course* stu) {
	int width = 1 + 10 + 1 + 30 + 1 + 9 + 1 + 9 + 1 + 9 + 1 + 9 + 1;
	for (int i = 0; i < width; i++) {
		if (i == 0 || i == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "| " << stu->id << " | ";
	cout << stu->name;
	for (int i = 0; i < 29 - stu->name.length(); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_mid;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_mid); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_fin;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_fin); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_lab;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_lab); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_ave;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_ave); i++) {
		cout << " ";
	} cout << "|" << endl;

	/*cout << "[" << stu->id << "]" << endl;
	cout << stu->name << endl;
	cout << "-Scores-" << endl;
	cout << "Mid-term: " << stu->sc_mid << endl;
	cout << "Final   : " << stu->sc_fin << endl;
	cout << "Bonus   : " << stu->sc_lab << endl;
	cout << "Total   : " << stu->sc_ave << endl;
	cout << endl;*/
}

void ShowScoreSolo(Student_Course* stu) {
	int width = 1 + 10 + 1 + 30 + 1 + 9 + 1 + 9 + 1 + 9 + 1 + 9 + 1;
	for (int i = 0; i < width; i++) {
		if (i == 0 || i == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "| " << stu->id << " | ";
	cout << stu->name;
	for (int i = 0; i < 29 - stu->name.length(); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_mid;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_mid); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_fin;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_fin); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_lab;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_lab); i++) {
		cout << " ";
	} cout << "| ";
	cout << stu->sc_ave;
	for (int i = 0; i < 8 - ScoreLength(stu->sc_ave); i++) {
		cout << " ";
	} cout << "|" << endl;

	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	}
	cout << endl;
}

void EditScore(Student_Course*& stuHead, int n, string fName) {
	std::system("cls");
	cout << "-Edit Grade-" << endl << endl;

	int ans = -1;
	/*while (ans != 4) {*/
	ShowScoreBoard(stuHead, n);
	int idcur;
	/*cout << "(Enter 0 to return)" << endl;*/
	cout << endl;
	cout << "[- ID --------]" << endl;
	cout << "> "; cin >> idcur;
	/*if (idcur == 0) {
		return;
	}*/
	while (idcur < 10000000 || idcur > 99999999) {
		cout << "Invalid input" << endl;
		cout << "> "; cin >> idcur;
	}
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		if (stucur->id == idcur) break;
		if (i < n - 1) stucur = stucur->stuNext;
		else {
			cout << "Cannot find ID." << endl << endl;
			return;
		}
	}
	system("cls");

	Menu_EditScore(stucur, n);
	SaveEdit(stuHead, n, fName);
	cin.ignore();

	/*cout << "Choose which score to edit" << endl;
	cout << "0 - Midterm" << endl;
	cout << "1 - Final" << endl;
	cout << "2 - Bonus" << endl;
	cout << "3 - Total" << endl;
	cout << "4 - Back" << endl;
	cout << "> ";
	cin >> ans;
	while (ans < 0 || ans > 4) {
		cout << "Invalid input" << endl;
		cout << "> "; cin >> ans;
	}
	float ans_sc;
	if (ans != 4) {
		cout << "Input new score: ";
		cin >> ans_sc;
		while (ans_sc < 0 || ans_sc > 11) {
			cout << "Invalid input" << endl;
			cout << "> "; cin >> ans_sc;
		}
	}
	switch (ans) {
	case 0:
		stucur->sc_mid = ans_sc;
		break;
	case 1:
		stucur->sc_fin = ans_sc;
		break;
	case 2:
		stucur->sc_lab = ans_sc;
		break;
	case 3:
		stucur->sc_ave = ans_sc;
		break;
	}
	if (ans != 4) {
		cout << "Edit complete" << endl;
	}
	system("cls");
}*/
/*}*/
}

bool ImportScoreBoard(Student_Course*& stuHead, int n, string fName) {
	ifstream fin;
	fin.open(fName + ".csv");
	if (!fin.is_open()) {
		return false;
	}
	else {
		ofstream fout;
		fout.open(fName + "-temp.txt");
		if (!fout.is_open()) {
			return false;
		}
		else {
			string temp;
			getline(fin, temp);
			while (!fin.eof()) {
				getline(fin, temp);
				replace(temp.begin(), temp.end(), ' ', '_');
				replace(temp.begin(), temp.end(), ',', ' ');
				fout << temp << endl;
			}
			fout.close();
		}
		fin.close();
	}

	fin.open(fName + "-temp.txt");
	if (!fin.is_open()) {
		return false;
	}
	else {
		Student_Course* stucur = stuHead;
		char b[100];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 7; j++) {
				fin >> b;
				if (j >= 3) {
					char* b_ = b;
					float k = atof(b_);
					switch (j) {
					case 3:
						stucur->sc_mid = k;
						break;
					case 4:
						stucur->sc_fin = k;
						break;
					case 5:
						stucur->sc_lab = k;
						break;
					case 6:
						stucur->sc_ave = k;
						break;
					}
				}
			}
			if (i < n - 1)
				stucur = stucur->stuNext;
		}
		/*cout << "Import complete" << endl;
		system("pause");*/
		fin.close();
	}
	remove((fName + "-temp.txt").c_str());
	return true;
}

void GetCourse_DelStu(Student_Course*& stuHead, int& n) {
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		AttDay* dcur = stucur->dHead;
		while (dcur != nullptr) {
			AttDay* ddel = dcur;
			dcur = dcur->dNext;
			delete ddel;
		}
		Student_Course* studel = stucur;
		if (i < n - 1)
			stucur = stucur->stuNext;
		delete studel;
	}
	n = 0;
}

void ShowCourseList(string Sem, char* Link) {
	std::system("cls");
	cout << "-List of Courses-" << endl << endl;
	string fName(Link);
	fName = fName + Sem + "-AllCourses.txt";
	ifstream fin;
	fin.open(fName);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
	}
	else {
		int n;
		fin >> n; fin.ignore(2);
		if (n == 0) {
			cout << "No Course available." << endl;
			std::system("pause");
			fin.close();
			return;
		}
		cout << "Total: " << n << endl << endl;
		int width = 1 + 12 + 1 + 35 + 1;

		for (int i = 0; i < n; i++) {
			cout << endl;
			for (int i = 0; i < width; i++) {
				if (i == 0) cout << "[";
				else if (i == width - 1) cout << "]";
				else cout << "-";
			} cout << endl;
			string Line; int EndSpace = 0;
			for (int j = 0; j < COURSELINE; j++) {
				if (j == 3 || j == 6 || j == 5 ||
					j == COURSELINE - 1) {
					getline(fin, Line);
					continue;
				}
				switch (j) {
				case 0:
					cout << "| ID         |";
					break;
				case 1:
					cout << "| Name       |";
					break;
				case 2:
					cout << "| Class      |";
					break;
				case 4:
					cout << "| Lecturer   |";
					break;
				case 7:
					cout << "| Start Date |";
					break;
				case 8:
					cout << "| End Date   |";
					break;
				case 9:
					cout << "| Week Date  |";
					break;
				case 10:
					cout << "| Start Time |";
					break;
				case 11:
					cout << "| End Time   |";
					break;
				case 12:
					cout << "| Room       |";
					break;
				} cout << " ";
				if (j == 7 || j == 8) {
					int xd, xm, xy;
					fin >> xy >> xm >> xd;
					fin.ignore();
					if (xd < 10) cout << "0";
					cout << xd << "/";
					if (xm < 10) cout << "0";
					cout << xm << "/" << xy;
					EndSpace = 34 - 10;
				}
				else if (j == 10 || j == 11) {
					int xh, xm;
					fin >> xh >> xm;
					fin.ignore();
					if (xh < 10) cout << "0";
					cout << xh << ":";
					if (xm < 10) cout << "0";
					cout << xm;
					EndSpace = 34 - 5;
				}

				else {
					getline(fin, Line);

					cout << Line;
					EndSpace = 34 - Line.length();
				}
				for (int k = 0; k < EndSpace; k++)
					cout << " ";
				cout << "|" << endl;

				if (j < COURSELINE - 2) {
					for (int k = 0; k < width; k++) {
						if (k == 0) cout << "|";
						else if (k == width - 1) cout << "|";
						else cout << "-";
					} cout << endl;
				}
			}
			for (int i = 0; i < width; i++) {
				if (i == 0) cout << "[";
				else if (i == width - 1) cout << "]";
				else cout << "-";
			} cout << endl << endl;

		}
		fin.close();
	}
	cout << endl;
	std::system("pause");
}

bool CheckStuInCourse(string fName, string Class, string Course, int id) {
	ifstream fin;
	fin.open(fName + "-" + Class + "-" + Course + "-Student.txt");
	if (!fin.is_open()) {
		return false;
	}
	string Line; int x = 0, n, active = 0;
	fin >> n; fin.ignore();
	int AttDayNo = CourseAttDay(fin) + 1;
	for (int i = 0; !fin.eof(); i++) {
		for (int j = 0; j < AttDayNo; j++) {
			if (j == 0) {
				fin >> x; fin.ignore();
			}
			else {
				if (x == id && j == 5) {
					fin >> active; fin.ignore();
					fin.close();
					if (active == 1) return true;
					else return false;
				}
				else getline(fin, Line);
			}
		}
	}
	fin.close();
	return false;
}

void DrawCourseLec(CourseSchedule* crs) {
	int width = 1 + 10 + 1 + 10 + 1 + 5 + 1 + 12 + 1 + 12 + 1 + 7 + 1 + 7 + 1 + 7 + 1;
	for (int j = 0; j < width; j++) {
		if (j == 0 || j == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "|";
	for (int i = 0; i < 8; i++) {
		string Line; int LineLen;
		cout << " ";
		switch (i) {
		case 0:
			Line = crs->clss;
			LineLen = 10;
			break;
		case 1:
			Line = crs->id;
			LineLen = 10;
			break;
		case 2:
			Line = crs->dow;
			LineLen = 5;
			break;
		case 3:
			if (crs->sd < 10) cout << "0";
			cout << crs->sd << "/";
			if (crs->sm < 10) cout << "0";
			cout << crs->sm << "/";
			cout << crs->sy << " |";
			break;
		case 4:
			if (crs->ed < 10) cout << "0";
			cout << crs->ed << "/";
			if (crs->em < 10) cout << "0";
			cout << crs->em << "/";
			cout << crs->ey << " |";
			break;
		case 5:
			if (crs->sHr < 10) cout << "0";
			cout << crs->sHr << ":";
			if (crs->sMin < 10) cout << "0";
			cout << crs->sMin << " |";
			break;
		case 6:
			if (crs->eHr < 10) cout << "0";
			cout << crs->eHr << ":";
			if (crs->eMin < 10) cout << "0";
			cout << crs->eMin << " |";
			break;
		case 7:
			Line = crs->room;
			LineLen = 7;
			break;
		}
		if (i == 0 || i == 1 || i == 2 || i == 7) {
			cout << Line;
			for (int j = 0; j < LineLen - 1 - Line.length(); j++) {
				cout << " ";
			} cout << "|";
		}
	}
	cout << endl;
}

bool CheckLecInCourse(CourseSchedule*crs, string lecid) {
	if (crs->lecid == lecid) return true;
	return false;
}

void DrawScheduleIndexLec(CourseSchedule* crs) {
	int width = 1 + 10 + 1 + 10 + 1 + 35 + 1;
	for (int j = 0; j < width; j++) {
		if (j == 0 || j == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "|";
	for (int i = 0; i < 3; i++) {
		string Line; int LineLen = 0;
		cout << " ";
		switch (i) {
		case 0:
			Line = crs->clss;
			LineLen = 10;
			break;
		case 1:
			Line = crs->id;
			LineLen = 10;
			break;
		case 2:
			Line = crs->name;
			LineLen = 35;
			break;
		}
		cout << Line;
		for (int j = 0; j < LineLen - 1 - Line.length(); j++)
			cout << " ";
		cout << "|";
	}
	cout << endl;
}

void ShowCourseListLec(string Sem, char* Link, string lecid) {
	std::system("cls");
	cout << "-List of Courses-" << endl << endl;
	string fName(Link);
	fName = fName + Sem + "-AllCourses.txt";
	ifstream fin; fin.open(fName);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		std::system("pause");
		return;
	} else {
		CourseSchedule* cHead;
		int n = 0;
		fin >> n; fin.ignore(2);
		CourseSchedule* crs = GetCourseSchedule(fin);
		cHead = crs;
		CourseSchedule* crscur = cHead;
		for (int i = 1; i < n; i++) {
			crs = GetCourseSchedule(fin);
			crscur->cNext = crs;
			crscur = crscur->cNext;
		}

		int width = 1 + 10 + 1 + 10 + 1 + 5 + 1 + 12 + 1 + 12 + 1 + 7 + 1 + 7 + 1 + 7 + 1;
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		}
		cout << endl;
		cout << "|  Class   |    ID    | DoW |   StDate   |   EnDate   | STime | ETime | Room  |" << endl;

		crscur = cHead;
		for (int i = 0; i < n; i++) {
			if (CheckLecInCourse(crscur, lecid)) {
				DrawScheduleCourse(crscur);
			}
			crscur = crscur->cNext;
		}
		for (int i = 0; i < width; i++) {
			if (i == 0) cout << "[";
			else if (i == width - 1) cout << "]";
			else cout << "-";
		}
		cout << endl << endl << endl;

		cout << "-Index-" << endl << endl;
		width = 1 + 10 + 1 + 10 + 1 + 35 + 1;
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;
		cout << "|  Class   |    ID    |               Name                |" << endl;
		crscur = cHead;
		for (int i = 0; i < n; i++) {
			if (CheckLecInCourse(crscur, lecid)) {
				DrawScheduleIndexLec(crscur);
			}
			crscur = crscur->cNext;
		}
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;

		DeleteScheduleList(cHead, n);
		fin.close();
	}
	cout << endl;
	std::system("pause");
}

CourseSchedule* GetCourseSchedule(ifstream& fin) {
	CourseSchedule* crs = new CourseSchedule;
	string Line;
	getline(fin, crs->id);
	getline(fin, crs->name);
	getline(fin, crs->clss);
	getline(fin, crs->lecid);
	getline(fin, crs->lecturer);
	getline(fin, Line); getline(fin, Line);
	fin >> crs->sy >> crs->sm >> crs->sd; fin.ignore();
	fin >> crs->ey >> crs->em >> crs->ed; fin.ignore();
	getline(fin, crs->dow);
	fin >> crs->sHr >> crs->sMin; fin.ignore();
	fin >> crs->eHr >> crs->eMin; fin.ignore();
	getline(fin, crs->room);
	getline(fin, Line);
	crs->cNext = nullptr;
	return crs;
}

void DrawScheduleCourse(CourseSchedule* crs) {
	int width = 1 + 10 + 1 + 10 + 1 + 5 + 1 + 12 + 1 + 12 + 1 + 7 + 1 + 7 + 1 + 7 + 1;
	for (int j = 0; j < width; j++) {
		if (j == 0 || j == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "|";
	for (int i = 0; i < 8; i++) {
		string Line; int LineLen;
		cout << " ";
		switch (i) {
		case 0:
			Line = crs->clss;
			LineLen = 10;
			break;
		case 1:
			Line = crs->id;
			LineLen = 10;
			break;
		case 2:
			Line = crs->dow;
			LineLen = 5;
			break;
		case 3:
			if (crs->sd < 10) cout << "0";
			cout << crs->sd << "/";
			if (crs->sm < 10) cout << "0";
			cout << crs->sm << "/";
			cout << crs->sy << " |";
			break;
		case 4:
			if (crs->ed < 10) cout << "0";
			cout << crs->ed << "/";
			if (crs->em < 10) cout << "0";
			cout << crs->em << "/";
			cout << crs->ey << " |";
			break;
		case 5:
			if (crs->sHr < 10) cout << "0";
			cout << crs->sHr << ":";
			if (crs->sMin < 10) cout << "0";
			cout << crs->sMin << " |";
			break;
		case 6:
			if (crs->eHr < 10) cout << "0";
			cout << crs->eHr << ":";
			if (crs->eMin < 10) cout << "0";
			cout << crs->eMin << " |";
			break;
		case 7:
			Line = crs->room;
			LineLen = 7;
			break;
		}
		if (i == 0 || i == 1 || i == 2 || i == 7) {
			cout << Line;
			for (int j = 0; j < LineLen - 1 - Line.length(); j++) {
				cout << " ";
			} cout << "|";
		}
	}
	cout << endl;
}

void DrawScheduleIndex(CourseSchedule* crs) {
	int width = 1 + 10 + 1 + 10 + 1 + 35 + 1 + 25 + 1;
	for (int j = 0; j < width; j++) {
		if (j == 0 || j == width - 1) cout << "|";
		else cout << "-";
	} cout << endl;
	cout << "|";
	for (int i = 0; i < 4; i++) {
		string Line; int LineLen;
		cout << " ";
		switch (i) {
		case 0:
			Line = crs->clss;
			LineLen = 10;
			break;
		case 1:
			Line = crs->id;
			LineLen = 10;
			break;
		case 2:
			Line = crs->name;
			LineLen = 35;
			break;
		case 3:
			Line = crs->lecturer;
			LineLen = 25;
			break;
		}
		cout << Line;
		for (int j = 0; j < LineLen - 1 - Line.length(); j++)
			cout << " ";
		cout << "|";
	}
	cout << endl;
}

void DeleteScheduleList(CourseSchedule*& cHead, int n) {
	CourseSchedule* crscur = cHead;
	for (int i = 0; i < n; i++) {
		CourseSchedule* crsdel = crscur;
		crscur = crscur->cNext;
		delete crsdel;
	}
	cHead = nullptr;
}

void ShowSchedule(string Sem, char* Link, int id) {
	std::system("cls");
	cout << "-Schedule-" << endl << endl;
	string fName(Link), fNameCourse(Link + Sem);
	fName = fName + Sem + "-AllCourses.txt";
	ifstream fin;
	fin.open(fName);
	// Get all course
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return;
	}
	else {
		int n; fin >> n; fin.ignore(2);
		CourseSchedule* cHead;
		CourseSchedule* crs = GetCourseSchedule(fin);
		cHead = crs;
		CourseSchedule* crscur = crs;
		for (int i = 1; i < n; i++) {
			crs = GetCourseSchedule(fin);
			crscur->cNext = crs;
			crscur = crscur->cNext;
		}

		int width = 1 + 10 + 1 + 10 + 1 + 5 + 1 + 12 + 1 + 12 + 1 + 7 + 1 + 7 + 1 + 7 + 1;
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		}
		cout << endl;
		cout << "|  Class   |    ID    | DoW |   StDate   |   EnDate   | STime | ETime | Room  |" << endl;
		crscur = cHead;
		for (int i = 0; i < n; i++) {
			if (CheckStuInCourse(fNameCourse, crscur->clss, crscur->id, id)) {
				DrawScheduleCourse(crscur);
			}

			crscur = crscur->cNext;
		}
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;

		cout << endl << endl;

		cout << "-Index-" << endl << endl;
		width = 1 + 10 + 1 + 10 + 1 + 35 + 1 + 25 + 1;
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;
		cout << "|  Class   |    ID    |               Name                |        Lecturer         |" << endl;
		crscur = cHead;
		for (int i = 0; i < n; i++) {
			if (CheckStuInCourse(fNameCourse, crscur->clss, crscur->id, id)) {
				DrawScheduleIndex(crscur);
			}
			crscur = crscur->cNext;
		}
		for (int j = 0; j < width; j++) {
			if (j == 0) cout << "[";
			else if (j == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;

		DeleteScheduleList(cHead, n);
		fin.close();
	}

	cout << endl;
	std::system("pause");
}

bool ExportScoreBoard(Student_Course*& stuHead, int n, string fName) {
	ofstream fout;
	fout.open(fName + ".csv");
	if (!fout.is_open()) {
		return false;
	}
	else {
		fout << "No,ID,Full Name,Mid-term,Final,Bonus,Total" << endl;
		Student_Course* cur = stuHead;
		for (int i = 0; i < n; i++) {
			fout << i + 1 << ",";
			fout << cur->id << ",";
			fout << cur->name << ",";
			fout << cur->sc_mid << "," << cur->sc_fin << ","
				<< cur->sc_lab << "," << cur->sc_ave << endl;
			cur = cur->stuNext;
		}
	}
	return true;
}



void Advance_ShowScoreBoard(string YearSem) {
	std::system("cls");
	cout << "-Search & View Scoreboard of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot view Scoreboard." << endl;
		std::system("pause");
		return;
	}
	std::system("cls");
	cout << fName.substr(27, fName.length() - 27 - 1)
		<< "\t Scoreboard" << endl << endl;
	ShowScoreBoard(stuHead, n);
	cout << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_ExportScoreBoard(string YearSem) {
	std::system("cls");
	cout << "-Export Scoreboard of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	char Link_Scr[] = "Files/Scoreboard/";
	string fNameScr = fName.substr(13, fName.length() - 14);
	fNameScr = Link_Scr + fNameScr + "-Scoreboard";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot export Scoreboard." << endl;
		std::system("pause");
		return;
	}
	if (ExportScoreBoard(stuHead, n, fNameScr))
		cout << "Export complete." << endl;
	else cout << "Cannot export Scoreboard." << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_ImportScoreBoard(string YearSem) {
	std::system("cls");
	cout << "-Import Scoreboard of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	char Link_Scr[] = "Files/Scoreboard/";
	string fNameScr = fName.substr(13, fName.length() - 14);
	fNameScr = Link_Scr + fNameScr + "-Scoreboard";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot import Scoreboard." << endl;
		std::system("pause");
		return;
	}
	if (ImportScoreBoard(stuHead, n, fNameScr)) {
		cout << "Import complete." << endl;
		SaveEdit(stuHead, n, fNameStu);
	}
	else cout << "Cannot import Scoreboard." << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_EditScore(string YearSem) {
	std::system("cls");
	cout << "-Edit Grade-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	string fNameScr = fName + "Scoreboard";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot edit Grade." << endl;
		std::system("pause");
		return;
	}
	EditScore(stuHead, n, fNameStu);
	GetCourse_DelStu(stuHead, n);
}

void Advance_ShowAttList(string YearSem) {
	std::system("cls");
	cout << "-View Attendance List of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot view Attendance List." << endl;
		std::system("pause");
		return;
	}
	std::system("cls");
	cout << fName.substr(14, fName.length() - 14 - 1)
		<< "\t Attendance List" << endl << endl;

	ifstream fin; fin.open(fNameStu + ".txt");
	int AttDayNo = CourseAttDay(fin) - 11;
	fin.close();
	ShowAttList(stuHead, n, AttDayNo);
	cout << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_ExportAttList(string YearSem) {
	std::system("cls");
	cout << "-Export Attendance List-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	char Link_AttList[] = "Files/AttList/";
	
	string fNameAL = fName.substr(13, fName.length() - 14);
	fNameAL = Link_AttList + fNameAL + "-AttList";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot export Attendance List." << endl;
		std::system("pause");
		return;
	}

	if (ExportAttList(stuHead, n, fNameAL))
		cout << "Export complete." << endl;
	else cout << "Cannot export Attendance List." << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_EditAtt(string YearSem) {
	std::system("cls");
	cout << "-Edit Attendance-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot edit Attendance List." << endl;
		std::system("pause");
		return;
	}
	ifstream fin; fin.open(fNameStu + ".txt");
	int AttDayNo = CourseAttDay(fin) - 11;
	fin.close();
	std::system("cls");
	cout << fName.substr(14, fName.length() - 14 - 1)
		<< "\t Attendance List" << endl << endl;
	ShowAttList(stuHead, n, AttDayNo);
	cout << endl;
	EditAtt(stuHead, n, fNameStu);
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_ShowCourse(string YearSem) {
	std::system("cls");
	cout << "-View Student List of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	string fNameAL = fName + "AttList";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot view Student List." << endl;
		std::system("pause");
		return;
	}
	std::system("cls");
	cout << fName.substr(14, fName.length() - 14 - 1)
		<< "\t Student List" << endl << endl;
	ShowCourse(stuHead, n);
	cout << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_CheckIn(string YearSem, int id) {
	std::system("cls");
	cout << "-Check-in-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	string fNameAL = fName + "AttList";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot Check-in." << endl;
		std::system("pause");
		return;
	}
	Student_Course* stu = GetStudent(stuHead, id);
	cout << endl;
	if (CheckIn(stu)) {
		cout << "Check-in successfully!" << endl;
		SaveEdit(stuHead, n, fNameStu);
	}
	else cout << "Cannot check-in." << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_CheckInRes(string YearSem, int id) {
	std::system("cls");
	cout << "-Check-in-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	string fNameAL = fName + "AttList";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot Check-in." << endl;
		std::system("pause");
		return;
	}
	Student_Course* stu = GetStudent(stuHead, id);
	cout << endl;
	CheckInRes(stu);
	cout << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}

void Advance_StuShowScore(string YearSem, int id) {
	std::system("cls");
	cout << "-View Score of a Course-" << endl << endl;
	char Link[] = "Files/Course/";
	string fName = GetFileName(YearSem, Link);
	string fNameStu = fName + "Student";
	string fNameAL = fName + "AttList";
	Student_Course* stuHead; int n = 0;
	if (!GetCourse(stuHead, n, fNameStu)) {
		cout << "Cannot Check-in." << endl;
		std::system("pause");
		return;
	}
	Student_Course* stu = GetStudent(stuHead, id);
	cout << endl;
	int width = 1 + 10 + 1 + 30 + 1 + 9 + 1 + 9 + 1 + 9 + 1 + 9 + 1;
	for (int i = 0; i < width; i++) {
		if (i == 0) cout << "[";
		else if (i == width - 1) cout << "]";
		else cout << "-";
	} cout << endl;
	cout << "|    ID    |             Name             |   Mid   |  Final  |  Bonus  | Average |" << endl;
	ShowScoreSolo(stu);
	cout << endl;
	system("pause");
	GetCourse_DelStu(stuHead, n);
}