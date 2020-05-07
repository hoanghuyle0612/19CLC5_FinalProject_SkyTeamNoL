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
					ti->tm_min < dcur->sMin) ||
					(ti->tm_hour == dcur->eHr &&
						ti->tm_min > dcur->eMin)) {
					dcur->pre = 1;
					return true;
				}
			}
		}
		if (dcur->dNext != nullptr)
			dcur = dcur->dNext;
	}
	return false;
}