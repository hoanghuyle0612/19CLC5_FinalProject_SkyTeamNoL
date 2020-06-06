// MENU ICONS
// This file is used only to draw icons & animations

#include "Login.h"
#include "Menu.h"

#define ENDLRANGE 5
#define SETWIDTH 55
#define IW 14
#define IH 9


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

//	cout << setw(25) << " ------------ " << endl; // 1
//	cout << setw(25) << "|    ----    |" << endl; // 2
//	cout << setw(25) << "|   |----|   |" << endl; // 3
//	cout << setw(25) << "|   |    |   |" << endl; // 4
//	cout << setw(25) << "|    \  /    |" << endl; // 5
//	cout << setw(25) << "|   /|  |\   |" << endl; // 6
//	cout << setw(25) << "|  |  \/  |  |" << endl; // 7 
//	cout << setw(25) << "|  |      |  |" << endl; // 8
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


//void Icon_Class() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|  --------  |" << endl; // 3
//	cout << setw(25) << 4 "| |        | |" << endl; // 4
//	cout << setw(25) << 5 "| |  ABCD  | |" << endl; // 5
//	cout << setw(25) << 4 "| |        | |" << endl; // 6 
//	cout << setw(25) << 3 "|  [======]  |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Course() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     __     |" << endl; // 3
//	cout << setw(25) << 4 "|    /  \    |" << endl; // 4
//	cout << setw(25) << 5 "|    \__/    |" << endl; // 5
//	cout << setw(25) << 4 "|    //\\    |" << endl; // 6
//	cout << setw(25) << 3 "|   //  \\   |" << endl; // 7 
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Course_Add() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     __ (+) |" << endl; // 3
//	cout << setw(25) << 4 "|    /  \    |" << endl; // 4
//	cout << setw(25) << 5 "|    \__/    |" << endl; // 5
//	cout << setw(25) << 4 "|    //\\    |" << endl; // 6
//	cout << setw(25) << 3 "|   //  \\   |" << endl; // 7 
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Course_Remove() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     __ (-) |" << endl; // 3
//	cout << setw(25) << 4 "|    /  \    |" << endl; // 4
//	cout << setw(25) << 5 "|    \__/    |" << endl; // 5
//	cout << setw(25) << 4 "|    //\\    |" << endl; // 6
//	cout << setw(25) << 3 "|   //  \\   |" << endl; // 7 
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Course_Edit() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     __ (E) |" << endl; // 3
//	cout << setw(25) << 4 "|    /  \    |" << endl; // 4
//	cout << setw(25) << 5 "|    \__/    |" << endl; // 5
//	cout << setw(25) << 4 "|    //\\    |" << endl; // 6
//	cout << setw(25) << 3 "|   //  \\   |" << endl; // 7 
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Scoreboard() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|  --------  |" << endl; // 3
//	cout << setw(25) << 4 "| | MID  8 | |" << endl; // 4
//	cout << setw(25) << 5 "| | FIN  9 | |" << endl; // 5
//	cout << setw(25) << 4 "| | LAB  7 | |" << endl; // 6 
//	cout << setw(25) << 3 "|  --------  |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_EditScore() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|   MID  8   |" << endl; // 3
//	cout << setw(25) << 4 "|     ||     |" << endl; // 4
//	cout << setw(25) << 5 "|    \||/    |" << endl; // 5
//	cout << setw(25) << 4 "|     \/     |" << endl; // 6 
//	cout << setw(25) << 3 "|   MID 10   |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_AttList() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "| ====== [v] |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "| ====== [v] |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "| ====== [ ] |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Checkin() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|  _      _  |" << endl; // 2
//	cout << setw(25) << 3 "| |        | |" << endl; // 3
//	cout << setw(25) << 4 "| |      / | |" << endl; // 4
//	cout << setw(25) << 5 "| |  \  /  | |" << endl; // 5
//	cout << setw(25) << 4 "| |   \/   | |" << endl; // 6 
//	cout << setw(25) << 3 "| |_      _| |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Back() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|            |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "|  <=======  |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "|            |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Import() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     ||     |" << endl; // 3
//	cout << setw(25) << 4 "|  --_||_--  |" << endl; // 4
//	cout << setw(25) << 5 "| |  \  /  | |" << endl; // 5
//	cout << setw(25) << 4 "| |   \/   | |" << endl; // 6 
//	cout << setw(25) << 3 "|  --------  |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Export() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     /\     |" << endl; // 3
//	cout << setw(25) << 4 "|  --/||\--  |" << endl; // 4
//	cout << setw(25) << 5 "| |   ||   | |" << endl; // 5
//	cout << setw(25) << 4 "| |   ||   | |" << endl; // 6 
//	cout << setw(25) << 3 "|  --------  |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Add() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|     __     |" << endl; // 3
//	cout << setw(25) << 4 "|  __|  |__  |" << endl; // 4
//	cout << setw(25) << 5 "| |__    __| |" << endl; // 5
//	cout << setw(25) << 4 "|    |__|    |" << endl; // 6 
//	cout << setw(25) << 3 "|            |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Remove() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|            |" << endl; // 3
//	cout << setw(25) << 4 "|  ________  |" << endl; // 4
//	cout << setw(25) << 5 "| |________| |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "|            |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_Edit() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|  __        |" << endl; // 2
//	cout << setw(25) << 3 "|  \_\       |" << endl; // 3
//	cout << setw(25) << 4 "|   \ \      |" << endl; // 4
//	cout << setw(25) << 5 "|    \ \     |" << endl; // 5
//	cout << setw(25) << 4 "|     \ \    |" << endl; // 6 
//	cout << setw(25) << 3 "|      \_\   |" << endl; // 7
//	cout << setw(25) << 2 "|       \|   |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_ChangeClass() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "|            |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "|  A ---> B  |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "|            |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_ViewClass() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "| 19CLC      |" << endl; // 3
//	cout << setw(25) << 4 "| ---------- |" << endl; // 4
//	cout << setw(25) << 5 "| ---------- |" << endl; // 5
//	cout << setw(25) << 4 "| ---------- |" << endl; // 6 
//	cout << setw(25) << 3 "| ---------- |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//}

