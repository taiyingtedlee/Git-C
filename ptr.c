#include <stdio.h>
#include <stdlib.h>

int main(char arg,char* argv[])
{
	int i; 
	char a[]={0x30,0x40,0x65,0x00,0x7e};
	char b='x';
	char *ptr= a;

	printf("&a[]: %p a[]: %p\n",&a,a);
	printf("&b: %p b: %c\n",&b,b);
	printf("&ptr: %p ptr : %p\n",&ptr,ptr);
	for (i = 0; i<(int)sizeof(a);i++)
	{
		printf("%c ", a[i]);
	}
	
	// NOTE : if *ptr == 0x00 (0), then false!!!
	for(;*ptr;ptr++)
	{
		printf("%c *(ptr++) :%p\n",*ptr,(void* )ptr);
	}

	return 0;
}
