#include<stdio.h>
#include<string.h>
int failure[20];
int fail(char *p )
{	
	int i=0,j,n;
	n=strlen(p);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		if(p[j]==p[i+1])
		{
			failure[j]=i+1;
		}
		else
		{
			failure[j]=-1;
		}
	}
	printf(" failure values are \n");
	/*for(i=0;i<n;i++)
	{
		printf("%d\n",failure[i]);
	}*/
	return 0;
}

int  nmatch(char *p,char *q)
{
	int lq,lp,i=0,j=0;
	lq=strlen(q);
	lp=strlen(p);
	while((i<lq)&&(j<lp))
	{
		if(p[j]==q[i])
		{
			i++;
			j++;
		}
		else if(j==0)
			{	i++;
		}
		else
		{
			j=failure[j-1]+1;
		}
	}
	return ((j==lp)?(i-lp):-1);
}


void main()
{	int i;
	char p[20],q[20];
	printf(" enter the pattern\n");
	scanf("%s",p);
	fail(p);
	printf(" enter the string\n");
	scanf("%s",q);
	i=nmatch(p,q);
	if(i==-1)
	{
		printf("pattern not found\n");
	}
	else
	{
		printf(" pattern found starting from index %d",i+1);
	}
}