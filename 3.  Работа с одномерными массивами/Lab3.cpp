#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	const int MAX_SIZE = 100;
	std::srand(std::time(nullptr));
	int n, i, k, a[MAX_SIZE] , b[MAX_SIZE], j = 0;
	std::cout << "\n Enter n : ";
	std::cin >> n;
	std::cout << "\n Array : ";
	//create and view array:
	for (i = 0; i < n; i++) {
		a[i] = std::rand() %100-50;
		std::cout << a[i] << "; ";
	}
    //delete elements:
	std::cout << "\n Array after delete: ";
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {  //”дал€ютс€ четные элементы, т.к. индекс массива начинаетс€ с нул€ 
			b[j] = a[i];
			std::cout << b[j] << "; ";
			j++;
			}
	}
	//insert a[k] in a[]
	std::cout << "\n Enter k, k<" << n << ":";
	std::cin >> k;
	k--;
	int* c = new int[n+1];
	std::cout << "\n Array after insert: ";
	for (i = 0; i < k; i++) {
		c[i] = a[i];
		std::cout << c[i] << "; ";
	}
	c[k] = std::rand() % 100 - 50;
	for (i = k+1; i < n+1; i++) {
		c[i] = a[i];
		std::cout << c[i] << "; ";
	}
	//transposition array
	std::cout << "\n Array after transposition: ";
	int aa[MAX_SIZE];
	j = n-1;
	for (i = 0; (i < n); i++) {
		aa[j] = a[i];
		--j;

	}
	for (i = 0; (i < n); i++) {
		std::cout << aa[i] << "; ";
	}
	//Search Mean
	int sum = 0;
	for (i = 0; (i < n); i++) {
		sum = sum + a[i];
	}
	int mean;
	mean = sum / n;
	j = 0;
	std::cout << "\n Average elemnt:" << mean << "; ";
	for (i = 0; (i < n); i++)
	{
		if (mean==a[i])
			{
			std::cout << "\n Number of Average element:" << i << "; ";
			i = n;
			}
		j++;
	}
	std::cout << "\n Count compare:" << j << "; ";
	//Sorting
	int min, n_min;
	for (i = 0; (i < n); i++)
	{
		min = a[i];
		n_min = i;
		for (j = i + 1; j < n; j++) 
		{
			if (a[j] < min)
			{
				min = a[j];
				n_min = j;
			}
		}
		a[n_min] = a[i];//обмен
		a[i] = min;
	}
	std::cout << "\n Array after sorting:";
	for (i = 0; (i < n); i++)
	{
		std::cout << a[i] << "; ";
	}
	j = 0;
	int l = n / 2;
	for (i = l - 1; (i < l + 1); i++)
	{
		if (mean == a[i])
		{
			std::cout << "\n Number of Average element:" << i << "; ";
			i = n;
		}
		j++;
	}
	std::cout << "\n Count compare with sorted array:" << j << "; ";
	}