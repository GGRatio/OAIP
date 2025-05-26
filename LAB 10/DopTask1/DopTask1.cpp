#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const int MAX_DIGITS = 10;

void generateNumbers(int A, int current[], int position, ofstream& outFile) {
    if (position == A) {
        for (int i = 0; i < A; i++) {
            outFile << current[i];
        }
        outFile << endl;
        return;
    }

    for (int digit = 0; digit <= A; digit++) {
        current[position] = digit;
        generateNumbers(A, current, position + 1, outFile);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int A;
    cout << "Введите цифру A (1-9): ";
    cin >> A;

    if (A < 1 || A > 9) {
        cout << "Ошибка: A должно быть от 1 до 9" << endl;
        return 1;
    }

    ofstream outFile("numbers.txt");
    if (!outFile) {
        cout << "Ошибка при создании файла" << endl;
        return 1;
    }

    int currentDigits[MAX_DIGITS]; // Дополнительный массив для хранения текущей комбинации цифр
    generateNumbers(A, currentDigits, 0, outFile);

    outFile.close();
    cout << "Числа успешно записаны в файл numbers.txt" << endl;

    return 0;
}