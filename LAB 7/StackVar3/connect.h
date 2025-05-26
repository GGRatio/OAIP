#pragma once

struct Stack {
	int data;
	Stack* next;
};

/* Прототипы функций которые определяются в файле Stack.cpp */
void push(int, Stack* &);  //Добавление элемента в стек
int pop(Stack* &); //Извлечение элемента из стека (с вершины)
void toFile(Stack* &);
void fromFile(Stack* &);
void show(Stack* &);
void delFirstPos(Stack* &);
void delFirstOver(Stack* &);
void var5(Stack*&, Stack*&, Stack*&);
void var9(Stack*&, Stack*&, Stack*&);