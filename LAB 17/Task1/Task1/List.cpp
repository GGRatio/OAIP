#include "List.h"

bool Object::Insert(void* data) {
    if (Head == NULL) {
        Head = new Element(NULL, data, NULL);
    }
    else {
        Head->Prev = new Element(NULL, data, Head);
        Head = Head->Prev;
    }
    return true;
}

Element* Object::Search(void* data) {
    Element* rc = Head;
    while ((rc != NULL) && (rc->Data != data))
        rc = rc->Next;
    return rc;
}

void Object::PrintList(void(*f)(void*)) {
    Element* e = Head;
    while (e != NULL) {
        f(e->Data);
        e = e->GetNext();
    }
}

void Object::PrintList(void(*f)(void*), Element* e) {
    if (e != NULL) {
        f(e->Data);
    }
}

bool Object::Delete(Element* e) {
    if (e == NULL) return false;

    if (e->Next != NULL)
        e->Next->Prev = e->Prev;
    if (e->Prev != NULL)
        e->Prev->Next = e->Next;
    else
        Head = e->Next;

    delete e;
    return true;
}

bool Object::Delete(void* data) {
    return Delete(Search(data));
}

Element* Object::GetLast() {
    Element* e = Head;
    while (e != NULL && e->Next != NULL) {
        e = e->Next;
    }
    return e;
}

// удаление всего списка
bool Object::DeleteList() {
    while (Head != NULL) {
        Element* temp = Head;
        Head = Head->Next;
        delete temp;
    }
    return true;
}

// подсчет элементов
int Object::CountList() {
    int count = 0;
    Element* e = Head;
    while (e != NULL) {
        count++;
        e = e->Next;
    }
    return count;
}

Object Create() {
    return Object();
}