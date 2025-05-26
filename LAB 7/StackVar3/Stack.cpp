#include <iostream>
#include <fstream>
#include "connect.h"

using namespace std;

void push(int x, Stack* &Stk) {
	Stack* el = new Stack; //��������� ������ ��� ������ ��������
	el->data = x;
	el->next = Stk; //������� ������� �� ��������� �������
	Stk = el; //����� ������� �� ��������� �������
}

int pop(Stack* &Stk) {
	if (Stk == NULL) {
		cout << "\n���� ����\n";
		return -1;
	}
	else {
		Stack* el = Stk; //���������� ��� �������� ������ (�������) ������� �����
		int x = Stk->data;
		if (Stk) {
			Stk = Stk->next; //������� �������
		}
		delete el;
		return x;
	}
	/*
	���������� ��� �������� ������ ������� ��� ����� ������ ��� ���� ����� �����
	���� �������� �� �� �������� ����� ������ ������� � ������� �.

	�� pop: (Stk ��������� �� ������� �����)
	Stk -> [A|next] -> [B|next] -> [C|next] -> NULL

	����� pop:
	Stk -> [B|next] -> [C|next] -> NULL
	����������: 'A'
	*/
}

void toFile(Stack* &Stk) {
	Stack* el = Stk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail()) {
		cout << "������ �������� �����\n";
		exit(1);
	}
	while (el) { // ���� �� ����� �� ��� ����� (el != NULL)
		buf = *el;
		frm.write((char*)&buf, sizeof(Stack)); //���������� ����� � ����
		el = el->next;
	}
	frm.close();
	cout << "���� ������� � ���� mStack.dat\n";
}

void fromFile(Stack* &Stk) {
	Stack buf, * p = nullptr, *e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail()) {
		cout << "������ �������� �����\n";
		exit(1);
	}
	frm.seekg(0); // ��������� � ������ �����
	frm.read((char*)&buf, sizeof(Stack)); // ������ ������ �������
	while (!frm.eof()) {
		push(buf.data, e); // ��������� ������ �� ��������� ����
		frm.read((char*)&buf, sizeof(Stack));// ������ ��������� �������
	}
	frm.close();
	while (e != NULL) {
		buf.data = pop(e);
		push(buf.data, p);
		Stk = p;
	}
	cout << "���� ������ �� ����� mSatck.dat\n";
}

void show(Stack* &Stk) {
	if (Stk == NULL) {
		cout << "���� ����...\n";
		return;
	}
	while (Stk != NULL) {
		cout << Stk->data << " ";
		Stack* current = Stk; 
		Stk = Stk->next; // �������� ������� 
		delete current; // �������� ������� ������� 
	}
	cout << endl;
}

void delFirstPos(Stack*& Stk) {
	// �������� �� ������ ����
	if (Stk == NULL) {
		return;
	}

	// �������� ������� ��������
	if (Stk->data >= 0) {
		Stack* temp = Stk;
		Stk = Stk->next;
		delete temp;
		return;
	}

	// ����� ������� �������������� �������� � �������� �����
	Stack* current = Stk;
	while (current->next != NULL) {
		if (current->next->data >= 0) {
			Stack* temp = current->next; //c�������� ����� � ���� ������� ���������� �������
			current->next = current->next->next; // ������� ��������� �������
			delete temp;
			return;
		}
		current = current->next;
	}
}

void delFirstOver(Stack*& Stk) {
	if (Stk == NULL) {
		cout << "���� ����\n";
		return;
	}

	if (Stk->data > 100) {
		Stack* temp = Stk;
		Stk = Stk->next;
		delete temp;
		return;
	}

	Stack* current = Stk;
	while (current->next != NULL) {
		if ((current->next->data)>100) {
			Stack* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		current = current->next;
	}
}
// Stk ->[A|next] ->[B|next] ->[C|next]->NULL

// ������� 5: �������� �� Stack1, �� �� � Stack2
void var5(Stack*& Stack1, Stack*& Stack2, Stack*& Result) {
	// ������� ��������� ����� ��� �����
	Stack* temp1 = NULL;
	Stack* temp2 = NULL;

	// �������� Stack1 � temp1 (���������� �������)
	Stack* current = Stack1;
	while (current) {
		push(current->data, temp1);
		current = current->next;
	}

	// �������� Stack2 � temp2 (���������� �������)
	current = Stack2;
	while (current) {
		push(current->data, temp2);
		current = current->next;
	}

	// ��������� �������� Stack1 �� ���������� � Stack2
	current = temp1;
	while (current) {
		int val = current->data;
		bool found = false;

		// ��������� ������� � Stack2
		Stack* temp = temp2;
		while (temp) {
			if (temp->data == val) {
				found = true;
				break;
			}
			temp = temp->next;
		}

		// ���� �� ������ � Stack2
		if (!found) {
			// ���������, ��� �� ��� � Result
			bool exists = false;
			Stack* res = Result;
			while (res) {
				if (res->data == val) {
					exists = true;
					break;
				}
				res = res->next;
			}

			if (!exists) {
				push(val, Result);
			}
		}

		current = current->next;
	}

	// ������� ��������� �����
	while (temp1) pop(temp1);
	while (temp2) pop(temp2);
}

// ������� 9: �������� �� ������ �����, �� �� �� �������
void var9(Stack*& Stack1, Stack*& Stack2, Stack*& Result) {
	// ������� ��������� var5(Stack1, Stack2)
	var5(Stack1, Stack2, Result);

	// ����� ��������� var5(Stack2, Stack1) � ��������� � ��� �� Result
	Stack* tempResult = NULL;
	var5(Stack2, Stack1, tempResult);

	// ���������� ����������
	while (tempResult) {
		int val = pop(tempResult);
		push(val, Result);
	}
}