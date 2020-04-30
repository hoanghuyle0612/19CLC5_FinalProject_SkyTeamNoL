// COURSE FUNCTION

#include "Course.h"

string GetFileName() {

	const int Class_lim = 8, Course_lim = 6, lim = 100;

	char Class[lim]; char Course[lim];
	cout << "Enter class: ";
	cin.getline(Class, lim);
	while (strlen(Class) + 1 != Class_lim) {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Class, lim);
	}
	cout << "Enter course: ";
	cin.getline(Course, lim);
	while (strlen(Course) + 1 != Course_lim) {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Course, lim);
	}

	// Get file link

	char Link[lim];
	cout << "Enter the file's directory (use '/' instead of '\\')." << endl;
	cout << "Ex: C:/Users/ADMIN/" << endl;
	cout << "Input: ";
	cin.getline(Link, lim);
	while (Link[strlen(Link) - 1] != '/') {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Link, lim);
	}

	// Search for the file

	string fClass(Class), fCourse(Course), fLink(Link);
	string fHead("2019-2020-HK2-");
	string fName(fLink + fHead + fClass + "-" + fCourse + "-Student");

	return fName;
}

Student *GetStudent(ifstream &fin) {
	Student* stu = new Student;
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

void ShowAttDay(Student *stu) {
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

void ShowAttList(Student* stuHead, int n) {
	Student* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		cout << "[" << stucur->id << "]" << endl;
		cout << stucur->name << endl;
		AttDay* dcur = stuHead->dHead;
		ShowAttDay(stucur);
		if (i < n - 1) stucur = stucur->stuNext;
		cout << endl;
	}
}

bool ExportAttList(Student* stuHead, int n, string fName) {
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
		Student* stucur = stuHead;
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
	cout << "Export complete" << endl << endl;
	ETC();
	return true;
}

void EditAtt(Student* stuHead, int n, string fName) {

	int idcur;
	cout << "Enter ID: "; cin >> idcur;
	while (idcur < 10000000 || idcur > 99999999) {
		cout << "Invalid input" << endl;
		cout << "Input: "; cin >> idcur;
	}
	Student* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		if (stucur->id == idcur) break;
		if (i < n - 1) stucur = stucur->stuNext;
		else {
			cout << "Cannot find ID" << endl << endl;
			ETC();
			return;
		}
	}
	AttDay* dcur = stucur->dHead;
	char dtemp[11]; int ddtemp, dmtemp, dytemp;
	cout << "Enter date (dd/mm/yyyy): "; cin >> dtemp;
	while (dtemp[2] != '/' && dtemp[5] != '/') {
		cout << "Invalid input" << endl;
		cout << "Input: "; cin >> dtemp;
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
		ETC();
		return;
	}
	if (dcur->pre == -1) dcur->pre = 1;
	else dcur->pre = -1;
	SaveAttList(stuHead, n, fName);
}

void SaveAttList(Student* stuHead, int n, string fName) {
	ofstream fout;
	fout.open(fName + ".txt");
	if (!fout.is_open()) {
		cout << "Cannot open file for saving." << endl;
	} else {
		fout << n << endl;
		Student* stucur = stuHead;
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

bool GetCourse(Student*& stuHead, int& n, string fName) {
	ifstream fin;
	fin.open(fName + ".txt");
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
		return false;
	}
	else {
		fin >> n;
		string temp; getline(fin, temp);
		Student* stu = GetStudent(fin);
		stuHead = stu;
		Student* stucur = stu;
		while (!fin.eof()) {
			stu = GetStudent(fin);
			stucur->stuNext = stu;
			stucur = stucur->stuNext;
		}
		fin.close();
	}
	return true;
};

void ShowCourse(Student *stuHead, int n) {
	Student* stucur = stuHead;
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

void GetCourse_DelStu(Student *&stuHead, int n) {
	Student* stucur = stuHead;
	for (int i = 0; i < n; i++) {
		AttDay* dcur = stucur->dHead;
		while (dcur != nullptr) {
			AttDay* ddel = dcur;
			dcur = dcur->dNext;
			delete ddel;
		}
		Student* studel = stucur;
		if (i < n - 1)
			stucur = stucur->stuNext;
		delete studel;
	}
}

void ETC() {
	char c;
	cout << "Enter anything to continue..." << endl;
	cin >> c;
}