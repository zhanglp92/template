/*************************************************************************
	> File Name: BinaryOp.cpp
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月05日 星期三 16时34分52秒
 ************************************************************************/

#ifndef _BINARYOP_CPP_
#define _BINARYOP_CPP_ 

/* 打印二叉树 */ 

#define printBiTree(out, p, type) \
	print_BiTree ()

template <typename OUT, typename NODE_TYPE> 
void print_BiTree (OUT &out, void *p, int n = 0) 
{
	BinaryTree<NODE_TYPE>::node_type *q = 
		(BinaryTree<NODE_TYPE>::node_type)p;
	
    if (!p) return;
    print_BiTree (p->RChild, n+1); 

    for (int i = 0; i < n; i++) 
    out << "    "; 
    out << p->data << std::endl; 

	print_BiTree (p->LChild, n+1);
}

#endif
