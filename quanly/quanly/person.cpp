#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int number = 0;
//Class Person
Student st;
//vector<Student> stu;
void Person::inputInfo()
{
	cout << "Nhap ma: ";
	cin >> id;
	cout << "Nhap ten: ";
	cin >> name;
	cout << "Nhap tuoi: ";
	cin >> age;
}

void Person::printInfo()
{

	cout << "\n---------------\n";
	cout << "Ma la: " << id;
	cout << "\nTen la: " << name;
	cout << "\nTuoi la: " << age;
}
void Person::add(){}
void Person::list() {}
void Person::remove() {}
void Person::update() {}
void Person::saveFile(){}


//Class Student
Student::Student() {};
Student::Student(int id, string name, int age, string jobStu) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->jobStu = jobStu;
};
void Student::add()
{
	number++;
	Person::inputInfo();
	cout << "Nhap nghe nghiep: ";
	cin >> jobStu;
}
void Student::list()
{
	try
	{
		ifstream input;
		input.open(fileNameHs, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		while (true) {
			input.read((char*)&st, sizeof(st));
			if (input.eof()) break;
			else {
				cout << "\n----------------------------\n";
				cout << "Ma hoc sinh la: " << st.id << endl;
				cout << "Ten hoc sinh la: " << st.name << endl;
				cout << "Tuoi hoc sinh la: " << st.age << endl;
				cout << "Nghe nghiep hoc sinh la: " << st.jobStu << endl;
			}
		}
		input.close();
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}
void Student::saveFile()
{
	ofstream output;
	output.open(fileNameHs, ios::app);
	st.id = id;
	st.name = name;
	st.age = age;
	st.jobStu = jobStu;
	output.write((char *) &st, sizeof(st));
	output.close();
}
void Student::update()
{ 
	
	int id;
	std::vector<Student>   listStudent;

	try {
		ifstream input;
		ofstream output;
		input.open(fileNameHs, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		cout << "Hay nhap ma so hoc sinh: ";
		cin >> id;
		while (true) {
			input.read((char*)&st, sizeof(st));
			if (input.eof()) break;
			/*cout << "id:" << st.id << endl;
			cout << "name:" << st.name << endl;
			cout << "age:" << st.age << endl;
			cout << "jobStu:" << st.jobStu << endl;*/
			else {
				if (id == st.id) {
					cout << "Nhap ten hoc sinh: ";
					cin >> name;
					cout << "Nhap tuoi hoc sinh: ";
					cin >> age;
					cout << "Nhap nghe nghiep hoc sinh: ";
					cin >> jobStu;
					listStudent.push_back(Student(id, name, age, jobStu));
					cout << "Sua thanh cong!";
				}
				else {
					listStudent.push_back(Student(st.id, st.name, st.age, st.jobStu));			
				} 
			}
		}
		/*if (id != st.id) {
			cout << "Ma khong chinh xac!";
			return;
		}*/
		output.open(fileNameHs, ios::app || ios::trunc);
		for (Student temp : listStudent) {
			/*cout << "id:" << temp.id << endl;
			cout << "name:" << temp.name << endl;
			cout << "age:" << temp.age << endl;
			cout << "jobStu:" << temp.jobStu << endl;*/
			output.write((char *)&temp, sizeof(temp));
		}
		output.flush();
		output.close();
		input.close();
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}

void Student::remove()
{
	int id;
	int index;
	vector<Student>   listStudent;
	try {
		ifstream input;
		ofstream output;
		input.open(fileNameHs, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		cout << "Hay nhap ma so hoc sinh: ";
		cin >> id;
		/*vector<Student>::iterator it = find(listStudent.begin(), listStudent.end(), id);
		if (it != listStudent.end())
		{
			index = distance(listStudent.begin(), it);
		}
		else
		{
			cout << "Element Not Found" << endl;
		}*/
		while (true) {
			input.read((char*)&st, sizeof(st));
			if (input.eof()) break;
			listStudent.push_back(Student(st.id, st.name, st.age, st.jobStu));
			/*else {
				if (id == st.id) {
					listStudent.erase(listStudent.begin() + index);
					cout << "Xoa thanh cong!";
				}
				else {
					cout << "Ma khong chinh xac!";
					return;
				}

			}*/
		}
		output.open(fileNameHs, ios::app || ios::trunc);
		for (Student temp : listStudent) {
			if (temp.id == id) {
				continue;
			} 
			output.write((char *)&temp, sizeof(temp));
		}
		output.flush();
		output.close();
		input.close();
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}


//Class Teacher


void Teacher::add() {
	inputInfo();
	cout << "Nhap nghe nghiep: ";
	cin >> jobTea;
}
void Teacher::list()
{
	Teacher *te = new Teacher[number];
	for (int i = 1; i <= number; i++) {
		//te[i].printInfo(i);
		cout << "Nghe nghiep la:" << jobTea;
	}
}

/*void Teacher::remove()
{
	int id;
	cout << "Hay nhap ma giao vien: ";
	cin >> id;
	if (id < 1 )
	{
		cout << "Ma giao vien khong hop le!\n";
		return;
	}
	Teacher *te = new Teacher[number];
	for (int i = id + 1; i <= number; i++)
		te[i - 1] = te[i];
}
void Teacher::update()
{
	int id;
	cout << "Hay nhap ma giao vien: ";
	cin >> id;
	if (id < 1 )
	{
		cout << "Ma giao vien khong hop le!\n";
		return;
	}
	Person::inputInfo();
}*/
void Teacher::saveFile()
{
	ofstream output;
	output.open(fileNameGv);
	//for (int i = 1; i <= 100; i++)
	//{
		output << id << '\n';
		output << name << '\n';
		output << age << '\n';
		output << jobTea << '\n';
	//}
	output.close();
}