//void Icon_AcaYear() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|  ________  |" << endl; // 2
//	cout << setw(25) << 3 "| |        | |" << endl; // 3
//	cout << setw(25) << 4 "| | [====] | |" << endl; // 4
//	cout << setw(25) << 5 "| |  2018  | |" << endl; // 5
//	cout << setw(25) << 4 "| |  2020  | |" << endl; // 6 
//	cout << setw(25) << 3 "| |________| |" << endl; // 7
//	cout << setw(25) << 2 "|  ========  |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//} 

//void Icon_MoreOptions() {

//	cout << setw(25) << 1 " ------------ " << endl; // 1
//	cout << setw(25) << 2 "|            |" << endl; // 2
//	cout << setw(25) << 3 "| []  []  [] |" << endl; // 3
//	cout << setw(25) << 4 "|            |" << endl; // 4
//	cout << setw(25) << 5 "| []  []  [] |" << endl; // 5
//	cout << setw(25) << 4 "|            |" << endl; // 6 
//	cout << setw(25) << 3 "| []  []  [] |" << endl; // 7
//	cout << setw(25) << 2 "|            |" << endl; // 8
//	cout << setw(25) << 1 " ------------ " << endl; // 9
//                          123456654321
//	cout << endl;
//} 

// HCMUS LOGO

//cout << setw(SETWIDTH) << 1 "              /|       | << endl;
//cout << setw(SETWIDTH) << 2 "             / |       | << endl;
//cout << setw(SETWIDTH) << 3 "           _/  |       | << endl;
//cout << setw(SETWIDTH) << 4 "          /    |       | << endl;
//cout << setw(SETWIDTH) << 5 "        _/     |       | << endl;
//cout << setw(SETWIDTH) << 6 "       /   *   |       | << endl;
//cout << setw(SETWIDTH) << 7 "     _/___     |       | << endl;
//cout << setw(SETWIDTH) << 8 "     \    \___/__      | << endl;
//cout << setw(SETWIDTH) << 9 "      \          \     | << endl;
//cout << setw(SETWIDTH) << 0 "       \___KHTN___|    | << endl;
							// 12345678901210987654321


//cout << setw(SETWIDTH) << " ______________________  "<< endl;
//cout << setw(SETWIDTH) << "|             /|       | "<< endl;
//cout << setw(SETWIDTH) << "|            / |       | "<< endl;
//cout << setw(SETWIDTH) << "|          _/  |       | "<< endl;
//cout << setw(SETWIDTH) << "|         /    |       | "<< endl;
//cout << setw(SETWIDTH) << "|       _/     |       | "<< endl;
//cout << setw(SETWIDTH) << "|      /   *   |       | "<< endl;
//cout << setw(SETWIDTH) << "|    _/___     |       | "<< endl;
//cout << setw(SETWIDTH) << "|    \    \___/__      | "<< endl;
//cout << setw(SETWIDTH) << "|     \          \     | "<< endl;
//cout << setw(SETWIDTH) << "|______\___KHTN___|____| "<< endl;

