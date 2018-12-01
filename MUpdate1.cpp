#include <iostream>
#include <string>
using namespace std;

string login();
bool Is_Teacher(string username);
void Teacher_login();
void Student_login();

int main()
{
	cout << "Due to time constraints, the usernames and passwords will be provided.\n";
	cout << "The username for admin will be 'Teacher' and the username for the student will be 'Student'\n";
	cout << "The password for both accounts will be 'StraightA'\n\n";

	string username = login();

	if (Is_Teacher(username) == true)
		Teacher_login();
	else
		Student_login();

	system("pause");
	return 0;
}

string login()
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

bool Is_Teacher(string username)
{
	if (username == "Teacher")
		return true;
	else
		return false;
}

void Teacher_login()
{

}

void Student_login()
{

}