/*
 * BitReverse.c 
 * Based on an interview question given me by Apple.
 * No lisence; free to copy.
 * Wesley "Weshmek"  Chalmers
 */

#include <stdio.h>
#include <assert.h>


static unsigned char reversed_byte_map[256];

static int populate_reversed_byte_map(void)
{
	unsigned char c;
	int i, j;
	for (i = 0; i < sizeof(reversed_byte_map) / sizeof(unsigned char); i++)
	{
		c = i & 0xff;
		reversed_byte_map[i] = 0;
		for (j = 0; j < 7; j++)
		{
			reversed_byte_map[i] |= ((c >> j) & 0x1);
			reversed_byte_map[i] = (reversed_byte_map[i] << 1) & 0xfe;
		}
		reversed_byte_map[i] |= (c >> 7) & 0x1;
		reversed_byte_map[i] &= 0xff;
	}
	return 0;
}


static unsigned char reverse_byte(unsigned char c)
{
	return reversed_byte_map[c];
}


static int reverse_buffer(unsigned char* buf, int L)
{
	int i;
	buf = buf - 1;

	for (i = 1; i <= (L  / 2); i++)
	{
		buf[i] = reverse_byte(buf[i]);
		buf[L - i + 1] = reverse_byte(buf[L - i + 1]);
		buf[i] = buf[i] ^ buf[L - i + 1];
		buf[L - i + 1] = buf[i] ^ buf[L - i + 1];
		buf[i] = buf[i] ^ buf[L - i + 1];
	}
	if (L % 2 != 0)
	{
		buf[(L / 2) + 1] = reverse_byte(buf[(L / 2) + 1]);
	}
	return 0;
}


int main(void)
{
	int r;
	printf("%x\n", 0x1 << 7);
	printf("%u\n", ((unsigned char) -1));
	printf("Populating...\n");
	r = populate_reversed_byte_map();
	if (r != 0)
	{
		goto fail;
	}
	printf("Done Populating\n");
	assert(reverse_byte(0) == 0);

	int i;
	unsigned char string[] = {0x01, 0x12, 0x23, 0x34, 0x45, 0xef};
	unsigned char string2[] = {0x01, 0x12, 0x23, 0x34, 0x45, 0xef, 0x79};
	
	for (i = 0; i < sizeof(string) / sizeof(unsigned char); i++)
	{
		int p = string[i] & 0xff;
		printf("%x", p);
	}
	printf("\n");
	reverse_buffer(string, sizeof(string) / sizeof(unsigned char));
	for ( i = 0; i < sizeof(string) / sizeof(unsigned char); i++)
	{
		int p = string[i];
		printf("%x", p);
	}
	printf("\n");
	printf("%c -> %c\n", 0x98, reverse_byte(0x98));

	for(i = 0; i < sizeof(string2) / sizeof(string2[0]); i++)
	{
		printf("%x", string2[i]);
	}
	printf("\n");
	reverse_buffer(string2, sizeof(string2) / sizeof(string2[0]));
	for (i = 0; i < sizeof(string2) / sizeof (string2[0]); i++)
	{
		printf("%x", string2[i]);
	}
	printf("\n");


// 0x98 = 10011000
// rev(0x98) = 00011001 = 0x19
// 70 = 01110000
	printf("%x -> %x\n", 0x98, reverse_byte(0x98));
	printf("%x -> %x\n", 0x19, reverse_byte(0x19));
	printf("%x -> %x\n", 0x45, reverse_byte(0x45));
	printf("%x -> %x\n", 0xc4, reverse_byte(0xc4));
	assert(reverse_byte(0x98) == 0x19);
	assert(reverse_byte(0x01) == 0x80);
	assert(reverse_byte(0x12) == 0x48);
	assert(reverse_byte(0x23) == 0xc4);
	assert(reverse_byte(0x34) == 0x2c);
	assert(reverse_byte(0x45) == 0xa2);
	assert(reverse_byte(0xef) == 0xf7);
	assert(reverse_byte(0x79) == 0x9e);

	return 0;
fail:
	printf("Could not populate the array!\n");
	return 1;
}
		
		
