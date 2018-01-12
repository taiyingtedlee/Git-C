#include <stdio.h>
#include <stdlib.h>


struct setting_result 
{
	unsigned char pid;
	unsigned short size;
	unsigned char arr[10];
};
/*
static struct setting_result shk_default =
{
	.pid=0x01,
	.size=3,
	.arr={0x00,0x00,0x00},
};

static struct setting_result xtx_default =
{
	.pid=0x00,
	.size=1,
	.arr={0x00},
};
*/
static struct setting_result Itf_default[]=
{
	{0,1,0x00},
	{1,3,{0x00,0x00,0x00}},
};

int main(char arg, char * argv[])
{
	int num;
	struct setting_result *Result;

	printf("input : ");
	scanf("%d",&num);
	
	printf("pid : %02x\n",Result[num].pid);
	printf("size : %d\n",Result[num].size);

	return 0;
}
