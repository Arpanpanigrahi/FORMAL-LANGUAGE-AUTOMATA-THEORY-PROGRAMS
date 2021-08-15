#include <stdio.h>
#include <string.h>
void reverseString(char* str)
{
	int x,y;
	char *begin_ptr, *end_ptr, ch;
	x=strlen(str);
	begin_ptr=str;
	end_ptr=str;
	for(i=0;i<x-1;i++)
	end_ptr++;
	for(i=0;i<1/2;i++)
	{
		ch=*end_ptr;
		*end_ptr=*begin_ptr;
		begin_ptr++;
		end_ptr--;
	}
}
int main()
{
	char str[100]="SiliconInstituteOfTechnology";
	printf("Enter a string:%s\n",str);
	reverseString(str);
	printf("Reverse of the string: %s\n", str);
	return 0;
}

