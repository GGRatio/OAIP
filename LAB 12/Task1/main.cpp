﻿#include "Heap.h"
#include <iostream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP
        rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else
        if (A2->x > A1->x)
            rc = heap::LESS;
    return rc;
#undef A2
#undef A1 
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice, index;
    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);

    for (;;)
    {
        cout << "1 - вывод кучи h1 на экран" << endl;
        cout << "2 - добавить элемент в h1" << endl;
        cout << "3 - удалить максимальный элемент из h1" << endl;
        cout << "4 - удалить минимальный элемент из h1" << endl;
        cout << "5 - удалить i-ый элемент из h1" << endl;
        cout << "6 - добавить элемент в h2" << endl;
        cout << "7 - объединить кучи h1 и h2" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;  cin >> choice;

        switch (choice)
        {
        case 0:  exit(0);
        case 1:  h1.scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "введите ключ" << endl; 	cin >> k;
            a->x = k;
            h1.insert(a);
        }
              break;
        case 3:   h1.extractMax();
            break;
        case 4:   h1.extractMin();
            break;
        case 5: {
            cout << "Введите индекс элемента: ";
            cin >> index;
            h1.extractI(index);
        }
              break;
        case 6: {
            AAA* a = new AAA;
            cout << "введите ключ" << endl; 	cin >> k;
            a->x = k;
            h2.insert(a);
        }
              break;
        case 7:   h1.unionHeap(&h2);
            break;
        default:  cout << endl << "Введена неверная команда!" << endl;
        }
    }
    return 0;
}