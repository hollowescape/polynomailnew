#include<stdio.h>
#define COMP(x,y)((x)>(y)?1:((x)==(y)?0:-1))
#define MAX 100
typedef struct 
{
	int degree;
	int coef[MAX];
}terms;
void input(terms *a,int d)
{	
	int i;
	for(i=a->degree;i>=0;i--)
	{
		printf(" enter the coffient for degree %d",i);
		scanf("%d",&a->coef[i]);
	}
}
void print(terms a,int d)
{	
	int i;
	printf(" elements of polynomail  is\n");
	for(i=a.degree;i>=0;i--)
	{
		printf(" %dx%d+",a.coef[i],i);
	}
}
int iszero(terms a,int d)
{	int i,flag=0;
	for(i=a.degree;i>=0;i--)
	{
		if(a.coef[i]!=0)
		{
			flag=1;
		}
		else
		{
			continue;
		}

	}
	if(flag==1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int lead(terms a)
{
	return a.degree;
}
void attach(terms *a,int c,int d)
{		
		a->coef[d]=c;
}
int coffient( terms a,int d)
{
	return a.coef[d];
}
void r(terms *a)
{
	a->degree=a->degree -1;
}

void main()
{
	terms a,b,d;
	int i,sum=0;
	printf("enter the degree of polynomial 1\n");
	scanf("%d",&a.degree);
	input(&a,a.degree);
	printf(" enter the degree of polynomial 2\n");
	scanf("%d",&b.degree);
	input(&b,b.degree);
	if(lead(a)>lead(b))
	{
		d.degree=a.degree;
	}
	else
	{
		d.degree=b.degree;
	}
	/*switch(COMP(lead(a),lead(b)))
	{
		case 1: attach(&d,coffient(a,lead(a)),lead(a));
				r(&a);
				break;
	}*/
	while(!(iszero(a,a.degree))&&!(iszero(b,b.degree)))
	{
			switch(COMP(lead(a),lead(b)))
			{
				case 1:	attach(&d,coffient(a,lead(a)),lead(a));
						r(&a); 
						break;
				case -1:attach(&d,coffient(b,lead(b)),lead(b));
						r(&b);
						break;
				case 0:	sum=coffient(a,lead(a))+coffient(b,lead(b));
						if(sum)
						{
							attach(&d,sum,lead(a));
						}
						r(&a);
						r(&b);
						break;
			}
		
	}
	print(d,d.degree);



}