#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#define nBooks 3

// Структура для книги
struct sBook {
    char author[30];
    char title[30];
    char publisher[30];
    char section[30]; // Раздел библиотеки

    // Объединение для происхождения книги
    union uOrigin {
        struct sPurchase {
            char purchaseDate[30]; // Дата покупки
            double price;         // Цена
        } purchase;

        struct sGift {
            char giverName[30];   // Имя дарителя
            char giftDate[30];    // Дата получения подарка
        } gift;

        struct sTheft {
            char location[30];    // Место кражи
            char theftDate[30];  // Дата кражи
        } theft;

        char otherInfo[30];       // Другая информация
    } origin;

    bool isAvailable; // Наличие книги
} books[nBooks];

void input();
void out();
void searchByAuthor();
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
            "3 - Поиск по автору\n" <<
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
            searchByAuthor();
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
    for (int i = 0; i < nBooks; i++) {
        cout << "\n-----------------------";
        cout << "\nКнига №" << (i + 1);
        cout << "\nАвтор: ";
        cin >> books[i].author;
        cout << "Название: ";
        cin >> books[i].title;
        cout << "Издательство: ";
        cin >> books[i].publisher;
        cout << "Раздел библиотеки: ";
        cin >> books[i].section;

        // Ввод происхождения книги
        int originChoice;
        cout << "\nПроисхождение книги:\n"
            << "1 - Покупка\n"
            << "2 - Подарок\n"
            << "3 - Кража\n"
            << "4 - Другое\n"
            << "Выберите происхождение: ";
        cin >> originChoice;

        switch (originChoice) {
        case 1: {
            cout << "Дата покупки: ";
            cin >> books[i].origin.purchase.purchaseDate;
            cout << "Цена: ";
            cin >> books[i].origin.purchase.price;
            break;
        }
        case 2: {
            cout << "Имя дарителя: ";
            cin >> books[i].origin.gift.giverName;
            cout << "Дата получения подарка: ";
            cin >> books[i].origin.gift.giftDate;
            break;
        }
        case 3: {
            cout << "Место кражи: ";
            cin >> books[i].origin.theft.location;
            cout << "Дата кражи: ";
            cin >> books[i].origin.theft.theftDate;
            break;
        }
        case 4: {
            cout << "Другая информация: ";
            cin >> books[i].origin.otherInfo;
            break;
        }
        default: {
            cout << "Неверный выбор. Используется 'Другое'.";
            cin >> books[i].origin.otherInfo;
            break;
        }
        }

        cout << "Наличие книги (1 - есть, 0 - нет): ";
        cin >> books[i].isAvailable;
    }
}

void out() {
    for (int i = 0; i < nBooks; i++) {
        cout << "\n-----------------------";
        cout << "\nКнига №" << (i + 1);
        cout << "\nАвтор: " << books[i].author;
        cout << "\nНазвание: " << books[i].title;
        cout << "\nИздательство: " << books[i].publisher;
        cout << "\nРаздел библиотеки: " << books[i].section;

        // Вывод информации о происхождении книги
        if (books[i].origin.purchase.price > 0) {
            cout << "\nПроисхождение: Покупка";
            cout << "\nДата покупки: " << books[i].origin.purchase.purchaseDate;
            cout << "\nЦена: " << books[i].origin.purchase.price;
        }
        else if (strlen(books[i].origin.gift.giverName) > 0) {
            cout << "\nПроисхождение: Подарок";
            cout << "\nИмя дарителя: " << books[i].origin.gift.giverName;
            cout << "\nДата получения подарка: " << books[i].origin.gift.giftDate;
        }
        else if (strlen(books[i].origin.theft.location) > 0) {
            cout << "\nПроисхождение: Кража";
            cout << "\nМесто кражи: " << books[i].origin.theft.location;
            cout << "\nДата кражи: " << books[i].origin.theft.theftDate;
        }
        else {
            cout << "\nПроисхождение: Другое";
            cout << "\nИнформация: " << books[i].origin.otherInfo;
        }

        cout << "\nНаличие: " << (books[i].isAvailable ? "Есть" : "Нет");
    }
    cout << "\n-----------------------";
}

