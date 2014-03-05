/*************************************************************************
	> File Name: test.cpp
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月03日 星期一 19时22分36秒
 ************************************************************************/

#include <string>

#include "BinaryTree.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

void createTree (BinaryTree<int>::node_type *p) 
{ 
	int		val; 
	BinaryTree<int>::node_type *q; 

	cout << "val (" << p->data << " = left) : "; 
	cin >> val; 
	if (val) {
        q = BinaryTree<int>::InsertNode (
				p, val, BinaryTree<int>::left_child); 
	    createTree (q); 
    } 

	cout << "val (" << p->data << " = right) : "; 
	cin >> val; 
	if (val) { 
        q = BinaryTree<int>::InsertNode (
				p, val, BinaryTree<int>::right_child); 
	    createTree (q); 
    }
} 

int main (void)
{ 
	BinaryTree<int>		tree (1); 

	int		t, i;
	BinaryTree<int>::node_type	*p = tree.root ();
	createTree (p);

	tree.PrintBiTree (cout); 

	return 0;
} 
