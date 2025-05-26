#include <iostream>
#include <windows.h>

#define nproduct 3

using namespace std;

void add();
void out();
void del();
void search();

struct Swarehouse {
    char name[30];
    double price;
    int quantity;
    enum Emarkup {
        markup5 = 5, markup7 = 7, markup11 = 11, markup20 = 20, markup25 = 25, markup30 = 30
    } markup;
} warehouse[nproduct];

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
            "4 - Поиск элементов по цене\n" <<
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
            search();
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
    for (int i = 0; i < nproduct; i++) {
        cout << "\n-------\n";
        cout << "Товар №" << i + 1 << endl;
        cout << "Введите наименование товара: ";
        cin >> warehouse[i].name;
        cout << "Введите цену товара: ";
        cin >> warehouse[i].price;
        cout << "Введите количество товара: ";
        cin >> warehouse[i].quantity;

        int markupChoice;
        do {
            cout << "\nВыберите процент торговой надбавки...\n" <<
                "5 - 5%\n" <<
                "7 - 7%\n" <<
                "11 - 11%\n" <<
                "20 - 20%\n" <<
                "25 - 25%\n" <<
                "30 - 30%\n";
            cin >> markupChoice;
            switch (markupChoice) {
            case 5: {
                warehouse[i].markup = Swarehouse::markup5;
                break;
            }
            case 7: {
                warehouse[i].markup = Swarehouse::markup7;
                break;
            }
            case 11: {
                warehouse[i].markup = Swarehouse::markup11;
                break;
            }
            case 20: {
                warehouse[i].markup = Swarehouse::markup20;
                break;
            }
            case 25: {
                warehouse[i].markup = Swarehouse::markup25;
                break;
            }
            case 30: {
                warehouse[i].markup = Swarehouse::markup30;
                break;
            }
            default: {
                cout << "\nНекоректный ввод..\n";
                break;
            }
            }
        } while (markupChoice != 5 && markupChoice != 7 && markupChoice != 11 && markupChoice != 20 && markupChoice != 25 && markupChoice != 30);
    }
}

void out() {
    for (int i = 0; i < nproduct; i++) {
        cout << "\n-------\n";
        cout << "Товар №" << i + 1 << endl;
        cout << "наименование: " << warehouse[i].name << endl;
        cout << "цена: " << warehouse[i].price << endl;
        cout << "количество: " << warehouse[i].quantity << endl;
        cout << "процент надбавки: " << warehouse[i].markup << "%" << endl;
    }
}

void del() {
    cout << "\n------------\n";
    int size = nproduct;
    if (size == 0) {
        cout << "\nСклад и так пуст...\n";
    }
    else {
        int n;
        cout << "\nВведите номер товара, который желаете удалить (от 1 до " << nproduct << "): ";
        cin >> n;

        if (n < 1 || n > nproduct) {
            cout << "Неверный номер товара.\n";
            return;
        }

        // Сдвигаем элементы массива влево
        for (int i = n - 1; i < nproduct - 1; i++) {
            warehouse[i] = warehouse[i + 1];
        }

        // Очищаем последний элемент
        warehouse[nproduct - 1] = Swarehouse(); // Обнуляем последний элемент

        cout << "Товар №" << n << " удален.\n";
    }
}

void search() {
    double searchPrice;
    cout << "Введите цену для поиска: ";
    cin >> searchPrice;

    bool found = false; // Флаг для проверки, найден ли хотя бы один товар

    for (int i = 0; i < nproduct; i++) {
        if (warehouse[i].price == searchPrice) {
            cout << "\n-------\n";
            cout << "Товар №" << i + 1 << endl;
            cout << "наименование: " << warehouse[i].name << endl;
            cout << "цена: " << warehouse[i].price << endl;
            cout << "количество: " << warehouse[i].quantity << endl;
            cout << "процент надбавки: " << warehouse[i].markup << "%" << endl;
            found = true; // Товар найден
        }
    }

    if (!found) {
        cout << "Товары с ценой " << searchPrice << " не найдены.\n";
    }
}