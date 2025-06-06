#include "Hash.h"
#include <iostream>
using namespace std;

struct AAA {
    int key;
    char* mas;
    AAA(int k, char* z) {
        key = k;  mas = z;
    }
    AAA() {}
};

int key(void* d) {
    AAA* f = (AAA*)d;
    return f->key;
}

void AAA_print(void* d) {
    cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    int siz = 10, choice, k;
    cout << "������� ������ ���-�������: ";
    cin >> siz;
    Object H = create(siz, key);

    for (;;) {
        cout << "\n1 - ����� ���-�������\n"
            << "2 - ���������� ��������\n"
            << "3 - �������� ��������\n"
            << "4 - ����� ��������\n"
            << "5 - ����� ���-�������\n"
            << "0 - �����\n"
            << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 0: exit(0);
        case 1: H.scan(AAA_print); break;
        case 2: {
            AAA* a = new AAA;
            char* str = new char[20];
            cout << "������� ����: ";
            cin >> k;
            a->key = k;
            cout << "������� ������: ";
            cin >> str;
            a->mas = str;
            if (H.N == H.size)
                cout << "������� ���������!" << endl;
            else
                H.insert(a);
            break;
        }
        case 3: {
            cout << "������� ���� ��� ��������: ";
            cin >> k;
            H.deleteByKey(k);
            break;
        }
        case 4: {
            cout << "������� ���� ��� ������: ";
            cin >> k;
            if (H.search(k) == NULL)
                cout << "������� �� ������!" << endl;
            else
                AAA_print(H.search(k));
            break;
        }
        case 5: {
            cout << "�������� ���-�������:\n"
                << "1 - �����������\n"
                << "2 - �����������������\n"
                << "3 - �������������\n";
            int hashChoice;
            cin >> hashChoice;
            setHashFunction(hashChoice, H);  // �������� H ��� ��������
            break;
        }
        default:
            cout << "�������� �����!" << endl;
        }
    }
    return 0;
}