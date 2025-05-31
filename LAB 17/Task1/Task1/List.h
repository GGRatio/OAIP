#pragma once
#include <iostream>
#include <string>

struct Element {
    Element* Prev;
    Element* Next;
    void* Data;

    Element(Element* prev, void* data, Element* next) {
        Prev = prev;
        Data = data;
        Next = next;
    }

    Element* GetNext() { return Next; };
    Element* GetPrev() { return Prev; };
};

class Object {
    Element* Head;

public:
    Object() : Head(nullptr) {};

    // Основные методы
    Element* GetFirst() { return Head; };
    Element* GetLast();
    Element* Search(void* data);
    bool Insert(void* data);
    bool Delete(Element* e);
    bool Delete(void* data);

    // Новые методы
    bool DeleteList();
    int CountList();

    void PrintList(void(*f)(void*));
    void PrintList(void(*f)(void*), Element* e);
};

Object Create();

// Структура для данных клиента банка
struct BankClient {
    std::string fullName;
    std::string accountType;
    int accountNumber;
    double balance;
    std::string lastUpdateDate;
};