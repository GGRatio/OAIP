#include "List.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Функция для вывода информации о клиенте
void printClient(void* data) {
    BankClient* client = (BankClient*)data;
    cout << left << setw(25) << client->fullName
        << setw(15) << client->accountType
        << setw(15) << client->accountNumber
        << setw(15) << client->balance
        << setw(15) << client->lastUpdateDate << endl;
}

// Функция для поиска по номеру счета
Element* searchByAccountNumber(Object& list, int accountNumber) {
    Element* e = list.GetFirst();
    while (e != NULL) {
        BankClient* client = (BankClient*)e->Data;
        if (client->accountNumber == accountNumber) {
            return e;
        }
        e = e->GetNext();
    }
    return NULL;
}

// Функция для ввода данных клиента
BankClient* inputClient() {
    BankClient* client = new BankClient;
    cout << "Введите Ф.И.О.: ";
    getline(cin, client->fullName);

    cout << "Тип счета (срочный/льготный/обычный): ";
    getline(cin, client->accountType);

    cout << "Номер счета: ";
    cin >> client->accountNumber;

    cout << "Сумма на счете: ";
    cin >> client->balance;

    cout << "Дата последнего изменения (ДД.ММ.ГГГГ): ";
    cin.ignore();
    getline(cin, client->lastUpdateDate);

    return client;
}

void displayMenu() {
    cout << "\nМеню управления клиентами банка:\n";
    cout << "1. Добавить клиента\n";
    cout << "2. Показать всех клиентов\n";
    cout << "3. Найти клиента по номеру счета\n";
    cout << "4. Удалить клиента\n";
    cout << "5. Подсчитать количество клиентов\n";
    cout << "6. Очистить список клиентов\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Object clientList = Create();
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            BankClient* newClient = inputClient();
            clientList.Insert(newClient);
            cout << "Клиент добавлен!\n";
            break;
        }
        case 2: {
            cout << "\nСписок клиентов:\n";
            cout << left << setw(25) << "Ф.И.О."
                << setw(15) << "Тип счета"
                << setw(15) << "Номер счета"
                << setw(15) << "Баланс"
                << setw(15) << "Дата изменения" << endl;
            clientList.PrintList(printClient);
            break;
        }
        case 3: {
            int accountNumber;
            cout << "Введите номер счета для поиска: ";
            cin >> accountNumber;

            Element* found = searchByAccountNumber(clientList, accountNumber);
            if (found != NULL) {
                cout << "\nНайден клиент:\n";
                cout << left << setw(25) << "Ф.И.О."
                    << setw(15) << "Тип счета"
                    << setw(15) << "Номер счета"
                    << setw(15) << "Баланс"
                    << setw(15) << "Дата изменения" << endl;
                printClient(found->Data);
            }
            else {
                cout << "Клиент с таким номером счета не найден.\n";
            }
            break;
        }
        case 4: {
            int accountNumber;
            cout << "Введите номер счета для удаления: ";
            cin >> accountNumber;

            Element* toDelete = searchByAccountNumber(clientList, accountNumber);
            if (toDelete != NULL) {
                clientList.Delete(toDelete);
                cout << "Клиент удален.\n";
            }
            else {
                cout << "Клиент с таким номером счета не найден.\n";
            }
            break;
        }
        case 5: {
            int count = clientList.CountList();
            cout << "Количество клиентов в списке: " << count << endl;
            break;
        }
        case 6: {
            clientList.DeleteList();
            cout << "Список клиентов очищен.\n";
            break;
        }
        case 0: {
            cout << "Выход из программы.\n";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
        }
    } while (choice != 0);

    // Очистка памяти перед выходом
    clientList.DeleteList();
    return 0;
}