#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Due to time constraints, the usernames and passwords will be provided.\n";
	cout << "The username for admin will be 'Teacher' and the username for the student will be 'Student'\n";
	cout << "The password for both accounts will be 'StraightA'\n";

	string username;
	cout << "Enter your username: ";
	cin >> username;

	while (username != "Teacher" && username!= "Student")
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

	system("pause");
	return 0;
}
