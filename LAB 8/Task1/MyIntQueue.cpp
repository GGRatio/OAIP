    #include "MyIntQueue.h"
    #include <iostream>

    Queue::Queue(int size) { //Реализация конструктора структуры ТИП::ИМЯ_КОНСТРУКТОРА
        Size = size;
        Head = Tail = 0;
        Data = new int[Size];
    } //конструктор - это "инструкция по сборке" объекта
    Queue createQueue(int n) { //
        return Queue(n);
    }


    QueueCh::QueueCh(int size) {
        Size = size;
        Head = Tail = 0;
        Data = new char[Size];
    }
    QueueCh createQueueCh(int n) { 
        return QueueCh(n);
    }


    QueueFl::QueueFl(int size) {
        Size = size;
        Head = Tail = 0;
        Data = new float[Size];
    }
    QueueFl createQueueFl(int n) {
        return QueueFl(n);
    }

    bool enQueue(Queue& q, int x) {
        if (q.isFull()) {
            std::cout << "Очередь полна!\n";
            return false;
        }

        q.Data[q.Tail] = x;
        q.Tail = (q.Tail + 1) % q.Size;
        return true;
    }

    bool enQueueCh(QueueCh& qCh, char symb) {
        if (qCh.Tail == 4) {
            for (int i = 0; i <= 2; i++) {
                qCh.Data[i] = qCh.Data[i + 1];
            }
            qCh.Data[qCh.Tail-1] = symb; // Добавляем новый элемент в конец

            std::cout << "Очередь: ";
            for (int i = qCh.Head; i != qCh.Tail; i++) {
                std::cout << qCh.Data[i] << " ";
            }
            std::cout << std::endl;
        }
        else {
            qCh.Data[qCh.Tail] = symb;
            qCh.Tail = qCh.Tail + 1;

            std::cout << "Очередь: ";
            for (int i = qCh.Head; i != qCh.Tail; i++) {
                std::cout << qCh.Data[i] << " ";
            }
            std::cout << std::endl;
        }

        return true;
    }

    bool enQueueFl(QueueFl& qFl) {
        float x, max = INT_MIN;
        std::cout << "Введите " << qFl.Size - 1 << " вещественных чисел:\n";
        for (int i = 0; i < qFl.Size - 1; i++) {
            std::cin >> x;
            qFl.Data[qFl.Tail] = x;
            qFl.Tail++;
            if (x > max) {
                max = x;
            }
        }
        std::cout << "Исходная очередь\n";
        for (int i = qFl.Head; i < qFl.Tail; i++) {
            std::cout << qFl.Data[i] << " ";
        }
        std::cout << std::endl;

        while (qFl.Data[qFl.Head] != max) { //Тут циклический сдвиг
            float buff = qFl.Data[qFl.Head]; 
            for (int i = qFl.Head; i < qFl.Tail - 1; i++) {
                qFl.Data[i] = qFl.Data[i + 1];
            }
            qFl.Data[qFl.Tail - 1] = buff;
        }

        std::cout << "Циклически сдвинутая очередь\n";
        for (int i = qFl.Head; i < qFl.Tail; i++) {
            std::cout << qFl.Data[i] << " ";
        }
        std::cout << std::endl;

        return 1;
    }

    int deQueue(Queue& q) {
        if (q.isEmpty()) {
            std::cout << "Очередь пуста!\n";
            return QUEUE_EMPTY_VALUE;
        }

        int value = q.Data[q.Head];
        q.Head = (q.Head + 1) % q.Size;
        return value;
    }

    int peekQueue(const Queue& q) {
        if (q.isEmpty()) {
            std::cout << "Очередь пуста!\n";
            return QUEUE_EMPTY_VALUE;
        }
        return q.Data[q.Head];
    }

    int getQueueSize(const Queue& q) {
        return (q.Tail - q.Head + q.Size) % q.Size;
    }

    int findMaxInQueue(const Queue& q) {
        if (q.isEmpty()) {
            std::cout << "Очередь пуста!\n";
            return QUEUE_EMPTY_VALUE;
        }

        int maxVal = q.Data[q.Head];
        int current = q.Head;

        while (current != q.Tail) {
            if (q.Data[current] > maxVal) {
                maxVal = q.Data[current];
            }
            current = (current + 1) % q.Size;
        }

        return maxVal;
    }

    void printQueue(const Queue& q) {
        std::cout << "Текущая очередь: ";
        if (q.isEmpty()) {
            std::cout << "пуста";
        }
        else {
            int current = q.Head;
            while (current != q.Tail) {
                std::cout << q.Data[current] << " ";
                current = (current + 1) % q.Size;
            }
        }
        std::cout << "\n";
    }

    bool Queue::isFull() const {
        return (Head % Size == (Tail + 1) % Size);
    }

    bool Queue::isEmpty() const {
        return (Head % Size == Tail % Size);
    }

    void releaseQueue(Queue& q) {
        delete[] q.Data;
        q.Size = 1;
        q.Head = q.Tail = 0;
    }

    void displayMenu() {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Просмотреть первый элемент\n";
        std::cout << "4. Узнать размер очереди\n";
        std::cout << "5. Найти максимальный элемент\n";
        std::cout << "6. Вывести очередь\n";
        std::cout << "7. Удалить три первых элемента\n";
        std::cout << "8. Доп.задание 1\n";
        std::cout << "9. Доп.задание 2\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
    }