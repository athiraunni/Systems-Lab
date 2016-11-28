#include<stdlib.h>
typedef struct tnode
{
	int data;
	struct tnode *right,*left;
}TNODE;

struct tnode *lca(struct tnode* root,int n1,int n2)
{
	if(root == NULL)
		return NULL;
	if(root->data > n1 && root->data > n2)
		return lca(root->left,n1,n2);
	if(root->data < n1 && root->data < n2)
		return lca(root->right,n1,n2);
	return root;
}

TNODE *CreateBST(TNODE *,int);
void Inorder(TNODE *);
TNODE *CreateBST(TNODE *root,int elem)
{
	if(root == NULL)
	{
		root = (TNODE *)malloc(sizeof(TNODE));
		root->left = root->right = NULL;
		root->data = elem;
		return root;
	}
	else
	{
		if(elem < root->data)
			root->left = CreateBST(root->left,elem);
		else if(elem > root->data)
			root->right = CreateBST(root->right,elem);
		else 
			printf("\nDuplicate element..!! Not Allowed");
		return (root);
	}
	
}

void Inorder(TNODE *root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		printf("\n%d",root->data);
		Inorder(root->right);
	}
}

main()
{
	struct tnode *t;
	int i,elem,n,n1,n2,c;
	int root = NULL;
	
	printf("\nBST for how many nodes ?");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nRead the data for Node %d : ",i);
		scanf("%d",&elem);
		root = CreateBST(root,elem);
	}
	printf("\nBST Traversal in Inorder");
	Inorder(root);
	
	printf("\nFor how many you need to check for LCA ?  ");
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	{
		printf("\nEnter the 2 Nodes : ");
		scanf("%d %d",&n1,&n2);
		t = lca(root,n1,n2);
		printf("\nLCA of %d & %d is %d.\n", n1, n2, t->data);
	}
}
	
