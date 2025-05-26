#include "Hash.h"
#include <iostream>
using namespace std;

struct AAA {
    int key;
    char* mas;
    AAA(int k, char* z) {
        key = k;  mas = z;
    }
    AAA() {}
};

int key(void* d) {
    AAA* f = (AAA*)d;
    return f->key;
}

void AAA_print(void* d) {
    cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    int siz = 10, choice, k;
    cout << "Введите размер хеш-таблицы: ";
    cin >> siz;
    Object H = create(siz, key);

    for (;;) {
        cout << "\n1 - вывод хеш-таблицы\n"
            << "2 - добавление элемента\n"
            << "3 - удаление элемента\n"
            << "4 - поиск элемента\n"
            << "5 - выбор хеш-функции\n"
            << "0 - выход\n"
            << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 0: exit(0);
        case 1: H.scan(AAA_print); break;
        case 2: {
            AAA* a = new AAA;
            char* str = new char[20];
            cout << "Введите ключ: ";
            cin >> k;
            a->key = k;
            cout << "Введите строку: ";
            cin >> str;
            a->mas = str;
            if (H.N == H.size)
                cout << "Таблица заполнена!" << endl;
            else
                H.insert(a);
            break;
        }
        case 3: {
            cout << "Введите ключ для удаления: ";
            cin >> k;
            H.deleteByKey(k);
            break;
        }
        case 4: {
            cout << "Введите ключ для поиска: ";
            cin >> k;
            if (H.search(k) == NULL)
                cout << "Элемент не найден!" << endl;
            else
                AAA_print(H.search(k));
            break;
        }
        case 5: {
            cout << "Выберите хеш-функцию:\n"
                << "1 - Стандартная\n"
                << "2 - Мультипликативная\n"
                << "3 - Универсальная\n";
            int hashChoice;
            cin >> hashChoice;
            setHashFunction(hashChoice, H);  // Передаем H как параметр
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
        }
    }
    return 0;
}