#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

#define size 30
#define nStudent 2
#define maxExams 10 // Максимальное количество экзаменов

void enter_new();
void del();
void out();
void add_to_file();
void from_file();
void grade();

struct data {
    char name[size];
    char surname[size];
    char patronymic[size];
    int nExams; // Количество экзаменов
    int asses[maxExams]; // Оценки за экзамены
};

struct data students[nStudent];

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0, goodStudents=0;

    do {
        cout << "Варианты использования: \n";
        cout << "1 - Ввод данных\n";
        cout << "2 - Вывод данных\n";
        cout << "3 - Запись в файл\n";
        cout << "4 - Чтение из файла\n";
        cout << "5 - Завершение работы\n";
        cout << "6 - Успеваемость студентов\n";
        cin >> choice;

        switch (choice) {
        case(1): {
            enter_new();
            break;
        }
        case(2): {
            out();
            break;
        }
        case(3): {
            add_to_file();
            break;
        }
        case(4): {
            from_file();
            break;
        }
        case(5): {
            cout << "\nЗавершение работы...";
            break;
        }
        case(6): {
            grade();
            break;
        }
        default: {
            cout << "\nНекорректный ввод, попробуйте ещё раз \n";
            break;
        }
        }
    } while (choice != 5);
}

void enter_new() {
    for (int i = 0; i < nStudent; i++) {
        cout << "\nСтудент №" << i + 1 << endl;
        cout << "Фамилия - ";
        cin >> students[i].surname;
        cout << "Имя - ";
        cin >> students[i].name;
        cout << "Отчество - ";
        cin >> students[i].patronymic;
        cout << "Количество экзаменов - ";
        cin >> students[i].nExams;

        for (int j = 0; j < students[i].nExams; j++) {
            cout << "Оценка за экзамен " << j + 1 << " - ";
            cin >> students[i].asses[j];
        }
        cout << "\n-----\n";
    }
    cout << "Список студентов закончился...\n\n";
}

void out() {
    int c;
    cout << "Введите номер студента для вывода его данных (для вывода всего списка ввести 0) - ";
    cin >> c;
    if (c != 0 && c <= nStudent) {
        cout << "\nСтудент №" << c << endl;
        cout << "Фамилия - " << students[c - 1].surname << endl;
        cout << "Имя - " << students[c - 1].name << endl;
        cout << "Отчество - " << students[c - 1].patronymic << endl;
        cout << "Количество экзаменов - " << students[c - 1].nExams << endl;
        for (int j = 0; j < students[c - 1].nExams; j++) {
            cout << "Оценка за экзамен " << j + 1 << " - " << students[c - 1].asses[j] << endl;
        }
        cout << "\n-----\n";
    }
    else if (c == 0) {
        for (int i = 0; i < nStudent; i++) {
            cout << "\nСтудент №" << i + 1 << endl;
            cout << "Фамилия - " << students[i].surname << endl;
            cout << "Имя - " << students[i].name << endl;
            cout << "Отчество - " << students[i].patronymic << endl;
            cout << "Количество экзаменов - " << students[i].nExams << endl;
            for (int j = 0; j < students[i].nExams; j++) {
                cout << "Оценка за экзамен " << j + 1 << " - " << students[i].asses[j] << endl;
            }
            cout << "\n-----\n";
        }
    }
    else {
        cout << "Некорректный номер студента.\n";
    }
}

void add_to_file() {
    ofstream inFile("list.txt");
    if (inFile.is_open()) {
        for (int i = 0; i < nStudent; i++) {
            inFile << students[i].surname << endl;
            inFile << students[i].name << endl;
            inFile << students[i].patronymic << endl;
            inFile << students[i].nExams << endl;
            for (int j = 0; j < students[i].nExams; j++) {
                inFile << students[i].asses[j] << endl;
            }
        }
        inFile.close();
        cout << "Данные успешно записаны в файл...\n";
    }
    else {
        cout << "Ошибка открытия файла для записи.\n";
    }
}

void from_file() {
    ifstream fromFile("list.txt");
    if (fromFile.is_open()) {
        for (int i = 0; i < nStudent; i++) {
            fromFile >> students[i].surname;
            fromFile >> students[i].name;
            fromFile >> students[i].patronymic;
            fromFile >> students[i].nExams;
            for (int j = 0; j < students[i].nExams; j++) {
                fromFile >> students[i].asses[j];
            }
        }
        fromFile.close();
        cout << "\nДанные успешно прочитаны...\n";
    }
    else {
        cout << "Ошибка открытия файла для чтения.\n";
    }
}

void grade() {
    int goodStudents = 0; // Количество хороших студентов
    for (int i = 0; i < nStudent; i++) {
        bool isGood = true; // Предполагаем, что студент хороший
        for (int j = 0; j < students[i].nExams; j++) {
            if (students[i].asses[j] < 4) { // Если есть оценка меньше 4
                isGood = false; // Студент не хороший
                break; // Прерываем внутренний цикл
            }
        }
        if (isGood) {
            goodStudents++;
        }
    }
    double percentage = (static_cast<double>/*Явное преобразование типа*/(goodStudents) / nStudent) * 100;
    cout << "Количество хороших студентов: " << goodStudents << endl;
    cout << "Общее количество студентов: " << nStudent << endl;
    cout << "Отношение хороших студентов к общему количеству: " << percentage << "%" << endl;
}