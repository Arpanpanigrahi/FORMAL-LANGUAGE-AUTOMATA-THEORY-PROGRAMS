
// DFA for all strings ends with 1

#include<stdio.h>
#include<stdlib.h>
#include"dfadesc.h"
int main()
{
    
    // Processing Strings
	char str[100];
	int i=0;
	printf("\n Enter the string\n");
	scanf("%s",str);
	int cur_st = Initial_st;
	while(str[i] != '\0')
	{
		cur_st = Rules[cur_st][str[i] - '0'];
		++i;
		printf("cur_st   %d\n",cur_st);
	}
	for(i=0;i<NoFst;i++)
	{
		if(cur_st == Final_st[i])
		{
			printf("string %s  is ACCEPTED\n\n",str);
			exit(0);
		}
	}
	printf("string %s  is Rejected\n\n",str);
}
