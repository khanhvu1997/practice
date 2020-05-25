#pragma once
#include <iostream>
#include <string>
using namespace std;
const std::string fileNameHs = "hocsinh.txt";
const std::string fileNameGv = "giaovien.txt";

class Person {
protected:
	int id;
	string name;
	int age;


public:
	void inputInfo();
	void printInfo();
	virtual void add();
	virtual void list();
	//virtual void remove();
	virtual void update();
	virtual void saveFile();
};
class Student : public Person {
private:
	string jobStu;
public:
	void add();
	void list();
	//void remove();
	void update();
	void saveFile();
};
class Teacher : public Person {
private:
	string jobTea;
public:
	void add();
	void list();
	//void remove();
	//void update();
	void saveFile();
};
