// ATTENDANCE LIST HEADER

#ifndef _ATTENDANCE_LIST_H_
#define _ATTENDANCE_LIST_H_
#define TOTALDAY 9

#include "General.h"

struct AttDay { // Attendance Day
	int ad, am, ay, pre; // attendance day, month, year
						 // presence
	int sHr, sMin, eHr, eMin; // start/end hour/minute
	AttDay* dNext;
};

AttDay* CreateDay(ifstream& fin);

#endif