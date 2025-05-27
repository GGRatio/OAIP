#include "Hash_Chain.h"
#include <iostream>
#include <cstring> // Для strcpy_s
using namespace std;

struct AAA {
    int key;
    char* mas;

    AAA(int k, char* z) {
        key = k;
        mas = new char[strlen(z) + 1];
        strcpy_s(mas, strlen(z) + 1, z); // Безопасная версия strcpy
    }

    AAA() : key(0), mas(nullptr) {}

    ~AAA() { // Добавляем деструктор для очистки памяти
        if (mas) delete[] mas;
    }
};

int hf(void* d) {
    AAA* f = (AAA*)d;
    const int prime = 31;
    return (f->key * prime);
}

void AAA_print(listx::Element* e) {
    if (e && e->data) {
        AAA* a = (AAA*)e->data;
        cout << a->key << " - " << a->mas << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int current_size;
    cout << "Введите размер хеш-таблицы: ";
    cin >> current_size;
    hashTC::Object H = hashTC::create(current_size, hf);

    int choice, k;
    char str[100];

    while (true) {
        cout << "\n1 - Вывод таблицы\n2 - Добавить школу\n3 - Удалить школу\n4 - Найти школу\n0 - Выход\nВыберите: ";
        cin >> choice;

        switch (choice) {
        case 0: return 0;

        case 1:
            H.Scan();
            break;

        case 2: {
            cout << "Номер школы: ";
            cin >> k;
            cout << "Фамилия директора: ";
            cin.ignore();
            cin.getline(str, 100);

            AAA* a = new AAA(k, str); // Используем конструктор
            H.insert(a);
            break;
        }

        case 3: {
            AAA b;
            cout << "Номер школы для удаления: ";
            cin >> b.key;
            if (H.deleteByData(&b))
                cout << "Удалено успешно\n";
            else
                cout << "Школа не найдена\n";
            break;
        }

        case 4: {
            AAA c;
            cout << "Номер школы для поиска: ";
            cin >> c.key;
            auto res = H.search(&c);
            if (res) {
                cout << "Найдено: ";
                AAA_print(res);
            }
            else {
                cout << "Не найдено\n";
            }
            break;
        }

        default:
            cout << "Неверный выбор!\n";
        }
    }
}