#include "Header.h"


int main()
{
	char AcaYear[] = "2019-2020", Semester[] = "HK2";
	CourseList* list = NULL;
	AddCourse(AcaYear, Semester);
	 
	
	//return 0;








	// TEST IMPORT COURSE !!!

	//CourseList* list = nullptr;
	//char AcaYear[] = "2019-2020",  Semester[] = "HK2";


	//

	//char temp[256], * Class, * Link;
	//cout << "Enter class: "; cin.getline(temp, 256, '\n');
	//Class = new char[strlen(temp) + 1];
	//strcpy_s(Class, strlen(temp) + 1, temp);
	//temp[0] = 0;
	//cout << "Enter Link: "; cin.getline(temp, 256, '\n');
	//Link = new char[strlen(temp) + 1];
	//strcpy_s(Link, strlen(temp) + 1, temp);
	//LoadCourses_csvfile(Link, list);
	//SaveSchedule(list, AcaYear, Semester, Class);

	//Save_Course_Stu_List(list, AcaYear, Semester, Class);

	return 0;

	/*CourseList* cur = list;
	while (cur != nullptr) {
		cout << cur->data.No << endl;
		cout << cur->data.ID <<endl;
		cout << cur->data.Name << endl;
		cout << cur->data.Class << endl;
		cout << cur->data.LecturerUser << endl << cur->data.LecturerName << endl << cur->data.LecturerDegree << endl << cur->data.LecturerGender << endl;
		cout << cur->data.StartDate.Year << " " << cur->data.StartDate.Month << " " << cur->data.StartDate.Day << endl;
		cout << cur->data.EndDate.Year << " " << cur->data.EndDate.Month << " " << cur->data.EndDate.Day << endl;
		cout << cur->data.DoW << endl;
		cout << cur->data.StartHour.h << " : " << cur->data.StartHour.m << endl;
		cout << cur->data.EndHour.h << " : " << cur->data.EndHour.m << endl;
		cout << cur->data.Room << endl;
		cout << "================================================" << endl;
		cur = cur->pNext;
	}
	cout << "hello ";*/

}
