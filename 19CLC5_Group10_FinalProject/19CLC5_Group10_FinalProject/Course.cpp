// COURSE FUNCTION

#include "Course.h"

string GetFileName(string Sem, char* Link) {

	cout << "-Enter Course's file-" << endl;

	const int lim = 100;

	char Class[lim], Course[lim];
	/*cin.ignore();*/
	cout << "Enter class: ";
	cin.getline(Class, lim);
	/*while (strlen(Class) + 1 != Class_lim) {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Class, lim);
	}*/
	cout << "Enter course: ";
	cin.getline(Course, lim);
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

Student_Course* GetStudentFile(ifstream& fin) {
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
	for (int i = 1; i < TOTALDAY; i++) {
		d = CreateDay(fin);
		dcur->dNext = d;
		dcur = dcur->dNext;
	} // 11 --> 19
	string temp; getline(fin, temp);
	return stu;
}

void ShowAttDay(Student_Course* stu) {
	cout << "[" << stu->id << "]" << endl;
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
	}
}

void ShowAttList(Student_Course* stuHead, int n) {
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {

		AttDay* dcur = stuHead->dHead;
		ShowAttDay(stucur);
		if (i < n - 1) stucur = stucur->stuNext;
		cout << endl;
	}
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
	cout << "-Attendance Edit-" << endl;

	int idcur;
	cout << "Enter ID: "; cin >> idcur;
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
	cout << "Enter date (dd/mm/yyyy): "; cin >> dtemp;
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
		cout << "Cannot find date" << endl << endl;
		return;
	}
	if (dcur->pre == -1) dcur->pre = 1;
	else dcur->pre = -1;
	SaveEdit(stuHead, n, fName);
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
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return false;
	}
	else {
		fin >> n;
		string temp; getline(fin, temp);
		Student_Course* stu = GetStudentFile(fin);
		stuHead = stu;
		Student_Course* stucur = stu;
		while (!fin.eof()) {
			stu = GetStudentFile(fin);
			stucur->stuNext = stu;
			stucur = stucur->stuNext;
		}
		fin.close();
	}
	return true;
};

void ShowCourse(Student_Course* stuHead, int n) {
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		cout << "[" << stucur->id << "]" << endl;
		cout << stucur->name << endl;
		if (stucur->bd < 10) cout << "0";
		cout << stucur->bd << "/";
		if (stucur->bm < 10) cout << "0";
		cout << stucur->bm << "/" << stucur->by << endl;
		cout << stucur->clss << endl;
		/*cout << "-Scores-" << endl;
		cout << "Mid-term: " << stucur->sc_mid << endl;
		cout << "Final   : " << stucur->sc_fin << endl;
		cout << "Lab     : " << stucur->sc_lab << endl;
		cout << "Average : " << stucur->sc_ave << endl;
		cout << "-Attendance-" << endl;
		ShowAttDay(stucur);*/
		if (i < n - 1) stucur = stucur->stuNext;
		cout << endl;
	}
}

void ShowScoreBoard(Student_Course* stuHead, int n) {
	Student_Course* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		ShowScore(stucur);
		if (i < n - 1) {
			stucur = stucur->stuNext;
		}
	}
}

void ShowScore(Student_Course* stu) {
	cout << "[" << stu->id << "]" << endl;
	cout << stu->name << endl;
	cout << "-Scores-" << endl;
	cout << "Mid-term: " << stu->sc_mid << endl;
	cout << "Final   : " << stu->sc_fin << endl;
	cout << "Bonus   : " << stu->sc_lab << endl;
	cout << "Total   : " << stu->sc_ave << endl;
	cout << endl;
}

void EditScore(Student_Course*& stuHead, int n, string fName) {
	cout << "-Score Edit-" << endl;

	int ans = -1;
	while (ans != 4) {
		ShowScoreBoard(stuHead, n);
		int idcur;
		cout << "(Enter 0 to return)" << endl;
		cout << "Enter ID: "; cin >> idcur;
		if (idcur == 0) {
			return;
		}
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
		system("cls");
		ShowScore(stucur);
		cout << "Choose which score to edit" << endl;
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
	}
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
	string fName(Link);
	fName = fName + Sem + ".txt";
	ifstream fin;
	fin.open(fName);
	if (!fin.is_open()) {
		cout << "Cannot find file" << endl;
	}
	else {
		int n;
		string Class, Course, CName;
		fin >> n; fin.ignore();
		cout << "Total: " << n << endl;
		while (!fin.eof()) {
			fin.ignore(2);
			getline(fin, Class);
			getline(fin, Course);
			getline(fin, CName);
			cout << "[" << Class << " - "
				<< Course << "] " << CName << endl;
			fin.ignore(38);
		}
		fin.close();
	}
}