#include "nfadesc.h"
#include<stdio.h>
#include<stdlib.h>
char str[10];
int IsFinal(int st)
{
	int i;
	for(i=0;i<NoFst;i++)
	{
		if(st==Final_st[i])
			return 1;
	}
	return -1;
}
void compute(int cur_st,int i)
{
	int k,next_st[10],next;
	printf("\n current st is : %d",cur_st);
	if(str[i]=='\0' && IsFinal(cur_st)==1)
	{
		printf("\n The string is ACCEPTED \n");
		return;
	}
	else if(IsFinal(cur_st)==-1 && str[i]=='\0')
	{
		printf("\n The string is REJECTED \n");
		return;
	}
	else
	{
		for(k=0;k<NoSt;k++)
		{
			next_st[k]=Rules[cur_st][str[i]-'0'][k];
		}
		printf("\n Next states:");
		for(k=0;k<NoSt;k++)
		{
			printf("\t %d",next_st[k]);
		}
		printf("\n\n");
		i=i+1;
		for(k=0;k<NoSt;k++)
		{
			if(next_st[k]>=0)
			{
				next=next_st[k];
				compute(next,i);
			}
			else continue;
		}
	}
}
int main()
{
	int i=0;
	printf("\nEnter the string \n");
	scanf("%s",str);
	int cur_st=Init_st;
	compute(cur_st,i);
}