void searchByAuthor() {
    char searchAuthor[30];
    cout << "\nВведите автора для поиска: ";
    cin >> searchAuthor;

    for (int i = 0; i < nBooks; i++) {
        if (strcmp(books[i].author, searchAuthor) == 0) {
            cout << "\nКнига найдена...";
            cout << "\nАвтор: " << books[i].author;
            cout << "\nНазвание: " << books[i].title;
            cout << "\nИздательство: " << books[i].publisher;
            cout << "\nРаздел библиотеки: " << books[i].section;

            // Вывод информации о происхождении книги
            if (books[i].origin.purchase.price > 0) {
                cout << "\nПроисхождение: Покупка";
                cout << "\nДата покупки: " << books[i].origin.purchase.purchaseDate;
                cout << "\nЦена: " << books[i].origin.purchase.price;
            }
            else if (strlen(books[i].origin.gift.giverName) > 0) {
                cout << "\nПроисхождение: Подарок";
                cout << "\nИмя дарителя: " << books[i].origin.gift.giverName;
                cout << "\nДата получения подарка: " << books[i].origin.gift.giftDate;
            }
            else if (strlen(books[i].origin.theft.location) > 0) {
                cout << "\nПроисхождение: Кража";
                cout << "\nМесто кражи: " << books[i].origin.theft.location;
                cout << "\nДата кражи: " << books[i].origin.theft.theftDate;
            }
            else {
                cout << "\nПроисхождение: Другое";
                cout << "\nИнформация: " << books[i].origin.otherInfo;
            }

            cout << "\nНаличие: " << (books[i].isAvailable ? "Есть" : "Нет");
            return;
        }
    }
    cout << "\nКнига не найдена.";
}

void toFile() {
    ofstream file("books.txt");
    for (int i = 0; i < nBooks; i++) {
        file << books[i].author << " " << books[i].title << " " << books[i].publisher << " "
            << books[i].section << " ";

        // Запись информации о происхождении книги
        if (books[i].origin.purchase.price > 0) {
            file << "Покупка " << books[i].origin.purchase.purchaseDate << " " << books[i].origin.purchase.price << " ";
        }
        else if (strlen(books[i].origin.gift.giverName) > 0) {
            file << "Подарок " << books[i].origin.gift.giverName << " " << books[i].origin.gift.giftDate << " ";
        }
        else if (strlen(books[i].origin.theft.location) > 0) {
            file << "Кража " << books[i].origin.theft.location << " " << books[i].origin.theft.theftDate << " ";
        }
        else {
            file << "Другое " << books[i].origin.otherInfo << " ";
        }

        file << books[i].isAvailable << "\n";
    }
    file.close();
    cout << "\nДанные записаны в файл.";
}

void fromFile() {
    ifstream file("books.txt");
    if (!file) {
        cout << "\nФайл не найден.";
        return;
    }

    for (int i = 0; i < nBooks; i++) {
        file >> books[i].author >> books[i].title >> books[i].publisher >> books[i].section;

        string originType;
        file >> originType;

        if (originType == "Покупка") {
            file >> books[i].origin.purchase.purchaseDate >> books[i].origin.purchase.price;
        }
        else if (originType == "Подарок") {
            file >> books[i].origin.gift.giverName >> books[i].origin.gift.giftDate;
        }
        else if (originType == "Кража") {
            file >> books[i].origin.theft.location >> books[i].origin.theft.theftDate;
        }
        else {
            file >> books[i].origin.otherInfo;
        }

        file >> books[i].isAvailable;
    }
    file.close();
    cout << "\nДанные прочитаны из файла.";
}