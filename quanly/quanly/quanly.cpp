#include <iostream>
#include "person.h"
using namespace std;

bool x = false;
bool y = false;

int getIntRange(int low, int high) {
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
int main()
{
	Person *person;
	int input;
	while (true) {
		if (!x && !y) {
			cout << "\n----------------------------------------";
			cout << "\n+++++Chuong trinh quan ly truong hoc+++++\n";
			cout << "1: Hoc sinh.\n";
			cout << "2: Giao vien.\n";
			cout << "0: Thoat.\n";
			input = getIntRange(0,2);
			switch (input)
			{
			case 1:
				x = true;
				break;

			case 2:
				x = false;
				y = true;
				break;

			case 0:
				return 0;
			}
		}
		else if (!y) {
			cout << "\n----------------------------------------";
			cout << "\n+++++Chuong trinh quan ly hoc sinh+++++\n";
			cout << "1: Hien thi danh sach hoc sinh.\n";
			cout << "2: Them hoc sinh.\n";
			cout << "3: Xoa hoc sinh.\n";
			cout << "4: Sua hoc sinh.\n";
			cout << "0: Thoat chuong trinh hoc sinh.\n";
			person = new Student();
			input = getIntRange(0, 4);
			switch (input) {
			case 1:
				cout << "Danh sach hoc sinh:\n";
				person->list();
				delete(person);
				break;
			case 2:
				cout << "Them hoc sinh:\n";
				person->add();
				person->saveFile();
				delete(person);
				cout << "Them thanh cong!";
				break;
			case 3:
				cout << "Xoa hoc sinh:\n";
				//person->remove();
				//person->saveFile();
				delete(person);
				cout << "Xoa thanh cong!";
				break;
			case 4:
				cout << "Sua hoc sinh:\n";
				person->update();
				person->saveFile();
				delete(person);
				cout << "Sua thanh cong!";
				break;
			case 0:
				x= false;
				y = false;
				delete(person);
				break;
			}
		}
		else {
			cout << "\n----------------------------------------";
			cout << "\n+++++Chuong trinh quan ly giao vien+++++\n";
			cout << "1: Hien thi danh sach giao vien.\n";
			cout << "2: Them giao vien.\n";
			cout << "3: Xoa giao vien.\n";
			cout << "4: Sua giao vien.\n";
			cout << "0: Thoat chuong trinh giao vien.\n";
			person = new Teacher();
			input = getIntRange(0, 4);
			switch (input) {
			case 1:
				cout << "Danh sach giao vien:\n";
				//delete(person);
				//person->list();
				break;
			case 2:
				cout << "Them giao vien:\n";
				//person->add();
				//person->saveFile();
				//delete(person);
				cout << "Them thanh cong!";
				break;
			case 3:
				cout << "Xoa giao vien:\n";
				//person->remove();
				//person->saveFile();
				//delete(person);
				cout << "Xoa thanh cong!";
				break;
			case 4:
				cout << "Sua giao vien:\n";
				//person->update();
				//person->saveFile();
				//delete(person);
				cout << "Sua thanh cong!";
				break;
			case 0:
				x = false;
				y = false;
				delete(person);
				break;
			}
		}
	}
	return 0;
}

