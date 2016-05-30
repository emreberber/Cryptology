/*
><><><><><><><><><><><><><><><><><><><><><><><><><><><
>													 
>
>		   Filename :  AffineEncoder.c
>		Explanation :  Affine Cipher Encoder
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

void Affine(char array[],int A,int B)
{
	int i , X;
	char key ;
	
	char upper[26]={'A','B','C','D','E','F','G','H','I','J','K','L',
	'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	char lower[26]={'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	for(i=0 ; array[i]!= '\0' ; i++)
	{    
		if(array[i]>64 && array[i]<91)
		{
			X = array[i] - 65 ;
	   	        key = (A*X+B) % 26 ;
			array[i] = upper[key] ;	
		}
		else if(array[i]>97)
		{
			X = array[i] - 97 ;
			key	= (A*X+B) % 26 ;
			array[i] = lower[key] ;
		}	
	}	
}

int main()
{
	char array[50];
	int A , B , i ;

	printf("Press String : ");   gets(array);
	printf("A : "); scanf("%d",&A);
	printf("B : "); scanf("%d",&B);
	
	Affine(array,A,B);
	
	printf("Cipher Text : ");
	for(i=0 ; array[i]!= '\0' ; i++)
	{
		printf("%c",array[i]);
	}	
	printf("\n\n");
	
	system("pause");
	return 0;
}
