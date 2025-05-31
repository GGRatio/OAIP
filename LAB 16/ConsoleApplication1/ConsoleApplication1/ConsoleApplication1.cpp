#include <iostream>
using namespace std;

struct Item {
    int data;
    int priority;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

bool isEmpty() {
    return head == nullptr;
}

// 1. Минимальный приоритет, LIFO при совпадении (извлечение с начала)
void insertMinPriorityLIFO(int x, int prio) {
    Item* newItem = new Item;
    newItem->data = x;
    newItem->priority = prio;
    newItem->next = nullptr;

    if (isEmpty()) {
        head = tail = newItem;
        return;
    }

    Item* current = head;
    Item* prev = nullptr;
    Item* lastMatch = nullptr;

    while (current != nullptr && current->priority <= prio) {
        if (current->priority == prio) {
            lastMatch = current;
        }
        prev = current;
        current = current->next;
    }

    if (lastMatch != nullptr) {
        newItem->next = lastMatch->next;
        lastMatch->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
    else if (prev == nullptr) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
}

// 2. Максимальный приоритет, FIFO при совпадении (извлечение с начала)
void insertMaxPriorityFIFO(int x, int prio) {
    Item* newItem = new Item;
    newItem->data = x;
    newItem->priority = prio;
    newItem->next = nullptr;

    if (isEmpty()) {
        head = tail = newItem;
        return;
    }

    Item* current = head;
    Item* prev = nullptr;

    while (current != nullptr && current->priority >= prio) {
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
}

// 3. Минимальный приоритет, LIFO при совпадении (извлечение с конца)
void insertMinPriorityLIFO_End(int x, int prio) {
    Item* newItem = new Item;
    newItem->data = x;
    newItem->priority = prio;
    newItem->next = nullptr;

    if (isEmpty()) {
        head = tail = newItem;
        return;
    }

    Item* current = head;
    Item* prev = nullptr;
    Item* lastMatch = nullptr;

    while (current != nullptr && current->priority <= prio) {
        if (current->priority == prio) {
            lastMatch = current;
        }
        prev = current;
        current = current->next;
    }

    if (lastMatch != nullptr) {
        newItem->next = lastMatch->next;
        lastMatch->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
    else if (prev == nullptr) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
}

// 4. Максимальный приоритет, FIFO при совпадении (извлечение с конца)
void insertMaxPriorityFIFO_End(int x, int prio) {
    Item* newItem = new Item;
    newItem->data = x;
    newItem->priority = prio;
    newItem->next = nullptr;

    if (isEmpty()) {
        head = tail = newItem;
        return;
    }

    Item* current = head;
    Item* prev = nullptr;
    Item* firstMatch = nullptr;

    while (current != nullptr && current->priority >= prio) {
        if (current->priority == prio && firstMatch == nullptr) {
            firstMatch = current;
        }
        prev = current;
        current = current->next;
    }

    if (firstMatch != nullptr) {
        if (firstMatch == head) {
            newItem->next = head;
            head = newItem;
        }
        else {
            Item* temp = head;
            while (temp->next != firstMatch) {
                temp = temp->next;
            }
            newItem->next = firstMatch;
            temp->next = newItem;
        }
    }
    else if (prev == nullptr) {
        newItem->next = head;
        head = newItem;
    }
    else {
        newItem->next = prev->next;
        prev->next = newItem;
        if (newItem->next == nullptr) {
            tail = newItem;
        }
    }
}

// Функции извлечения
int dequeueFromFront() {
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return -1;
    }

    int value = head->data;
    Item* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }

    return value;
}

int dequeueFromEnd() {
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return -1;
    }

    int value = tail->data;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        Item* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    return value;
}

// Дополнительные функции
void printQueue() {
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }

    Item* current = head;
    cout << "Очередь: ";
    while (current != nullptr) {
        cout << current->data << "(" << current->priority << ")";
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueFromFront();
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice = 1;
    int queueType = 1;
    int value, priority;

    while (choice != 0) {
        cout << "\nТекущий тип очереди: ";
        switch (queueType) {
        case 1: cout << "1. Минимальный приоритет, LIFO (извлечение с начала)"; break;
        case 2: cout << "2. Максимальный приоритет, FIFO (извлечение с начала)"; break;
        case 3: cout << "3. Минимальный приоритет, LIFO (извлечение с конца)"; break;
        case 4: cout << "4. Максимальный приоритет, FIFO (извлечение с конца)"; break;
        }

        cout << "\nМеню:\n"
            << "1 - Добавить элемент\n"
            << "2 - Извлечь элемент\n"
            << "3 - Вывести очередь\n"
            << "4 - Очистить очередь\n"
            << "5 - Сменить тип очереди\n"
            << "0 - Выход\n"
            << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            cout << "Введите приоритет: ";
            cin >> priority;
            switch (queueType) {
            case 1: insertMinPriorityLIFO(value, priority); break;
            case 2: insertMaxPriorityFIFO(value, priority); break;
            case 3: insertMinPriorityLIFO_End(value, priority); break;
            case 4: insertMaxPriorityFIFO_End(value, priority); break;
            }
            printQueue();
            break;

        case 2:
            if (queueType == 3 || queueType == 4) {
                cout << "Извлеченный элемент: " << dequeueFromEnd() << endl;
            }
            else {
                cout << "Извлеченный элемент: " << dequeueFromFront() << endl;
            }
            printQueue();
            break;

        case 3:
            printQueue();
            break;

        case 4:
            clearQueue();
            cout << "Очередь очищена" << endl;
            break;

        case 5:
            cout << "Выберите тип очереди:\n"
                << "1 - Минимальный приоритет, LIFO (извлечение с начала)\n"
                << "2 - Максимальный приоритет, FIFO (извлечение с начала)\n"
                << "3 - Минимальный приоритет, LIFO (извлечение с конца)\n"
                << "4 - Максимальный приоритет, FIFO (извлечение с конца)\n"
                << "Ваш выбор: ";
            cin >> queueType;
            clearQueue();
            break;

        case 0:
            cout << "Выход из программы" << endl;
            break;

        default:
            cout << "Неверный выбор" << endl;
        }
    }

    clearQueue();
    return 0;
}