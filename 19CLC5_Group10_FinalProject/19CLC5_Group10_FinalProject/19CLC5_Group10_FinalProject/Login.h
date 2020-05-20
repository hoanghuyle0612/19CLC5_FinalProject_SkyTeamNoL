// LOGIN HEADER

#include "General.h"

struct staff {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int gender;
	int type;
};

struct lecturer {
	char username[100];
	char password[100];
	char fullname[100];
	char dob[20];
	int gender;
	int type;
};

struct student {
	char username[100];
	char password[100];
	char fullname[100];
	char classname[10];
	int id;
	char dob[20];
	int gender;
	int type;
};
