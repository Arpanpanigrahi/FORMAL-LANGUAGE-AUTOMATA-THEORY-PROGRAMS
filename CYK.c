
//IMPLEMENTATION OF CYK Algorithm for membership  testing in CFG//
//--------------------------------------------------------//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[30];
char GRAMMAR[10][10] = { {'S','A','B'},{'S','B','C'},
						 {'A','B','B'},{'A','0'},{'B','B','A'},
						 {'B','1'},{'C','A','C'},
						 {'C','A','A'},{'C','0'}
					   };
char ter[10]={'0','1'};
char non_ter[10]={'S','A','B','C'};
int N_pro =9 ,N_ter = 2 ,N_Nter= 4;
int X_indx[10][10];
char X[60][10];

int main()
{

	int i,k=0,r,t,len,j,x,m,n;
	printf("\n The given Grammar is:\n");
	for(i=0;i<N_pro;i++)
	{
		printf("%s ",GRAMMAR[i]);
		printf("\n");
	}
	printf("\n Enter the string to test \n");
	scanf("%s",str);
	len = strlen(str);
	
	//X-index matrix //
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			
			X_indx[i][j] = k;
			++k;
		}
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			
			printf("%d  ",X_indx[i][j]);
		
		}
		printf("\n");
	}
	int no_index = k;
	
	//Initialization of X[][] table//
	
	for(i=0;i<len;i++)
	{
		t=0;
		for(j=0;j<N_pro;j++)
		{
			if(GRAMMAR[j][1] == str[i])
			{
				x=X_indx[i][i];
				X[x][t] = GRAMMAR[j][0];
				t++;
			}
		}
		X[x][t] = '\0';
	}
	printf("\n");
	
	// Computint X table//
	
	int pro,loc,pro_l,check;
	for(k=1 ; k <= len-1;k++)
	{
		for(r=0; r <= len-k-1; r++)
		{
			for(t=0;t<=k-1;t++)
			{
				m=X_indx[r][r+t];
				n=X_indx[r+t+1][r+k];
				for(i=0;X[m][i] !='\0';i++)
				{
					for(j=0;X[n][j] !='\0';j++)
					{
						for(pro=0;pro < N_pro;pro++)
						{
							if(GRAMMAR[pro][1] == X[m][i] && GRAMMAR[pro][2] == X[n][j] )
							{
								loc = X_indx[r][r+k];
								pro_l = strlen(X[loc]);
								for(check =0;X[loc][check] != '\0';check++)
								{
									if(X[loc][check] == GRAMMAR[pro][0])
										break;
								}
								if(check == pro_l)
								{
									X[loc][pro_l] =GRAMMAR[pro][0];
									X[loc][++pro_l] = '\0';
								}
							}
						}
					}
				}
			}
		}
	}
	
	//Print X table//
	
	printf("\n The computed X table is:  \n\n");
	printf("------------------------------------------------------------------------\n");
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(i<=j)
			{
				loc = X_indx[i][j];
				printf("X[%d][%d] =  %s \t",i,j,X[loc]);
			}
		}
		printf("\n\n");
	}
	
	//testing the membership //
	
	loc = X_indx[0][len-1];
	for(i=0;X[loc][i] !='\0';i++)
	{
		if(X[loc][i] == 'S')
		{
			printf("\n The string %s is derivable by the Grammar\n",str);
			exit(0);
		}
	}

	printf("\n The string %s is NOT  derivable by the Grammar\n",str);
	return 0;
}	
			
