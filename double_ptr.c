#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char arg, char * argv[])
{
	unsigned char a1[]={"hello"};
	unsigned char a2[]={'w','o','r','l','d','!'};
	unsigned char *p,*p2;
	unsigned char **ptr;

	p=a1;
	printf("sizeof(p) : %d\n",(int)sizeof(p));
	printf("&p : %p p : %p *p : %c\n",&p,p,*p);
	printf("sizeof(a1) : %d\n",(int)sizeof(a1));
	printf("&a1[] : %p a1[] : %p\n",&a1,a1);
	printf("sizeof(a2) : %d\n",(int)sizeof(a2));
	printf("&a2[] : %p a2[] : %p a2[0] : %c a2[1] : %c\n",&a2,a2,a2[0],a2[1]);

	ptr=&p;
	printf("sizeof(ptr) : %d\n",(int)sizeof(ptr));
	printf("&ptr : %p ptr : %p *ptr: %p *ptr: %s **ptr: %c \n",&ptr,ptr,*ptr,*ptr,**ptr);

	p2=a2;
	ptr=&p2;
	printf("ptr+1 : %p *(ptr+1) : %p *(ptr+1) : %s **(ptr+1) : %c\n",ptr+1,*(ptr+1),*(ptr+1),**(ptr+1));
	return 0;
}
