#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

struct student
{
	char* name;
	int kurs;
	float rating;
};
int s;

student* CreateOne(int n)
{
	student* a = new student[n];
	for (int i = 0; i < n; i++)
	{
		char Name[20];
		std::cout << "Name #"<< i << "?\n";
		std::cin >> Name;
		a[i].name=new char[strlen(Name)+1];
		strcpy_s(a[i].name,20, Name);
		std::cout << "Kurs #" << i << "?\n";
		std::cin >> a[i].kurs;
		std::cout << "Rating #" << i << "?\n";
		std::cin >> a[i].rating;
	}
	return a;
}
void PrintOne(student a[], int n) {
	std::cout << "\n Students:";
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n#" << i << ": ";
		std::cout << " Name:  "<< a[i].name;
		std::cout << " Kurs:"<< a[i].kurs;
		std::cout << " Rating:"<< a[i].rating;
	}
}
student* Search(student a[], int n) 
{

	student* b = new student[n];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].rating < 3)
		{
			b[j].name = a[i].name;
			b[j].kurs = a[i].kurs;
			b[j].rating = a[i].rating;
			j++;
		}
	}
	if (j == 0) {
	std::cout << "\n We not have Students with rating <3!";
	}
	else {
		std::cout << "\n Students with rating <3:";
		for (int i = 0; i < j; i++)
		{
			std::cout << "\n#" << i << ": ";
			std::cout << " Name:  " << b[i].name;
			std::cout << " Kurs:" << b[i].kurs;
			std::cout << " Rating:" << b[i].rating;
		}
		
	}
	return b;
	}
char** CreateArrayOfString() {
	std::cout << "\n Enter size : ";
	std::cin >> s;
	char** arr = new char* [s];
	for (int i = 0; i < s; i++) {
		char str [256];
		std::cout << "\nInput # " << i <<"string:";
		std::cin >> str;
		arr[i] = new char[strlen(str) + 1];
		strcpy_s(arr[i],255, str);
		}
	std::cout << "\nResult:";
	for (int i = 0; i < s; i++) {
		std::cout << "\n#" << i << "string:";
		std::cout << arr[i];
	}
	return arr;
}
char** ModifyArrayOfString(char** c) {
	int n;
	std::cout << "\n Enter number of string for delete : ";
	std::cin >> n;
	if (n > s) {
		std::cout << "\n ERROR. TOO MANY DELETED STRING";
	}
	else {

		int lengh = s - n;
		char** arr = new char* [lengh];
		for (int i = 0; i < lengh; i++) {
			arr[i] = new char[strlen(c[i]) + 1];
			strcpy_s(arr[i], 255, c[i]);
		}
		std::cout << "\nResult:";
		for (int i = 0; i < n; i++) {
			std::cout << "\n#" << i << "string:";
			std::cout << arr[i];
		}

		delete[] c;
		return arr;
	}
}
int main()
{
	int k,n;
	student* a{};
	student* b{};
	char** c{};
	std::cout << "\n Enter n : ";
	std::cin >> n;
	do
	{
		std::cout << "\n 1.Forming array\n";
		std::cout << "2.Print Array\n";
		std::cout << "3.Search\n";
		std::cout << "4.Create Array of sring\n";
		std::cout << "5.Modify Array of sring\n";
		std::cout << "6.Exit\n";
		std::cin >> k;
		switch (k)
		{
		case 1: a = CreateOne(n); break;//выделение памяти и заполнение
		case 2: PrintOne(a,n); break;//печать
		case 3: b = Search(a, n); break;//поиск
		case 4: c = CreateArrayOfString(); break;//создание
		case 5: c = ModifyArrayOfString(c); break;//изменение
		}
	} while (k != 6);//выход
	delete[] a;
	delete[] b;
	delete[] c;
}