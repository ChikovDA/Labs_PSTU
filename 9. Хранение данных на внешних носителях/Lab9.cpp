// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <fstream> 
using namespace std;
#include <iostream>


//

struct buyer
{
	char fio[255];
	char adress[255];
	char number[255];
	char card[255];
};

buyer* Create(int n) {
fstream f("f.txt", ios::out);//��������������� �������� �����

//char fio[255], adress[255], card[255], number[255];
	buyer* a;
	a = new buyer[n];//������� ������������ ������
	for (int i = 0; i < n; i++)
	{
		cout << "Fio # " << i << "?";
		cin >> a[i].fio;
		//a[i].fio = new char[256];
		//strcpy_s(a[i].fio, 255, fio);
		cout << "Adress # " << i << "?";
		cin >> a[i].adress;
		//a[i].adress = new char[256];
		//strcpy_s(a[i].adress, 255, adress);
		cout << "Phone number # " << i << "?";
		cin >> a[i].number;
		//a[i].number = new char[256];
		//strcpy_s(a[i].number, 255, number);
		cout << "Credit Card # " << i << "?";
		cin >> a[i].card;
		//a[i].card = new char[256];
		//strcpy_s(a[i].card, 255, card);
	}
	for (int i = 0; i < n; i++)
	{
		f << a[i].fio; f << "\t";
		f << a[i].adress; f << "\t";
		f << a[i].number; f << "\t";
		f << a[i].card; f << "\n";
	}
	f.close();//�������� ������
return  a;

}

void Read(int n)
{
	buyer p;//������� ������������ ������
	ifstream f;
	f.open("f.txt", ios::in);//��������������� �������� �����
	do
	{
		/*������ �������� ���� person �� ��������� ������ f � ���������� p*/
		f >> p.fio;
		f >> p.adress;
		f >> p.number;
		f >> p.card;
		// ���� ��������� ����� �����, ������� �� �����
		if (f.eof())break;
		//����� �� �����
		cout <<"FIO: " <<  p.fio << " Adress: "<< p.adress << " Phone Number: " << p.number << " Credit Card:" << p.card <<"\n";

	} while (!f.eof());
	f.close();//�������� ������
}
buyer* Modify_delete(int n, buyer* a, int j=0) {
	if (j > n) {
		cout << "Error";
		return a;
	}
	fstream f("f_delete.txt", ios::out);//��������������� �������� �����

	//char fio[255], adress[255], card[255], number[255];
	
	for (int i = j; i < n; i++)
	{
		f << a[i].fio; f << "\t";
		f << a[i].adress; f << "\t";
		f << a[i].number; f << "\t";
		f << a[i].card; f << "\t";
	}
	f.close();//�������� ������
	return  a;

}
buyer* Modify_add(int n, buyer* a, int k, int j) {

	fstream f("f_add.txt", ios::out);//��������������� �������� �����
	buyer* p;
	//k - ����� ���� ��������� �������
	//j - ���-�� ���������
	int jk = j + k;//����� �� ���� ��������� ��������
	int nj = j + n;//����� �� ���� ��������� �������� � ������
	p = new buyer[nj];//������� ������������ ������
	for (int i = 0; i < k; i++)//0,1
	{
		strcpy_s(p[i].fio,255,a[i].fio);
		strcpy_s(p[i].adress, 255, a[i].adress);
		strcpy_s(p[i].number, 255, a[i].number);
		strcpy_s(p[i].card, 255, a[i].card);
	}
	//char fio[255], adress[255], card[255], number[255];
	for (int i = k; i <  jk; i++)//2,3
	{
		cout << "Fio # " << i << "?";
		cin >> p[i].fio;
		//a[i].fio = new char[256];
		//strcpy_s(a[i].fio, 255, fio);
		cout << "Adress # " << i << "?";
		cin >> p[i].adress;
		//a[i].adress = new char[256];
		//strcpy_s(a[i].adress, 255, adress);
		cout << "Phone number # " << i << "?";
		cin >> p[i].number;
		//a[i].number = new char[256];
		//strcpy_s(a[i].number, 255, number);
		cout << "Credit Card # " << i << "?";
		cin >> p[i].card;
		//a[i].card = new char[256];
		//strcpy_s(a[i].card, 255, card);
	}
	for (int i = jk; i < nj; i++)//4
	{
		cout << "ckeck " << i << "?";
		strcpy_s(p[i].fio, 255, a[i-j].fio);
		strcpy_s(p[i].adress, 255, a[i-j].adress);
		strcpy_s(p[i].number, 255, a[i-j].number);
		strcpy_s(p[i].card, 255, a[i-j].card);
	}
	for (int i = 0; i < nj; i++)
	{
		f << p[i].fio; f << "\t";
		f << p[i].adress; f << "\t";
		f << p[i].number; f << "\t";
		f << p[i].card; f << "\n";
	}
	f.close();//�������� ������
	delete[] a;
	return  p;

}

int main() {
int n,k,j;
cout << "N?";
cin >> n;
buyer* a{};
do
{
	std::cout << "1.Forming file\n";
	std::cout << "2.Read file\n";
	std::cout << "3.Modify file\n";
	std::cout << "4.Add to file\n";
	std::cout << "5.Exit\n";
	std::cin >> k;
	switch (k)
	{
	case 1: a = Create(n); break;//��������� ������ � ����������
	case 2: Read(n); break;//������
	case 3: a = Modify_delete(n, a, 2); break;//��������
	case 4: a = Modify_add(n, a, 2,2); break;//����������
	}
} while (k != 5);//�����
delete[] a;
}