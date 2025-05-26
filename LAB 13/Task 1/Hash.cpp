#include "Hash.h"
#include <iostream>
#include <cmath>


int MultiplicativeHash(int key, int size) {
    const double A = (sqrt(5.0) - 1) / 2;
    double fractional = (key * A) - floor(key * A);
    return static_cast<int>(size * fractional);
}

int HashFunction(int key, int size, int p) {
    double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
    return (p + key) % size;
}

int UniversalHash(int key, int size, int p) {
    const int a = 2654435761;
    const int b = 7;
    return (a * key + b + p) % size;
}

int (*currentHashFunc)(int, int, int) = HashFunction;

// Изменяем сигнатуру функции
void setHashFunction(int choice, Object& H) {
    switch (choice) {
    case 1: currentHashFunc = HashFunction; break;
    case 2: currentHashFunc = [](int key, int size, int) {
        return MultiplicativeHash(key, size);
        }; break;
    case 3: currentHashFunc = UniversalHash; break;
    default: return;
    }

    if (H.size > 0) {
        H.rehash();
    }
    std::cout << "Хеш-функция изменена. Таблица перестроена.\n";
}

/*
int Next_hash(int hash, int size, int p) {
    return (hash + 5 * p + 3 * p * p) % size;
}
*/

//Kbytqyjt htitybt rjkbpbb dfhbyn 5
    int Next_hash(int hash, int size, int p) {
    return (hash + 1) % size;
    }

// Создание объекта хеш-таблицы
Object create(int size, int(*getkey)(void*)) {
    return *(new Object(size, getkey));
}

// Конструктор (:
Object::Object(int size, int(*getkey)(void*)) {
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void* [size];
    for (int i = 0; i < size; ++i)
        data[i] = NULL;
}


bool Object::insert(void* d) {
    bool b = false;
    if (N != size)
        for (int i = 0, t = getKey(d), j = currentHashFunc(t, size, 0);
            i != size && !b;  j = Next_hash(j, size, ++i))
            if (data[j] == NULL || data[j] == DEL) {
                data[j] = d;
                N++;
                b = true;
            }
    return b;
}


int Object::searchInd(int key) {
    int t = -1;
    bool b = false;
    if (N != 0)
        for (int i = 0, j = currentHashFunc(key, size, 0); data[j] != NULL && i != size && !b; j = currentHashFunc(key, size, ++i))
            if (data[j] != DEL)
                if (getKey(data[j]) == key) {
                    t = j; b = true;
                }
    return t;
}

// Поиск элемента по ключу
void* Object::search(int key) {
    int t = searchInd(key);
    return(t >= 0) ? (data[t]) : (NULL);
}

// Удаление по ключу
void* Object::deleteByKey(int key) {
    int i = searchInd(key);
    void* t = data[i];
    if (t != NULL) {
        data[i] = DEL;
        N--;
    }
    return t;
}

// Удаление по значению
bool Object::deleteByValue(void* d) {
    return(deleteByKey(getKey(d)) != NULL);
}


void Object::scan(void(*f)(void*)) {
    for (int i = 0; i < this->size; i++) {
        std::cout << " Элемент" << i;
        if ((this->data)[i] == NULL)
            std::cout << "  пусто" << std::endl;
        else if ((this->data)[i] == DEL)
            std::cout << "  удален" << std::endl;
        else
            f((this->data)[i]);
    }
}

void Object::rehash() {
    void** oldData = data;
    int oldSize = size;

    // Создаём новую таблицу того же размера
    data = new void* [size];
    N = 0;
    for (int i = 0; i < size; ++i) {
        data[i] = NULL;
    }

    // Перемещаем элементы из старой таблицы
    for (int i = 0; i < oldSize; ++i) {
        if (oldData[i] != NULL && oldData[i] != DEL) {
            insert(oldData[i]);  // Вставляем заново (уже с новой хеш-функцией)
        }
    }
    delete[] oldData;
}