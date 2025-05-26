#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

#define size 30
#define nTrain 3

struct TRAIN {
    char destination[size]; // Название пункта назначения
    int trainNumber; // Номер поезда
    char departureTime[size]; // Время отправления
};

TRAIN trains[nTrain];

void enter_new();
void sort_trains();
void find_trains();
int compare_strings(const char* str1, const char* str2);

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;

    do {
        cout << "Варианты использования: \n";
        cout << "1 - Ввод данных\n";
        cout << "2 - Сортировка и вывод данных\n";
        cout << "3 - Поиск поездов\n";
        cout << "4 - Завершение работы\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            enter_new();
            break;
        }
        case 2: {
            sort_trains();
            break;
        }
        case 3: {
            find_trains();
            break;
        }
        case 4: {
            cout << "\nЗавершение работы...\n";
            break;
        }
        default: {
            cout << "\nНекорректный ввод, попробуйте ещё раз \n";
            break;
        }
        }
    } while (choice != 4);
}

void enter_new() {
    for (int i = 0; i < nTrain; i++) {
        cout << "\nПоезд №" << i + 1 << endl;
        cout << "Пункт назначения - ";
        cin >> trains[i].destination;
        cout << "Номер поезда - ";
        cin >> trains[i].trainNumber;
        cout << "Время отправления (формат HH:MM) - ";
        cin >> trains[i].departureTime;
        cout << "\n-----\n";
    }
    cout << "Ввод данных завершен...\n\n";
}

void sort_trains() {
    // Сортировка пузырьком по алфавиту (по названию пункта назначения)
    for (int i = 0; i < nTrain - 1; i++) {
        for (int j = 0; j < nTrain - i - 1; j++) {
            if (compare_strings(trains[j].destination, trains[j + 1].destination) > 0) {
                // Обмен местами
                TRAIN temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }

    cout << "\nДанные о поездах (отсортированы по пункту назначения):\n";
    for (int i = 0; i < nTrain; i++) {
        cout << "\nПоезд №" << i + 1 << endl;
        cout << "Пункт назначения - " << trains[i].destination << endl;
        cout << "Номер поезда - " << trains[i].trainNumber << endl;
        cout << "Время отправления - " << trains[i].departureTime << endl;
        cout << "\n-----\n";
    }
}

void find_trains() {
    char time[size];
    cout << "Введите время отправления (формат HH:MM) - ";
    cin >> time;

    bool found = false;
    cout << "\nПоезда, отправляющиеся после " << time << ":\n";
    for (int i = 0; i < nTrain; i++) {
        if (compare_strings(trains[i].departureTime, time) > 0) {
            cout << "\nПоезд №" << i + 1 << endl;
            cout << "Пункт назначения - " << trains[i].destination << endl;
            cout << "Номер поезда - " << trains[i].trainNumber << endl;
            cout << "Время отправления - " << trains[i].departureTime << endl;
            cout << "\n-----\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Поездов, отправляющихся после " << time << ", не найдено.\n";
    }
}

// Функция для сравнения строк
int compare_strings(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}