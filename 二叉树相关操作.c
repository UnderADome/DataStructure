#include <stdio.h>
#include <stdlib.h> 

//#ifdef _TREE_H 
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree* T);
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int x, SearchTree* T);
SearchTree Delete(int x, SearchTree T);
int Retrieve(Position P);


#define OK 1;
//#endif /*_TREE_H*/
struct TreeNode{
	int Element;
	SearchTree Left;
	SearchTree Right
};


SearchTree MakeEmpty(SearchTree* T){
	printf("ready to clean\n");
	if (*T == NULL){
		printf("为空，不需要free\n");
	}	
	if (*T != NULL){
		MakeEmpty( &((*T)->Left) );
		printf ("清理左子树\n");
		MakeEmpty( &((*T)->Right) );
		printf("清理右子树\n");
		free(T);
		printf("已释放\n");
	}
	printf("all clear!\n");
	return NULL;
}

/*查找*/
Position Find(int x, SearchTree T){
	if (T == NULL)
		return NULL;
		
	if (x < T->Element)
		return Find(x, T->Left);
	else if(x > T->Element)
		return Find(x, T->Right);
	else 
		return T;
}

/*查找最小值*/ 
Position FindMin(SearchTree T){
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else 
		return FindMin(T->Left);
}

/*查找最大值, 非递归*/ 
Position FindMax(SearchTree T){
	if (T != NULL)
		while(T->Right != NULL)
			T = T->Right;
	return T;
}

/*插入*/
SearchTree Insert(int x, SearchTree* T){
	printf ("执行insert\n");
	if (*T == NULL){
		*T = malloc(sizeof(struct TreeNode));
		printf ("分配空间\n");
		if (*T == NULL)
			printf ("Out of space\n");
		else{
			((*T)->Element) = x;
			((*T)->Left) = ((*T)->Right) = NULL;
		} 
	}
	else if (x < (*T)->Element)
		(*T)->Left = Insert(x, &((*T)->Left));
	else if (x > (*T)->Element)
		(*T)->Right = Insert(x, &((*T)->Right));
		
	return T;
}

int main(void){

	SearchTree T;
	printf("创建二叉树\n");
	MakeEmpty(T);
	printf("clear finished!\n");
	
	int n = 100;//输入数字的数量
	int x;//记录输入的数字
	int i;//记录循环的次数 
	scanf ("%d", &n);
	for (i=1;i<=n;i++){
		scanf("%d", &x);
		Insert(x, T);
		printf ("插入第%d个数，x[%d] = %d\n", i, i, x);
	} 
	
	return 0;
}