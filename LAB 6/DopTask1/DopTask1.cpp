#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Прототипы функций
void addElement(Node*& head);
void deleteElement(Node*& head, int value);
void printList(Node* head);
void findSumPositive2part(Node* head);
void saveToFile(Node* head, const string& filename);
void loadFromFile(Node*& head, const string& filename);
void menu();

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Node* head = nullptr;
    int choice;
    string filename = "list.txt";

    do {
        menu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            addElement(head);
            break;
        }
        case 2: {
            if (head == nullptr) {
                cout << "Список пуст!" << endl;
            }
            else {
                int value;
                cout << "Введите значение для удаления: ";
                cin >> value;
                deleteElement(head, value);
            }
            break;
        }
        case 3: {
            findSumPositive2part(head);
            break;
        }
        case 4: {
            printList(head);
            break;
        }
        case 5: {
            saveToFile(head, filename);
            break;
        }
        case 6: {
            loadFromFile(head, filename);
            break;
        }
        case 7: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Неверный выбор!" << endl;
            break;
        }
        }
    } while (choice != 7);

    // Очистка памяти перед выходом
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

void menu() {
    cout << "\nМеню:" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Удалить элемент" << endl;
    cout << "3. Найти сумму положительных двухзначных элементов" << endl;
    cout << "4. Вывести список" << endl;
    cout << "5. Сохранить список в файл" << endl;
    cout << "6. Загрузить список из файла" << endl;
    cout << "7. Выход" << endl;
}

void addElement(Node*& head) {
    int value;
    cout << "Введите целое число: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Элемент добавлен." << endl;
}

void deleteElement(Node*& head, int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Элемент не найден." << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current;
    cout << "Элемент удален." << endl;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список пуст!" << endl;
        return;
    }

    cout << "Список: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void findSumPositive2part(Node* head) {
    int sum = 0;
    bool found = false;
    Node* current = head;

    while (current != nullptr) {
        if (current->data > 0 && (current->data > 9 and current->data < 100)) {
            sum += current->data;
            found = true;
        }
        current = current->next;
    }

    if (found) {
        cout << "Сумма положительных, двухзначных элементов: " << sum << endl;
    }
    else {
        cout << "В списке нет положительных, двухзначных элементов..." << endl;
    }
}

void saveToFile(Node* head, const string& filename) {
    ofstream outFile("Node.txt");
    if (!outFile) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        outFile << current->data << " ";
        current = current->next;
    }

    outFile.close();
    cout << "Список сохранен в файл." << endl;
}

void loadFromFile(Node*& head, const string& filename) {
    ifstream inFile("Node.txt");
    if (!inFile) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    // Очищаем существующий список
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;

    int value;
    Node* tail = nullptr;
    while (inFile >> value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    inFile.close();
    cout << "Список загружен из файла." << endl;
}