/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  CaesarEncoder.c
>		Explanation :  Encode caesar cipher
>		   	
>		   Compiler :  TDM-GCC 4.9.2 64-bit  
>
>		  Developer :  Emre Berber 
>		      Other :  emreberber.com 
>
><><><><><><><><><><><><><><><><><><><><><><><><><><><
*/

#include <stdio.h>
#include <stdlib.h> 

void Caesar(char array[] , long int counter)
{
	int i=0,a=1;
	while(array[i]!='\0')  
	{
		a=1;
		if(array[i]>64 && array[i]<91)  
		{
			while(a<=counter) 
			{
				array[i]+=1;  
				if(array[i]==91) 
				{
					array[i]=65; 
				}	
				a++; 	
			}
			i++; 
		}
		else if(array[i]>96 && array[i]<122) 
		{	
			while(a<=counter) 
			{
				array[i]+=1;  
				if(array[i]==123)  
				{
					array[i]=97;  
				} 
				a++;  
			}
			i++;    
		}
		if(array[i]==' ')  
		{
			array[i]==' ';  
			i++;  
		}				
	}	
}
int main()
{
	char plain[20];    
	long int key;
	
	printf("Caesar Encrypting \n\n");
	printf("Plain Text    : ");    gets(plain);             
	printf("Key           : ");    scanf("%d",&key);
	
	while(key<0)
	{
		key +=26;
	}
	
	Caesar(plain,key);
	printf("Cipher Text   : %s \n\n",plain);								    	

	system("PAUSE");
	return 0;
}
