#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int toFile1(string userInput, ofstream& file1) {
    file1 << userInput;
    return 1;
}
int toFile2(string userInput, ofstream& file2) {
    for (char check : userInput) {
        if (check != '0' and check != '1' and check != '2' and check != '3' and check != '4' and check != '5' and check != '6' and check != '7' and check != '8' and check != '9') {
            file2 << check;
        }
    }
    return 1;
}
int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string userInput;
    int wordCount = 1;

    ofstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    cout << "Введите строку разделяю слова и цифры пробелами пробелами\n";
    getline(cin, userInput);

    toFile1(userInput, file1);
    toFile2(userInput, file2);
}