#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

void writeToFile(const string& userInput, ofstream& toFILE) {
    if (toFILE.is_open()) {
        toFILE << userInput;
    }
}

string readFromFile(ifstream& fromFILE) {
    string content, line;
    while (getline(fromFILE, line)) {
        content += line + ' ';
    }
    return content;
}

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream toFILE("FILE.txt");
    ifstream fromFILE("FILE.txt");

    string userInput;
    cout << "Введите строку: ";
    getline(cin, userInput);

    writeToFile(userInput, toFILE);

    string fileContent = readFromFile(fromFILE);

    int minIndex = 0;
    int minLength = INT_MAX;
    int currentLength = 0;
    int currentIndex = 0;
    bool inWord = false;

    for (int i = 0; i <= fileContent.size(); i++) {
        if (i < fileContent.size() and fileContent[i] != ' ' and fileContent[i] != '\n') {
            if (!inWord) {
                inWord = true;
                currentIndex = i;
            }
            ++currentLength;
        }
        else {
            if (inWord) {
                inWord = false;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    minIndex = currentIndex;
                }
                currentLength = 0;
            }
        }
    }

    cout << "Порядковый номер слова минимальной длины: " << minIndex + 1 << endl;
    cout << "Количество символов в этом слове: " << minLength << endl;

    return 0;
}
