/*
	*	Implementation of Tidy Drawings of Trees by CHARLES WETHERELL AND ALFRED SHANNON (Algorithm3)
	*	INPUT: root and height of an already constructed binary tree, calling bst_init from bst.h file
	*	OUTPUT: Drawing of the tree in OpenGL
	*
	*	This file does the intermediate processing of finding the coordinates of center of each node.
	*	These coordinates are then passed to draw.h which then draws the tree using midpoint line and circle algos in openGL
	*
	*	Compilation: g++ main.cpp -lglut -lGL -lGLU
*/

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <csetjmp>

#include "Point.h"
#include "bst.h"									//constructing a sample binary tree
#include "draw.h"									//draw the tree
using namespace std;
static jmp_buf env;
int main(int argc, char* argv[]) {
	pair<struct Node*, int> p;			//pair that stores the root and height of the tree;
	struct Node* root{};                    //root of the tree
	int height;                          //height of the tree
	int n, k = 0;
	char s;
	point* a{};
	point2* b{};
	do
{
		std::cout << "\n 1.Forming list\n";
		std::cout << "2.Print list\n";
		std::cout << "3.Add element to list\n";
		std::cout << "4.Forming 2way list\n";
		std::cout << "5.Print 2way list\n";
		std::cout << "6.Delete element from 2way list\n";
		std::cout << "7.Forming Tree\n";
		std::cout << "8.Print Tree\n";
		std::cout << "9.Search in Tree\n";
		std::cout << "10.Exit\n";
		std::cin >> k;
		switch (k)
		{
		case 1: 
			std::cout << "\n Enter n for list: ";
			std::cin >> n;
			a = make_list(n); break;//выделение памяти и заполнение
		case 2: print_list(a); break;//печать
		case 3:
			for (int i = 0; i <= n; i++) {
				if (i % 2 == 0)
				{
					a = add_point(a, i);
					n++;
				}
			}
			break;
		case 4:
			std::cout << "\n Enter n for 2 way list: ";
			std::cin >> n;
			b = make_list2(n); break;
		case 5: print_list(b); break;
		case 6: popBack(b); break;
		case 7: 
			p = bst_init();
			root = p.first;
			height = p.second;
			root = process(root);							//assign coordinates
			root = modify(root, 0);							//shift based on modifier
			inorder(root); break;
		case 8: draw_main(root, height, argc, argv); break;			//draw tree, function in draw.h break;
		case 9:	main_search(root); break;
		}
		} while (k != 10);//выход
		delete[] a;
		delete[] b;
return 0;
}
