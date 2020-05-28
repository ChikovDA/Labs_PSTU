#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    bool j;
    double y,x,z,a,b,n,m;
    float a1, b1,z1,r;


#pragma region Task1

    std::cout << "\n Task 1 ";
    std::cout << "\n Enter n : ";
    std::cin >> n;
    std::cout << "\n Enter m : ";
    std::cin >> m;
    r = n / m++;
    std::cout << "\n m=" << m << " n=" << n << "   n/m++=" << r;
   
    std::cout << "\n Enter n : ";
    std::cin >> n;
    std::cout << "\n Enter m : ";
    std::cin >> m;
    j = m++ < --n;
    std::cout << "\n m=" << m << " n=" << n << "   m++<--n=" << j;
    
    std::cout << "\n Enter n : ";
    std::cin >> n;
    std::cout << "\n Enter m : ";
    std::cin >> m;
    j = (m/n) < n/m;
    std::cout << "\n m=" << m << " n=" << n << "   (m/n)++ < n/m" << j;

    std::cout << "\n Enter X : ";
    std::cin >> x;
    y = pow(abs(pow(x, 3) - 1), 1.0 / 2)-7 * cos(pow(pow(x, 4) + x, 1.0 / 3));
 std::cout << "\n Y :" << y;

#pragma endregion

#pragma region Task2
 std::cout << "\n Task 2 ";
 std::cout << "\n Enter X : ";
 std::cin >> x;
 std::cout << "\n Enter Y : ";
 std::cin >> y;
 if (x <= 0) {
     if (pow(x, 2) + pow(y, 2) <= 4)
     {
         std::cout << "\n TRUE";
     }
     else {
         std::cout << "\n ELSE ";
     }
 }
 else if (y>=0){
     if (y <= (-x + 2)) {
         std::cout << "\n TRUE";
     }
     else {
         std::cout << "\n ELSE ";
          }
 }
 else if (y < 0) {
     if (y >= x - 2) {
         std::cout << "\n TRUE";
     }
     else {
         std::cout << "\n ELSE ";
     }
 }


#pragma endregion

#pragma region Task3
 std::cout << "\n Task 3" << y;
 a = 100;
 b = 0.001;
 a1 = 100;
 b1 = 0.001;
 z = (pow(a + b, 3) - pow(a, 3)) / (pow(b, 3) + 3 * a * b * b + 3 * a * a * b);
 z1 = (pow(a1 + b1, 3) - pow(a1, 3)) / (pow(b1, 3) + 3 * a1 * b1 * b1 + 3 * a1 * a1 * b1);
 std::cout << "\n For double: " << z;
 std::cout << "\n For float: " << z1;
#pragma endregion

}