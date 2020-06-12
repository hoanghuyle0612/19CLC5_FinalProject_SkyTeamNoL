// ATTENDANCE LIST FUNCTION

#include "AttendanceList.h"

AttDay* CreateDay(ifstream& fin) {
	AttDay* d = new AttDay;
	fin >> d->ay >> d->am >> d->ad;
	fin >> d->sHr >> d->sMin >> d->eHr >> d->eMin >> d->pre;
	string temp; getline(fin, temp);
	d->dNext = nullptr;
	return d;
}