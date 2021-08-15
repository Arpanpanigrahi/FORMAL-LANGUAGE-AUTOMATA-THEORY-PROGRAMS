//2//

#include<stdio.h>
void sort(int,int*);
int main ()
{
	int n,i, arr[100];
	printf("Enter the length of the array:\n");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(n,arr);
	printf("The sorted array:\n");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
}
void sort(int n,int *arr)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		[
		if(*[arr+j]<*[arr+i])
		{
			temp = *(arr+i);
			*(arr+i) = *(arr+j);
			*(arr+j) = temp;
		}
	}
}
