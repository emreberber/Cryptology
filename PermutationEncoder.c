/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  PermutationEncoder.c
>		Explanation :  Permutation Cipher Encoder for Word (DEMO)
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

int Permutation(char Array[] , char Cipher[] , int Key)
{
	int Num[40] ;
	int temp , letter = 0 , counter=0 ;
	int a , i , j=0 , extra , digit , num ;

	for(a=0 ; Array[a]!='\0' ; a++)
	{
		letter ++ ;
    }	
    
	extra = Key ;  //replacement	
	while(extra>0)
	{	
		extra = extra / 10 ;
		counter ++ ; 	
	} 

	num = counter ; //replacement	
	while(counter>=0)
	{
		Num[counter-1]=Key%10 ;
		Key = Key / 10 ;
		counter -- ;
	}

	digit = num ;  //replacement
	
	for(i=0; Array[i]!='\0' ; i++)
	{		
		temp = Num[j] ;
		if(temp==0)
		{	
			return -1;
		}
		if(digit>0 && temp<=letter && Array[temp-1]!='\0')
		{				
			if(Array[temp-1]!='\0')
			{
				Cipher[i]=Array[temp-1] ;
			}
			else
			{
				Cipher[i]=Array[i];
			}
			
		}		
		else if(temp>num && temp>letter)
		{
			temp = i+1 ;
			if(Array[temp-1]!='\0')
			{
				Cipher[i]=Array[temp-1] ;	
			}
			else
			{
				Cipher[i]=Array[i];
			}
		}
		else if(digit<=0)
		{
			Cipher[i]=Array[i] ;
		}
		if(digit>0)
		{
			digit --;
			j++;
		}				
	}	
}

int main()
{	
	char Word[40] , Cipher[40];
	int Key , i ;
	
	printf("Permutation Encoder \n\n");
	printf("Press Word   : ");  gets(Word);
	printf("Key          : ");  scanf("%d",&Key);
	
	for(i=0 ; Word[i]!='\0'; i++)
	{
		if(Word[i]==' ')
		{
			printf("\nError Message ! \nPlease enter without spaces\n ");
			return 0;
		}
	
	}
	if(Key<=0)
	{
		printf("\nError Message ! \nKey must be greater than zero\n");
		return 0;
	}
	
	Permutation(Word,Cipher,Key);
	if(Permutation(Word,Cipher,Key)==-1)
	{
		printf("\nError Message ! \n");
		return 0;
	}

	printf("Cipher Word  : ");
	for(i=0 ; Cipher[i]!='\0'; i++)
	{
		printf("%c",Cipher[i]);
	}
	printf("\n\n");
	
	system("pause");
	return 0;
}
