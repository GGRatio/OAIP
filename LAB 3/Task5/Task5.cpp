
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string buff;
    int count = 0, k;

    ifstream fin("FILE1.txt");
    ofstream fon("FILE2.txt");

    cout << "Введите начиная с какой строки копировать текст\n";
    cin >> k;

    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";

    for (int i = 1;i <= k;i++) {
        getline(fin, buff);
    }

    for (int i = 0;i < 3;i++) {
        fon << buff;
        getline(fin, buff);
        for (char lt : buff) { //Попорядку присваеваем каждый символ buff --> lt
            if (lt == 65 or lt == 69 or lt == 73 or lt == 79 or lt == 85 or lt == 97 or lt == 101 or lt == 105 or lt == 111 or lt == 117) {
                count++;
            }
        }
    }
    fin.close();
    cout << count;
}