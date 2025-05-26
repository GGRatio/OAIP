#ifndef MY_INT_QUEUE_H
#define MY_INT_QUEUE_H

#define QUEUE_EMPTY_VALUE -2147483648  // Специальное значение для пустой очереди

struct Queue {
    int Head;           // Индекс начала очереди
    int Tail;           // Индекс конца очереди
    int Size;           // Размер хранилища (макс. количество +1)
    int* Data;          // Массив для хранения данных

    Queue(int size);    // Конструктор

    bool isFull() const;  // Проверка на заполненность
    bool isEmpty() const; // Проверка на пустоту
};

struct QueueCh {
    int Head;           // Индекс начала очереди
    int Tail;           // Индекс конца очереди
    int Size;           // Размер хранилища (макс. количество +1)         
    char* Data;      // Массив для хранения символов 

    QueueCh(int size);    // Конструктор
};

struct QueueFl {
    int Head;
    int Tail;
    int Size;
    float* Data;

    QueueFl(int size);
};

// Прототипы функций
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