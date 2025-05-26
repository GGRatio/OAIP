#include <iostream>
#include <Windows.h>
#include "connect.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice, x;
    Stack* Stk = new Stack;
    Stack* Stk1 = new Stack; // Для вариантов 5 и 9
    Stack* Stk2 = new Stack; // Для вариантов 5 и 9
    Stack* Result = new Stack; // Для результатов
    Stk = NULL;
    Stk1 = NULL;
    Stk2 = NULL;
    Result = NULL;

    do {
        cout << "Варианты использования:\n"
            << "1 - добавление элемента в стек\n"
            << "2 - Извлечение элемента из стека\n"
            << "3 - запись в файл\n"
            << "4 - чтение из файла\n"
            << "5 - Вывод и отчистка стека\n"
            << "6 - удаление первого положительного элемента\n"
            << "7 - завершение работы\n"
            << "8 - (Доп.вар 5)\n"
            << "9 - Удаление первого элемента значение которого превышает (Доп.вар 7)\n"
            << "10 - (Доп.вар 9)\n"
            << "11 - Добавить элемент в Stack1 (для вариантов 5 и 9)\n"
            << "12 - Добавить элемент в Stack2 (для вариантов 5 и 9)\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Введите элемент: " << endl;
            cin >> x;
            push(x, Stk);
            break;
        }
        case 2: {
            x = pop(Stk);
            if (x != -1) {
                cout << "Извлечённый элемент: " << x << endl;
            }
            break;
        }
        case 3: {
            toFile(Stk);
            break;
        }
        case 4: {
            fromFile(Stk);
            break;
        }
        case 5: {
            cout << "Стек: " << endl;
            show(Stk);
            break;
        }
        case 6: {
            delFirstPos(Stk);
            break;
        }
        case 7: {
            cout << "Завершение работы...";
            break;
        }
        case 8: { // Вариант 5
            if (!Stk1) {
                cout << "Stack1 пуст!\n";
                break;
            }
            var5(Stk1, Stk2, Result);
            cout << "Результат (элементы из Stack1, но не в Stack2):\n";
            show(Result);
            // Очищаем результат для следующего использования
            while (Result) pop(Result);
            break;
        }
        case 9: {
            delFirstOver(Stk);
            break;
        }
        case 10: { // Вариант 9
            if (!Stk1 && !Stk2) {
                cout << "Оба стека пусты!\n";
                break;
            }
            var9(Stk1, Stk2, Result);
            cout << "Результат (элементы из одного стека, но не из другого):\n";
            show(Result);
            // Очищаем результат для следующего использования
            while (Result) pop(Result);
            break;
        }
        case 11: { // Добавление в Stack1
            cout << "Введите элемент для Stack1: " << endl;
            cin >> x;
            push(x, Stk1);
            break;
        }
        case 12: { // Добавление в Stack2
            cout << "Введите элемент для Stack2: " << endl;
            cin >> x;
            push(x, Stk2);
            break;
        }
        default: {
            cout << "некорректный ввод, попробуйте ещё раз...\n";
            break;
        }
        }
    } while (choice != 7);

    // Освобождение памяти
    while (Stk) pop(Stk);
    while (Stk1) pop(Stk1);
    while (Stk2) pop(Stk2);
    while (Result) pop(Result);

    return 0;
}