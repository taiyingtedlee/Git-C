#include <stdio.h>
#include <stdlib.h>

int plus(int a, int b);
int greater(int a,int b);
// NOTE : typedef ( ABC )  ; ABC is type, just like int. therefore, there is no  &int or &ABC.
typedef int (*func_ptr_new)(int x, int y);

int main(char arg, char *argv[])
{
	int ret;
	int (*func_ptr)(int,int);
	func_ptr=&plus;
	ret= ((func_ptr)(6,5));
	
	printf("func_ptr(6,5) : %d\n",ret);
	printf("func_ptr : %p\n",func_ptr);
	printf("plus(3,5) : %d &plus : %p\n",plus(3,5),&plus);
	
	ret=((func_ptr_new)plus)(7,8);
	printf("(func_ptr(plus))(7,8) : %d\n",ret);
	printf("plus : %p\n",plus);
	
	printf("greater : %d\n",((func_ptr_new)greater)(5,17));
	return 0;
}

int plus(int a, int b)
{	
	return a+b;
}

int greater(int a, int b)
{
	return (a>b ? a:b);
}
