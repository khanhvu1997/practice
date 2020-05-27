#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <experimental/filesystem> // compilers that support the TS
// #include <filesystem> // C++17 compilers
namespace fs = std::experimental::filesystem;
using namespace std;

int number = 0;
//Class Person
Student st;
Teacher te;
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
	bool a = false;
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
			else {
					if (id == st.id) {
						cout << "Nhap ten hoc sinh: ";
						cin >> name;
						cout << "Nhap tuoi hoc sinh: ";
						cin >> age;
						cout << "Nhap nghe nghiep hoc sinh: ";
						cin >> jobStu;
						listStudent.push_back(Student(id, name, age, jobStu));
						a = false;
					}
					else {
						listStudent.push_back(Student(st.id, st.name, st.age, st.jobStu));
						a = true;
					}
				}	
		}
		input.close();
		if (!a) {
			output.open(fileNameHs, ios::app || ios::trunc);
			for (Student temp : listStudent) {
				output.write((char *)&temp, sizeof(temp));
			}
			output.flush();
			output.close();
			cout << "Sua thanh cong!";
		}
		else {
			cout << "--------- Ma hoc sinh khong ton tai ---------\n";
			this->update();
		}
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
	bool idCheck = false;
	vector<Student>   listStudentTemp;
	try {
		ifstream input;
		input.open(fileNameHs, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		cout << "Hay nhap ma so hoc sinh: ";
		cin >> id;
		while (true) {
			input.read((char*)&st, sizeof(st));
			if (input.eof()) break;
			if (st.id != id) {
				listStudentTemp.push_back(Student(st.id, st.name, st.age, st.jobStu));
			}
			else {
				idCheck = true;
			}
		}
		input.close();
		if (idCheck) {
			ofstream output;
			fs::resize_file(fileNameHs, 0);
			output.open(fileNameHs, ios::out | ios::app);
			output.seekp(0);
			for (Student tehs : listStudentTemp) {
				if (tehs.id == id) {
					continue;
				}
				output.write((char *)&tehs, sizeof(tehs));
			}
			output.close();
			idCheck = false;
			cout << "--------- Xoa thanh cong hoc sinh voi id = " << id << " ---------" << endl;
			return;
		}
		else {
			cout << "--------- Ma hoc sinh khong ton tai ---------" << endl;
			this->remove();
		}
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}


//Class Teacher
Teacher::Teacher() {};
Teacher::Teacher(int id, string name, int age, string jobTea) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->jobTea = jobTea;
};

void Teacher::add() {
	Person::inputInfo();
	cout << "Nhap nghe nghiep: ";
	cin >> jobTea;
}
void Teacher::list()
{
	try
	{
		ifstream input;
		input.open(fileNameGv, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		while (true) {
			input.read((char*)&te, sizeof(te));
			if (input.eof()) break;
			else {
				cout << "\n----------------------------\n";
				cout << "Ma giao vien la: " << te.id << endl;
				cout << "Ten giao vien la: " << te.name << endl;
				cout << "Tuoi giao vien la: " << te.age << endl;
				cout << "Nghe nghiep giao vien la: " << te.jobTea << endl;
			}
		}
		input.close();
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}
void Teacher::saveFile()
{
	ofstream output;
	output.open(fileNameGv, ios::app);
	te.id = id;
	te.name = name;
	te.age = age;
	te.jobTea = jobTea;
	output.write((char *)&te, sizeof(te));
	output.close();
}

void Teacher::remove()
{
	int id;
	int index;
	bool idCheck = false;
	vector<Teacher>   listTeacherTemp;
	try {
		ifstream input;
		input.open(fileNameGv, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		cout << "Hay nhap ma giao vien: ";
		cin >> id;
		while (true) {
			input.read((char*)&te, sizeof(te));
			if (input.eof()) break;
			if (te.id != id) {
				listTeacherTemp.push_back(Teacher(te.id, te.name, te.age, te.jobTea));
			}
			else {
				idCheck = true;
			}
		}
		input.close();
		if (idCheck) {
			ofstream output;
			fs::resize_file(fileNameGv, 0);
			output.open(fileNameGv, ios::out | ios::app);
			output.seekp(0);
			for (Teacher tegv : listTeacherTemp) {
				if (tegv.id == id) {
					continue;
				}
				output.write((char *)&tegv, sizeof(tegv));
			}
			output.close();
			idCheck = false;
			cout << "--------- Xoa thanh cong giao vien voi id = " << id << " ---------" << endl;
			return;
		}
		else {
			cout << "--------- Ma giao vien khong ton tai ---------" << endl;
			this->remove();
		}
	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}
void Teacher::update()
{
	int id;
	bool a = false;
	std::vector<Teacher>   listTeacher;

	try {
		ifstream input;
		ofstream output;
		input.open(fileNameGv, ios::in);
		if (!input) {
			cout << "Error in opening file..";
		}
		cout << "Hay nhap ma giao vien: ";
		cin >> id;
		while (true) {
			input.read((char*)&te, sizeof(te));
			if (input.eof()) break;
			else {
				if (id == te.id) {
					cout << "Nhap ten giao vien: ";
					cin >> name;
					cout << "Nhap tuoi giao vien: ";
					cin >> age;
					cout << "Nhap nghe nghiep giao vien: ";
					cin >> jobTea;
					listTeacher.push_back(Teacher(id, name, age, jobTea));
					a = false;
				}
				else {
					listTeacher.push_back(Teacher(te.id, te.name, te.age, te.jobTea));
					a = true;
				}
			}
		}
		input.close();
		if (!a) {
			output.open(fileNameGv, ios::app || ios::trunc);
			for (Teacher temp : listTeacher) {
				output.write((char *)&temp, sizeof(temp));
			}
			output.flush();
			output.close();
			cout << "Sua thanh cong!";
		}
		else {
			cout << "--------- Ma giao vien khong ton tai ---------\n" << endl;
			this->update();
		}

	}
	catch (std::exception& e)
	{
		cout << "erorrrrr" << endl;
	}
}


