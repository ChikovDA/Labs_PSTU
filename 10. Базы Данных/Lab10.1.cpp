#include <stdio.h>
#include <fstream> 
#include <algorithm>
using namespace std;
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>

struct student
{
	char group[255];
	char fio[255];
	int index;
};
std::string filepath("C:/Users/blooo/source/repos/Labs/Release/DB/");



student* Add_to_end(int n) { //функция создания файлов групп
	student* a;
	list<const char*>::iterator it;
	a = new student[n];//создаем динамический массив
	for (int i = 0; i < n; i++)
	{
		cout << "Fio # " << i << "?";
		cin >> a[i].fio;
		cout << "Group # " << i << "?";
		cin >> a[i].group;
		std::string filename = filepath + a[i].group;
		std::ifstream file_in(filename);
		int i_number_line_now = 0; //счётчик строк
		std::string line; //для хранения строки
		std::string line_file_text; //для хранения текста файла
		while (getline(file_in, line))
		{
			i_number_line_now++;
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
				/*добавить перенос на слудующую строку*/
				line_file_text.insert(line_file_text.size(), "\r\n");
		}
		file_in.close();

		fstream f(filename, ios::app);//двунаправленный файловый поток с установкой указателя в конец файла
		f << a[i].fio; f << "\t";
		f << a[i].group; f << "\t";
		f << "index:"; f << i_number_line_now; f << "\n";
		f.close();//закрытие потока
		std::string filename2 = filepath + "main.txt";
		ifstream file(filename2);
		istream_iterator<string> eof;
		bool found = find(istream_iterator<string>(file), eof, a[i].group) != eof;
		if (!found)
		{
			fstream f(filename2, ios::app);//двунаправленный файловый поток с установкой указателя в конец файла
			f << a[i].group; f << "\n";
			f.close();//закрытие потока
		}
	}
	return  a;
}

void Add_to_file(int n) { //функция создания файлов групп
	
	std::vector<std::string> vec;
	int index, i_number_line_now=0;
	std::string add, fio, group; //для хранения текста изменения
	cout << "New Fio :";
	cin >> fio;
	cout << "New Group: ";
	cin >> group;
	cout << "New Index: ";
	cin >> index;
	std::string filename = filepath + group;
	std::ifstream file_in(filename);
	if (!file_in)
	{
		std::cerr << "Error. Can't open file" << std::endl;
	}



	std::string line; //для хранения строки
	std::string line_file_text; //для хранения текста файла


	while (getline(file_in, line))
	{
		add = fio + "\t" + group + "\t" + "index:" + to_string(i_number_line_now);
		if (!(i_number_line_now == n))
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");

		}
		else {
			line_file_text.insert(line_file_text.size(), add);
			line_file_text.insert(line_file_text.size(), "\r\n");
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");

		}
		i_number_line_now++;
	}

	file_in.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	std::ofstream file_out;

	file_out.open(filename, std::ios::trunc | std::ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
	std::string filename2 = filepath + "main.txt";
	ifstream file(filename2);
	istream_iterator<string> eof;
	bool found = find(istream_iterator<string>(file), eof, group) != eof;
	if (!found)
	{
		fstream f(filename2, ios::app);//двунаправленный файловый поток с установкой указателя в конец файла
		f << group; f << "\n";
		f.close();//закрытие потока
	}
}
void Add()
{
	int n,k,j;
	cout << "Enter count students to add";
	cin >> n;
	student* a = new student[n];
	do
	{
		std::cout << "1.Add to end\n";
		std::cout << "2.Add to i place\n";
		std::cout << "3.Add to 1 place\n";
		std::cout << "4.Exit\n";
		std::cin >> k;
		switch (k)
		{
		case 1:	a = Add_to_end(n); break;
		case 2: 	for (int i = 0; i < n; i++)
		{
			cout << "Enter place";
			cin >> j;
			Add_to_file(j);

		}
			  break;
		case 3: 	for (int i = 0; i < n; i++)	Add_to_file(0); break;
		}
	} while (k != 4);//выход


}
void Read_group()
{
	std::string filename = filepath + "main.txt";
	std::string line;
	ifstream f;

	f.open(filename, ios::in);//двунаправленный файловый поток
	if (f.is_open()) 
		cout << "List of Group:" << std::endl;
		{
			while (getline(f, line))
			{
				cout << line << std::endl;
			}
		}
		cout << std::endl;
		f.close();//закрытие потока

}

