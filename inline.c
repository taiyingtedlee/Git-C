#include <stdio.h>
#include <stdlib.h>

void hal_putchar(int ch);

static inline int trans_ch(unsigned char ch,unsigned char *p)
{
	int n=0;
	*p = ch;

	if(ch == 0x7e){ // '~'
		n=0;
	}else if (ch == 0x5c){ // '\\'
		n=1;
	}else if (ch == 0x06){ // 'ACK'
		n=2;
	}else if (ch == 0x15){ // 'NAK'
		n=3;
	}else if (ch == 0x11){ // 'XON'
		n=4;
	}else if (ch == 0x13){ // 'XOFF'
		n=5;
	}else{
		n=-1;
	}
	
	if (n>=0){
		*(p+0) = 0x5c; // '\\'
		*(p+1) = n;
		return 2;
	}
	return 1; 
}

static inline void trans_ch_putchar(int ch)
{
	unsigned char t[2];
	int n = trans_ch(ch,t);
	
	hal_putchar(t[0]);
	if(n==2)
		hal_putchar(t[1]);
}

int main(char arg,char * argv[])
{
	unsigned char cmd[]={0x80,0x00,0x00,0x00,0x00,0x00,0x7e,0x5c,0x06,0x11,0x13};
	int i;
	for(i=0;i<(int)sizeof(cmd);i++)
	{
		trans_ch_putchar(cmd[i]);
		printf(" ");
	}

	return 0;
}

void hal_putchar(int ch)
{
	printf("%02x",ch);
}
