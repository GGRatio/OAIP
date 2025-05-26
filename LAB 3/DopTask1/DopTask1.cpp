#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fromFILE1("FILE1.txt");
	ofstream toFILE2("FILE2.txt");

	string buff,check;

	int nEnd = 0,nSymb=0;

	for (int i = 0;i < 3;i++) {
		getline(fromFILE1,buff);
		nEnd++;
	}
	while (fromFILE1.is_open()) {
		getline(fromFILE1, buff);
		if (check == buff) {
			fromFILE1.close();
			break;
		}
		nEnd++;
		toFILE2 << buff;
		check = buff;
	}
	for (char symb : check) {
		if (symb == ' ') {
			nSymb = 0;
		}
		nSymb++;
	}

	cout << "Количество строк = " << nEnd;
	cout << "\nКоличество символов в последнем слове = " << nSymb;

	return 0;
}