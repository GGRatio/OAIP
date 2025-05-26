#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#define nClient 3

struct sClient {
    char name[30];
    char secondName[30];
    char middleName[30];
    union uProduct {
        char adress[30];
        struct sItem {
            char itemName[30];
            int cost;
            int summ;
            char dateOfDeliver[30];
            int shelf;
        } item[nClient];
    } product;
} client[nClient];

void input();
void out();
void serch();
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
            "3 - Поиск\n" <<
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
            serch();
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
    for (int i = 0; i < nClient; i++) {
        cout << "\n-----------------------";
        cout << "\nКлиент №" << (i + 1);
        cout << "\nИмя: ";
        cin >> client[i].name;
        cout << "Фамилия: ";
        cin >> client[i].secondName;
        cout << "Отчество: ";
        cin >> client[i].middleName;

        int uChoice;
        cout << "\n1 - недвижемость\n2 - товар" << "\nТип: ";
        cin >> uChoice;
        do {
            switch (uChoice) {
            case(1): {
                cout << "\nАдрес недвижимости: ";
                cin >> client[i].product.adress;
                uChoice = -1;
                break;
            }
            case(2): {
                cout << "\nНазвание товара: ";
                cin >> client[i].product.item[i].itemName;
                cout << "Оценочная стоимость: ";
                cin >> client[i].product.item[i].cost;
                cout << "Сумма, выданная под залог: ";
                cin >> client[i].product.item[i].summ;
                cout << "Дата сдачи: ";
                cin >> client[i].product.item[i].dateOfDeliver;
                cout << "Срок хранения: ";
                cin >> client[i].product.item[i].shelf;
                uChoice = -1;
                break;
            }
            default: {
                cout << "\nПопробуйте снова...";
                break;
            }
            }
        } while (uChoice != -1);

    }
}

void out() {
    for (int i = 0; i < nClient; i++) {
        cout << "\n-----------------------";
        cout << "\nКлиент №" << (i + 1);
        cout << "\nИмя: " << client[i].name;
        cout << "\nФамилия: " << client[i].secondName;
        cout << "\nОтчество: " << client[i].middleName;

        if (strlen(client[i].product.adress) > 0) {
            cout << "\nАдрес недвижимости: " << client[i].product.adress;
        }
        else {
            cout << "\nНазвание товара: " << client[i].product.item[i].itemName;
            cout << "\nОценочная стоимость: " << client[i].product.item[i].cost;
            cout << "\nСумма, выданная под залог: " << client[i].product.item[i].summ;
            cout << "\nДата сдачи: " << client[i].product.item[i].dateOfDeliver;
            cout << "\nСрок хранения: " << client[i].product.item[i].shelf;
        }
    }
    cout << "\n-----------------------";
}

void serch() {
    char searchName[30];
    cout << "\nВведите название товара для поиска: ";
    cin >> searchName;

    for (int i = 0; i < nClient; i++) {
        if (strcmp(client[i].product.item[i].itemName, searchName) == 0) { //strcmp функция сравнения строк
            cout << "\nТовар найден...";
            cout << "\nНазвание товара: " << client[i].product.item[i].itemName;
            cout << "\nОценочная стоимость: " << client[i].product.item[i].cost;
            cout << "\nСумма, выданная под залог: " << client[i].product.item[i].summ;
            cout << "\nДата сдачи: " << client[i].product.item[i].dateOfDeliver;
            cout << "\nСрок хранения: " << client[i].product.item[i].shelf;
            return;
        }
    }
    cout << "\nТовар не найден.";
}

void toFile() {
    ofstream file("clients.txt");
    for (int i = 0; i < nClient; i++) {
        file << client[i].name << " " << client[i].secondName << " " << client[i].middleName << " ";
        if (strlen(client[i].product.adress) > 0) {
            file << client[i].product.adress << "\n";
        }
        else {
            file << client[i].product.item[i].itemName << " " << client[i].product.item[i].cost << " "
                << client[i].product.item[i].summ << " " << client[i].product.item[i].dateOfDeliver << " "
                << client[i].product.item[i].shelf << "\n";
        }
    }
    file.close();
    cout << "\nДанные записаны в файл.";
}

void fromFile() {
    ifstream file("clients.txt");
    if (!file) {
        cout << "\nФайл не найден.";
        return;
    }

    for (int i = 0; i < nClient; i++) {
        file >> client[i].name >> client[i].secondName >> client[i].middleName;
        if (file.peek() == '\n') {
            file >> client[i].product.adress;
        }
        else {
            file >> client[i].product.item[i].itemName >> client[i].product.item[i].cost
                >> client[i].product.item[i].summ >> client[i].product.item[i].dateOfDeliver
                >> client[i].product.item[i].shelf;
        }
    }
    file.close();
    cout << "\nДанные прочитаны из файла.";
}