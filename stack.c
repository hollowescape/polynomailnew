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

void main()
{
	int *ptr,n,i,*new;
	printf(" enter the size of array\n");
	scanf("%d",&n);
	MALLOC(ptr,n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("%d",ptr[i]);
	}
	free(ptr);
	printf(" enter the new size of array\n");
	scanf("%d",&n);
	REALLOC(ptr,ptr,n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("%d",ptr[i]);
	}
	
	free(ptr);
	free(new);
}