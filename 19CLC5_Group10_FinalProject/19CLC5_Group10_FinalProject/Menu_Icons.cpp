// MENU ICONS
// This file is used only to draw icons & animations

#include "Login.h"

#define ENDLRANGE 8
#define SETWIDTH 55

//void Icon_Sample() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|            |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "|            |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "|            |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Login() {

//	cout << setw(25) << " ------------- " << endl; // 1
//	cout << setw(25) << "|    -----    |" << endl; // 2
//	cout << setw(25) << "|   |-----|   |" << endl; // 3
//	cout << setw(25) << "|   |     |   |" << endl; // 4
//	cout << setw(25) << "|    \   /    |" << endl; // 5
//	cout << setw(25) << "|   /|   |\   |" << endl; // 6
//	cout << setw(25) << "|  |  \_/  |  |" << endl; // 7 
//	cout << setw(25) << "|  |       |  |" << endl; // 8
//	cout << setw(25) << " ------------ " << endl; // 9
//	cout << endl;
//}

//void Icon_Exit() {

//	cout << setw(25) << " ------------- " << endl; // 1
//	cout << setw(25) << "|   -------   |" << endl; // 2
//	cout << setw(25) << "|  |       |  |" << endl; // 3
//	cout << setw(25) << "|          |  |" << endl; // 4
//	cout << setw(25) << "| ------>  |  |" << endl; // 5
//	cout << setw(25) << "|          |  |" << endl; // 6 
//	cout << setw(25) << "|  |       |  |" << endl; // 7
//	cout << setw(25) << "|   -------   |" << endl; // 8
//	cout << setw(25) << " ------------ " << endl; // 9
//	cout << endl;
//}


//void Icon_ViewProfile() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|     --     |" << endl; // 2
//	cout << setw(25) << 3 "|    |  |    |" << endl; // 3
//	cout << setw(25) << 4 "|     --     |" << endl; // 4
//	cout << setw(25) << 5 "|    |  |    |" << endl; // 5
//	cout << setw(25) << 4 "|    |  |    |" << endl; // 6 
//	cout << setw(25) << 3 "|    |  |    |" << endl; // 7
//	cout << setw(25) << 2 "|     --     |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_ChangePassword() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|  _         |" << endl; // 3
//	cout << setw(25) << 4 "| / \_______ |" << endl; // 4
//	cout << setw(25) << 5 "| \_/    | | |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "|   ******   |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Option() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "| [] ======= |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "| [] ======= |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "| [] ======= |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

// Welcome

void Welcome_01() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl; 
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
}
void Welcome_02() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "         =         " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "         =         " << endl;
}
void Welcome_03() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "        ===        " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "        ===        " << endl;
}
void Welcome_04() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "       =====       " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "       =====       " << endl;
}
void Welcome_05() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "      =======      " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "      =======      " << endl;
}
void Welcome_06() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "     =========     " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "     =========     " << endl;
}
void Welcome_07() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "    ===========    " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "    ===========    " << endl;
}
void Welcome_08() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "   =============   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "   =============   " << endl;
}
void Welcome_09() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "  ===============  " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "  ===============  " << endl;
}
void Welcome_10() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << " ================= " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << " ================= " << endl;
}
void Welcome_11() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_12() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "                   " << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_13() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_14() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     W           |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_15() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WE          |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_16() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WEL         |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_17() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WELC        |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_18() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WELCO       |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_19() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WELCOM      |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void Welcome_20() {
	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "|     WELCOME     |" << endl;
	cout << setw(SETWIDTH) << "|                 |" << endl;
	cout << setw(SETWIDTH) << "[=================]" << endl;
}
void DrawWelcome() {
	void (*draw[])() = { Welcome_01, Welcome_02, Welcome_03,
		Welcome_04, Welcome_05, Welcome_06, Welcome_07,
		Welcome_08, Welcome_09, Welcome_10, Welcome_11,
		Welcome_12, Welcome_13, Welcome_14, Welcome_15,
		Welcome_16, Welcome_17, Welcome_18, Welcome_19,
		Welcome_20 };

	for (int i = 0; i < 20; i++) {
		std::system("cls");
		draw[i]();
		Sleep(70);
	}
	Sleep(2000);
}