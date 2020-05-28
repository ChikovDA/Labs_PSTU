#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

struct point
{
	char* data;	//�������������� ����
	point* next;	//�������� ����
};
//������������ ���������������� ������
struct point2
{
	int key;//�������������� ����
	point2* next;//��������� �� ��������� �������
	point2* prev;//��������� �� ���������� �������
};
point* make_list(int n)
{
	point* beg;//��������� �� ������ �������
	point* p, * r;//��������������� ���������
	beg = new(point);//�������� ������ ��� ������ �������
	std::cout << "Enter 1 element:   ";
	beg->data = new char[65536];
	std::cin >> beg->data;//������ �������� ��������������� ����
	std::cout << "\n";
	beg->next = 0;//�������� �������� ����
//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	int num;
	for (int i = 0; i < n - 1; i++)
	{
		num = i + 2;
		r = new(point);//������� ����� �������
		std::cout << "\nEnter " << num << " element:    ";
		r->data = new char[65536];
		std::cin >> r->data;
		r->next = 0;
		p->next = r;//��������� p � r
		p = r;//������ �� r ��������� p (��������� �������)
	}
	return beg;//���������� beg ��� ��������� �������
}

void print_list(point* beg)
//������ ������
{
	std::cout << "\nList:";
	point* p = beg;//������ ������
	while (p != 0)
	{

		std::cout << p->data << "\t";
		p = p->next;//������� � ���������� ��������
	}
}

void print_list(point2* beg)
//������ ������
{
	std::cout << "\nList:";
	point2* p = beg;//������ ������
	while (p != 0)
	{
		std::cout << p->key << "\t";
		p = p->next;//������� � ���������� ��������
	}
}
void* popBack(point2* list) {
	point2* p = list, * next, * prev;//������ ������
	while (p->next != NULL)
		p = p->next;  // ������� � ����� ������
	do {
		if (p->key % 2 != 0) {
			p = p->prev; // ������� � ����������� ����
		}
		else {
			prev = p->prev; // ����, �������������� lst
			next = p->next; // ����, ��������� �� lst
			if (prev != NULL)
				prev->next = p->next; // ������������ ���������
			if (next != NULL)
				next->prev = p->prev; // ������������ ���������
			free(p); // ����������� ������ ���������� ��������
			break;
		}
	} while (p != NULL); // ������� ��������� ������
	return list;
}
point* add_point(point* beg, int k)
//���������� �������� � ������� k
{
	point* p = beg;//������ �� ������ �������
	point* New = new(point);//������� ����� �������
	std::cout << "Key?";
	New->data = new char[65536];
	std::cin >> New->data;
	if (k == 0)//���������� � ������, ���� k=0
	{
		New->next = beg;
		beg = New;
		return beg;
	}
	for (int i = 0; i < k - 1 && p != 0; i++)
		p = p->next;//�������� �� ������ ��(k-1) �������� ��� �� �����
	if (p != 0)//���� k-� ������� ����������
	{
		New->next = p->next;//��������� New � k-� �������
		p->next = New;//��������� (k-1)������� � New
	}
	return beg;
}
point* del_point(point* beg, int k)
//�������� �������� � ������� k �� ������
{
	point* p = beg;
	if (k == 0)//�������� ������� ��������
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//�������� �� ������ �� �������� � ������� k-1
	for (int i = 1; i < k && p->next != 0; i++)
		p = p->next;
	/*���� ������ �������� � ������ ���, �� ���������� ��������� �� ������ ������ � �������� ���������� �������*/
	if (p->next == 0) return beg;
	point* r = p->next;//������ ��������� r �� k-� �������
	p->next = r->next;//��������� k-1 � k+1 �������
	delete r;//������� k-� ������� �� ������
	return beg;
}
point2* make_point2()
//�������� ������ ��������
{
	point2* p = new(point2);
	p->next = 0; p->prev = 0;//�������� ���������
	int s;
	std::cout << "\nEnter num:";
	std::cin >> s;
	p->key = s;
	return p;
}
point2* make_list2(int n)
//�������� ������
{
	point2* p, * beg;
	beg = make_point2();//������� ������ �������
	for (int i = 1; i < n; i++)
	{
		p = make_point2();//������� ���� �������
//���������� �������� � ������ ������
		p->next = beg;//��������� � � ������ ���������
		beg->prev = p;//��������� ������ ������� � p
		beg = p;// p ���������� ������ ��������� ������
	}
	return beg;
}
