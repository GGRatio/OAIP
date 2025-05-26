#pragma once

struct Stack {
	int data;
	Stack* next;
};

/* ��������� ������� ������� ������������ � ����� Stack.cpp */
void push(int, Stack* &);  //���������� �������� � ����
int pop(Stack* &); //���������� �������� �� ����� (� �������)
void toFile(Stack* &);
void fromFile(Stack* &);
void show(Stack* &);
void delFirstPos(Stack* &);
void delFirstOver(Stack* &);
void var5(Stack*&, Stack*&, Stack*&);
void var9(Stack*&, Stack*&, Stack*&);