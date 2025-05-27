#include "Hash_Chain.h"
#include <iostream>
#include <cstring> // ��� strcpy_s
using namespace std;

struct AAA {
    int key;
    char* mas;

    AAA(int k, char* z) {
        key = k;
        mas = new char[strlen(z) + 1];
        strcpy_s(mas, strlen(z) + 1, z); // ���������� ������ strcpy
    }

    AAA() : key(0), mas(nullptr) {}

    ~AAA() { // ��������� ���������� ��� ������� ������
        if (mas) delete[] mas;
    }
};

int hf(void* d) {
    AAA* f = (AAA*)d;
    const int prime = 31;
    return (f->key * prime);
}

void AAA_print(listx::Element* e) {
    if (e && e->data) {
        AAA* a = (AAA*)e->data;
        cout << a->key << " - " << a->mas << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int current_size;
    cout << "������� ������ ���-�������: ";
    cin >> current_size;
    hashTC::Object H = hashTC::create(current_size, hf);

    int choice, k;
    char str[100];

    while (true) {
        cout << "\n1 - ����� �������\n2 - �������� �����\n3 - ������� �����\n4 - ����� �����\n0 - �����\n��������: ";
        cin >> choice;

        switch (choice) {
        case 0: return 0;

        case 1:
            H.Scan();
            break;

        case 2: {
            cout << "����� �����: ";
            cin >> k;
            cout << "������� ���������: ";
            cin.ignore();
            cin.getline(str, 100);

            AAA* a = new AAA(k, str); // ���������� �����������
            H.insert(a);
            break;
        }

        case 3: {
            AAA b;
            cout << "����� ����� ��� ��������: ";
            cin >> b.key;
            if (H.deleteByData(&b))
                cout << "������� �������\n";
            else
                cout << "����� �� �������\n";
            break;
        }

        case 4: {
            AAA c;
            cout << "����� ����� ��� ������: ";
            cin >> c.key;
            auto res = H.search(&c);
            if (res) {
                cout << "�������: ";
                AAA_print(res);
            }
            else {
                cout << "�� �������\n";
            }
            break;
        }

        default:
            cout << "�������� �����!\n";
        }
    }
}