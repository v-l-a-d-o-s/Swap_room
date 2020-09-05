#pragma once
#include<iostream>
#include<string>

using namespace std;

class Apartment {
protected:
	string city;
	string area;
	float square;
	float square_kitchen;
	int floor;
	float price;
public:
	Apartment();
};

class Person: public Apartment {
protected:
	string first_name;
	string last_name;
	string father_name;
	int mobile;
	string pass;
public:
	Person();
	void Input_person();
	void Input_apartment();
	void Write_to_file();
	void ShowData();
	void Output();
	friend string check_line(string line);
};

class Working_Data : public Person{
public:
	void Update();
	void Search();
	void Sort();
};

class Registration :public Person{
public:
	void Create();
	void Sign_in();
};