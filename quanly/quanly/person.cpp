#pragma once
#include "person.h"
#include <iostream>
#include <String>
#include <fstream>
#include <vector>
using namespace std;

int number = 0;
//Class Person

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
//void Person::remove() {}
void Person::update() {}
void Person::saveFile(){}


//Class Student
void Student::add()
{
	number++;
	Person::inputInfo();
	cout << "Nhap nghe nghiep: ";
	cin >> jobStu;
}
void Student::list()
{
	ifstream input;
	input.open(fileNameHs, ios::in);
	Student st;
	//vector<Student> stu;
	while (!input.eof()) {
		input.read((char*)&st, sizeof(st));
		cout << "\n----------------------------\n";
		cout << "Ma hoc sinh la: " << st.id <<  endl;
		cout << "Ten hoc sinh la: " << st.name << endl;
		cout << "Tuoi hoc sinh la: " << st.age << endl;
		cout << "Nghe nghiep hoc sinh la: " << st.jobStu << endl;
		//input.read((char*)&st, sizeof(st));
	}
	input.close();

}
void Student::saveFile()
{
	ofstream output;
	output.open(fileNameHs, ios::app);
	Student st;
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
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	if (id < 1)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	Person::inputInfo();
	cout << "Nhap nghe nghiep: ";
	cin >> jobStu;
}

/*void Student::remove()
{
	int id;
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	Student *st = new Student[number];
	st[id] = st[number - 1];
	if (id < 1||id > number)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	number--;
}*/


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

