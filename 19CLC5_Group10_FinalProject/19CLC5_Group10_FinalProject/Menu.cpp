// MENU FUNCTION

#include "Login.h"
#include "Course.h"
#define ONCOL 11
#define OFFCOL 15

void staffclass_func(staff a[], int& idx);
void Menu_Staff_Advance(staff a[], int& idx);
void Menu_Staff_Class(staff a[], int& idx);
void Menu_Staff_Course(staff a[], int& idx);
void Menu_Staff_Course_Course(staff a[], int& idx);
void Menu_Staff_Scoreboard(staff a[], int& idx, string YearSem);
void Menu_Staff_AttList(staff a[], int& idx, string YearSem);
void Menu_Lecturer_Advance(lecturer b[], int& idx);
void Menu_Student_Advance(student c[], int& idx);

void SetColor(int color[], int i) {
	if (i == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[1]);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
}

void Menu_Main() {
	std::system("cls");

	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0 };
	int ptr = 0;
	int width = 35;
	int last = 1;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();
		
		cout << setw(51) << "-MAIN MENU-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|    ----    |";
			SetColor(color, i[1]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|   |----|   |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|   |    |   |";
			SetColor(color, i[1]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|    \\__/    |";
			SetColor(color, i[1]);
			cout << setw(width) << "| ----->  |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|   /|  |\\   |";
			SetColor(color, i[1]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  |  \\/  |  |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  |      |  |";
			SetColor(color, i[1]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "     LOGIN    ";
			SetColor(color, i[1]);
			cout << setw(width) << "     EXIT     " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		/*while (true) {
			if (GetAsyncKeyState(VK_LEFT) != 0) {
				i[ptr] = 0;
				if (ptr == 0) ptr = 1;
				else ptr--;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0) {
				i[ptr] = 0;
				if (ptr == 1) ptr = 0;
				else ptr++;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (ptr) {
					case 0:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
						cin.ignore();
						login();
						break;
					case 1:
						system("cls");
						return;
				}
				break;
			}
		}*/
		/*Sleep(125);*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	if (ptr == 0) {
		login();
	} else {
		std::system("cls");
		cls();
	}

}

void Menu_Staff(staff a[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 3;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(53) << "-ACADEMIC STAFF-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 3
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  _         |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 4
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "| / \\_______ |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 5
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| \\_/    | | |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ----->  |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 6
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 7
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "ACADEMIC STAFF";
			SetColor(color, i[1]);
			cout << setw(width) << " VIEW PROFILE ";
			SetColor(color, i[2]);
			cout << setw(width) << "CHANGE PASSWORD";
			SetColor(color, i[3]);
			cout << setw(width) << "    LOGOUT    " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		/*while (true) {
			if (GetAsyncKeyState(VK_LEFT) != 0) {
				i[ptr] = 0;
				if (ptr == 0) ptr = 1;
				else ptr--;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0) {
				i[ptr] = 0;
				if (ptr == 1) ptr = 0;
				else ptr++;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (ptr) {
					case 0:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
						cin.ignore();
						login();
						break;
					case 1:
						system("cls");
						return;
				}
				break;
			}
		}*/
		/*Sleep(50);*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}
	
	switch (ptr) {
		case 0:
			Menu_Staff_Advance(a, idx);
			break;
		case 1:
			view_profile_staff(a, idx);
			break;
		case 2:
			changepassword_staff(a, idx);
			break;
		case 3:
			Menu_Main();
			break;
	}
}

//void Menu_Staff_Welcome() {
//	int KeyBoard();
//}

void Menu_Staff_Advance(staff a[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 4;
	int KeyPressed = 0;

	char AcaYear[] = "2019-2020";
	char Semester[] = "HK2";
	char YearSem[] = "2019-2020-HK2";
	char Link[] = "";
	string YearSem_str(YearSem);

	while (KeyPressed != 13) {
		cls();

		cout << setw(53) << "-ACADEMIC STAFF-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  --------  |"; // 3
			SetColor(color, i[1]);
			cout << setw(width) << "|     __     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ====== [v] |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |        | |"; // 4
			SetColor(color, i[1]);
			cout << setw(width) << "|    /  \\    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| | MID  8 | |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |  ABCD  | |"; // 5
			SetColor(color, i[1]);
			cout << setw(width) << "|    \\__/    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| | FIN  9 | |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ====== [v] |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |        | |"; // 6
			SetColor(color, i[1]);
			cout << setw(width) << "|    //\\\\    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| | LAB  7 | |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  [======]  |"; // 7
			SetColor(color, i[1]);
			cout << setw(width) << "|   //  \\\\   |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ====== [ ] |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "    CLASS     ";
			SetColor(color, i[1]);
			cout << setw(width) << "    COURSE    ";
			SetColor(color, i[2]);
			cout << setw(width) << "  SCOREBOARD  ";
			SetColor(color, i[3]);
			cout << setw(width) << "ATTENDANCE LIST" << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ " << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|  <=======  |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			cout << setw(width) << "     BACK     " << endl;
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else ptr = 4;
			i[ptr] = 1;
		} else KeyPressed = KeyPressed;

		/*while (true) {
			if (GetAsyncKeyState(VK_LEFT) != 0) {
				i[ptr] = 0;
				if (ptr == 0) ptr = 1;
				else ptr--;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0) {
				i[ptr] = 0;
				if (ptr == 1) ptr = 0;
				else ptr++;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (ptr) {
					case 0:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
						cin.ignore();
						login();
						break;
					case 1:
						system("cls");
						return;
				}
				break;
			}
		}*/
		/*Sleep(50);*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
		case 0:
			Menu_Staff_Class(a, idx);
			break;
		case 1:
			Menu_Staff_Course(a, idx);
			break;
		case 2:
			Menu_Staff_Scoreboard(a, idx, YearSem_str);
			break;
		case 3:
			Menu_Staff_AttList(a, idx, YearSem_str);
			break;
		case 4:
			Menu_Staff(a, idx);
			break;
	}
}

void Menu_Staff_Class(staff a[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 7;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(57) << "-ACADEMIC STAFF - CLASS-" << endl;
		cout << endl;

		// Don't open, unless it's for editing buttons

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 2.2
			SetColor(color, i[2]);
			cout << setw(width) << "|  __        |"; // 2.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|     ||     |"; // 3.1
			SetColor(color, i[1]);
			cout << setw(width) << "|     __     |"; // 3.2
			SetColor(color, i[2]);
			cout << setw(width) << "|  \\_\\       |"; // 3.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  --_||_--  |"; // 4.1
			SetColor(color, i[1]);
			cout << setw(width) << "|  __|  |__  |"; // 4.2
			SetColor(color, i[2]);
			cout << setw(width) << "|   \\ \\      |"; // 4.3
			SetColor(color, i[3]);
			cout << setw(width) << "|  ________  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |  \\  /  | |"; // 5.1
			SetColor(color, i[1]);
			cout << setw(width) << "| |__    __| |"; // 5.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    \\ \\     |"; // 5.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |________| |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |   \\/   | |"; // 6.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    |__|    |"; // 6.2
			SetColor(color, i[2]);
			cout << setw(width) << "|     \\ \\    |"; // 6.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  --------  |"; // 7.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 7.2
			SetColor(color, i[2]);
			cout << setw(width) << "|      \\_\\   |"; // 7.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 8.2
			SetColor(color, i[2]);
			cout << setw(width) << "|       \\|   |"; // 8.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " IMPORT CLASS ";
			SetColor(color, i[1]);
			cout << setw(width) << " ADD STUDENT  ";
			SetColor(color, i[2]);
			cout << setw(width) << " EDIT STUDENT ";
			SetColor(color, i[3]);
			cout << setw(width) << "REMOVE STUDENT" << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[6]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[7]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 2.1
			SetColor(color, i[5]);
			cout << setw(width) << "|            |"; // 2.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 2.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 3.1
			SetColor(color, i[5]);
			cout << setw(width) << "| 19CLC      |"; // 3.2
			SetColor(color, i[6]);
			cout << setw(width) << "| [] ======= |"; // 3.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 4.1
			SetColor(color, i[5]);
			cout << setw(width) << "| ---------- |"; // 4.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 4.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|  A ---> B  |"; // 5.1
			SetColor(color, i[5]);
			cout << setw(width) << "| ---------- |"; // 5.2
			SetColor(color, i[6]);
			cout << setw(width) << "| [] ======= |"; // 5.3
			SetColor(color, i[7]);
			cout << setw(width) << "|  <=======  |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 6.1
			SetColor(color, i[5]);
			cout << setw(width) << "| ---------- |"; // 6.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 6.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 7.1
			SetColor(color, i[5]);
			cout << setw(width) << "| ---------- |"; // 7.2
			SetColor(color, i[6]);
			cout << setw(width) << "| [] ======= |"; // 7.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 8.1
			SetColor(color, i[5]);
			cout << setw(width) << "|            |"; // 8.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 8.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[6]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[7]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "CHANGE STU CLASS";
			SetColor(color, i[5]);
			cout << setw(width) << "VIEW CLASS LIST";
			SetColor(color, i[6]);
			cout << setw(width) << "VIEW CLASS STU";
			SetColor(color, i[7]);
			cout << setw(width) << "     BACK     " << endl;
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else ptr += 4;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 7:
		Menu_Staff_Advance(a, idx);
		break;
	case 0:
		import(a, idx);
		break;
	case 1:
		add_a_new_student(a, idx);
		break;
	case 2:
		edit_existing_student(a, idx);
		break;
	case 3:
		remove_a_student(a, idx);
		break;
	case 4:
		change_student_classA_to_B(a, idx);
		break;
	case 5:
		list_of_classes(a, idx);
		break;
	case 6:
		list_of_student_in_class(a, idx);
		break;
	}
}

void Menu_Staff_Course(staff a[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 4;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(57) << "-ACADEMIC STAFF - COURSE-" << endl;
		cout << endl;

		// Don't open, unless it's for editing buttons

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  ________  |"; // 2.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 2.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    ----    |"; // 2.3
			SetColor(color, i[3]);
			cout << setw(width) << "|    ----    |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |        | |"; // 3.1
			SetColor(color, i[1]);
			cout << setw(width) << "|     __     |"; // 3.2
			SetColor(color, i[2]);
			cout << setw(width) << "|   |----|   |"; // 3.3
			SetColor(color, i[3]);
			cout << setw(width) << "|   |----|   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| | [====] | |"; // 4.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    /  \\    |"; // 4.2
			SetColor(color, i[2]);
			cout << setw(width) << "|   |    |   |"; // 4.3
			SetColor(color, i[3]);
			cout << setw(width) << "|   |    |   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |  2019  | |"; // 5.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    \\__/    |"; // 5.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    \\  /    |"; // 5.3
			SetColor(color, i[3]);
			cout << setw(width) << "|    \\  /    |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |  2020  | |"; // 6.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    //\\\\    |"; // 6.2
			SetColor(color, i[2]);
			cout << setw(width) << "|   /|  |\\   |"; // 6.3
			SetColor(color, i[3]);
			cout << setw(width) << "|   /|  |\\   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |________| |"; // 7.1
			SetColor(color, i[1]);
			cout << setw(width) << "|   //  \\\\   |"; // 7.2
			SetColor(color, i[2]);
			cout << setw(width) << "|  | |\\/| |  |"; // 7.3
			SetColor(color, i[3]);
			cout << setw(width) << "|  |  \\/  |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  ========  |"; // 8.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 8.2
			SetColor(color, i[2]);
			cout << setw(width) << "|  | |||| |  |"; // 8.3
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "ACADEMIC YEAR ";
			SetColor(color, i[1]);
			cout << setw(width) << "    COURSE    ";
			SetColor(color, i[2]);
			cout << setw(width) << "   LECTURER   ";
			SetColor(color, i[3]);
			cout << setw(width) << "   STUDENT    " << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ " << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|  <=======  |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			cout << setw(width) << "     BACK     " << endl;
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else ptr = 4;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 4:
		Menu_Staff_Advance(a, idx);
		break;
	case 1:
		Menu_Staff_Course_Course(a, idx);
		break;
	}
}

void Menu_Staff_Course_Course(staff a[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 5;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(57) << "-ACADEMIC STAFF - COURSE-" << endl;
		cout << endl;

		// Don't open, unless it's for editing buttons

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 2.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 2.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|     __ (+) |"; // 3.1
			SetColor(color, i[1]);
			cout << setw(width) << "|     __ (E) |"; // 3.2
			SetColor(color, i[2]);
			cout << setw(width) << "|     __ (-) |"; // 3.3
			SetColor(color, i[3]);
			cout << setw(width) << "|     __ (I) |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|    /  \\    |"; // 4.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    /  \\    |"; // 4.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    /  \\    |"; // 4.3
			SetColor(color, i[3]);
			cout << setw(width) << "|    /  \\    |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|    \\__/    |"; // 5.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    \\__/    |"; // 5.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    \\__/    |"; // 5.3
			SetColor(color, i[3]);
			cout << setw(width) << "|    \\__/    |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|    //\\\\    |"; // 6.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    //\\\\    |"; // 6.2
			SetColor(color, i[2]);
			cout << setw(width) << "|    //\\\\    |"; // 6.3
			SetColor(color, i[3]);
			cout << setw(width) << "|    //\\\\    |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|   //  \\\\   |"; // 7.1
			SetColor(color, i[1]);
			cout << setw(width) << "|   //  \\\\   |"; // 7.2
			SetColor(color, i[2]);
			cout << setw(width) << "|   //  \\\\   |"; // 7.3
			SetColor(color, i[3]);
			cout << setw(width) << "|   //  \\\\   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8.1
			SetColor(color, i[1]);
			cout << setw(width) << "|            |"; // 8.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 8.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "  ADD COURSE  ";
			SetColor(color, i[1]);
			cout << setw(width) << " EDIT COURSE  ";
			SetColor(color, i[2]);
			cout << setw(width) << "REMOVE COURSE ";
			SetColor(color, i[3]);
			cout << setw(width) << "IMPORT COURSE " << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "| [] ======= |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "| [] ======= |";
			SetColor(color, i[5]);
			cout << setw(width) << "|  <=======  |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "| [] ======= |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |";
			SetColor(color, i[5]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[4]);
			cout << setw(width) << " COURSES LIST ";
			SetColor(color, i[5]);
			cout << setw(width) << "     BACK     " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else if (ptr == 0) ptr += 4;
			else ptr = 5;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	char AcaYear[] = "2019-2020";
	char Semester[] = "HK2";
	char YearSem[] = "2019-2020-HK2";
	char Link[] = "";
	string YearSem_str(YearSem);

	switch (ptr) {
	case 0:
		AddCourse(AcaYear, Semester);
		break;
	case 3:
		ImportCourses(AcaYear, Semester);
		break;
	case 4:
		ShowCourseList(YearSem_str, Link);
		break;
	case 5:
		Menu_Staff_Course(a, idx);
		break;
	}
	if (ptr != 5) Menu_Staff_Course_Course(a, idx);

}

void Menu_Staff_Scoreboard(staff a[], int &idx, string YearSem) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0 };
	int ptr = 0;
	int width = 26;
	int last = 2;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(58) << "-ACADEMIC STAFF - SCOREBOARD-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[1]);
			cout << setw(width) << "|     /\\     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| | MID  8 | |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  --/  \\--  |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| | FIN  9 | |";
			SetColor(color, i[1]);
			cout << setw(width) << "| |   ||   | |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  <=======  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| | LAB  7 | |";
			SetColor(color, i[1]);
			cout << setw(width) << "| |   ||   | |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "  VIEW SCRBD  ";
			SetColor(color, i[1]);
			cout << setw(width) << " EXPORT SCRBD ";
			SetColor(color, i[2]);
			cout << setw(width) << "     BACK     " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
		case 0:
			Advance_ShowScoreBoard(YearSem);
			break;
		case 1:
			Advance_ExportScoreBoard(YearSem);
			break;
		case 2:
			Menu_Staff_Advance(a, idx);
			break;
	}
	if (ptr != 2) Menu_Staff_Scoreboard(a, idx, YearSem);

}

void Menu_Staff_AttList(staff a[], int& idx, string YearSem) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0 };
	int ptr = 0;
	int width = 26;
	int last = 2;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(59) << "-ACADEMIC STAFF - ATTENDANCE LIST-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[1]);
			cout << setw(width) << "|     /\\     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  --/  \\--  |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[1]);
			cout << setw(width) << "| |   ||   | |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  <=======  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "| |   ||   | |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[1]);
			cout << setw(width) << "|  --------  |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |";
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " VIEW ATTLIST ";
			SetColor(color, i[1]);
			cout << setw(width) << "EXPORT ATTLIST";
			SetColor(color, i[2]);
			cout << setw(width) << "     BACK     " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 0:
		Advance_ShowAttList(YearSem);
		break;
	case 1:
		Advance_ExportAttList(YearSem);
		break;
	case 2:
		Menu_Staff_Advance(a, idx);
		break;
	}
	if (ptr != 2) Menu_Staff_AttList(a, idx, YearSem);

}



void Menu_EditScore(Student_Course*& stu, int n) {
	std::system("cls");

	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0 };
	int ptr = 0;
	int last = 4;
	int KeyPressed = 0;

	while (KeyPressed != 13) {

		cls();

		cout << "-Edit Grade-" << endl << endl;

		int width = 1 + 10 + 1 + 30 + 1 + 9 + 1 + 9 + 1 + 9 + 1 + 9 + 1;
		for (int i = 0; i < width; i++) {
			if (i == 0) cout << "[";
			else if (i == width - 1) cout << "]";
			else cout << "-";
		} cout << endl;
		cout << "|    ID    |             Name             |   Mid   |  Final  |  Bonus  | Average |" << endl;

		ShowScoreSolo(stu); cout << endl;

		for (int j = 0; j < last + 1; j++) {
			SetColor(color, i[j]);
			if (i[j] == 1) cout << "> "; else cout << "  ";
			switch (j) {
			case 0: cout << "Mid-term"; break;
			case 1: cout << "Final"; break;
			case 2: cout << "Bonus"; break;
			case 3: cout << "Total"; break;
			case 4: cout << "Back"; break;
			}
			cout << endl;
		}
		cout << endl;

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 72) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	if (ptr == 4) return;
	float sc_ans;
	cout << "[- New Score -]" << endl;
	cout << "> "; cin >> sc_ans;
	while (sc_ans < 0) {
		cout << "Invalid input." << endl;
		cout << "> "; cin >> sc_ans;
	}
	switch (ptr) {
	case 0: stu->sc_mid = sc_ans; break;
	case 1: stu->sc_fin = sc_ans; break;
	case 2: stu->sc_lab = sc_ans; break;
	case 3: stu->sc_ave = sc_ans; break;
	}

	cout << endl;
	cout << "Edit complete." << endl;
	system("pause");
}

void Menu_Lecturer(lecturer b[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 3;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(50) << "-LECTURER-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 3
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  _         |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 4
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "| / \\_______ |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 5
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| \\_/    | | |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ----->  |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 6
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 7
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "   LECTURER   ";
			SetColor(color, i[1]);
			cout << setw(width) << " VIEW PROFILE ";
			SetColor(color, i[2]);
			cout << setw(width) << "CHANGE PASSWORD";
			SetColor(color, i[3]);
			cout << setw(width) << "    LOGOUT    " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 0:
		Menu_Lecturer_Advance(b, idx);
		break;
	case 1:
		view_profile_lecturer(b, idx);
		break;
	case 2:
		changepassword_lecturer(b, idx);
		break;
	case 3:
		Menu_Main();
		break;
	}
}

void Menu_Lecturer_Advance(lecturer b[], int &idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 7;
	int KeyPressed = 0;
	
	char AcaYear[] = "2019-2020";
	char Semester[] = "HK2";
	char YearSem[] = "2019-2020-HK2";
	char Link[] = "";
	string YearSem_str(YearSem);

	while (KeyPressed != 13) {
		cls();

		cout << setw(50) << "-LECTURER-" << endl;
		cout << endl;

		// Don't open, unless it's for editing buttons

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    ----    |"; // 2.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 2.3
			SetColor(color, i[3]);
			cout << setw(width) << "|  _      _  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 3.1
			SetColor(color, i[1]);
			cout << setw(width) << "|   |----|   |"; // 3.2
			SetColor(color, i[2]);
			cout << setw(width) << "| ====== [v] |"; // 3.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |        | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 4.1
			SetColor(color, i[1]);
			cout << setw(width) << "|   |    |   |"; // 4.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 4.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |      / | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 5.1
			SetColor(color, i[1]);
			cout << setw(width) << "|    \\  /    |"; // 5.2
			SetColor(color, i[2]);
			cout << setw(width) << "| ====== [v] |"; // 5.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |  \\  /  | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 6.1
			SetColor(color, i[1]);
			cout << setw(width) << "|   /|  |\\   |"; // 6.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 6.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |   \\/   | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 7.1
			SetColor(color, i[1]);
			cout << setw(width) << "|  |  \\/  |  |"; // 7.2
			SetColor(color, i[2]);
			cout << setw(width) << "| ====== [ ] |"; // 7.3
			SetColor(color, i[3]);
			cout << setw(width) << "| |_      _| |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8.1
			SetColor(color, i[1]);
			cout << setw(width) << "|  |      |  |"; // 8.2
			SetColor(color, i[2]);
			cout << setw(width) << "|            |"; // 8.3
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "  COURSELIST  ";
			SetColor(color, i[1]);
			cout << setw(width) << "COURSE STULIST";
			SetColor(color, i[2]);
			cout << setw(width) << "COURSE ATTLIST";
			SetColor(color, i[3]);
			cout << setw(width) << "EDIT ATTENDANCE" << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ "; // 1.1
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ "; // 1.2
			SetColor(color, i[6]);
			cout << setw(width) << " ------------ "; // 1.3
			SetColor(color, i[7]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 2.1
			SetColor(color, i[5]);
			cout << setw(width) << "|            |"; // 2.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 2.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|     ||     |"; // 3.1
			SetColor(color, i[5]);
			cout << setw(width) << "|   MID  8   |"; // 3.2
			SetColor(color, i[6]);
			cout << setw(width) << "|  --------  |"; // 3.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|  --_||_--  |"; // 4.1
			SetColor(color, i[5]);
			cout << setw(width) << "|     ||     |"; // 4.2
			SetColor(color, i[6]);
			cout << setw(width) << "| | MID  8 | |"; // 4.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "| |  \\  /  | |"; // 5.1
			SetColor(color, i[5]);
			cout << setw(width) << "|    \\||/    |"; // 5.2
			SetColor(color, i[6]);
			cout << setw(width) << "| | FIN  9 | |"; // 5.3
			SetColor(color, i[7]);
			cout << setw(width) << "|  <=======  |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "| |   \\/   | |"; // 6.1
			SetColor(color, i[5]);
			cout << setw(width) << "|     \\/     |"; // 6.2
			SetColor(color, i[6]);
			cout << setw(width) << "| | LAB  7 | |"; // 6.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|  --------  |"; // 7.1
			SetColor(color, i[5]);
			cout << setw(width) << "|   MID 10   |"; // 7.2
			SetColor(color, i[6]);
			cout << setw(width) << "|  --------  |"; // 7.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << "|            |"; // 8.1
			SetColor(color, i[5]);
			cout << setw(width) << "|            |"; // 8.2
			SetColor(color, i[6]);
			cout << setw(width) << "|            |"; // 8.3
			SetColor(color, i[7]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ "; // 9.1
			SetColor(color, i[5]);
			cout << setw(width) << " ------------ "; // 9.2
			SetColor(color, i[6]);
			cout << setw(width) << " ------------ "; // 9.3
			SetColor(color, i[7]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[4]);
			cout << setw(width) << " IMPORT SCRBD ";
			SetColor(color, i[5]);
			cout << setw(width) << "  EDIT GRADE  ";
			SetColor(color, i[6]);
			cout << setw(width) << "  VIEW SCRBD  ";
			SetColor(color, i[7]);
			cout << setw(width) << "     BACK     " << endl;
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else ptr += 4;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	string lecid(b[idx].username);
	switch (ptr) {
	case 0:
		ShowCourseListLec(YearSem, Link, lecid);
		break;
	case 1:
		Advance_ShowCourse(YearSem_str);
		break;
	case 2:
		Advance_ShowAttList(YearSem_str);
		break;
	case 3:
		Advance_EditAtt(YearSem_str);
		break;
	case 4:
		Advance_ImportScoreBoard(YearSem_str);
		break;
	case 5: 
		Advance_EditScore(YearSem);
		break;
	case 6:
		Advance_ShowScoreBoard(YearSem_str);
		break;
	case 7:
		Menu_Lecturer(b, idx);
		break;
	}
	if (ptr != last) Menu_Lecturer_Advance(b, idx);
}




void Menu_Student(student c[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 3;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		cls();

		cout << setw(50) << "-STUDENT-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 2
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 3
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|  _         |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 4
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "| / \\_______ |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 5
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "| \\_/    | | |";
			SetColor(color, i[3]);
			cout << setw(width) << "| ----->  |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 6
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|         |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| [] ======= |"; // 7
			SetColor(color, i[1]);
			cout << setw(width) << "|    |  |    |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  |      |  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8
			SetColor(color, i[1]);
			cout << setw(width) << "|     --     |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|   ------   |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "   STUDENT    ";
			SetColor(color, i[1]);
			cout << setw(width) << " VIEW PROFILE ";
			SetColor(color, i[2]);
			cout << setw(width) << "CHANGE PASSWORD";
			SetColor(color, i[3]);
			cout << setw(width) << "    LOGOUT    " << endl;
			SetColor(color, i[0]);
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == last) ptr = 0;
			else ptr++;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 0:
		Menu_Student_Advance(c, idx);
		break;
	case 1:
		view_profile_student(c, idx);
		break;
	case 2:
		changepassword_student(c, idx);
		break;
	case 3:
		Menu_Main();
		break;
	}
}

void Menu_Student_Advance(student c[], int& idx) {
	std::system("cls");
	int color[] = { OFFCOL, ONCOL };
	int i[] = { 1, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 4;
	int KeyPressed = 0;

	char AcaYear[] = "2019-2020";
	char Semester[] = "HK2";
	char YearSem[] = "2019-2020-HK2";
	char Link[] = "";
	string YearSem_str(YearSem);

	while (KeyPressed != 13) {
		cls();

		cout << setw(50) << "-STUDENT-" << endl;
		cout << endl;

		{
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 1
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|  _      _  |"; // 2
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |        | |"; // 3
			SetColor(color, i[1]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[2]);
			cout << setw(width) << "| [][------] |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  --------  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |      / | |"; // 4
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "| | MID  8 | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |  \\  /  | |"; // 5
			SetColor(color, i[1]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[2]);
			cout << setw(width) << "| [][------] |";
			SetColor(color, i[3]);
			cout << setw(width) << "| | FIN  9 | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |   \\/   | |"; // 6
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "| | LAB  7 | |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "| |_      _| |"; // 7
			SetColor(color, i[1]);
			cout << setw(width) << "| ====== [v] |";
			SetColor(color, i[2]);
			cout << setw(width) << "| [][------] |";
			SetColor(color, i[3]);
			cout << setw(width) << "|  --------  |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "|            |"; // 8
			SetColor(color, i[1]);
			cout << setw(width) << "|            |";
			SetColor(color, i[2]);
			cout << setw(width) << "|            |";
			SetColor(color, i[3]);
			cout << setw(width) << "|            |" << endl;
			SetColor(color, i[0]);
			cout << setw(width) << " ------------ "; // 9
			SetColor(color, i[1]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[2]);
			cout << setw(width) << " ------------ ";
			SetColor(color, i[3]);
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			SetColor(color, i[0]);
			cout << setw(width) << "   CHECK-IN   ";
			SetColor(color, i[1]);
			cout << setw(width) << " CHECK-IN RES ";
			SetColor(color, i[2]);
			cout << setw(width) << "VIEW SCHEDULE ";
			SetColor(color, i[3]);
			cout << setw(width) << "  VIEW SCRBD  " << endl;
			SetColor(color, i[0]);
		}
		cout << endl;
		{
			SetColor(color, i[4]);
			cout << setw(width) << " ------------ " << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|  <=======  |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << "|            |" << endl;
			cout << setw(width) << " ------------ " << endl;
			cout << endl;
			cout << setw(width) << "     BACK     " << endl;
		}

		KeyPressed = _getch();
		fflush(stdin);

		if (KeyPressed == 75) {
			i[ptr] = 0;
			if (ptr == 0) ptr = 3;
			else if (ptr == 4) ptr = last;
			else ptr--;
			i[ptr] = 1;
		}
		else if (KeyPressed == 77) {
			i[ptr] = 0;
			if (ptr == 3) ptr = 0;
			else if (ptr == last) ptr = 4;
			else ptr++;
			i[ptr] = 1;
		}
		else if (KeyPressed == 72 || KeyPressed == 80) {
			i[ptr] = 0;
			if (ptr >= 4) ptr -= 4;
			else ptr = 4;
			i[ptr] = 1;
		}
		else KeyPressed = KeyPressed;

		/*while (true) {
			if (GetAsyncKeyState(VK_LEFT) != 0) {
				i[ptr] = 0;
				if (ptr == 0) ptr = 1;
				else ptr--;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RIGHT) != 0) {
				i[ptr] = 0;
				if (ptr == 1) ptr = 0;
				else ptr++;
				i[ptr] = 1;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (ptr) {
					case 0:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
						cin.ignore();
						login();
						break;
					case 1:
						system("cls");
						return;
				}
				break;
			}
		}*/
		/*Sleep(50);*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}

	switch (ptr) {
	case 0:
		Advance_CheckIn(YearSem, c[idx].id);
		break;
	case 1:
		Advance_CheckInRes(YearSem, c[idx].id);
		break;
	case 2:
		ShowSchedule(YearSem, Link, c[idx].id);
		break;
	case 3:
		Advance_StuShowScore(YearSem, c[idx].id);
		break;
	case 4:
		Menu_Student(c, idx);
		break;
	}
	if (ptr != last) Menu_Student_Advance(c, idx);
}