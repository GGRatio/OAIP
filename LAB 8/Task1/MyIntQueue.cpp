    #include "MyIntQueue.h"
    #include <iostream>

    Queue::Queue(int size) { //���������� ������������ ��������� ���::���_������������
        Size = size;
        Head = Tail = 0;
        Data = new int[Size];
    } //����������� - ��� "���������� �� ������" �������
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
            std::cout << "������� �����!\n";
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
            qCh.Data[qCh.Tail-1] = symb; // ��������� ����� ������� � �����

            std::cout << "�������: ";
            for (int i = qCh.Head; i != qCh.Tail; i++) {
                std::cout << qCh.Data[i] << " ";
            }
            std::cout << std::endl;
        }
        else {
            qCh.Data[qCh.Tail] = symb;
            qCh.Tail = qCh.Tail + 1;

            std::cout << "�������: ";
            for (int i = qCh.Head; i != qCh.Tail; i++) {
                std::cout << qCh.Data[i] << " ";
            }
            std::cout << std::endl;
        }

        return true;
    }

    bool enQueueFl(QueueFl& qFl) {
        float x, max = INT_MIN;
        std::cout << "������� " << qFl.Size - 1 << " ������������ �����:\n";
        for (int i = 0; i < qFl.Size - 1; i++) {
            std::cin >> x;
            qFl.Data[qFl.Tail] = x;
            qFl.Tail++;
            if (x > max) {
                max = x;
            }
        }
        std::cout << "�������� �������\n";
        for (int i = qFl.Head; i < qFl.Tail; i++) {
            std::cout << qFl.Data[i] << " ";
        }
        std::cout << std::endl;

        while (qFl.Data[qFl.Head] != max) { //��� ����������� �����
            float buff = qFl.Data[qFl.Head]; 
            for (int i = qFl.Head; i < qFl.Tail - 1; i++) {
                qFl.Data[i] = qFl.Data[i + 1];
            }
            qFl.Data[qFl.Tail - 1] = buff;
        }

        std::cout << "���������� ��������� �������\n";
        for (int i = qFl.Head; i < qFl.Tail; i++) {
            std::cout << qFl.Data[i] << " ";
        }
        std::cout << std::endl;

        return 1;
    }

    int deQueue(Queue& q) {
        if (q.isEmpty()) {
            std::cout << "������� �����!\n";
            return QUEUE_EMPTY_VALUE;
        }

        int value = q.Data[q.Head];
        q.Head = (q.Head + 1) % q.Size;
        return value;
    }

    int peekQueue(const Queue& q) {
        if (q.isEmpty()) {
            std::cout << "������� �����!\n";
            return QUEUE_EMPTY_VALUE;
        }
        return q.Data[q.Head];
    }

    int getQueueSize(const Queue& q) {
        return (q.Tail - q.Head + q.Size) % q.Size;
    }

    int findMaxInQueue(const Queue& q) {
        if (q.isEmpty()) {
            std::cout << "������� �����!\n";
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
        std::cout << "������� �������: ";
        if (q.isEmpty()) {
            std::cout << "�����";
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
        std::cout << "\n����:\n";
        std::cout << "1. �������� �������\n";
        std::cout << "2. ������� �������\n";
        std::cout << "3. ����������� ������ �������\n";
        std::cout << "4. ������ ������ �������\n";
        std::cout << "5. ����� ������������ �������\n";
        std::cout << "6. ������� �������\n";
        std::cout << "7. ������� ��� ������ ��������\n";
        std::cout << "8. ���.������� 1\n";
        std::cout << "9. ���.������� 2\n";
        std::cout << "0. �����\n";
        std::cout << "�������� ��������: ";
    }