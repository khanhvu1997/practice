#include <iostream>
#include "person.h"
using namespace std;

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
			input = person->getIntRange(0, 2);

			switch (input)
			{
			case 1:
				person->student();
				break;

			case 2:
				person->teacher();
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
			person = new Student;
			input = person->getIntRange(0, 4);
			switch (input) {
			case 1:
				cout << "Danh sach hoc sinh:\n";
				person->list();
				break;
			case 2:
				cout << "Them hoc sinh:\n";
				person->add();
				person->saveFile();
				cout << "Them thanh cong!";
				break;
			case 3:
				cout << "Xoa hoc sinh:\n";
				person->remove();
				person->saveFile();
				cout << "Xoa thanh cong!";
				break;
			case 4:
				cout << "Sua hoc sinh:\n";
				person->update();
				person->saveFile();
				cout << "Sua thanh cong!";
				break;
			case 0:
				person->exit();
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
			person = new Teacher;
			input = person->getIntRange(0, 4);
			switch (input) {
			case 1:
				cout << "Danh sach giao vien:\n";
				person->list();
				break;
			case 2:
				cout << "Them giao vien:\n";
				person->add();
				person->saveFile();
				cout << "Them thanh cong!";
				break;
			case 3:
				cout << "Xoa giao vien:\n";
				person->remove();
				person->saveFile();
				cout << "Xoa thanh cong!";
				break;
			case 4:
				cout << "Sua giao vien:\n";
				person->update();
				person->saveFile();
				cout << "Sua thanh cong!";
				break;
			case 0:
				person->exit();
				break;
			}
		}
	}
	return 0;
}

