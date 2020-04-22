// 05 - ACADEMIC STAFF - ATTENDANCE LIST - MAIN

#include "PTP_05_Header.h"

int main() {
	StudentAttList stulist;
	AttDayList exdlist;
	string ExFileName;
	bool exp = false;

	ViewAttendanceList(stulist, ExFileName, exdlist, exp);
	ExFileName = ExFileName + ".csv";

	if (exp && stulist.sahead != nullptr) {
		ShowStudentAttList(stulist);
		ofstream fout;
		fout.open(ExFileName);
		if (!fout.is_open()) {
			cout << "Cannot create file.";
		} else {
			ExportAttList(fout, stulist, exdlist);
			fout.close();
		}
		DelStudentAttList(stulist);
	}

	return 0;
}