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
		cout << "Варианты использования: \n";
		cout << "1 - Ввод данных\n";
		cout << "2 - Сортировка и вывод данных\n";
		cout << "3 - Поиск поездов\n";
		cout << "0 - Завершение работы\n";
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