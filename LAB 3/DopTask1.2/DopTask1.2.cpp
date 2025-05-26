#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string serch(string userInput) {
	string numb = " ";
	for (char check : userInput) {
		if (check >= '0' and check <= '9')
			numb += check;
		if ((numb != " ") and !((check >= '0') and (check <= '9'))) {
			return "подстрока соответсвующая записи целого числа " + numb;
			break;
		}
	}
	if (numb == " ") {
		return "В введённой строке отсутсвтуют цифры.";
	}
}

int to(string userInput, ofstream& toFILE) {
	if (!(toFILE << userInput)) {
		return 0;
	}
	else {
		toFILE << userInput;
		return 1;
	}
	toFILE.close();
}

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream toFile("FILE.txt");

	string userInput;

	cout << "Введите строку состоящую из букв, цифр, запятых, точек, знаков + и -\n";
	cin >> userInput;

	to(userInput, toFile);
	cout << serch(userInput);

}