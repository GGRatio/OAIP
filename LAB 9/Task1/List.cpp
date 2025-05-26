#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Добавление элемента (Var 5)" << endl;
	cout << "2. Удаление элемента" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Чтение из файла" << endl;
	cout << "7. Удаление каждого m-го (Var 3)" << endl;
	cout << "0. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c <= 0 or c >= 8);
	return c;
}
//-----------------------------------------------------------
void insertEnd(Address* e, Address** phead, Address** plast) //Добавление в конец списка
//e это указатель на функции создания нового объекта
//в нашем случае та функция возвращает указатель на новый объект
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()     
{
	Address* temp = new Address(); //Создаём новый объект в куче (указатель на него)
	if (!temp)
	{
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	//функция getline (то куда записываем, условия при которых запись остановится)
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	//Сбрасывает флаги состояния потока
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}

void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insertEnd(t, phead, plast);
	}
	fclose(fp);
}
//Вариант 3
void deleteEveryM(int m, Address*& head, Address*& last) {
	// Проверка на некорректные начальное
	if (m <= -1 or head == nullptr) {
		return;
	}

	Address* current = head;
	int count = 1;

	while (current != nullptr) {
		Address* nextNode = current->next;

		if (count % m == 0) {
			if (current->prev != nullptr) {
				current->prev->next = current->next;
			}
			else {
				head = current->next;
			}

			if (current->next != nullptr) {
				current->next->prev = current->prev;
			}
			else {
				last = current->prev;
			}

			delete current;
		}

		current = nextNode;
		count++;
	}
}
//-----------------------------------------------------------
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insertEnd(setElement(), &head, &last);
			break;
		case 2: {
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
		case 5: {
			writeToFile(&head);
			break;
		}
		case 6: {
			readFromFile(&head,&last);
			break;
		}
		case 7: {
			int m;
			cout << "Введите поярядок элементов для удаление (m)\n";
			cin >> m;
			deleteEveryM(m,head,last);
			break;
		}
			  break;
		case 0:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}

