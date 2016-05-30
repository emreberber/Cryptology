/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  CaesarDecoder.c
>		Explanation :  Decode caesar cipher
>		   	
>		   Compiler :  TDM-GCC 4.9.2 64-bit  
>
>		  Developer :  Emre Berber 
>		      Other :  emreberber.com 
>
><><><><><><><><><><><><><><><><><><><><><><><><><><><
*/

#include <stdlib.h> 
#include <stdio.h>

void Decoder(char array[] )
{
	int i=0,counter=0,a;
	for(a=0 ; a<25 ; a++)
	{
		i=0;
		while(array[i] != '\0')
		{
			if(array[i]==32)
			{
				array[i]=32;
				i++;
			}
			array[i]+=1;
			if(array[i]==91)
			{
				array[i]=65;
			}
			if(array[i]==123)
			{
				array[i]=97;
			}
			i++;
		}		
		printf("%s \n",array);	
	}
}
void Key(char array[] ,  int counter)
{
	int i=0,a=1;
	if(counter>26)
	{
		counter = counter % 26 ;
	}
	else if(counter<0)
	{
		if(counter<-26)
		{
			counter = -counter ;
			counter = counter % 26 ;
		}
		else if(counter >-26)
		{
			counter = -counter ;
		}
		counter = 26 - counter ;
	}
	while(array[i]!='\0')  
	{
		a=1;
		if(array[i]==' ')  
		{
			array[i]==' ';  
			i++;  
		}
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
		else if(array[i]>96 && array[i]<123) 
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
	}	
}
int main()
{
	char array[50];                            
	int key;
	char b_or_k[1];
	printf("Cipher Text   : ");  gets(array);  
	printf("Brute Force[b] or Key[k] ?   :"); scanf("%c",&b_or_k[0]);
	if(b_or_k[0] == 'b')
	{
		Decoder(array);
	}
	else if(b_or_k[0] == 'k')
	{
		printf("Key : ");  scanf("%d",&key);
		Key(array,key);	
		printf("Plain Text : %s \n\n",array);
	}
	else
	{
		printf("Error ! ");
	}
	
	system("PAUSE");
	return 0;
}
