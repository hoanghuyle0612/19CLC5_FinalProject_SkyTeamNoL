// 05 - ACADEMIC STAFF - ATTENDANCE LIST - FUNCTION

#include "PTP_05_Header.h"

AttDay *CreateDay(int _dd, int _mm, int _yy, int _pres) {
	AttDay* d = new AttDay;
	d->dd = _dd; d->mm = _mm; d->yy = _yy;
	d->pres = _pres;
	d->dnext = nullptr;
	return d;
}

StudentAtt *CreateStuAtt(int _id, string _name, AttDayList _adlist) {
	StudentAtt* stu = new StudentAtt;
	stu->id = _id; stu->name = _name;
	stu->adlist = _adlist;
	stu->stunext = nullptr;
	return stu;
}

void ShowStudentAttList(StudentAttList list) {
	StudentAtt* cur = list.sahead;
	while (cur != nullptr) {
		cout << cur->id << endl;
		cout << cur->name << endl;
		AttDay* curday = cur->adlist.adhead;
		while (curday != nullptr) {
			if (curday->dd < 10) cout << "0";
			cout << curday->dd << "-";
			if (curday->mm < 10) cout << "0";
			cout << curday->mm << "-" << curday->yy << ": ";
			if (curday->pres == -1) cout << "Absent";
			else cout << "Present";
			cout << endl;
			curday = curday->dnext;
		}
		cur = cur->stunext;
	}
}

void DelStudentAttList(StudentAttList &list) {
	StudentAtt* cur = list.sahead;
	while (cur != nullptr) {
		StudentAtt* pdel = cur;
		AttDay* curday = cur->adlist.adhead;
		while (curday != nullptr) {
			AttDay* pdeld = curday;
			curday = curday->dnext;
			delete pdeld;
		}
		cur = cur->stunext;
		delete pdel;
	}
}

void SaveAttendanceList(ifstream &fin, StudentAttList &list, AttDayList &edlist) {
	AttDayList dlist;
	dlist.adhead = nullptr;
	AttDay* curday = nullptr;

	AttDayList tempdlist;
	tempdlist.adhead = nullptr;
	bool gettemp = false;

	list.sahead = nullptr;
	StudentAtt* curstu = nullptr;

	int _id; string _name;

	string pLine;
	int cnt = 0;
	for (int i = 0; !fin.eof(); i++) {
		if (i == 1 + 20 * cnt) fin >> _id; 
		if (i == 3 + 20 * cnt) getline(fin, _name);
		if (i >= 11 + 20 * cnt && i <= 19 + 20*cnt) {
			int pd, pm, py;
			fin >> py >> pm >> pd;
			int checkin;
			for (int j = 0; j < 5; j++) fin >> checkin;
			getline(fin, pLine);
			AttDay* p = CreateDay(pd, pm, py, checkin);
			if (i == 11 + 20 * cnt) {
				dlist.adhead = p;
				if (!gettemp) tempdlist.adhead = p;
				curday = p;
			} else {
				curday->dnext = p;
				curday = curday->dnext;
			}
		}
		if (i != 3 + 20*cnt && (i < 11 + 20*cnt || i > 19 + 20*cnt)) {
			getline(fin, pLine);
		}
		if (i < 1 + 20 * cnt || i == 2 + 20 * cnt || (i > 3 + 20 * cnt &&
			i < 11 + 20 * cnt) || i > 19 + 20 * cnt) {
			if (i >= 20 && i % 20 == 0) {
				StudentAtt* pstu = CreateStuAtt(_id, _name, dlist);
				if (cnt == 0) {
					list.sahead = pstu;
					curstu = pstu;
				} else {
					curstu->stunext = pstu;
					curstu = curstu->stunext;
				}
				dlist.adhead = nullptr;
				curday = nullptr;
				cnt++;	
			}
		}
	}
	edlist = tempdlist;
}

void ViewAttendanceList(StudentAttList &list, string& exfname, AttDayList &edlist, bool &exp) {

	// Get class & course

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
	cin.getline(Link, lim);
	while (Link[strlen(Link) - 1] != '/') {
		cout << "Invalid input. Please enter again." << endl;
		cin.getline(Link, lim);
	}

	// Search for the file

	string fClass(Class), fCourse(Course), fLink(Link);
	string fHead("2019-2020-HK2-");
	string fName(fLink + fHead + fClass + "-" + fCourse + "-Student");
	string fNametxt(fName + ".txt");
	exfname = fName; // for exporting purpose

	cout << "File: " << fNametxt << endl << endl;

	// Open & read file

	ifstream fin;
	fin.open(fNametxt);
	if (!fin.is_open()) {
		cout << "Cannot open file." << endl;
	} else {
		string pline;
		int cnt = 0;
		for (int i = 0; !fin.eof(); i++) {
			if (i < 11 + 20 * cnt || i > 19 + 20 * cnt)
				getline(fin, pline);
			if (i < 1 +20*cnt || i == 2 +20*cnt || (i > 3 +20*cnt &&
				i < 11 + 20*cnt) || i > 19 + 20*cnt) {
				if (i >= 20 && i % 20 == 0) {
					cnt++; cout << endl;
				}
				continue;
			}
			if (i >= 11 +20*cnt && i <= 19 +20*cnt) {
				int pd, pm, py;
				fin >> py >> pm >> pd;
				if (pd < 10) cout << "0";
				cout << pd << "-";
				if (pm < 10) cout << "0";
				cout << pm << "-" << py << ": ";
				int checkin;
				for (int j = 0; j < 5; j++) fin >> checkin;
				if (checkin == -1) cout << "Absent";
				else cout << "Present";
				cout << endl;
				getline(fin, pline);
			} else {
				cout << pline << endl;
			}
		}
	}
	fin.close();
	cout << endl;

	// Saving the list for exporting

	cout << "Export the attendance list? (Y/N): " << endl;
	char ans; cin >> ans;
	while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
		cout << "Invalid input. Please enter again (Y/N): ";
		cin >> ans;
	}
	if (ans == 'y' || ans == 'Y') {
		exp = true;
		fin.open(fNametxt);
		if (!fin.is_open()) {
			cout << "Cannot open file." << endl;
		} else {
			SaveAttendanceList(fin, list, edlist);
			fin.close();
		}
	}
}

void ExportAttList(ofstream &fout, StudentAttList list, AttDayList dlist) {
	fout << "ID,Student,";
	AttDay* curday = dlist.adhead;
	while (curday != nullptr) {
		fout << "=" << "\"";
		if (curday->dd < 10) fout << "0";
		fout << curday->dd << "/";
		if (curday->mm < 10) fout << "0";
		fout << curday->mm << "/" << curday->yy << "\"" << ",";
		curday = curday->dnext;
	}
	fout << "\n";
	StudentAtt* cur = list.sahead;
	while (cur != nullptr) {
		fout << cur->id << "," << cur->name << ",";
		curday = cur->adlist.adhead;
		while (curday != nullptr) {
			if (curday->pres == -1) fout << " ";
			else fout << "v";
			fout << ",";
			curday = curday->dnext;
		}
		cur = cur->stunext;
		fout << "\n";
	}
}