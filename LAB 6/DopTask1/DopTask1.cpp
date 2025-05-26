#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// ��������� �������
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
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            addElement(head);
            break;
        }
        case 2: {
            if (head == nullptr) {
                cout << "������ ����!" << endl;
            }
            else {
                int value;
                cout << "������� �������� ��� ��������: ";
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
            cout << "����� �� ���������." << endl;
            break;
        }
        default: {
            cout << "�������� �����!" << endl;
            break;
        }
        }
    } while (choice != 7);

    // ������� ������ ����� �������
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

void menu() {
    cout << "\n����:" << endl;
    cout << "1. �������� �������" << endl;
    cout << "2. ������� �������" << endl;
    cout << "3. ����� ����� ������������� ����������� ���������" << endl;
    cout << "4. ������� ������" << endl;
    cout << "5. ��������� ������ � ����" << endl;
    cout << "6. ��������� ������ �� �����" << endl;
    cout << "7. �����" << endl;
}

void addElement(Node*& head) {
    int value;
    cout << "������� ����� �����: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "������� ��������." << endl;
}

void deleteElement(Node*& head, int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "������� �� ������." << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current;
    cout << "������� ������." << endl;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "������ ����!" << endl;
        return;
    }

    cout << "������: ";
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
        cout << "����� �������������, ����������� ���������: " << sum << endl;
    }
    else {
        cout << "� ������ ��� �������������, ����������� ���������..." << endl;
    }
}

void saveToFile(Node* head, const string& filename) {
    ofstream outFile("Node.txt");
    if (!outFile) {
        cout << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        outFile << current->data << " ";
        current = current->next;
    }

    outFile.close();
    cout << "������ �������� � ����." << endl;
}

void loadFromFile(Node*& head, const string& filename) {
    ifstream inFile("Node.txt");
    if (!inFile) {
        cout << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    // ������� ������������ ������
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
    cout << "������ �������� �� �����." << endl;
}