//void Welcome_00() {           //12345678901210987654321
//	cout << setw(SETWIDTH) << " _______________________ "<< endl;
//	cout << setw(SETWIDTH) << "|              /|       |"<< endl;
//	cout << setw(SETWIDTH) << "|             / |       |"<< endl;
//	cout << setw(SETWIDTH) << "|           _/  |       |"<< endl;
//	cout << setw(SETWIDTH) << "|          /    |       |"<< endl;
//	cout << setw(SETWIDTH) << "|        _/     |       |"<< endl;
//	cout << setw(SETWIDTH) << "|       /   *   |       |"<< endl;
//	cout << setw(SETWIDTH) << "|     _/___     |       |"<< endl;
//	cout << setw(SETWIDTH) << "|     \    \___/__      |"<< endl;
//	cout << setw(SETWIDTH) << "|      \          \     |"<< endl;
//	cout << setw(SETWIDTH) << "|       \___KHTN___|    |"<< endl;
//	cout << setw(SETWIDTH) << "|                       |" << endl;
//	cout << setw(SETWIDTH) << "| ------ WELCOME ------ |" << endl;
//	cout << setw(SETWIDTH) << "|_______________________|" << endl;
//}




void Welcome_25() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KHTN___|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| ------ WELCOME ------ |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_24() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KHTN___|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| ------ WELCOM  ------ |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_23() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KHTN___|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| -----  WELCO    ----- |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_22() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KHTN___|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| ----   WELC      ---- |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_21() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KHT____|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| ---    WEL        --- |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_20() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___KH_____|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| --     WE          -- |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_19() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /   *   |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\___K______|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "| -      W            - |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_18() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /       |       |" << endl;
	cout << setw(SETWIDTH) << "|     _/___     |       |" << endl;
	cout << setw(SETWIDTH) << "|     \\    \\___/__      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\__________|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_17() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /       |       |" << endl;
	cout << setw(SETWIDTH) << "|      / __     |       |" << endl;
	cout << setw(SETWIDTH) << "|          \\______      |" << endl;
	cout << setw(SETWIDTH) << "|      \\          \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\__________|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_16() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|        _/     |       |" << endl;
	cout << setw(SETWIDTH) << "|       /       |       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|          \\______      |" << endl;
	cout << setw(SETWIDTH) << "|                 \\     |" << endl;
	cout << setw(SETWIDTH) << "|       \\__________|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_15() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|         /     |       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|           ______      |" << endl;
	cout << setw(SETWIDTH) << "|                 \\     |" << endl;
	cout << setw(SETWIDTH) << "|         _________|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_14() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|           _/  |       |" << endl;
	cout << setw(SETWIDTH) << "|          /    |       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|             ____      |" << endl;
	cout << setw(SETWIDTH) << "|                 \\     |" << endl;
	cout << setw(SETWIDTH) << "|           _______|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_13() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|            /  |       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|               __      |" << endl;
	cout << setw(SETWIDTH) << "|                 \\     |" << endl;
	cout << setw(SETWIDTH) << "|             _____|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_12() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|             / |       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                 \\     |" << endl;
	cout << setw(SETWIDTH) << "|               ___|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_11() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|              /|       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                 _|    |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_10() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_09() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_08() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_07() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "|                       |" << endl;
	cout << setw(SETWIDTH) << "|_______________________|" << endl;
}
void Welcome_06() {
	cout << setw(SETWIDTH) << " _______________________ " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << " _______________________ " << endl;
}
void Welcome_05() {
	cout << setw(SETWIDTH) << "   ___________________   " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "   ___________________   " << endl;
}
void Welcome_04() {
	cout << setw(SETWIDTH) << "     _______________     " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "     _______________     " << endl;
}
void Welcome_03() {
	cout << setw(SETWIDTH) << "       ___________       " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "       ___________       " << endl;
}
void Welcome_02() {
	cout << setw(SETWIDTH) << "         _______         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "         _______         " << endl;
}
void Welcome_01() {
	cout << setw(SETWIDTH) << "           ___           " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "                         " << endl;
	cout << setw(SETWIDTH) << "           ___           " << endl;
}

void Draw_WelCome(char name[], int gender) {
	std::system("cls");
	void (*draw[])() = { Welcome_01, Welcome_02, Welcome_03,
		Welcome_04, Welcome_05, Welcome_06, Welcome_07, Welcome_08,
		 Welcome_09, Welcome_10, Welcome_11, Welcome_12, Welcome_13,
		 Welcome_14, Welcome_15, Welcome_16, Welcome_17, Welcome_18,
		 Welcome_19, Welcome_20, Welcome_21, Welcome_22, Welcome_23,
		Welcome_24, Welcome_25 };
	for (int i = 0; i < 25; i++) {
		cls();
		/*std::system("cls");*/
		if (i == 0) Sleep(60);
		for (int j = 0; j < ENDLRANGE; j++) cout << endl;
		draw[i]();
		Sleep(60);
	}
	if (gender == 1)
		cout << endl << setw(42 - strlen(name) / 2);
	else if (gender == 0)
		cout << endl << setw(40 - strlen(name) / 2);
	char preMale[] = { "Mr. " };
	char preFemale[] = { "Ms/Mrs. " };
	if (gender == 0)
		for (int i = 0; i < strlen(preFemale); i++) {
			cout << preFemale[i];
			Sleep(30);
		}
	else 
		for (int i = 0; i < strlen(preMale); i++) {
			cout << preMale[i];
			Sleep(30);
		}
	for (int i = 0; i < strlen(name); i++) {
		cout << name[i];
		Sleep(30);
	}
	cout << endl;
	Sleep(2000);
}

