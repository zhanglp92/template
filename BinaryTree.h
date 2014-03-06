/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月03日 星期一 19时03分01秒
 ************************************************************************/

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <cstring> 

template <class T>
class BinaryTree { 

public: 
    /* 二叉树的结点类型 */  
    typedef struct _NODE { 
        T   data; 
        struct _NODE    *LChild; 
        struct _NODE    *RChild; 
        struct _NODE    *parent; 
    }BiNode, *BiTree; 
    BiNode      node_null; 

    /* 二叉树结点数目类型 */ 
    #define size_type   size_t 
    #define node_type   BiNode 

    static const unsigned char    left_child = 0; 
    static const unsigned char    right_child = 1;  

    BinaryTree (void): head (NULL), val (0) {} 
    /* 初始化一个根 */
    inline BinaryTree (const T &h_node); 
    inline ~BinaryTree ();

    /* 将树初始化为一颗空树 */ 
    bool init_tree (void) { 
        return head != NULL ? false : (BinaryTree (), true); 
    } 

    /* 销毁树 */ 
    bool destory_tree (void) { 
        return DeleteChildTree (head); 
    } 
    
    /* 判断一颗树是否为空树 */ 
    bool tree_empty (void) const { 
        return head == NULL ? true : false; 
    } 

    /* 返回一颗树的根 */ 
    BiTree root (void) { 
        return tree_empty () ? NULL : head; 
    } 

    /* 返回一个结点的父结点 */ 
    inline BiTree parent (const BiNode &x);
    /* 若x为非叶子结点，则返回它的第一个孩子 */ 
    inline BiTree first_child (const BiNode &x);
    /* 返回x的下一个兄弟 */
    inline BiTree NextSibling (const BiTree x);
    /* 删除子树 */
    bool DeleteChild (BiTree p, int i);
    /* 添加一个结点 */ 
    static BiTree InsertNode (BiTree, T&, int); 

//    InsertChild (BiTree p, BiTree ) 
/* 
    TraverseTree () 
    */ 

private: 
    BiTree      head; 
    size_type   val; 

    bool DeleteChildTree (BiTree p);
    void print_BiTree (BiTree, int);
};

template <class T>
const unsigned char     BinaryTree<T>::left_child;
template <class T>
const unsigned char     BinaryTree<T>::right_child;

#include "BinaryTree.cpp" 
#include "BinaryOp.cpp"
#endif
