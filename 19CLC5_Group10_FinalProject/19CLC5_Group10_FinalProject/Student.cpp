// STUDENT FUNCTION

#include "Course.h"

bool CheckIn(Student_Course*& stu) {
	AttDay* dcur = stu->dHead;

	time_t rawtime;
	struct tm* ti;

	time(&rawtime);
	ti = localtime(&rawtime);
	while (true) {
		if (ti->tm_year == dcur->ay - 1900 &&
			ti->tm_mon + 1 == dcur->am &&
			ti->tm_mday == dcur->ad) {
			if (ti->tm_hour >= dcur->sHr &&
				ti->tm_hour <= dcur->eHr) {
				if ((ti->tm_hour == dcur->sHr &&
					ti->tm_min <= dcur->sMin) ||
					(ti->tm_hour == dcur->eHr &&
						ti->tm_min >= dcur->eMin)) {
					dcur->pre = 1;
					return true;
				}
			}
		}
		if (dcur->dNext != nullptr)
			dcur = dcur->dNext;
		else break;
	}
	return false;
}

void CheckInRes(Student_Course* stu) {
	AttDay* dcur = stu->dHead;

	time_t rawtime;
	struct tm* ti;
	bool first = false;

	time(&rawtime);
	ti = localtime(&rawtime);
	if (ti->tm_year <= dcur->ay - 1900 &&
		ti->tm_mon + 1 <= dcur->am &&
		ti->tm_mday <= dcur->ad) {
		first = true;
	}
	if (!first)
		while (true) {
			if (dcur->dNext != nullptr)
				/*if (ti->tm_year <= dcur->dNext->ay - 1900 &&
					ti->tm_mon + 1 <= dcur->dNext->am &&
					ti->tm_mday <= dcur->dNext->ad) {
					break;
				}*/
				if ((ti->tm_year < dcur->dNext->ay - 1900) ||
					((ti->tm_year == dcur->dNext->ay - 1900) && (ti->tm_mon + 1 < dcur->dNext->am)) ||
					((ti->tm_mon + 1 == dcur->dNext->am) && (ti->tm_mday < dcur->dNext->ad))) {
					break;
				}
			if (dcur->dNext != nullptr)
				dcur = dcur->dNext;
			else break;
		}
	cout << "-Last Attendance Date-" << endl;
	if (dcur->ad < 10) cout << "0";
	cout << dcur->ad << "/";
	if (dcur->am < 10) cout << "0";
	cout << dcur->am << "/";
	cout << dcur->ay << " - ";
	if (dcur->pre == -1)
		cout << "Absent";
	else cout << "Present";
	cout << endl;
}

Student_Course* GetStudent(Student_Course* stuHead, int id) {
	Student_Course* stucur = stuHead;
	while (true) {
		if (stucur->id == id)
			return stucur;
		if (stucur->stuNext != nullptr)
			stucur = stucur->stuNext;
		else return nullptr;
	}
}