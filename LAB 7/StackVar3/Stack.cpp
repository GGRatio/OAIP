#include <iostream>
#include <fstream>
#include "connect.h"

using namespace std;

void push(int x, Stack* &Stk) {
	Stack* el = new Stack; //Выделение памяти для нового элемента
	el->data = x;
	el->next = Stk; //Перенос вершины на следующий элемент
	Stk = el; //Сдвиг вершины на следующий элемент
}

int pop(Stack* &Stk) {
	if (Stk == NULL) {
		cout << "\nСтек пуст\n";
		return -1;
	}
	else {
		Stack* el = Stk; //переменная для хранения адреса (текущей) вершины стека
		int x = Stk->data;
		if (Stk) {
			Stk = Stk->next; //Перенос вершины
		}
		delete el;
		return x;
	}
	/*
	Переменная для хранения адреса вершины нам нужна только для того чтобы после
	всех действий мы не потеряли адрес старой вершины и удалили её.

	До pop: (Stk указатель на вершину стека)
	Stk -> [A|next] -> [B|next] -> [C|next] -> NULL

	После pop:
	Stk -> [B|next] -> [C|next] -> NULL
	Возвращено: 'A'
	*/
}

void toFile(Stack* &Stk) {
	Stack* el = Stk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail()) {
		cout << "Ошибка открытия файла\n";
		exit(1);
	}
	while (el) { // пока не дошли до дна стека (el != NULL)
		buf = *el;
		frm.write((char*)&buf, sizeof(Stack)); //Записываем буфер в файл
		el = el->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack* &Stk) {
	Stack buf, * p = nullptr, *e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail()) {
		cout << "Ошибка открытия файла\n";
		exit(1);
	}
	frm.seekg(0); // Переходим в начало файла
	frm.read((char*)&buf, sizeof(Stack)); // Читаем первый элемент
	while (!frm.eof()) {
		push(buf.data, e); // Добавляем данные во временный стек
		frm.read((char*)&buf, sizeof(Stack));// Читаем следующий элемент
	}
	frm.close();
	while (e != NULL) {
		buf.data = pop(e);
		push(buf.data, p);
		Stk = p;
	}
	cout << "Стек считан из файла mSatck.dat\n";
}

void show(Stack* &Stk) {
	if (Stk == NULL) {
		cout << "Стек пуст...\n";
		return;
	}
	while (Stk != NULL) {
		cout << Stk->data << " ";
		Stack* current = Stk; 
		Stk = Stk->next; // Сдвигаем вершину 
		delete current; // Отчищаем текущий элемент 
	}
	cout << endl;
}

void delFirstPos(Stack*& Stk) {
	// Проверка на пустой стек
	if (Stk == NULL) {
		return;
	}

	// Проверка первого элемента
	if (Stk->data >= 0) {
		Stack* temp = Stk;
		Stk = Stk->next;
		delete temp;
		return;
	}

	// Поиск первого положительного элемента в середине стека
	Stack* current = Stk;
	while (current->next != NULL) {
		if (current->next->data >= 0) {
			Stack* temp = current->next; //cохраняем адрес к тому который необходимо удалить
			current->next = current->next->next; // Обходим удаляемый элемент
			delete temp;
			return;
		}
		current = current->next;
	}
}

void delFirstOver(Stack*& Stk) {
	if (Stk == NULL) {
		cout << "Стек пуст\n";
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

// Вариант 5: элементы из Stack1, но не в Stack2
void var5(Stack*& Stack1, Stack*& Stack2, Stack*& Result) {
	// Создаем временные стеки для копий
	Stack* temp1 = NULL;
	Stack* temp2 = NULL;

	// Копируем Stack1 в temp1 (инвертируя порядок)
	Stack* current = Stack1;
	while (current) {
		push(current->data, temp1);
		current = current->next;
	}

	// Копируем Stack2 в temp2 (инвертируя порядок)
	current = Stack2;
	while (current) {
		push(current->data, temp2);
		current = current->next;
	}

	// Проверяем элементы Stack1 на отсутствие в Stack2
	current = temp1;
	while (current) {
		int val = current->data;
		bool found = false;

		// Проверяем наличие в Stack2
		Stack* temp = temp2;
		while (temp) {
			if (temp->data == val) {
				found = true;
				break;
			}
			temp = temp->next;
		}

		// Если не найден в Stack2
		if (!found) {
			// Проверяем, нет ли уже в Result
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

	// Очищаем временные стеки
	while (temp1) pop(temp1);
	while (temp2) pop(temp2);
}

// Вариант 9: элементы из одного стека, но не из другого
void var9(Stack*& Stack1, Stack*& Stack2, Stack*& Result) {
	// Сначала выполняем var5(Stack1, Stack2)
	var5(Stack1, Stack2, Result);

	// Затем выполняем var5(Stack2, Stack1) и добавляем в тот же Result
	Stack* tempResult = NULL;
	var5(Stack2, Stack1, tempResult);

	// Объединяем результаты
	while (tempResult) {
		int val = pop(tempResult);
		push(val, Result);
	}
}