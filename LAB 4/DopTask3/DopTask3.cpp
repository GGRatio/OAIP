#include <iostream>
#include <windows.h>

#define size 30
#define nVar 5

void enter_nwe();
void serch();
void sort();

struct Data {
	char sanatorium[size];
	char location[size];
	char profile[size];
	int col;
};

Data data_base[nVar];

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int choice=1;

	do {
		cout << "�������� �������������: \n";
		cout << "1 - ���� ������\n";
		cout << "2 - ���������� � ����� ������\n";
		cout << "3 - ����� �������\n";
		cout << "0 - ���������� ������\n";
		cin >> choice;

		switch (choice) {
		case(1): {

		}
		case(2): {

		}
		case(3): {

		}
		case(0): {

		}
		}
	} while (choice != 0);
}