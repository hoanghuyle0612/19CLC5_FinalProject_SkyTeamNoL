// MENU FUNCTION

#include "Login.h"

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
			cout << setw(width) << "    LOGIN     ";
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
	int width = 20;
	int last = 3;
	int KeyPressed = 0;

	while (KeyPressed != 13) {
		std::system("cls");

		cout << setw(51) << "-ACADEMIC STAFF-" << endl;

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
			cout << setw(width) << "|   ******   |";
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
		/*Sleep(125);*/
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[0]);
	}
	
	switch (ptr) {
		case 2:
			changepassword_staff(a, idx);
			break;
		case 3:
			Menu_Main();
			break;
	}
}