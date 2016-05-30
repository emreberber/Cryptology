/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  CumulativeEncoder.c
>		Explanation :  Cumulative Cipher Encoder
>		   	
>		   Compiler :  TDM-GCC 4.9.2 
>
>		  Developer :  Emre Berber 
>		 	  Other :  emreberber.com 
>
><><><><><><><><><><><><><><><><><><><><><><><><><><><
*/

#include <stdio.h>
#include <stdlib.h>

void Cumulative(char Array[] , char Cipher[] )
{
	int sum = 0 , bol , i ;
	if(Array[0]<91)
	{
		for(i=0 ; Array[i] != '\0' ; i++)
    	{
			if(Array[i]==' ')
			{
				Cipher[i] = ' ' ;
			}
			else
			{
				sum += Array[i] - 64 ;
				bol = sum / 3 ;
				if(bol<1)
				{
					bol = sum ;
				}
				while(bol>26)
				{
					bol -= 26 ;
				}
				Cipher[i] = 64 + bol ;
			}		
		}		
	}
	else if(Array[0]>96)
	{
		for(i=0 ; Array[i] != '\0' ; i++)
    	{	
			if(Array[i]==' ')
			{
				Cipher[i] = ' ' ;
			}
			else
			{
				sum += Array[i] - 96 ;
				bol = sum / 3 ;
				if(bol<1)
				{
					bol = sum ;
				}
				while(bol>26)
				{
					bol -= 26 ;
				}
				Cipher[i] = 96 + bol ;	
			}
		}			
	}
	Cipher[i]='\0' ;
}
int main()
{
	char Array[40];
	int param = 0 ,i ;
	char Cipher[40];
	
	printf("Cumulative Encoder \n\n");
	printf("Press String : ");  gets(Array);
	
	if(Array[0]<91)
	{
		for(i=0 ; Array[i] != '\0' ; i++)
		{
			if(Array[i]>90 && Array[i]!=32)
			{
				param = 1 ;
			}
		}
	}
	else if(Array[0]>96)
	{
		for(i=0 ; Array[i] != '\0' ; i++)
		{
			if(Array[i]<97 && Array[i]!=32)
			{
				param = 1 ;
			}
		}
	}	
		
	Cumulative(Array,Cipher);
	
	printf("Cipher Text  : ");
	if(param==0)
	{
		for(i=0 ; Cipher[i] != '\0' ; i++)
		{ 
			printf("%c",Cipher[i]);
		}
	}
	else if(param==1)
	{
		printf("Error ! ");
	}
	printf("\n\n");
	
	system("pause");
	return 0;
}
