#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#define nProducts 3

// Структура для товара
struct sProduct {
    char name[30]; // Наименование товара
    double price;  // Цена товара
    int quantity;  // Количество товара

    // Объединение для торговой надбавки
    union uMarkup {
        int markup; // Процент торговой надбавки (5, 10, 15, 20, 25, 30)
    } markup;
} products[nProducts];

void input();
void out();
void searchByName();
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
            "3 - Поиск по наименованию\n" <<
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
            searchByName();
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
    for (int i = 0; i < nProducts; i++) {
        cout << "\n-----------------------";
        cout << "\nТовар №" << (i + 1);
        cout << "\nНаименование товара: ";
        cin >> products[i].name;
        cout << "Цена товара: ";
        cin >> products[i].price;
        cout << "Количество товара: ";
        cin >> products[i].quantity;

        // Ввод процента торговой надбавки
        int markupChoice;
        cout << "Процент торговой надбавки (5, 10, 15, 20, 25, 30): ";
        cin >> markupChoice;

        // Проверка корректности ввода
        while (markupChoice != 5 && markupChoice != 10 && markupChoice != 15 && markupChoice != 20 && markupChoice != 25 && markupChoice != 30) {
            cout << "Некорректный ввод. Введите одно из допустимых значений (5, 10, 15, 20, 25, 30): ";
            cin >> markupChoice;
        }

        products[i].markup.markup = markupChoice;
    }
}

void out() {
    for (int i = 0; i < nProducts; i++) {
        cout << "\n-----------------------";
        cout << "\nТовар №" << (i + 1);
        cout << "\nНаименование товара: " << products[i].name;
        cout << "\nЦена товара: " << products[i].price;
        cout << "\nКоличество товара: " << products[i].quantity;
        cout << "\nПроцент торговой надбавки: " << products[i].markup.markup << "%";
    }
    cout << "\n-----------------------";
}

void searchByName() {
    char searchName[30];
    cout << "\nВведите наименование товара для поиска: ";
    cin >> searchName;

    for (int i = 0; i < nProducts; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            cout << "\nТовар найден...";
            cout << "\nНаименование товара: " << products[i].name;
            cout << "\nЦена товара: " << products[i].price;
            cout << "\nКоличество товара: " << products[i].quantity;
            cout << "\nПроцент торговой надбавки: " << products[i].markup.markup << "%";
            return;
        }
    }
    cout << "\nТовар не найден.";
}

void toFile() {
    ofstream file("products.txt");
    for (int i = 0; i < nProducts; i++) {
        file << products[i].name << " " << products[i].price << " " << products[i].quantity << " "
            << products[i].markup.markup << "\n";
    }
    file.close();
    cout << "\nДанные записаны в файл.";
}

void fromFile() {
    ifstream file("products.txt");
    if (!file) {
        cout << "\nФайл не найден.";
        return;
    }

    for (int i = 0; i < nProducts; i++) {
        file >> products[i].name >> products[i].price >> products[i].quantity >> products[i].markup.markup;
    }
    file.close();
    cout << "\nДанные прочитаны из файла.";
}