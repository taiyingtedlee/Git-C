#include <stdio.h>
#include <stdlib.h>

int main(char arg,char* argv[])
{
	int i; 
	char a[]="hello world!";
	char b='x';
	char *ptr= a;

	printf("&a[]: %p a[]: %p\n",&a,a);
	printf("&b: %p b: %c\n",&b,b);
	printf("&ptr: %p ptr : %p\n",&ptr,ptr);
	for (i = 0; i<(int)sizeof(a);i++)
	{
		printf("%c ", a[i]);
	}
	
	for(;*ptr;++ptr)
	{
		printf("%c *(ptr++) :%p\n",*ptr,(void* )ptr);
	}

	return 0;
}
