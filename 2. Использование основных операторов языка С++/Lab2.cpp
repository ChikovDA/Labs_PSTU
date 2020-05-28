#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
	int n, i, num,x;
	double min,max,s;
#pragma region Task1


	std::cout << "\n Task 1 ";
	std::cout << "\n Enter n : ";
	std::cin >> n;
	std::cout << "\n Enter n symbols : ";
	std::cin >> x;
	min = x;
	num = 1;
	for (i = 1; i < n; i++) {
		std::cin >> x;
		if (min > x) {
			min = x;
			num = i + 1;
		}

	}
	std::cout << "\n Min value : " << min << "  Min place" << num;

#pragma endregion
#pragma region Task2
	std::cout << "\n Task 2 ";
	int min2,max2;
	std::cout << "\n Enter symbol, 0 will be end : ";
	std::cin >> x;
	min2 = x;
	max2 = x;
	do {
		if (min2 > x) {
			min2 = x;
		}
		if (max2 < x) {
			max2 = x;
		}
		std::cin >> x;
	} while (x != 0);
	std::cout << "\n Min value+Max Value : " << min2+max2;
#pragma endregion

#pragma region Task3
	std::cout << "\n Task 3 ";
	std::cout << "\n Enter n, n>3 : ";
	std::cin >> n;
	i = 1;
	while (i <= n) {
	std::cout << "sin(" << i << "x";
	if ((i+1) % 3 == 0) {
		std::cout << "-";
	}
	else {
		std::cout << "+";
	}
	i++;
	std::cout << "cos(" << i << "x";
	if ((i+1) % 3 == 0) {
		std::cout << "-";
	}
	else {
		std::cout << "+";
	}
	i++;
		}
	std::cout << "...)...)";
#pragma endregion
}
