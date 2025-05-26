#include <iostream>
#include <windows.h>

using namespace std;

#define size 3

void add();
void out();
void del();
void serch();

struct listOfStudents {
    char lastName[30];
    char name[30];
    char middleName[30];
    struct pole {
        unsigned number : 4;
        unsigned letter : 8;
    } byte;
    enum Esubject {
        Mathematics = 1, Physics, Literature, English, informatics
    } subject;
};

struct listOfStudents st[size];
int currentSize = 0; // Текущее количество учеников в массиве

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        cout << "\nВарианты использования...\n" <<
            "1 - Ввод данных\n" <<
            "2 - Вывод данных\n" <<
            "3 - Удаление элементов\n" <<
            "4 - Поиск элементов\n" <<
            "5 - Завершение работы...\n" <<
            "Выбор: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            add();
            break;
        }
        case 2: {
            out();
            break;
        }
        case 3: {
            del();
            break;
        }
        case 4: {
            serch();
            break;
        }
        case 5: {
            cout << "Завершение работы...\n";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}

void add() {
    if (currentSize >= size) {
        cout << "\nМассив учеников заполнен!\n";
        return;
    }

    cout << "\n------------";
    for (int i = currentSize; i < size; i++) {
        cout << "\nученик №" << i + 1;
        cout << "\nВведите фамилию: ";
        cin >> st[i].lastName;
        cout << "Введите имя: ";
        cin >> st[i].name;
        cout << "Введите отчество: ";
        cin >> st[i].middleName;

        unsigned int numb;
        cout << "Введите номер класса: ";
        cin >> numb;
        st[i].byte.number = numb;

        unsigned char lett;
        cout << "Введите букву класса: ";
        cin >> lett;
        st[i].byte.letter = lett;

        bool key = 0;
        do {
            unsigned int sub;
            cout << "Выберите предмет:\n"
                << "Mathematics -> (1)\nPhysics -> (2)\nLiterature -> (3)\nEnglish -> (4)\ninformatics -> (5)\n";
            cin >> sub;
            switch (sub) {
            case 1: {
                st[i].subject = listOfStudents::Mathematics;
                key = 1;
                break;
            }
            case 2: {
                st[i].subject = listOfStudents::Physics;
                key = 1;
                break;
            }
            case 3: {
                st[i].subject = listOfStudents::Literature;
                key = 1;
                break;
            }
            case 4: {
                st[i].subject = listOfStudents::English;
                key = 1;
                break;
            }
            case 5: {
                st[i].subject = listOfStudents::informatics;
                key = 1;
                break;
            }
            default: {
                cout << "\nТакого предмета у нас нет...\n";
                break;
            }
            }
        } while (!key);
        currentSize++; // Увеличиваем количество учеников
    }
    cout << "\n------------";
}

void out() {
    cout << "\n------------";
    for (int i = 0; i < currentSize; i++) {
        cout << "\nученик №" << i + 1;
        cout << "\nфамилия: " << st[i].lastName;
        cout << "\nимя: " << st[i].name;
        cout << "\nотчество: " << st[i].middleName;
        cout << "\nкласс: " << int(st[i].byte.number) << char(st[i].byte.letter);
        cout << "\nпредмет: ";
        switch (st[i].subject) {
        case 1: {
            cout << "Mathematics\n";
            break;
        }
        case 2: {
            cout << "Physics\n";
            break;
        }
        case 3: {
            cout << "Literature\n";
            break;
        }
        case 4: {
            cout << "English\n";
            break;
        }
        case 5: {
            cout << "informatics\n";
            break;
        }
        default: {
            cout << "\nошибка с перечислением!!!\n";
            break;
        }
        }
    }
    cout << "\n------------";
}

void del() {
    cout << "\n------------";
    if (currentSize == 0) {
        cout << "\nСписок учеников пуст!\n";
        cout << "\n------------";
        return;
    }

    int n;
    cout << "\nВведите номер ученика, которого желаете удалить: ";
    cin >> n;

    if (n < 1 || n > currentSize) {
        cout << "\nНеверный номер ученика!\n";
        cout << "\n------------";
        return;
    }

    for (int i = n - 1; i < currentSize - 1; i++) {
        st[i] = st[i + 1];
    }
    currentSize--; // Уменьшаем количество учеников
    cout << "\nУченик удален.\n";
    cout << "\n------------";
}

void serch() {
    cout << "\n------------";
    if (currentSize == 0) {
        cout << "\nСписок учеников пуст!\n";
        cout << "\n------------";
        return;
    }

    char searchLastName[30];
    cout << "\nВведите фамилию для поиска: ";
    cin >> searchLastName;

    bool found = false;
    for (int i = 0; i < currentSize; i++) {
        if (strcmp(st[i].lastName, searchLastName) == 0) {
            cout << "\nученик №" << i + 1;
            cout << "\nфамилия: " << st[i].lastName;
            cout << "\nимя: " << st[i].name;
            cout << "\nотчество: " << st[i].middleName;
            cout << "\nкласс: " << int(st[i].byte.number) << char(st[i].byte.letter);
            cout << "\nпредмет: ";
            switch (st[i].subject) {
            case 1: {
                cout << "Mathematics\n";
                break;
            }
            case 2: {
                cout << "Physics\n";
                break;
            }
            case 3: {
                cout << "Literature\n";
                break;
            }
            case 4: {
                cout << "English\n";
                break;
            }
            case 5: {
                cout << "informatics\n";
                break;
            }
            default: {
                cout << "\nошибка с перечислением!!!\n";
                break;
            }
            }
            found = true;
        }
    }

    if (!found) {
        cout << "\nУченик с такой фамилией не найден.\n";
    }
    cout << "\n------------";
}