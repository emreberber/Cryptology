/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  PasswordGenerator.c
>		Explanation :  Create random passwords
>		   	
>		   Compiler :  TDM-GCC 4.9.2 
>
>		  Developer :  Emre Berber 
>		      Other :  emreberber.com 
>
><><><><><><><><><><><><><><><><><><><><><><><><><><><
*/

#include <stdio.h>
#include <stdlib.h>

void Password(int difficulty , int size , char cipher[])
{
	srand(time(NULL)) ;
	int j ,i,a,b,c;
	
	int num[10]={'0','1','2','3','4','5','6','7','8','9'} ;
	
	char lower[26]={'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'} ;
	
	char upper[26]={'A','B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'} ;
			
	char special[10]={'+','-','/','\\','.','#','!','=','*','-'} ;
	
	for(j=0 ; j<size ; j++)  
	{
		cipher[j]=-1 ;
	} 
	
	if(difficulty==1)
	{		
		for(i=0 ; i<size ; i++)
		{			
			do
			{
				a = rand()%size ;	
			}while(cipher[a]!=-1);			
			b = rand()%10 ;
			cipher[a]=num[b];						
		}
		cipher[i]='\0';
	}
	else if(difficulty==2)
	{		
		for(i=0 ; i<size ;i++)
		{
			do
			{
				a=rand()%size ;
			}while(cipher[a]!=-1);
			c=rand()%2 ;		
			if(c==0)
			{
				b=rand()%10 ;
				cipher[a]=num[b] ;
			}
			else if(c==1)
			{
				b=1+rand()%26 ;
				cipher[a]=lower[b];
			}
		}
		cipher[i]='\0' ;		
	}
	else if(difficulty==3)
	{
		for(i=0 ; i<size ; i++)
		{
			do
			{
				a=rand()%size ;
			}while(cipher[a]!=-1);
			c=rand()%3 ;
			if(c==0)
			{
				b=rand()%10 ;
				cipher[a]=num[b] ;
			}
			else if(c==1)
			{
				b=1+rand()%26 ;
				cipher[a]=lower[b];
			}
			else if(c==2)
			{
				b=1+rand()%26 ;
				cipher[a]=upper[b];
			}			
		}
		cipher[i]='\0';		
	}
	else if(difficulty==4)
	{
		for(i=0 ; i<size ; i++)
		{
			do
			{
				a=rand()%size ;
			}while(cipher[a]!=-1);
			c=rand()%4 ;
			if(c==0)
			{
				b=rand()%10 ;
				cipher[a]=num[b] ;
			}
			else if(c==1)
			{
				b=1+rand()%26 ;
				cipher[a]=lower[b];
			}
			else if(c==2)
			{
				b=1+rand()%26 ;
				cipher[a]=upper[b];
			}
			else if(c==3)
			{
				b=rand()%10 ;
				cipher[a]=special[b];				
			}			
		}
		cipher[i]='\0';
	}		
}

int main()
{
	
	int difficulty , size ,i,j ,start=0;
	char cipher[100]  , ans[1];
	printf("======== RANDOM PASSWORD GENERATOR ======== \n");
	printf("                                            \n");
	printf("	======= LEVEL 1 ======= > 0296541   \n");
	printf("	======= LEVEL 2 ======= > 02h6y4v   \n");
	printf("	======= LEVEL 3 ======= > P2h6y4V   \n");
	printf("	======= LEVEL 4 ======= > P2h.y4?   \n");
	printf(" 				            \n");
	printf("<!> We recommend you use Level 3 - 4  <!>   \n");
	printf("<!> and size should be greater than 8 <!>   \n\n");
	
	while(start == 0)
	{
		
		printf("========================================== \n\n");
		printf("Degree of difficulty : ");    scanf("%d",&difficulty);
		printf("Size                 : ");    scanf("%d",&size);	

		Password(difficulty,size,cipher);
		printf("Password             : ");
		for(i=0 ; cipher[i]!='\0'; i++)
		{
			printf("%c",cipher[i]);
		}
		printf("\n\nQuit [q] or Again[a] : ");  scanf("%s",&ans[0]);
		if(ans[0] == 'q')
		{
			start = -1 ;
		}
		else if(ans[0] == 'a')
		{
			start = 0 ;
		}
		else
		{
			printf("========================================== \n");
			printf("Error ! \n");
			start = -2 ;
		}
	}
	if(start==-1)
	{
		printf("========================================== \n");
		printf("Exit is successful \n");
	}
	
	printf("\n\n");
	system("pause");
	return 0;
}