void Read_students()
{

	std::string line,students;
	cout << "Enter Group?";
	cin >> line;
	std::string filename = filepath + line;
	ifstream f;

	f.open(filename, ios::in);//двунаправленный файловый поток
	if (f.is_open()){
		cout << "List of Students who state in " << line << " group:" << std::endl;
	{
		while (getline(f, students))
		{
			cout << students << std::endl;
		}
	}
	cout << std::endl;
	f.close();//закрытие потока
}
	else
		cout << "Error! Same group not exist" << std::endl;
}
int search_line(string filename, string line_search) //процедура для окончательного удаления строк
{
	std::vector<std::string> vec;
	std::ifstream file_in(filename);
	if (!file_in)
	{
		std::cerr << "Error. Can't open file" << std::endl;
	}

	int i_number_line_now = 0; //счётчик строк
	int searched_line=0;
	std::string line; //для хранения строки
	std::string line_file_text; //для хранения текста файла

	while (getline(file_in, line))
	{
		i_number_line_now++;
		int check = line.find(line_search);
		if (check == -1)
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
		else
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
            /*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");
			searched_line =  i_number_line_now;
		}
	}

	file_in.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	std::ofstream file_out;

	file_out.open(filename, std::ios::trunc | std::ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
	return searched_line;
}
string remove_line(string filename, int i_number_line_delete) //процедура для окончательного удаления строк
{
	std::vector<std::string> vec;
	std::ifstream file_in(filename);
	if (!file_in)
	{
		std::cerr << "Error. Can't open file" << std::endl;
	}

	int i_number_line_now = 0; //счётчик строк
	std::string line; //для хранения строки
	std::string line_file_text; //для хранения текста файла
	std::string last; //для хранения удаляемой строки

	while (getline(file_in, line))
	{
		i_number_line_now++;

		if (!(i_number_line_now == i_number_line_delete))
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");

		}
		else last = line;
	}

	file_in.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	std::ofstream file_out;

	file_out.open(filename, std::ios::trunc | std::ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
	return last;
}

void modify_line(string filename, int i_number_line) //процедура для окончательного удаления строк
{
	std::vector<std::string> vec;
	std::ifstream file_in(filename);
	std::string change,fio,group; //для хранения текста изменения
	int index;
	if (!file_in)
	{
		std::cerr << "Error. Can't open file" << std::endl;
	}
	cout << "New Fio :";
	cin >> fio;
	cout << "New Group: " ;
	cin >> group;
	cout << "New Index: ";
	cin >> index;
	change = fio + "\t" + group + "\t" + "index:" + to_string(index);

	int i_number_line_now = 0; //счётчик строк
	std::string line; //для хранения строки
	std::string line_file_text; //для хранения текста файла


	while (getline(file_in, line))
	{
		i_number_line_now++;

		if (!(i_number_line_now == i_number_line))
		{
			line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");

		}
		else {
			line_file_text.insert(line_file_text.size(), change); /*дабавить строку*/
			/*добавить перенос на слудующую строку*/
			line_file_text.insert(line_file_text.size(), "\r\n");
		}
	}

	file_in.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	std::ofstream file_out;

	file_out.open(filename, std::ios::trunc | std::ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();
}
void remove_students() { //процедура для поиска строк для удаления
	int k,n;
	std::string line, students,fio, last;
	do
	{
		std::cout << "1.Delete students with FIO\n";
		std::cout << "2.Delete students with num\n";
		std::cout << "3.Revert last delete\n";
		std::cout << "4.Main menu\n";
		std::cin >> k;
		switch (k)
		{
		case 1: 
			cout << "Enter Group?";
			cin >> line;
			cout << "Enter FIO?";
			cin >> fio;
			students = filepath + line;
			n = search_line(students, fio);
			last = remove_line(students, n);
			break;
		case 2: 
			cout << "Enter Group?";
			cin >> line;
			cout << "Enter num?";
			cin >> n;
			students = filepath + line;
			last = remove_line(students, n);
			break;
		}
	} while (k != 4);//выход
}

void modify_students() { //процедура для поиска строк для удаления
	int k, n;
	std::string line, students, fio, last;
	do
	{
		std::cout << "1.Modify students with FIO\n";
		std::cout << "2.Modify students with num\n";
		std::cout << "3.Main menu\n";
		std::cin >> k;
		switch (k)
		{
		case 1:
			cout << "Enter Group?";
			cin >> line;
			cout << "Enter FIO?";
			cin >> fio;
			students = filepath + line;
			n = search_line(students, fio);
			modify_line(students, n);
			break;
		case 2:
			cout << "Enter Group?";
			cin >> line;
			cout << "Enter num?";
			cin >> n;
			students = filepath + line;
			modify_line(students, n);
			break;
		}
	} while (k != 3);//выход
}

void Create_sum() {
	std::string filename = filepath + "main.txt";
	std::string filename3 = filepath + "summary.txt";
	int index, i_number_line_now = 0;
	std::string group, line, line_file_text; //для хранения текста изменения
	ifstream f(filename, ios::in);
	istream_iterator<string> eof;
	//открыли файл со списком групп для чтения
	while (getline(f, group))
	{
	std::string filename2 = filepath + group;
	ifstream file_in(filename2, ios::in);
	//открыли файл со списком студентов для чтения
	while (getline(file_in, line))
	{
	line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
	/*добавить перенос на слудующую строку*/
	line_file_text.insert(line_file_text.size(), "\r\n");
	}
	file_in.close();
	//закрыли файл со студентами, в переменной line_file_text теперь весь файл
	std::ofstream file_out;
	file_out.open(filename3, ios::app | ios::binary); //открыть
	file_out.write(line_file_text.c_str(), line_file_text.size());//записать
	file_out.clear();
	line_file_text.clear();
	}	
	f.close();//закрытие потока
}

int main() {
	int k;
	do
	{
		std::cout << "0.Create Summary file\n";
		std::cout << "1.Add students file\n";
		std::cout << "2.List of Group\n";
		std::cout << "3.List of Students\n";
		std::cout << "4.Delete student\n";
		std::cout << "5.Modify_students\n";
		std::cout << "6.Exit\n";
		std::cin >> k;
		switch (k)
		{
		case 0: Create_sum(); break;//Добавление студентов в файлы
		case 1: Add(); break;//Добавление студентов в файлы
		case 2: Read_group(); break;//Просмотр групп
		case 3: Read_students(); break;//Просмотр студентов
		case 4: remove_students(); break;//Удаление студентов
		case 5:	modify_students(); break;//Изменение студентов
				}
	} while (k != 6);//выход
}