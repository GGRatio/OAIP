﻿#include <fstream>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	char buff[50];// буфер для хранения считываемого из файла текста
	ofstream fout("t.txt");//создание обьекта fout класса ofstream для записи
	fout << "Работа с файлами в C++";// запись строки в файл
	fout.close();
	ifstream fin("t.txt");//создание обьекта fin класса ifstream для чтения
	if (!fin.is_open()) {
		cout << "файл не может быть открыт!\n";
	}
	else {
		fin >> buff; //считывание первого слова из файла
		cout << buff << endl;//печать слова
		fin.getline(buff, 50);//считывание строки из файла
		fin.close();
		cout << buff << endl; //печать строки
	}
}

