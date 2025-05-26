#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#define nStudents 3

// Структура для ученика
struct sStudent {
    char fullName[30]; // Ф.И.О.

    // Объединение для класса (цифра + буква)
    union uClass {
        struct sClassInfo {
            int number; // Цифра класса
            char letter; // Буква класса
        } classInfo;
    } classUnion;

    char subjects[3][30]; // Предметы (максимум 3 предмета)
    int grades[3];        // Оценки по предметам
    double averageGrade;  // Средний балл
} students[nStudents];

void input();
void out();
void searchByLastName();
void toFile();
void fromFile();

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        cout << "\nВарианты использования\n" <<
            "1 - Ввод данных\n" <<
            "2 - Вывод данных\n" <<
            "3 - Поиск по фамилии\n" <<
            "4 - Добавление в файл\n" <<
            "5 - Чтение из файла\n" <<
            "6 - Завершение работы\n";
        cin >> choice;
        switch (choice) {
        case(1): {
            input();
            break;
        }
        case(2): {
            out();
            break;
        }
        case(3): {
            searchByLastName();
            break;
        }
        case(4): {
            toFile();
            break;
        }
        case(5): {
            fromFile();
            break;
        }
        }
    } while (choice != 6);

    return 0;
}

void input() {
    for (int i = 0; i < nStudents; i++) {
        cout << "\n-----------------------";
        cout << "\nУченик №" << (i + 1);
        cout << "\nФ.И.О.: ";
        cin.ignore();
        cin.getline(students[i].fullName, 30);

        // Ввод класса (цифра + буква)
        cout << "Цифра класса: ";
        cin >> students[i].classUnion.classInfo.number;
        cout << "Буква класса: ";
        cin >> students[i].classUnion.classInfo.letter;

        // Ввод предметов и оценок
        for (int j = 0; j < 3; j++) {
            cout << "Предмет " << (j + 1) << ": ";
            cin >> students[i].subjects[j];
            cout << "Оценка по предмету " << students[i].subjects[j] << ": ";
            cin >> students[i].grades[j];
        }

        // Расчет среднего балла
        students[i].averageGrade = 0;
        for (int j = 0; j < 3; j++) {
            students[i].averageGrade += students[i].grades[j];
        }
        students[i].averageGrade /= 3;
    }
}

void out() {
    for (int i = 0; i < nStudents; i++) {
        cout << "\n-----------------------";
        cout << "\nУченик №" << (i + 1);
        cout << "\nФ.И.О.: " << students[i].fullName;
        cout << "\nКласс: " << students[i].classUnion.classInfo.number << students[i].classUnion.classInfo.letter;
        cout << "\nПредметы и оценки:";
        for (int j = 0; j < 3; j++) {
            cout << "\n  " << students[i].subjects[j] << ": " << students[i].grades[j];
        }
        cout << "\nСредний балл: " << students[i].averageGrade;
    }
    cout << "\n-----------------------";
}

void searchByLastName() {
    char searchName[30];
    cout << "\nВведите фамилию для поиска: ";
    cin.ignore();
    cin.getline(searchName, 30);

    for (int i = 0; i < nStudents; i++) {
        if (strstr(students[i].fullName, searchName) != nullptr) {
            cout << "\nУченик найден...";
            cout << "\nФ.И.О.: " << students[i].fullName;
            cout << "\nКласс: " << students[i].classUnion.classInfo.number << students[i].classUnion.classInfo.letter;
            cout << "\nПредметы и оценки:";
            for (int j = 0; j < 3; j++) {
                cout << "\n  " << students[i].subjects[j] << ": " << students[i].grades[j];
            }
            cout << "\nСредний балл: " << students[i].averageGrade;
            return;
        }
    }
    cout << "\nУченик не найден.";
}

void toFile() {
    ofstream file("students.txt");
    for (int i = 0; i < nStudents; i++) {
        file << students[i].fullName << " "
            << students[i].classUnion.classInfo.number << students[i].classUnion.classInfo.letter << " ";
        for (int j = 0; j < 3; j++) {
            file << students[i].subjects[j] << " " << students[i].grades[j] << " ";
        }
        file << students[i].averageGrade << "\n";
    }
    file.close();
    cout << "\nДанные записаны в файл.";
}

void fromFile() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nФайл не найден.";
        return;
    }

    for (int i = 0; i < nStudents; i++) {
        file >> students[i].fullName
            >> students[i].classUnion.classInfo.number >> students[i].classUnion.classInfo.letter;
        for (int j = 0; j < 3; j++) {
            file >> students[i].subjects[j] >> students[i].grades[j];
        }
        file >> students[i].averageGrade;
    }
    file.close();
    cout << "\nДанные прочитаны из файла.";
}