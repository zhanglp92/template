/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月05日 星期三 15时04分40秒
 ************************************************************************/

#ifndef _BINARYTREE_CPP_ 
#define _BINARYTREE_CPP_ 

template <class T>
bool BinaryTree<T>::DeleteChild (BinaryTree<T>::BiTree p, int i) 
{
    if (i == left_child) 
        return DeleteChildTree (p->LChild);
    else if (i == right_child) 
        return DeleteChildTree (p->RChild);
    return false; 
}

template <class T>
typename BinaryTree<T>::BiTree BinaryTree<T>::NextSibling (const BinaryTree<T>::BiTree x) 
{
    if (tree_empty ()) return NULL; 
    if (x->parent && x->parent->LChild == x) 
        return x->parent->RChild;
    return NULL; 
}

template <class T>
typename BinaryTree<T>::BiTree BinaryTree<T>::parent (const BinaryTree<T>::BiNode &x) 
{ 
    if (tree_empty ()) return NULL;
    return x.parent == NULL ? NULL : x.parent; 
}

template <class T>
BinaryTree<T>::~BinaryTree () 
{
	std::cout << "destory tree" << std::endl;
    DeleteChildTree (head);
}

template <class T>
typename BinaryTree<T>::BiTree BinaryTree<T>::first_child (const BinaryTree<T>::BiNode &x) 
{ 
    if (tree_empty ()) return NULL; 
    if (x.LChild == NULL && x.RChild == NULL) 
        return NULL; 
    return x.RChild == NULL ? x.LChild : x.RChild; 
} 

template <class T>
void BinaryTree<T>::print_BiTree (BinaryTree<T>::BiTree p, int n) 
{
    if (!p) return;
    print_BiTree (p->RChild, n+1); 
    
    for (int i = 0; i < n; i++) 
    std::cout << "    "; 
    std::cout << p->data << std::endl; 

	print_BiTree (p->LChild, n+1);
}

template <class T>
typename BinaryTree<T>::BiTree BinaryTree<T>::InsertNode (BinaryTree<T>::BiTree p, T& x, int i) 
{
    if (!p || i < left_child || i > right_child) 
		return NULL; 

    BiTree  temp = new BiNode; 
    temp->data = x; 
    temp->parent = p;
    temp->LChild = temp->RChild = NULL; 

    if (i == left_child) 
        p->LChild = temp; 
    else if (i == right_child) 
        p->RChild = temp; 

//    val++; 
    return temp; 
}

template <class T> 
bool BinaryTree<T>::DeleteChildTree (BinaryTree<T>::BiTree p) 
{
    if (p == NULL) return false; 
    DeleteChildTree (p->LChild); 
    DeleteChildTree (p->RChild); 

    delete p; 
    p = NULL;
//	val--; 
    return true; 
}


template <class T> 
BinaryTree<T>::BinaryTree (const T &h_node) 
{ 
    head = new BiNode; 
//    memset ((char*)&head, 0, sizeof (BiNode));  
    head->data = h_node; 
    head->parent = NULL;
    head->LChild = head->RChild = NULL; 

//    val++; 
} 

#endif

