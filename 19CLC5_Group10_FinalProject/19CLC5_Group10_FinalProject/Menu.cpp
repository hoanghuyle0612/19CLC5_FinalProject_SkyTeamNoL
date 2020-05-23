// MENU FUNCTION

#include "Login.h"

void staffclass_func(staff a[], int& idx);
void Menu_Staff_Advance(staff a[], int& idx);
void Menu_Staff_Class(staff a[], int& idx);

void SetColor(int color[], int i) {
	if (i == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[1]);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
}

void Menu_Main() {
	int color[] = { 15, 12 };
	int i[] = { 1, 0 };
	int ptr = 0;
	int width = 35;
	int last = 1;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		std::system("cls");

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
	}

}

void Menu_Staff(staff a[], int& idx) {
	int color[] = { 15, 12 };
	int i[] = { 1, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 3;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		std::system("cls");

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
	int color[] = { 15, 12 };
	int i[] = { 1, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 4;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		std::system("cls");

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
			Menu_Staff_Class(a, idx);
			break;
		case 4:
			Menu_Staff(a, idx);
			break;
	}
}

void Menu_Staff_Class(staff a[], int& idx) {
	int color[] = { 15, 12 };
	int i[] = { 1, 0, 0, 0, 0, 0, 0, 0 };
	int ptr = 0;
	int width = 21;
	int last = 7;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		std::system("cls");

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
	}
}