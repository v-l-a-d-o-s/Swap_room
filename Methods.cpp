#include<iostream>
#include<fstream>
#include<string>
#include<locale>
#include<cstdlib>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include"Classes.h"
using namespace std;
/* 1 регестраци€ и проверка данных на валидность (* сделать проверку на цыфры)?
   2 сделать вход (* ƒоделать чтоб проверка когда много учетных записей а не одна )(сделать бинарний поиск в будущем)?
   3 сделать информацию про пользовател€ и квартиру
*/

string check_line(string line) {
	string str;
	for (int i = 0; i < line.length(); i++) {
		if (isalpha(line[i])) {
			str += line[i];
		}
	}
	cout <<"LINE NOT NUMBER_:"<< str << endl;
	return str;
} 

Apartment::Apartment() {
	city = " ";
	area = " ";
	square = 0.0;
	square_kitchen = 0.0;
	floor = 0;
	price = 0.0;
}



Person::Person() {
	first_name = " ";
	last_name = " ";
	father_name = " ";
	mobile = 0;
	pass = " ";
}

void Person::Input_person() {
	
	cout << "First name:" << endl;
	cin >> first_name;
	first_name = check_line(first_name);
	cout << "Last name:" << endl;
	cin >> last_name;
	last_name = check_line(last_name);
	cout << "Father name:" << endl;
	cin >> father_name;
	father_name = check_line(father_name);
	cout << "Mobile:" << endl;
	cin >> mobile;
	cout << "Password:" << endl;
	cin >> pass;

	
	
	
}

void Person::Input_apartment() {
	cout << "Input City" << endl;
	cin >> city;
	city = check_line(city);
	cout << "Input Area" << endl;
	cin >> area;
	area = check_line(area);
	cout << "Input Square" << endl;
	cin >> square;
	cout << "Input Square Kitchen" << endl;
	cin >> square_kitchen;
	cout << "Input Price" << endl;
	cin >> price;
}

void Person::Write_to_file() {
	fstream file;
	file.open("Information.txt", ios::app);
	if (!file.is_open()) {
		cout << "File Error" << endl;
	}
	else {
		file << first_name << endl;
		file << last_name << endl;
		file << father_name << endl;
		file << mobile << endl;
		file << pass << endl;
		file << city << endl;
		file << area<<endl;
		file << square<<endl;
		file << square_kitchen<<endl;
		file << price<<endl;
		file << endl;

	}
	file.close();
}

void Person::ShowData() {
	cout << "First name:\t" << first_name << endl;
	cout << "Last name:\t" << last_name << endl;
	cout << "Father name:\t" << father_name << endl;
	cout << "Mobile:\t" << mobile << endl;
	cout << "Password:\t" << pass << endl;
	cout << "City:\t" << city << endl;
	cout << "Area:\t" << area << endl;
	cout << "Square:\t" << square << endl;
	cout << "Square Kitchen:\t" << square_kitchen << endl;
	cout << "Price:\t" << price << endl;
	cout << endl;
	
	
}
void Person::Output() {
	fstream file;
	file.open("Information.txt", ios::in);
	if (!file.is_open()) {
		cout << "File Error" << endl;
	}
	else {
		while (!file.eof()) {
			file >> first_name;
			file >> last_name;
			file >> father_name;
			file >> mobile;
			file >> pass;
			file >> city;
			file >> area;
			file >> square;
			file >> square_kitchen;
			file >> price;
			ShowData();
		}
	}
	file.close();
}


void Working_Data::Search() {

	cout << "Search in file" << endl;
	int n;
	string str;
	double f;
	cout << "\tMenu" << endl;
	cout << "1)First name" << endl;
	cout << "2)City" << endl;
	cout << "3)Area" << endl;
	cout << "4)Price" << endl;
	cin >> n;
	fstream file;
	file.open("Information.txt", ios::in);
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		switch (n)
		{
		case 1:
			cout << "Search by first name" << endl;
			cin >> str;
			while (!file.eof()) {
				file >> first_name;
				file >> last_name;
				file >> father_name;
				file >> mobile;
				file >> pass;
				file >> city;
				file >> area;
				file >> square;
				file >> square_kitchen;
				file >> price;
				if (str == first_name) {
					ShowData();
				}
				else {
					cout << "Not found" << endl;
				}
			}
			break;
		case 2:cout << "Search by City" << endl;
			cin >> str;
			while (!file.eof()) {
				file >> first_name;
				file >> last_name;
				file >> father_name;
				file >> mobile;
				file >> pass;
				file >> city;
				file >> area;
				file >> square;
				file >> square_kitchen;
				file >> price;
				if (str == city) {
					ShowData();
				}
				else {
					cout << "Not found" << endl;
				}
			}
			break;

		case 3:cout << "Search by Area" << endl;
			cin >> str;
			while (!file.eof()) {
				file >> first_name;
				file >> last_name;
				file >> father_name;
				file >> mobile;
				file >> pass;
				file >> city;
				file >> area;
				file >> square;
				file >> square_kitchen;
				file >> price;
				if (str == area) {
					ShowData();
				}
				else {
					cout << "Not found" << endl;
				}
			}
			break;
		case 4:cout << "Search by Price" << endl;
			cin >> str;
			while (!file.eof()) {
				file >> first_name;
				file >> last_name;
				file >> father_name;
				file >> mobile;
				file >> pass;
				file >> city;
				file >> area;
				file >> square;
				file >> square_kitchen;
				file >> price;
				f = stod(str);
				if (f == price) {
					ShowData();
				}
				else {
					cout << "Not found" << endl;
				}
			}
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		
	}
	file.close();
}

