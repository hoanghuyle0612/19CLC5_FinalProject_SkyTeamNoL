// 05 - ACADEMIC STAFF - ATTENDANCE LIST - HEADER

#ifndef _05_ATTENDANCELIST_
#define _05_ATTENDANCELIST_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct AttDay { // Att = Attendance
	int dd, mm, yy, pres; // pres = presence (= 1 / -1 = absent)
	AttDay *dnext;
};

struct AttDayList {
	AttDay* adhead;
};

struct StudentAtt {
	int id;
	string name;
	AttDayList adlist;
	StudentAtt* stunext;
};

struct StudentAttList {
	StudentAtt* sahead;
};

AttDay* CreateDay(int _dd, int _mm, int _yy, int _pres);

StudentAtt* CreateStuAtt(int _id, string _name, AttDayList _adlist);

void ShowStudentAttList(StudentAttList list);

void DelStudentAttList(StudentAttList& list);

void SaveAttendanceList(ifstream& fin, StudentAttList& list, AttDayList &edlist);

void ViewAttendanceList(StudentAttList &list, string &exfname, AttDayList &edlist, bool &exp);

void ExportAttList(ofstream& fout, StudentAttList list, AttDayList dlist);

#endif