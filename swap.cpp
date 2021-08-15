//1//
#include<stdio.h>
void swap(int *, int *);
int main ()
{
	int x,y;
	printf("Enter the value of x and y\n");
	scanf("%d %d",&x,&y);
	printf("Before swapping\n x=%d\n y=%d\n",x,y);
	swap(&x, &y);
	printf("After swapping\n x=%d\n y=%d\n",x,y);
}
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
	
