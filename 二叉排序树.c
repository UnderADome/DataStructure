//代码来源 http://blog.csdn.net/feixiaoxing/article/details/6860493

typedef struct _TREE_NODE
{
	int data;
	struct _TREE_NODE* parent;
	struct _TREE_NODE* left_child;
	struct _TREE_NODE* right_child; 
} TREE_NODE;

//创建二叉树结点
TREE_NODE* create_tree_node(int data)
{
	TREE_NODE pTreeNode = NULL;
	pTreeNode = (TREE_NODE*)malloc(sizeof(TREE_NODE));
	assert(NULL != pTreeNode);//程序出错即终止 
	
	memset(pTreeNode, 0, sizeof(TREE_NODE));
	pTreeNode->data = data;
	return pTreeNode;
} 

//数据的查找
TREE_NODE* find_data_in_tree_node(const TREE_NODE* pTreeNode, int data)
{
	if (NULL == pTreeNode)
		return (TREE_NODE*)pTreeNode;
	else if (data < pTreeNode->data)
		return find_data_in_tree_node(pTreeNode->left_child, data);
	else
		return find_data_in_tree_node(pTreeNode->right_child, data);
} 

//数据统计
int count_node_number_in_tree(const TREE_NODE* pTreeNode)
{
	if (NULL == pTreeNode)
		return 0;
	
	return 1 + count_node_number_in_tree(pTreeNode->left_child)
			+ count_node_number_in_tree(pTreeNode->right_child);
} 

//按照从小到大的顺序打印节点的数据 
void print_all_node_data(const TREE_NODE* pTreeNode)
{
	if (pTreeNode){
		print_all_node_data(pTreeNode->left_child);
		printf ("%d\n", pTreeNode->data);
		print_all_node_data(pTreeNode->right_child);
	}
}

//统计树的高度
int calculate_height_of_tree(const TREE_NODE* pTreeNode)
{
	int left, right;
	if (NULL == pTreeNode){
		return 0;
	}
	
	left = calculate_height_of_tree(pTreeNode->left_child);
	right = calculate_height_of_tree(pTreeNode->right_child);
	return (left > right) ? (left + 1) : (right + 1);
} 