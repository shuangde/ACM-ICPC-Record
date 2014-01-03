/*

	Red-Black Tree
	Author: shuangde 
	mail: zengshuangde@gmail.com
	参考：算法导论
	2014.1.4
*/

/*
红黑树性质：
   1. 每个结点是红的，或是黑的
   2. 根结点是黑色的
   3. 每个叶结点(NIL)是黑的
   4. 如果一个结点是红的，则它的两个儿子都是黑的
   5. 对每个结点，从该结点到其子孙结点的所有路径上包含相同数目的黑结点
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <set>
// 生成0~x-1
#define random(x) (rand()%x)
using namespace std;
typedef int KeyType;

enum Color{ 
	RED, 
	BLACK 
};

struct Node {
	KeyType key;
	Color color;
	Node *left, *right, *parent;
};
typedef Node* RBTree;

// 哨兵结点
static Node nilNode = (Node){KeyType(0),BLACK,NULL,NULL,NULL}; 
static Node * nil = &nilNode;


// 新建一个结点，颜色为红色
Node* createNode(KeyType e) {
	Node *t = new Node();
	t->key = e;
	t->color = RED;
	t->left = t->right = t->parent = nil;
	return t;
}

// 释放一个结点的内存
void freeNode(Node *node) {
	if (node != nil)
		delete node;
}

// 初始化一颗红黑树, T是根结点
void initRBTree(RBTree& T) {
	T = nil;
}

// 中序遍历红黑树
void inOrderTreeWalk(RBTree &T) {
	if (T != nil) {
		inOrderTreeWalk(T->left);	
		cout << T->key << " ";
		inOrderTreeWalk(T->right);
	}
}

// 在树T中查找键值为k的结点
Node* treeSearch(RBTree &T, KeyType k) {
	Node *x = T;
	while (x != nil && k != x->key) {
		if (k < x->key) x = x->left;
		else x = x->right;
	}
	return x;
}

// 返回x子树的最小结点
Node* treeMinimum(Node *x) {
	while (x->left != nil)
		x = x->left;
	return x;
}

// 查找中序遍历下x的后继结点
Node* treeSuccessor(Node *x) {
	if (x->right != nil)
		return treeMinimum(x->right);
	Node *y = x->parent;
	while (y != nil && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

// 左旋
void leftRotate(RBTree &T, Node *x) {
	Node *y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == nil) 
		T = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

// 右旋
void rightRotate(RBTree &T, Node *x) {
	Node *y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		T = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;
}


void RBInsertFixup(RBTree &T, Node *z) {
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			Node *y = z->parent->parent->right;	
			if (y->color == RED) { // Case 1
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right){ // Case 2
					z = z->parent;
					leftRotate(T, z);
				}
				z->parent->color = BLACK; // Case 3
				z->parent->parent->color = RED;
				rightRotate(T, z->parent->parent);
			}
		} else {
			Node *y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z = z->parent->parent;
				z->color = RED;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					rightRotate(T, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(T, z->parent->parent);
			}
		}
	}
	T->color = BLACK;
}

// 插入
Node* RBInsert(RBTree &T, KeyType k) {
	Node *y = nil; // y是插入位置的父结点
	Node *x = T;   // x是插入的位置
	Node *z = createNode(k); // z是插入的新结点
	while (x != nil) {
		y = x;
		if (k < x->key) 
			x = x->left;	
		else
			x = x->right;
	}
	z->parent = y;
	if (y == nil) 
		T = z;
	else if (k < y->key)
		y->left = z;
	else 
		y->right = z;
	RBInsertFixup(T, z);
	return z;
}

void RBDeleteFixUp(RBTree &T, Node *x) {
	while (x != T && x->color == BLACK) {
		if (x == x->parent->left) {

			Node * w = x->parent->right;
			// Case 1
			if (w->color == RED) {
				w->color = BLACK;	
				x->parent->color = RED;
				leftRotate(T, x->parent);
				w = x->parent->right;
			}
			// Case 2
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				// Case 3
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(T, w);
					w = x->parent->right;
				}
				// Case 4
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(T, x->parent);
				x = T;
			} 

		} else {
			Node *w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(T, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(T, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(T, x->parent);
				x = T;
			}
		}
	}
	x->color = BLACK;
}

void RBDelete(RBTree &T, Node *z) {

	if (z == nil) return;
	// y是真正要删除的点
	Node *x, *y;

	if (z->left == nil || z->right == nil) y = z;
	else y = treeSuccessor(z);

	if (y->left != nil) x = y->left;
	else x = y->right;

	x->parent = y->parent;

	if (y->parent == nil)
		T = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != z)
		z->key = y->key;
	if (y->color == BLACK)
		RBDeleteFixUp(T, x);
	freeNode(y);
}


int main () {

	RBTree T;
	initRBTree(T);
	for (int i = 0; i < 100; ++i) {
		int tmp = random(10000);	
		RBInsert(T, tmp);
	}
	inOrderTreeWalk(T);
	return 0;
}

