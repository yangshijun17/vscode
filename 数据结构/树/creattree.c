#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode//二叉树节点声明
{
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}*PtrNode,TreeNode;
 
void CreatTree(PtrNode *root)//先序建立一个树
{
	int tmp;
	scanf("%d",&tmp);
	if(tmp==-1)
		*root=NULL;
	else
	{
		*root=(PtrNode)malloc(sizeof(TreeNode));
		(*root)->value=tmp;
		printf("left:");
		CreatTree(&(*root)->left);
		printf("right:");
		CreatTree(&(*root)->right);
	}
}
void PreOrder(PtrNode root)//前序遍历
{
	if(root==NULL)
		return;
	printf("%d ",root->value);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(PtrNode root)//中序遍历
{
	if(root==NULL)
		return;
	InOrder(root->left);
	printf("%d ",root->value);
	InOrder(root->right);
}
void PostOrder(PtrNode root)//后序遍历
{
	if(root==NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ",root->value);
}
 
int main()
{
	PtrNode root;
	CreatTree(&root);
	PreOrder(root);
	printf("\n");
	return 0;
}