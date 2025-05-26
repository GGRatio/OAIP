#ifndef MY_INT_QUEUE_H
#define MY_INT_QUEUE_H

#define QUEUE_EMPTY_VALUE -2147483648  // ����������� �������� ��� ������ �������

struct Queue {
    int Head;           // ������ ������ �������
    int Tail;           // ������ ����� �������
    int Size;           // ������ ��������� (����. ���������� +1)
    int* Data;          // ������ ��� �������� ������

    Queue(int size);    // �����������

    bool isFull() const;  // �������� �� �������������
    bool isEmpty() const; // �������� �� �������
};

struct QueueCh {
    int Head;           // ������ ������ �������
    int Tail;           // ������ ����� �������
    int Size;           // ������ ��������� (����. ���������� +1)         
    char* Data;      // ������ ��� �������� �������� 

    QueueCh(int size);    // �����������
};

struct QueueFl {
    int Head;
    int Tail;
    int Size;
    float* Data;

    QueueFl(int size);
};

// ��������� �������
Queue createQueue(int n);
QueueCh createQueueCh(int n);
QueueFl createQueueFl(int n);

bool enQueue(Queue& q, int x);
bool enQueueCh(QueueCh& qCh, char symb);
bool enQueueFl(QueueFl& qFl);

int deQueue(Queue& q);
int peekQueue(const Queue& q);
int getQueueSize(const Queue& q);
int findMaxInQueue(const Queue& q);
void printQueue(const Queue& q);
void releaseQueue(Queue& q);
void displayMenu();

#endif