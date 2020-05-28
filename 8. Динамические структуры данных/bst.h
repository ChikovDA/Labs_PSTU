/*
	*	.h file that just creates a basic BST to be used for our programs
	*	Returns a pair containing the root and the height of the tree
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
#define inf INT_MAX
#define _inf INT_MIN

int next_pos[100] = { 0 };							//next available position for each level, initialized with 0
//Structure of node
struct Node {
	char data;
	int x, y;						//x and y coordinates, y also stores the height of the node
	int modifier;					//amount of shift for the subtree
	bool searched;
	struct Node* left, * right;		//left and right subtrees
};
struct Node* process(struct Node* root) {
	struct Node* left = root->left, * right = root->right;
	int height = root->y, prov_pos = _inf, actual_pos, modifier = 0;

	if (left == NULL && right == NULL) {				//if leaf node actual will simply be the 1st available pos on its level
		actual_pos = next_pos[height];
		modifier = 0;
	}
	else if (left == NULL || right == NULL) {			//only one child
		if (left == NULL) {							//only right child
			right = process(right);
			prov_pos = right->x - 1;
		}
		else {										//only left child
			left = process(left);
			prov_pos = left->x + 1;
		}
		actual_pos = max(prov_pos, next_pos[height]);
		if (next_pos[height] > prov_pos) modifier = next_pos[height] - prov_pos;
	}
	else {											//if both children present
		left = process(left);
		right = process(right);
		prov_pos = (left->x + right->x) / 2;
		actual_pos = max(prov_pos, next_pos[height]);
		if (next_pos[height] > prov_pos) modifier = next_pos[height] - prov_pos;
	}

	next_pos[height] = actual_pos + 2;				//incrementing next available position on this level
	root->x = actual_pos;
	root->modifier = modifier;
	return root;
}

//Does the approprite shifting of the subtrees based on modifier
struct Node* modify(struct Node* root, int shft) {
	if (root == NULL) return NULL;
	root->x = root->x + shft;						//shift towards right
	root->left = modify(root->left, shft + root->modifier);
	root->right = modify(root->right, shft + root->modifier);
	return root;
}
int search(struct Node* root, char key, int c) {
	if (root) {
		if (root->data == key)
		{
			root->searched = 1;
			c++;
		}
		else
		root->searched = 0;
	c=search(root->left, key, c);
	c=search(root->right, key, c);
	}
	return c;
}

void main_search(struct Node* root) {
	std::cout << "\n Enter element for search : ";
	char h;
	std::cin >> h;
	int j = search(root, h, 0);
	std::cout << "Elementov '" << h << "' in Tree: " << j;
}

//Inorder traversal of tree
void inorder(struct Node* root) {
	//Inorder traversal of tree
	if (root == NULL) return;
	inorder(root->left);
	printf("data=%d, x=%d, y=%d, modifier=%d, searched=%d\n", root->data, root->x, root->y, root->modifier, root->searched);
	inorder(root->right);
}
//Creates a new node and returns it
struct Node* getNode(char val, int height) {
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->data = val;
	root->searched = 1;
	root->x = root->modifier = 0;
	root->y = height;
	root->left = root->right = NULL;
	return root;
}

//Insert node into BST
struct Node* Insert(struct Node* root, int height, int n) {
	int nl, nr;
    char data;
	if (n == 0) { root = NULL; return root; }
	nl = n / 2;
	nr = n - nl - 1;
	std::cout << "?";
	std::cin >> data;
	if (root == NULL)
		root = getNode(data, height);
	root->left = Insert(root->left, height + 1, nl);
	root->right = Insert(root->right, height + 1, nr);
	return root;

}


int findHeight(struct Node* root) {
	if (root == NULL) return 0;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

//Creates a binary tree and returns its root and height
pair<struct Node*, int> bst_init() {
	struct Node* root = NULL;
	int n;	//insert all elements in BST
	std::cout << "\n Enter n for Tree : ";
	std::cin >> n;
	root = Insert(root, 0, n);
	int height = findHeight(root);
	pair<struct Node*, int> p = make_pair(root, height);
	return p;
}

void Forming_tree(pair<struct Node*, int> p, struct Node* root, int height)
{
	p = bst_init();
	root = p.first;
	height = p.second;
	root = process(root);							//assign coordinates
	root = modify(root, 0);							//shift based on modifier
	inorder(root);
}