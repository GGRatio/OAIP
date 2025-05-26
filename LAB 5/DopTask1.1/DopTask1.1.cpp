#include <iostream>
#include <windows.h>

#define nbook 3

using namespace std;

void add();
void out();
void del();
void serch();

struct Slibriary {
    char author[30];
    char name[30];
    char publishing[30];
    char chapter[30];
    enum Eorigin {
        purchase = 1, theft, gift, other
    } origin;
    struct Syear {
        unsigned year : 32;
    } byte;
    bool availability;
} libriary[nbook];

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
    for (int i = 0; i < nbook; i++) {
        cout << "\n-------\n";
        cout << "Книга №" << i + 1 << endl;
        cout << "Введите автора книги: ";
        cin >> libriary[i].author;
        cout << "Введите название книги: ";
        cin >> libriary[i].name;
        cout << "Введите редакцию: ";
        cin >> libriary[i].publishing;
        cout << "Введите раздел: ";
        cin >> libriary[i].chapter;

        int from = 0;
        do {
            cout << "\nВыберите происхождение...\n" <<
                "1 - покупка\n" <<
                "2 - кража\n" <<
                "3 - подарок\n" <<
                "4 - иной вариант\n";
            cin >> from;
            switch (from) {
            case(1): {
                libriary[i].origin = Slibriary::purchase;
                from = 5;
                break;
            }
            case(2): {
                libriary[i].origin = Slibriary::theft;
                from = 5;
                break;
            }
            case(3): {
                libriary[i].origin = Slibriary::gift;
                from = 5;
                break;
            }
            case(4): {
                libriary[i].origin = Slibriary::other;
                from = 5;
                break;
            }
            default: {
                cout << "\nНекоректный ввод..\n";
                break;
            }
            }
        } while (from != 5);

        unsigned int iyear;
        cout << "Введите год: ";
        cin >> iyear;
        libriary[i].byte.year = iyear;

        cout << "1 - книга доступна\n" <<
            "0 - книга не доступна\n";
        cin >> libriary[i].availability;
    }
}

void out() {
    for (int i = 0; i < nbook; i++) {
        cout << "\n-------\n";
        cout << "Книга №" << i + 1 << endl;
        cout << "автор: " << libriary[i].author << endl;
        cout << "название: " << libriary[i].name << endl;
        cout << "редакция: " << libriary[i].publishing << endl;
        cout << "раздел: " << libriary[i].chapter << endl;
        switch (libriary[i].origin) {
        case(1): {
            cout << "покупка\n";
            break;
        }
        case(2): {
            cout << "кража\n";
            break;
        }
        case(3): {
            cout << "подарок\n";
            break;
        }
        case(4): {
            cout << "иной вариант\n";
            break;
        }
        default: {
            cout << "\nошибка в перечислении..\n";
            break;
        }
        }
        cout << "год: " << libriary[i].byte.year << endl;
        if (libriary[i].availability) {
            cout << "книга доступна\n";
        }
        else {
            cout << "книга не доступна\n";
        }
    }
}

void del() {
    cout << "\n------------\n";
    int size = nbook;
    if (size == 0) {
        cout << "\nБиблиотека и так пуста...\n";
    }
    else {
        int n;
        cout << "\nВведите номер книги, которую желаете удалить (от 1 до " << nbook << "): ";
        cin >> n;

        if (n < 1 || n > nbook) {
            cout << "Неверный номер книги.\n";
            return;
        }

        // Сдвигаем элементы массива влево
        for (int i = n - 1; i < nbook - 1; i++) {
            libriary[i] = libriary[i + 1];
        }

        // Очищаем последний элемент
        libriary[nbook - 1] = Slibriary(); // Обнуляем последний элемент

        cout << "Книга №" << n << " удалена.\n";
    }
}

void serch() {
    unsigned int searchYear;
    cout << "Введите год для поиска: ";
    cin >> searchYear;

    bool found = false; // Флаг для проверки, найдена ли хотя бы одна книга

    for (int i = 0; i < nbook; i++) {
        if (libriary[i].byte.year == searchYear) {
            cout << "\n-------\n";
            cout << "Книга №" << i + 1 << endl;
            cout << "автор: " << libriary[i].author << endl;
            cout << "название: " << libriary[i].name << endl;
            cout << "редакция: " << libriary[i].publishing << endl;
            cout << "раздел: " << libriary[i].chapter << endl;
            switch (libriary[i].origin) {
            case(1): {
                cout << "покупка\n";
                break;
            }
            case(2): {
                cout << "кража\n";
                break;
            }
            case(3): {
                cout << "подарок\n";
                break;
            }
            case(4): {
                cout << "иной вариант\n";
                break;
            }
            default: {
                cout << "\nошибка в перечислении..\n";
                break;
            }
            }
            cout << "год: " << libriary[i].byte.year << endl;
            if (libriary[i].availability) {
                cout << "книга доступна\n";
            }
            else {
                cout << "книга не доступна\n";
            }
            found = true; // Книга найдена
        }
    }

    if (!found) {
        cout << "Книги с годом " << searchYear << " не найдены.\n";
    }
}