// STUDENT FUNCTION

#include "Course.h"

bool CheckIn(Student *&stu) {
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

void CheckInRes(Student *stu) {
	AttDay* dcur = stu->dHead;

	time_t rawtime;
	struct tm* ti;
	bool first = false;

	time(&rawtime);
	ti = localtime(&rawtime);
	if (ti->tm_year >= dcur->ay - 1900 &&
		ti->tm_mon + 1 >= dcur->am &&
		ti->tm_mday >= dcur->ad) {
		if (ti->tm_hour >= dcur->sHr &&
			ti->tm_hour <= dcur->eHr) {
			if ((ti->tm_hour == dcur->sHr &&
				ti->tm_min <= dcur->sMin) ||
				(ti->tm_hour == dcur->eHr &&
					ti->tm_min >= dcur->eMin)) {
				first = true;
			}
		}
	}
	if (!false)
	while (true) {
		if (ti->tm_year >= dcur->dNext->ay - 1900 &&
			ti->tm_mon + 1 >= dcur->dNext->am &&
			ti->tm_mday >= dcur->dNext->ad) {
			if (ti->tm_hour >= dcur->dNext->sHr &&
				ti->tm_hour <= dcur->dNext->eHr) {
				if ((ti->tm_hour == dcur->dNext->sHr &&
					ti->tm_min <= dcur->dNext->sMin) ||
					(ti->tm_hour == dcur->dNext->eHr &&
						ti->tm_min >= dcur->dNext->eMin)) {
					break;
				}
			}
		}
		if (dcur->dNext->dNext != nullptr)
			dcur = dcur->dNext;
		else break;
	}
	cout << "-Last Attendance Date-" << endl;
	if (dcur->ad < 10) cout << dcur->ad << "/";
	if (dcur->am < 10) cout << dcur->am << "/";
	cout << dcur->ay << " - ";
	if (dcur->dNext->pre == -1)
		cout << "Absent";
	else cout << "Present";
	cout << endl;
}

Student* GetStudent(Student *stuHead, int id) {
	Student* stucur = stuHead;
	while (true) {
		if (stucur->id == id)
			return stucur;
		if (stucur->stuNext != nullptr)
			stucur = stucur->stuNext;
		else return nullptr;
	}
}