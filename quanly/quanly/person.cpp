#include "person.h"
#include <iostream>
#include <fstream>
using namespace std;

//Class Person
int Person::getIntRange(int low, int high) {
	int input;
	while (true) {
		cin >> input;
		if (input < low || input > high) {
			cout << "Gia tri khong hop le. Vui long nhap lai!\n";
		}
		else
			break;
	}
	return input;
}

void Person::inputInfo(int id)
{
	cout << "Nhap ma: \n";
	cin >> id;
	cout << "Nhap ten: \n";
	cin >> name;
	cout << "Nhap tuoi: \n";
	cin >> age;
}

void Person::printInfo(int id)
{
	cout << "\n---------------\n";
	cout << "Ma la: " << id;
	cout << "\nTen la: " << name;
	cout << "\nTuoi la: " << age;
}
void Person::saveFile()
{
	ofstream output;
	output.open(fileName);
	for (int i = 1; i <= number; i++)
	{
		output << id << '\n';
		output << name << '\n';
		output << age << '\n';
	}
	output.close();
}
void Person::student() {
	x = true;
}
void Person::teacher() {
	y = true;
	x = false;
}
void Person::exit() {
	x = false;
	y = false;
}

//Class Student
void Student::add()
{
	number++;
	Person::inputInfo(number);
	cout << "Nhap nghe nghiep:";
	cin >> jobStu;
}
void Student::list()
{
	for (int i = 1; i <= number; i++) {
		Person::printInfo(i);
		cout << "Nghe nghiep la:" << jobStu;
	}

}

void Student::remove()
{
	int id;
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	for (int i = id + 1; i <= number; i++)
		//allStudent[i - 1] = allStudent[i];
		number--;
}
void Student::update()
{
	int id;
	cout << "Hay nhap ma so hoc sinh: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma so hoc sinh khong hop le!\n";
		return;
	}
	Person::inputInfo(id);
}

//Class Teacher


void Teacher::add() {
	number++;
	Person::inputInfo(number);
	cout << "Nhap nghe nghiep:";
	cin >> jobTea;
}
void Teacher::list()
{
	for (int i = 1; i <= number; i++) {
		Person::printInfo(i);
		cout << "Nghe nghiep la:" << jobTea;
	}
}

void Teacher::remove()
{
	int id;
	cout << "Hay nhap ma giao vien: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma giao vien khong hop le!\n";
		return;
	}
	for (int i = id + 1; i <= number; i++)
		//allStudent[i - 1] = allStudent[i];
		number--;
}
void Teacher::update()
{
	int id;
	cout << "Hay nhap ma giao vien: ";
	cin >> id;
	if (id < 1 || id > number)
	{
		cout << "Ma giao vien khong hop le!\n";
		return;
	}
	Person::inputInfo(id);
}

