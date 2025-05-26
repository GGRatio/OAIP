#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N1, N2, i = 0;
    ifstream fromFILE1("FILE1.txt");
    ofstream toFILE2("FILE2.txt");

    string buff;

    cout << "N1:";
    cin >> N1;
    cout << "N2:";
    cin >> N2;

    for (; i < N1; i++) {
        getline(fromFILE1, buff);
    }

    while ((i <= N2-1) && getline(fromFILE1, buff)) {
        if (buff[0] == 'C') {
            toFILE2 << buff << endl; 
        }
        i++; 
    }

    fromFILE1.close();
    toFILE2.close();
    ifstream fromFILE2("FILE2.txt");
    if (getline(fromFILE2, buff)) {
        int wordCount = 0;
        int length = buff.length();
        bool inWord = false;

        for (int i = 0; i < length; ++i) {
            if (buff[i] != ' ' && !inWord) {
                inWord = true;
                wordCount++;
            }
            else if (buff[i] == ' ') {
                inWord = false;
            }
        }
        cout << "Количество слов в первой строке файла FILE2: " << wordCount << endl;
    }
    fromFILE2.close();

}
