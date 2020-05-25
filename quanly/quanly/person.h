#pragma once
#include <iostream>
using namespace std;
const std::string fileName = "data.txt";

int number;
bool x = false;
bool y = false;
class Person {
protected:
	int id;
	char name[30];
	int age;


public:
	int getIntRange(int low, int high);
	virtual void inputInfo(int id);
	void add();
	virtual void printInfo(int id);
	void list();
	void remove();
	void update();
	void saveFile();
	void student();
	void teacher();
	void exit();


};
class Student : public Person {
private:
	char jobStu;
public:
	void add();
	void list();
	void update();
	void remove();

};
class Teacher : public Person {
private:
	char jobTea;
public:
	void add();
	void list();
	void update();
	void remove();
};