void Draw_WelCome_Lec(char name[], int degree) {
	std::system("cls");
	void (*draw[])() = { Welcome_01, Welcome_02, Welcome_03,
		Welcome_04, Welcome_05, Welcome_06, Welcome_07, Welcome_08,
		 Welcome_09, Welcome_10, Welcome_11, Welcome_12, Welcome_13,
		 Welcome_14, Welcome_15, Welcome_16, Welcome_17, Welcome_18,
		 Welcome_19, Welcome_20, Welcome_21, Welcome_22, Welcome_23,
		Welcome_24, Welcome_25 };
	for (int i = 0; i < 25; i++) {
		cls();
		/*std::system("cls");*/
		if (i == 0) Sleep(60);
		for (int j = 0; j < ENDLRANGE; j++) cout << endl;
		draw[i]();
		Sleep(60);
	}
	char pre[3][12] = { "Dr. ", "Prof. ", "Vice Prof. " };
	cout << endl << setw(43 - (strlen(name) + strlen(pre[degree])) / 2);
	for (int i = 0; i < strlen(pre[degree]); i++) {
		cout << pre[degree][i];
		Sleep(30);
	}
	for (int i = 0; i < strlen(name); i++) {
		cout << name[i];
		Sleep(30);
	}
	cout << endl;
	Sleep(2000);
}

void Draw_WelCome_Stu(char name[]) {
	std::system("cls");
	void (*draw[])() = { Welcome_01, Welcome_02, Welcome_03,
		Welcome_04, Welcome_05, Welcome_06, Welcome_07, Welcome_08,
		 Welcome_09, Welcome_10, Welcome_11, Welcome_12, Welcome_13,
		 Welcome_14, Welcome_15, Welcome_16, Welcome_17, Welcome_18,
		 Welcome_19, Welcome_20, Welcome_21, Welcome_22, Welcome_23,
		Welcome_24, Welcome_25 };
	for (int i = 0; i < 25; i++) {
		cls();
		/*std::system("cls");*/
		if (i == 0) Sleep(60);
		for (int j = 0; j < ENDLRANGE; j++) cout << endl;
		draw[i]();
		Sleep(60);
	}
	cout << endl << setw(43 - strlen(name) / 2);
	for (int i = 0; i < strlen(name); i++) {
		cout << name[i];
		Sleep(30);
	}
	cout << endl;
	Sleep(2000);
}

// Welcome

//void Welcome_01() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl; 
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//}
//void Welcome_02() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "         =         " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "         =         " << endl;
//}
//void Welcome_03() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "        ===        " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "        ===        " << endl;
//}
//void Welcome_04() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "       =====       " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "       =====       " << endl;
//}
//void Welcome_05() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "      =======      " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "      =======      " << endl;
//}
//void Welcome_06() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "     =========     " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "     =========     " << endl;
//}
//void Welcome_07() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "    ===========    " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "    ===========    " << endl;
//}
//void Welcome_08() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "   =============   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "   =============   " << endl;
//}
//void Welcome_09() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "  ===============  " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "  ===============  " << endl;
//}
//void Welcome_10() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << " ================= " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << " ================= " << endl;
//}
//void Welcome_11() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_12() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "                   " << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_13() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_14() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     W           |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_15() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WE          |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_16() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WEL         |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_17() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WELC        |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_18() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WELCO       |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_19() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WELCOM      |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void Welcome_20() {
//	for (int i = 0; i < ENDLRANGE; i++) cout << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "|     WELCOME     |" << endl;
//	cout << setw(SETWIDTH) << "|                 |" << endl;
//	cout << setw(SETWIDTH) << "[=================]" << endl;
//}
//void DrawWelcome() {
//	void (*draw[])() = { Welcome_01, Welcome_02, Welcome_03,
//		Welcome_04, Welcome_05, Welcome_06, Welcome_07,
//		Welcome_08, Welcome_09, Welcome_10, Welcome_11,
//		Welcome_12, Welcome_13, Welcome_14, Welcome_15,
//		Welcome_16, Welcome_17, Welcome_18, Welcome_19,
//		Welcome_20 };
//
//	for (int i = 0; i < 20; i++) {
//		std::system("cls");
//		draw[i]();
//		Sleep(50);
//	}
//	Sleep(2000);
//}