#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char arg, char * argv[])
{
	
	unsigned char *p,*p2;
	unsigned char a1[]={"hello"};
	unsigned char a2[]={'w','o','r','l','d','!'};
	int array[3][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},};
	int **pptr;
	void * void_p;
	void ** void_pp;

	p=a1;
	printf("sizeof(p) : %d\n",(int)sizeof(p));
	printf("sizeof(a1) : %d\n",(int)sizeof(a1));
	printf("sizeof(a2) : %d\n",(int)sizeof(a2));
	printf("sizeof(pptr) : %d  &ptr : %p\n",(int)sizeof(pptr),&pptr);
	printf("sizeof(void_p) : %d  &ptr : %p\n",(int)sizeof(void_p),&void_p);
	printf("sizeof(void_pp) : %d  &ptr : %p\n",(int)sizeof(void_pp),&void_pp);
	
	// NOTE : Multidimensional arrays v.s pointer to pointer 
	// Arrays are syntactically different from pointers. 
	// Specifically, this means the compiler/machine will treat them differently. check assembly for further details

	*pptr=array[0];
	**pptr=array[0][0];

	printf("&p : %p p : %p *p : %c\n",&p,p,*p);
	printf("&a1[] : %p a1[] : %p\n",&a1,a1);
	printf("&a2[] : %p a2[] : %p a2[0] : %c a2[1] : %c\n",&a2,a2,a2[0],a2[1]);

	printf("&pptr: %p pptr: %p *pptr: %p\n",&pptr,pptr,*pptr);

	printf("&array[0] : %p &array[1] : %p\n",&array[0],&array[1]);
	printf("&array[0][0] : %p &array[0][1] : %p &array[1][1]: %p\n",&array[0][0],&array[0][1],&array[1][1]);
//	printf("&ptr : %p ptr : %p *ptr: %p *ptr: %s **ptr: %c \n",&ptr,ptr,*ptr,*ptr,**ptr);

	return 0;
}


