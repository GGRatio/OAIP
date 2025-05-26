#include "MyIntQueue.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    int capacity;
    std::cout << "Введите размер очереди: ";
    std::cin >> capacity;
    capacity++;

    Queue q = createQueue(capacity);
    QueueCh qCh = createQueueCh(4);
    QueueFl qFl = createQueueFl(capacity);

    int choice;
    int value;
    char symb;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: // Добавление элемента
            std::cout << "Введите число: ";
            std::cin >> value;
            enQueue(q, value);
            break;

        case 2: // Удаление элемента
            value = deQueue(q);
            if (value != QUEUE_EMPTY_VALUE) {
                std::cout << "Удален элемент: " << value << "\n";
            }
            break;

        case 3: // Просмотр первого элемента
            value = peekQueue(q);
            if (value != QUEUE_EMPTY_VALUE) {
                std::cout << "Первый элемент: " << value << "\n";
            }
            break;

        case 4: // Размер очереди
            std::cout << "Текущий размер очереди: " << getQueueSize(q) << "\n";
            break;

        case 5: // Максимальный элемент
            value = findMaxInQueue(q);
            if (value != QUEUE_EMPTY_VALUE) {
                std::cout << "Максимальный элемент: " << value << "\n";
            }
            break;

        case 6: // Вывод очереди
            printQueue(q);
            break;

        case 7: // Удаление трех элементов
            for (int i = 0; i < 3; i++) {
                value = deQueue(q);
                if (value == QUEUE_EMPTY_VALUE) {
                    std::cout << "Очередь пуста, нельзя удалить 3 элемента\n";
                    break;
                }
                std::cout << "Удален элемент: " << value << "\n";
            }
            std::cout << "Текущий размер очереди: " << getQueueSize(q) << "\n";
            break;
        case 8: //Вариант 5
            std::cout << "Введите символ\n";
            std::cin >> symb;
            enQueueCh(qCh, symb);
            break;
        case 9: {
                enQueueFl(qFl);
            break;
        }
        case 0: // Выход
            std::cout << "Завершение программы...\n";
            break;

        default:
            std::cout << "Неверный выбор!\n";
        }

    } while (choice != 0);

    releaseQueue(q);
    return 0;
}