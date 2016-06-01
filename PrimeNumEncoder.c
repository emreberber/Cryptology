/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  PrimeNumEncoder.c
>		Explanation :  Cipher Encoder with Prime Numbers
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

int PrimeControl(int num)
{
	int i , counter=0 ;
	
	for(i=1 ; i<num ; i++)
	{		
		if(num%i==0 && num>2)
		{
			counter ++ ;
		}
	}
	
	if(counter==1)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}

void PrimeNumber(char Array[] , int num1 , int num2)
{
	int key , j=0 , i;
	
	for(i=0 ; Array[i]!='\0' ; i++)
	{	
		if(j%2==0 && Array[i]!=32)
		{
			key = num1 ;
		}
		else if(j%2==1 && Array[i]!=32)
		{
			key = num2 ;
		}
		else if(Array[i]==32)
		{
			j++ ;
		}
		if(Array[i]<91 && Array[i]!=32)
		{
			if(Array[i]-64 + key != 26)
			{
				Array[i]=64+(Array[i]-64 + key)%26 ;
			}	
		}
		else if(Array[i]>96)
		{
			if(Array[i]-96 + key != 26)
			{
				Array[i]=96+(Array[i]-96 + key)%26 ;
			}		
		}
		j++ ;
	}	
}

int main()
{
	char Array[40];
	int num1, num2 ,i ;
	
	printf("Prime Number Encoder \n\n");
	printf("Press String     : ");     	gets(Array);
	printf("1st Prime Number : "); 	 	scanf("%d",&num1);
	printf("2nd Prime Number : ");  	scanf("%d",&num2);
	
	if (PrimeControl(num1)  + PrimeControl(num2)==2)
	{
		PrimeNumber(Array,num1,num2) ;
		
		printf("Cipher Text  	 : ");
		for(i=0 ; Array[i]!='\0'; i++)
		{
			printf("%c",Array[i]);
		}
	}
	else
	{
		printf("\nError Message ! \n");
		printf("First and second number must be prime");
	}
	printf("\n\n");
	
	system("pause");
	return 0;
}
