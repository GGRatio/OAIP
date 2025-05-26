#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;
#define size 30
#define nClient 2

void enter_new();
void del();
void out();
void add_to_file();
void from_file();
void out_by_number();

struct Data{
    char name[size];
    char surname[size];
    char patronymic[size];
    char typeIndex[size];
    int indexNumber;
    char money[size];
    char data[size];
};

struct Data list_of_client[nClient];

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice = 0;

    do {
        cout << "Варианты использования: \n";
        cout << "1 - Ввод данных\n";
        cout << "2 - Вывод данных\n";
        cout << "3 - Вывод данных по номеру счёта\n";
        cout << "4 - Удаление данных\n";
        cout << "5 - Запись в файл\n";
        cout << "6 - Чтение из файла\n";
        cout << "7 - Завершение работы\n";
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
            out_by_number();
            break;
        }
        case(4): {
            del();
            break;
        }
        case(5): {
            add_to_file();
            break;
        }
        case(6): {
            from_file();
            break;
        }
        case(7): {
            cout << "\nЗавершение работы...";
            break;
        }
        default: {
            cout << "\nНекорректный ввод, попробуйте ещё раз \n";
            break;
        }
        }
    } while (choice != 7);
}

void enter_new() {
    for (int i = 0; i < nClient; i++) {
        cout << "\nКлиент №" << i + 1 << endl;
        cout << "Фамилия - ";
        cin >> list_of_client[i].surname;
        cout << "Имя - ";
        cin >> list_of_client[i].name;
        cout << "Отчество - ";
        cin >> list_of_client[i].patronymic;
        cout << "Тип счёта - ";
        cin >> list_of_client[i].typeIndex;
        cout << "Номер счёта - ";
        cin >> list_of_client[i].indexNumber;
        cout << "Текущий баланс - ";
        cin >> list_of_client[i].money;
        cout << "Дата изменения - ";
        cin >> list_of_client[i].data;
        cout << "\n-----\n";
    }
    cout << "Список клиентов закончился...\n\n";
}

void del() {
    int id;
    cout << "Введите номер клиента, которого желаете удалить -  ";
    cin >> id;
    id--; // коррекция
    for (int i = id; i < nClient - 1; i++) {
        list_of_client[i] = list_of_client[i + 1];
    }
    // Обнуление последнего элемента массива
    //memset (адрес на начальный блок памяти с которого нужно начать заполнение,
    // символ для заполнения,
    // количество байт)
    memset(&list_of_client[nClient - 1], 0, sizeof(Data));
    cout << "Клиент удален.\n";
}

void change() {
    int id;
    cout << "Введите номер клиента - ";
    cin >> id;
    cout << "\nКлиент №" << id << endl;
    id--; // Коррекция
    cout << "Фамилия - ";
    cin >> list_of_client[id].surname;
    cout << "Имя - ";
    cin >> list_of_client[id].name;
    cout << "Отчество - ";
    cin >> list_of_client[id].patronymic;
    cout << "Тип счёта - ";
    cin >> list_of_client[id].typeIndex;
    cout << "Номер счёта - ";
    cin >> list_of_client[id].indexNumber;
    cout << "Текущий баланс - ";
    cin >> list_of_client[id].money;
    cout << "Дата изменения - ";
    cin >> list_of_client[id].data;
    cout << "\n-----\n";
 }

void out(){
    int c;
    cout << "Введите номер клиента для вывода его данных (для вывода всего списка ввести 0) - ";
    cin >> c;
    if (c != 0) {
        cout << "\nКлиент №" << c << endl;
        cout << "Фамилия - " << list_of_client[c-1].surname << endl;
        cout << "Имя - " << list_of_client[c-1].name << endl;
        cout << "Отчество - " << list_of_client[c-1].patronymic << endl;
        cout << "Тип счёта - " << list_of_client[c-1].typeIndex << endl;
        cout << "Номер счёта - " << list_of_client[c - 1].indexNumber << endl;
        cout << "Текущий баланс - " << list_of_client[c-1].money << endl;
        cout << "Дата изменения - " << list_of_client[c-1].data << endl;
        cout << "\n-----\n";
    }
    else {
        for (int i = 0;i < nClient;i++) {
            cout << "\nКлиент №" << i+1 << endl;
            cout << "Фамилия - " << list_of_client[i].surname << endl;
            cout << "Имя - " << list_of_client[i].name << endl;
            cout << "Отчество - " << list_of_client[i].patronymic << endl;
            cout << "Тип счёта - " << list_of_client[i].typeIndex << endl;
            cout << "Номер счёта - " << list_of_client[i].indexNumber << endl;
            cout << "Текущий баланс - " << list_of_client[i].money << endl;
            cout << "Дата изменения - " << list_of_client[i].data << endl;
            cout << "\n-----\n";
        }
    }
}

void out_by_number() {
    int input,key=0;
    cout << "\nВведите счёт клиента - ";
    cin >> input;
    for (int i = 0;i < nClient;i++) {
        if (list_of_client[i].indexNumber == input) {
            cout << "\nКлиент №" << i+1 << endl;
            cout << "Фамилия - " << list_of_client[i].surname << endl;
            cout << "Имя - " << list_of_client[i].name << endl;
            cout << "Отчество - " << list_of_client[i].patronymic << endl;
            cout << "Тип счёта - " << list_of_client[i].typeIndex << endl;
            cout << "Номер счёта - " << list_of_client[i].indexNumber << endl;
            cout << "Текущий баланс - " << list_of_client[i].money << endl;
            cout << "Дата изменения - " << list_of_client[i].data << endl;
            cout << "\n-----\n";
            key++;
            break;
        }
    }
    if (key == 0) {
        cout << "\nВведён не верный счёт...\n";
    }
}
void add_to_file() {
    ofstream inFile("list.txt");
    for (int i = 0;i < nClient;i++) {
        inFile << list_of_client[i].surname << endl;
        inFile << list_of_client[i].name << endl;
        inFile << list_of_client[i].patronymic << endl;
        inFile << list_of_client[i].typeIndex << endl;
        inFile << list_of_client[i].indexNumber << endl;
        inFile << list_of_client[i].money << endl;
        inFile << list_of_client[i].data << endl;
    }
    cout << "Данные успешно записанны в файл...";
}
void from_file() {
    ifstream fromFile("list.txt");
    for (int i = 0;i < nClient;i++) {
        fromFile >> list_of_client[i].surname;
        fromFile >> list_of_client[i].name;
        fromFile >> list_of_client[i].patronymic;
        fromFile >> list_of_client[i].typeIndex;
        fromFile >> list_of_client[i].indexNumber;
        fromFile >> list_of_client[i].money;
        fromFile >> list_of_client[i].data;
    }
    cout << "\nДанные успешно прочитаны...\n";
}