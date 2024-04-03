#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* lchild;
	struct node* rchild;
	int val;
}NODE;

void InsertBST(NODE**root,int n)
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->val=n;
	temp->lchild=NULL;
	temp->rchild=NULL;

	if(!(*root))
	  { 
	  	*root=temp;
	     return;
	  }
    
	NODE*cur=*root;
	NODE*parent;
       while(cur)
       {
       	 parent=cur;
       	 if(cur->val<n)
       	 	cur=cur->rchild;
       	 else if(cur->val>n)
       	 	cur=cur->lchild;
       	 else
       	 	{
       	 		printf("No duplicates allowed\n");
       	 		return;
       	 	}
       }

    if(parent->val<n)
    	parent->rchild=temp;
    else
    	parent->lchild=temp;

}

void search(NODE**root,int n)
{
	NODE*cur=*root;
       while(cur)
       {
       	 if(cur->val<n)
       	 	cur=cur->rchild;
       	 else if(cur->val>n)
       	 	cur=cur->lchild;
       	 else
       	 	{
       	 		printf("key found\n");
       	 		return;
       	 	}
       }
    InsertBST(root,n);
}

void preorder(NODE*root)
{
	if(root)
	{
		printf("%d",root->val);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void inorder(NODE*root)
{
	if(root)
	{
		inorder(root->lchild);
		printf("%d",root->val);
		inorder(root->rchild);
	}
}

void postorder(NODE*root)
{
	if(root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d",root->val);
	}
}

int main()
{
	NODE* root=(NODE*)malloc(sizeof(NODE));
	root=NULL;
    printf("Creating BST\n");
	int k;
	while(1)
	{
		printf("Enter the element(-1 to end): ");
	    scanf("%d",&k);
	    if(k==-1)
	    	break;
	    InsertBST(&root,k);
	   
    }

    printf("Element to search? ");
    scanf("%d",&k);
    search(&root,k);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

}