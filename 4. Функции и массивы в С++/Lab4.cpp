#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

int n, i,m;

void CreateOne(int a[])
{
	std::srand(std::time(nullptr));
	std::cout << "\n New Array:";
	for (i = 0; i < n; i++) 
	{
		a[i] = std::rand() % 100 - 50;
		std::cout << a[i] << "; ";
	}
}
void ChangeOne(int a[])
{
	std::cout << "\n Array after change:";
	int* temp = new int[n];
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			temp[j] = a[i];
			j++;
		}
		
	}
	for (i = 0; i < j; i++)
	{
		std::cout << temp[i] << "; ";
	}

}

int** CreateTwo(int nn, int mm)
{
	int** b;
	b = new int* [nn]; 
	for (int i = 0; i < nn; i++) {
		b[i] = new int[mm];
	}
	return b;
}
void initialize(int** b, int nn, int mm)
{
	std::cout << "\n New Array:" << "\n";
	srand(time(0));
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < mm; j++)
		{
			b[i][j] = std::rand() % 100 - 50;
			std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void ChangeTwo(int** b, int nn, int mm)
{
	int min, n_min,j,c;
	std::cout << "\n Array after change:";
	for (i = 0; (i < mm); i++)
	{
			min = b[0][i];
			n_min = i;
			for (j = i + 1; j < mm; j++)
			{
				if (b[0][j] < min)
				{
					min = b[0][j];
					n_min = j;
				}
			}
			b[0][n_min] = b[0][i];
			b[0][i] = min;
			for (c = 1; (c < nn); c++)
			{
				int temp = b[c][n_min];
				b[c][n_min] = b[c][i];
				b[c][i] = temp;
	        }
	}
	for (i = 0; i < nn; i++)
	{
		for (j = 0; j < mm; j++)
		{
			std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}

}

char* CreateChar(int l) {
	char* s = new char[l+1];
	std::cin >>
	gets_s(s,l);
	printf("The line entered was: \n");
	puts(s);
	return s;
}

int isvowel(char chr)
{
	char vowels[] = "aeiouy";//Перечисляем все гласные
	//узнаём длинну строки vowels
	long i, len = sizeof(vowels) / sizeof(vowels[0]);
	if (isupper(chr))//Для упрощения опускаем chr в нижний регистр
		chr = tolower(chr);
	for (i = 0; i < len; i++)
	{
		if (chr == vowels[i])
			break;
	}
	return len - i;
}
void ChangeChar(char* s,int l) {
	for (int i = 0, j; i < strlen(s); i++)
	{
		if (isvowel(s[i]))//Символ гласная
		{
			if (i + 1 < strlen(s))
			{
				//Если символ не последняя буква строки
				//копируем на место i символы после него
				for (j = i; j < strlen(s) - 1; j++)
					s[j] = s[j + 1];
				s[j] = '\0';//Т.к. это не strcpy а из строки выкинули 1 символ, 
				//то и уменьшим на символ саму строку
				i--;//Возвращаемся т.к. на i-ой позиции уже i + 1 символ
			}
			else//Если символ не последняя буква строки
				s[i] = '\0';//просто обрезаем строку
		}
	}
	printf("The line after deleting: \n");
	puts(s);
		}


int main()
{
	std::cout << "\n Enter n : ";
	std::cin >> n;
	int* a = new int[n];
	int** b;
	char* s;
	CreateOne(a);
	ChangeOne(a);
	std::cout << "\n Enter n : ";
	std::cin >> n;
	std::cout << "\n Enter m : ";
	std::cin >> m;
	b = CreateTwo(n,m);
	initialize(b, n, m);
	ChangeTwo(b, n, m);
	std::cout << "\n Enter lengh for strings : ";
	std::cin >> n;
	s = CreateChar(n);
	ChangeChar(s,n);
	}




