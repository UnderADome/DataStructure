//教材中二叉树的代码


//实现简单的插入和删除
#include <stido.h>
#include <stdlib.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *leftChild;
	struct Node *rightChild;
}BiTreeNode;

//初始化创建二叉树的头结点 
void Initate(BiTreeNode **root)
{
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	*root->leftChild = NULL;
	*root->rightChild = NULL;
}

BiTreeNode* InsertLeftNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode *s, *t;
	
	if (curr == NULL)
		return NULL;
		
	t = curr->leftChild;
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;
	s->rightChild = NULL;
	
	curr->leftChild = s;
	return curr->leftChild;
}

BiTreeNode* InsertRightNode(BiTreeNode* curr, DataType x)
{
	BiTreeNode *s, *t;
	
	if (curr = NULL)
		return NULL;
		
	t = curr->rightChild;
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	
	s->data = x;
	s->leftChild = NULL;
	s->rightChild = s;
	
	curr->rightChild = s;
	return curr->rightChild;
}

BiTreeNode* DeleteLeftChild(BiTreeNode* curr)
{
	if (curr == NULL || curr->leftChild == NULL)
		return NULL;
		
	//另加一个Destory函数，将做字数遍历free 
	free(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}


BiTreeNode* DeleteRightTree(BiTreeNode* curr)
{
	if (curr == NULL || curr->rightChild = NULL)
		return NULL;
	
	free(&curr->leftChild);
	curr->rightChild = NULL;
	return curr;	
}

int main(void)
{
	BiTreeNode *root, *p, *pp;
	
	Initiate(&root)
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	pp = p;
	InsertLeftNode(p, 'E');
	InsertRightNode(pp, 'EE');
	
	return 0;
}