void Working_Data::Sort() {
	
	vector<float> dt;
	fstream file;
	file.open("Information.txt", ios::in);
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		while (!file.eof())
		{
			file >> first_name;
			file >> last_name;
			file >> father_name;
			file >> mobile;
			file >> pass;
			file >> city;
			file >> area;
			file >> square;
			file >> square_kitchen;
			file >> price;
			dt.push_back(price);
		}
		file.close();
		
	}
	dt.pop_back();
	sort(dt.begin(), dt.end());
	for (float n : dt) {
		cout << n << endl;
	}
}

void Working_Data::Update() { // дописует последнею строку дважды 
	string str;
	fstream file_r,file_w;
	file_r.open("Information.txt", ios::in);
	file_w.open("Wr.txt", ios::out);
	if (!file_r.is_open() && !file_w.is_open()) {
		cout << "Error" << endl;
	}
	else {
		cout << "Update:" << endl;
		cout << "Search by First name" << endl;
		cin >> str;
		str = check_line(str);
		while (!file_r.eof()) {
			file_r >> first_name;
			file_r >> last_name;
			file_r >> father_name;
			file_r >> mobile;
			file_r >> pass;
			file_r >> city;
			file_r >> area;
			file_r >> square;
			file_r >> square_kitchen;
			file_r >> price;

			
			if (str == first_name) {
				Input_person();
				Input_apartment();
				file_w << first_name << endl;
				file_w << last_name << endl;
				file_w << father_name << endl;
				file_w << mobile << endl;
				file_w << pass << endl;
				file_w << city << endl;
				file_w << area << endl;
				file_w << square << endl;
				file_w << square_kitchen << endl;
				file_w << price << endl;
				file_w << endl;

			}
			else {
				file_w << first_name<<endl;
				file_w << last_name << endl;
				file_w << father_name<<endl;
				file_w << mobile<<endl;
				file_w << pass << endl;
				file_w << city << endl;
				file_w << area << endl;
				file_w << square << endl;
				file_w << square_kitchen << endl;
				file_w << price << endl;
				file_w << endl;
			}
		}
	}
	file_r.close();
	file_w.close();
	remove("Information.txt");
	rename("Wr.txt", "Information.txt");
}


void Registration::Create() {
	Input_person();
	Input_apartment();

	fstream file;
	file.open("Information.txt", ios::app);
	if (!file.is_open()) {
		cout << "File Error" << endl;
	}
	else {
		file << first_name << endl;
		file << last_name << endl;
		file << father_name << endl;
		file << mobile << endl;
		file << pass << endl;
		file << city << endl;
		file << area << endl;
		file << square << endl;
		file << square_kitchen << endl;
		file << price << endl;
		file << endl;

	}
	file.close();
}

void Registration::Sign_in() {
	int n;
	string f_name;
	string password;
	cout << "\tWelcome" << endl;
	cout << "Input First name:" << endl;
	cin >> f_name;
	f_name = check_line(f_name);
	cout << "Input password:" << endl;
	cin >> password;
	fstream file;
	file.open("Information.txt", ios::in);
	if (!file.is_open()) {
		cout << "File Error" << endl;
	}
	else {
		while (!file.eof()) {
			file >> first_name;
			file >> last_name;
			file >> father_name;
			file >> mobile;
			file >> pass;
			file >> city;
			file >> area;
			file >> square;
			file >> square_kitchen;
			file >> price;
			if (f_name == first_name && password == pass) {
				cout << "Welcome " << first_name << endl;
				cout << "\tMenu User" << endl;
				cout << "1)Update" << endl;
				cout << "2)Search" << endl;
				cout << "3)Sort" << endl;
				Working_Data dt;
				cin >> n;	
			    switch (n) {
					case 1:dt.Update(); break;
					case 2:dt.Search(); break;
					case 3:dt.Sort(); break;
					default:
						cout << "Error" << endl;
						break;
					}
				break;
			}
			else {
				cout << "Error login and password" << endl;
			}
		}

	}
	file.close();
}

