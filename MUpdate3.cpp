#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Grades
{
public:
	int grades[3];

	string login();
	bool Is_Teacher(string username);
	void Teacher_login();
	void Student_login();
	void get_info();
	void set_info();
	//double Get_GPA();
};



int main()
{
	Grades G;

	cout << "Due to time constraints, the usernames and passwords will be provided.\n";
	cout << "The username for admin will be 'Teacher' and the username for the student will be 'Student'\n";
	cout << "The password for both accounts will be 'StraightA'\n\n";

	string username = G.login();

	if (G.Is_Teacher(username) == true)
		G.Teacher_login();
	else
		G.Student_login();

	system("pause");
	return 0;
}

string Grades::login()
{
	string username;
	cout << "Enter your username: ";
	cin >> username;

	while (username != "Teacher" && username != "Student")
	{
		cout << "Invalid username, please enter the correct username: ";
		cin >> username;
	}

	string password;
	cout << "Enter your password: ";
	cin >> password;

	while (password != "StraightA")
	{
		cout << "Invalid password, please enter the correct password: ";
		cin >> password;
	}
	return username;
}

bool Grades::Is_Teacher(string username)
{
	if (username == "Teacher")
		return true;
	else
		return false;
}

void Grades::Teacher_login()
{
	set_info();
}

void Grades::Student_login()
{
	get_info();
}

void Grades::set_info()
{
	ofstream out;

	string name;
	cout << "Enter the students name, followed by '.txt' to enter a new student\n";
	cin >> name;

	out.open(name);

	string set[6];

	cout << "Please fill out the new student's information.\n";
	cout << "New Student Name: ";
	cin >> set[0];
	cout << "\nNew Student ID: ";
	cin >> set[1];
	cout << "\nStudent's Course: ";
	cin >> set[2];
	cout << "\nThe Student's Three Exam Scores: ";
	cin >> set[3] >> set[4] >> set[5];

	for (int i = 0; i < 6; i++)
	{
		out << set[i];
	}
}

void Grades::get_info()
{
	ifstream in;

	string name;
	cout << "Enter your name, followed by '.txt' to access your information\n";
	cout << "For a default template, please enter in 'studentinfo.txt'\n";
	cin >> name;
	in.open(name);

	string gather[6];
	int Avg;
	int total;

	for (int i = 0; i < 6; i++)
	{
		in >> gather[i];
	}
	cout << "\nStudent Name: " << gather[0] << " " << "\nStudent ID: " << gather[1] << " " << "\nCourse: " << gather[2] << endl;
	cout << "\nScore 1: " << gather[3] << " " << "\nScore 2: " << gather[4] << " " << "\nScore 3: " << gather[5] << endl << endl;
	grades[0] = stoi(gather[3]);
	grades[1] = stoi(gather[4]);
	grades[2] = stoi(gather[5]);

	total = grades[0] + grades[1] + grades[2];

	Avg = total / 3;

	if (Avg >= 90)
		{
		cout << "Your GPA is a 4.0\n";
		}
	else if (Avg >= 80 && Avg < 90)
		{
		cout << "Your GPA is a 3.0\n";
		}
	else if (Avg >= 70 && Avg < 80)
		{
		cout << "Your GPA is a 2.0\n";
		}
	else if (Avg >= 60 && Avg < 70)
		{
		cout << "Your GPA is a 1.0\n";
		}
	else if (Avg < 60)
		{
		cout << "Your GPA is a 0.0\n";
		}

	
}

//double Grades::Get_GPA()
//{
//	int Avg;
//	int total;
//	double GPA = 0.0;
//
//	total = grades[0] + grades[1] + grades[2];
//
//	Avg = total / 3;
//
//	switch (Avg)
//	{
//	case 1: if (Avg >= 90)
//	{
//		GPA = 4.0;
//		break;
//	}
//	case 2: if (Avg >= 80 && Avg < 90)
//	{
//		GPA = 3.0;
//		break;
//	}
//	case 3: if (Avg >= 70 && Avg < 80)
//	{
//		GPA = 2.0;
//		break;
//	}
//	case 4: if (Avg >= 60 && Avg < 70)
//	{
//		GPA = 1.0;
//		break;
//	}
//	case 5: if (Avg < 60)
//	{
//		GPA = 0.0;
//		break;
//	}
//	}
//
//	return GPA;
//}