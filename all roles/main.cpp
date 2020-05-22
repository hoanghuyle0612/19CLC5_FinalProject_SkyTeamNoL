// main.cpp
#include "Header.h"
int main()
{
	login();
	char temp3[100];
	ofstream fi1("temp.txt");
	fi1 << "student-";
	fi1 << futureclass;
	fi1 << ".txt";
	fi1.close();
	ifstream fo1("temp.txt");
	fo1 >> temp3;
	fo1.close();
	remove("temp.txt");
	char temp34[100];
	ofstream fi12("temp.txt");
	fi12 << "student-";
	fi12 << currentclass;
	fi12 << ".txt";
	fi12.close();
	ifstream fo12("temp.txt");
	fo12 >> temp34;
	fo12.close();
	remove("temp.txt");
	ifstream f10(temp34);
	student c[10];
	ifstream f8(temp3);
	ofstream f9("temp_student.txt");
	fstream f11("temp.txt");
	if (!f8.is_open() || !f9.is_open())
	{
		cout << "Error opening files!" << endl;
	}
	int ff = 0;
	int m;
	f8 >> m;
	f9 << m + 1 << "\n";
	char linez[100];
	while (f8.getline(linez, 100))
	{
		f9 << linez << "\n";
	}
	char lineb[100];
	while (f10.getline(lineb, 100))
	{
		char linec[100];
		itoa(id, linec, 10);
		if (!strcmp(lineb, linec))
		{
			ff++;
			if (ff == 1)
			{
				for (int i = 0;i < 8;i++)
				{
					f11 << lineb << "\n";
				}
			}
		}
	}
	char linev[100];
	while (f11.getline(linev, 100))
	{
		f9 << linev << "\n";
	}
	f10.close();
	f11.close();
	f8.close();
	f9.close();
	remove("temp.txt");
	remove(temp3);
	if (rename("temp_student.txt", temp3) == 0)
	{
		cout << "Successfully" << endl;
	}
}
	return 0;
}