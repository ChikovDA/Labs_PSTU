#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

struct point
{
	char* data;	//информационное поле
	point* next;	//адресное поле
};
//формирование двунаправленного списка
struct point2
{
	int key;//информационное поле
	point2* next;//указатель на следующий элемент
	point2* prev;//указатель на предыдущий элемент
};
point* make_list(int n)
{
	point* beg;//указатель на первый элемент
	point* p, * r;//вспомогательные указатели
	beg = new(point);//выделяем память под первый элемент
	std::cout << "Enter 1 element:   ";
	beg->data = new char[65536];
	std::cin >> beg->data;//вводим значение информационного поля
	std::cout << "\n";
	beg->next = 0;//обнуляем адресное поле
//ставим на этот элемент указатель p (последний элемент)
	p = beg;
	int num;
	for (int i = 0; i < n - 1; i++)
	{
		num = i + 2;
		r = new(point);//создаем новый элемент
		std::cout << "\nEnter " << num << " element:    ";
		r->data = new char[65536];
		std::cin >> r->data;
		r->next = 0;
		p->next = r;//связываем p и r
		p = r;//ставим на r указатель p (последний элемент)
	}
	return beg;//возвращаем beg как результат функции
}

void print_list(point* beg)
//печать списка
{
	std::cout << "\nList:";
	point* p = beg;//начало списка
	while (p != 0)
	{

		std::cout << p->data << "\t";
		p = p->next;//переход к следующему элементу
	}
}

void print_list(point2* beg)
//печать списка
{
	std::cout << "\nList:";
	point2* p = beg;//начало списка
	while (p != 0)
	{
		std::cout << p->key << "\t";
		p = p->next;//переход к следующему элементу
	}
}
void* popBack(point2* list) {
	point2* p = list, * next, * prev;//начало списка
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		if (p->key % 2 != 0) {
			p = p->prev; // переход к предыдущему узлу
		}
		else {
			prev = p->prev; // узел, предшествующий lst
			next = p->next; // узел, следующий за lst
			if (prev != NULL)
				prev->next = p->next; // переставляем указатель
			if (next != NULL)
				next->prev = p->prev; // переставляем указатель
			free(p); // освобождаем память удаляемого элемента
			break;
		}
	} while (p != NULL); // условие окончания обхода
	return list;
}
point* add_point(point* beg, int k)
//добавление элемента с номером k
{
	point* p = beg;//встали на первый элемент
	point* New = new(point);//создали новый элемент
	std::cout << "Key?";
	New->data = new char[65536];
	std::cin >> New->data;
	if (k == 0)//добавление в начало, если k=0
	{
		New->next = beg;
		beg = New;
		return beg;
	}
	for (int i = 0; i < k - 1 && p != 0; i++)
		p = p->next;//проходим по списку до(k-1) элемента или до конца
	if (p != 0)//если k-й элемент существует
	{
		New->next = p->next;//связываем New и k-й элемент
		p->next = New;//связываем (k-1)элемент и New
	}
	return beg;
}
point* del_point(point* beg, int k)
//удаление элемента с номером k из списка
{
	point* p = beg;
	if (k == 0)//удаление первого элемента
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//проходим по списку до элемента с номером k-1
	for (int i = 1; i < k && p->next != 0; i++)
		p = p->next;
	/*если такого элемента в списке нет, то возвращаем указатель на начало списка в качестве результата функции*/
	if (p->next == 0) return beg;
	point* r = p->next;//ставим указатель r на k-й элемент
	p->next = r->next;//связываем k-1 и k+1 элемент
	delete r;//удаляем k-й элемент из памяти
	return beg;
}
point2* make_point2()
//создание одного элемента
{
	point2* p = new(point2);
	p->next = 0; p->prev = 0;//обнуляем указатели
	int s;
	std::cout << "\nEnter num:";
	std::cin >> s;
	p->key = s;
	return p;
}
point2* make_list2(int n)
//создание списка
{
	point2* p, * beg;
	beg = make_point2();//создаем первый элемент
	for (int i = 1; i < n; i++)
	{
		p = make_point2();//создаем один элемент
//добавление элемента в начало списка
		p->next = beg;//связываем р с первым элементом
		beg->prev = p;//связываем первый элемент с p
		beg = p;// p становится первым элементом списка
	}
	return beg;
}
