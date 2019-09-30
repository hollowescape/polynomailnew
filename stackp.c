#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!((p)=malloc(s))){\
		printf(" insuffient memory");\
	}\

#define REALLOC(n,p,s)\
	if(!((n)=realloc((p),(s)))){\
		printf(" insuffient memory");\
	}\

	typedef struct 
	{
		int key;
	}element;
	element stack[1];
	int top=-1;
	int cp=1;
	void rall(element *s)
	{	
		element *new;
		REALLOC(new,s,2*cp*sizeof(element));
		new=s;
		cp++;
	}
	void push(element item,int s,int *top)
	{	
		if(*top>=s)
		{
			rall(stack);
		}
		else
		{
			stack[++*top]=item;
		}
	}

	element pop()
	{
		if(top==-1)
		{
			printf(" stack is empty");
			exit(0);
		}
		else
		{
			return stack[top--];
		}
	}

	void display(element *stack,int top)
	{	int i=0;
		for(i=0;i<=top;i++)
		{
			printf(" the element %d is %d",(i+1),stack[i].key);
		}
	}
	void main()
	{
		element d,p;
		int c,s;
		printf(" enter the choice \n");
		while(1)
		{
		printf(" 1. push\n 2. pop\n 3. display\n 4.exit\n");
		scanf("%d",&c);
			switch(c)
			{
				case 1: printf("enter the elment to insert\n");
						scanf("%d",&d.key);
						s=sizeof(element);
						push(d,s,&top);
						break;
				case 2: p=pop();
						printf(" element poped off is %d",p.key);
						break;
				case 3: display(stack,top);
						break;
				case 4: exit(0);
			}
		}
	}		