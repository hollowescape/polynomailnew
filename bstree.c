#include<stdio.h>
#include<stdlib.h>

typedef struct node *tree_p;
typedef struct node{
	int data;
	tree_p llink;
	tree_p rlink;
	}l;

	
	 tree_p search(tree_p root,int key)
	{
		if(!root)
		return NULL;
		if(key == root->data)
		return root;
		if(key > root->data)
		return search(root->rlink,key);
		if(key < root->data)
		return search(root->llink,key);
	}
	tree_p modifieds(tree_p root,int num)
	{
		if(root)
		{
			if((root->llink==NULL)&&(root->rlink==NULL))
			{
				return root;
			}
			else if(root->data>num)
			{
				modifieds(root->llink,num);
			}
			else if(root->data<num)
			{
				modifieds(root->rlink,num);
			}
			else if(root->data==num)
			{
				return 	NULL;
			}		
				
		}	
			
	}
		
	void insert (tree_p *node, int num)
	{
		tree_p ptr,temp;
		temp=modifieds(*node,num);
		if(temp==NULL)
		{
			printf(" same element exists\n");
		}
		else{ 
		if(temp||!(*node))
		{
			ptr=(tree_p)malloc(sizeof(l));
			
			ptr->data=num;
			ptr->llink=ptr->rlink=NULL;
		
		if(*node)
			{
				if(num<temp->data)
				{
					temp->llink=ptr;
				}
				else
				{
					temp->rlink=ptr;
				}
			}
			else
			{
				*node=ptr;
			}
		}
		}
	}
	void display(tree_p root)
	{
		if(root){
	
		display(root->llink);
		printf("%d\n",root->data);
		display(root->rlink);
		}
	}
	
	void main()
	{
		int n,key, keys,e=1;
		tree_p root =(tree_p)malloc(sizeof(l));
		tree_p rec;
		while(e==1){
		printf(" enter the choice\n");
		printf(" 1. insert\n 2. search\n 3.display\n 4. exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf(" enter the element to be inserted\n");
				scanf("%d",&key);
				insert(&root,key);
				break;
			case 2: printf(" enter the element to be searched\n");
				scanf("%d",&keys);
				rec=search(root,keys);
				if(rec==NULL)
				printf(" no element found\n");
				else
				printf(" element found \n");
				break;
			case 3: printf(" inorder display\n");
				display(root);
				break;
			case 4: exit(0);
				break;
		
		}				
			}
	}
