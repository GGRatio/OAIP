#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fromFILE1("FILE1.txt");
    ofstream toFILE2("FILE2.txt");

    string buff, sBuff = "0";

    while (getline(fromFILE1, buff)) {
        bool isSingleWord = true;
        for (char check : buff) {
            if (check == ' ') {
                isSingleWord = false;
                break;
            }
        }
        if (isSingleWord) {
            toFILE2 << buff << "\n";
        }
        sBuff = buff;
    }

    fromFILE1.close();
    toFILE2.close();

    ifstream fromFILE2("FILE2.txt");

    bool foundFiveLetterWord = false;
    while (getline(fromFILE2, buff)) {
        if (buff.length() == 5) {
            cout << "Слово в файле 2 из 5 букв: " << buff << endl;
            foundFiveLetterWord = true;
            break;
        }
    }
    if (!foundFiveLetterWord) {
        cout << "Во втором файле нет слова из 5 букв" << endl;
    }

    fromFILE2.close();

    return 0;
}
