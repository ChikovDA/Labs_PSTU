// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <iostream>
#include <ctime>


int n,nn,mm;

int* CreateOne(int n)
{
	int* a = new int[n];
	std::srand(std::time(nullptr));
	std::cout << "\n New one-dimensional Array Formed!";
	for (int i = 0; i < n; i++)
	{
		a[i] = std::rand() % 100 - 50;
	}
	return a;
}
int** CreateTwo(int n)
{
	nn = n;
	mm = n;
	int** b;
	b = new int* [nn];
	for (int i = 0; i < nn; i++) {
		b[i] = new int[mm];
	}
	std::cout << "\n New two-dimensional Array Formed!";
	std::srand(std::time(nullptr));
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < mm; j++)
		{
			b[i][j] = std::rand() % 100 - 50;
		}
	}
	return b;
}

void PrintOne(int a[]) {
	int n = _msize(a) / sizeof(int);
	std::cout << "\n New one-dimensional Array:";
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << "; ";
	}
}
void PrintTwo(int** b) {
	std::cout << "\n New two-dimensional Array: \n";
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < mm; j++)
		{
		std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int* DeleteFromOne(int* a, int n) {
	div_t divresult = div(n,2);
	int l = divresult.quot, j=0;
	int* result = new int[l];
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0) {
			result[j] = a[i];
			j++;
		}
	}
	delete[] a;
	a = nullptr;
	return result;
}

int** AddToTwo(int** b) {
	int K;
	std::cout << "\n Enter K : ";
	std::cin >> K;
	mm = n + K;
	int** result;
	result = new int* [nn];
	for (int i = 0; i < nn; i++) {
		result[i] = new int[mm];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = b[i][j];
		}
	}
	for (int i = 0; i < nn; i++)
	{
		for (int j = K-1; j < mm; j++)
		{
			result[i][j] = std::rand() % 100 - 50;
		}
	}
	delete[] b;
	return result;

}

int main()
{
	int k;
	int* a{};
	int** b{};
	std::cout << "\n Enter n : ";
	std::cin >> n;
	do
	{
		std::cout << "1.Forming array\n";
		std::cout << "2.Pront Array\n";
		std::cout << "3.Delete from Array\n";
		std::cout << "4.Add to Array\n";
		std::cout << "5.Exit\n";
		std::cin >> k;
		switch (k)
		{
		case 1: a = CreateOne(n); b = CreateTwo(n); break;//выделение памяти и заполнение
		case 2: PrintOne(a); PrintTwo(b); break;//печать
		case 3: a= DeleteFromOne(a, n); break;//удаление
		case 4: b=AddToTwo(b); break;//добавление
		}
	}
	while (k != 5);//выход
	delete[] a;
	delete[] b;
	}