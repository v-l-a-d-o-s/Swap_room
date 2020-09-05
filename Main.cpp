#include<iostream>
#include<fstream>
#include<string>
#include"Classes.h"
using namespace std;


int main() {
	
	Registration reg;
	cout << "\tMenu" << endl;
	cout << "1)Registration in system" << endl;
	cout << "2)Sign in" << endl;
	int n;
	cin >> n;
	
		switch (n)
		{
		case 1:reg.Create(); break;

		case 2:reg.Sign_in(); break;
		default:
			cout << "Error" << endl;
			break;
		}
	
	return 0; 
}