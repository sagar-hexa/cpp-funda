#include <stdio.h>

unsigned int toggle_endian(unsigned int x, int atomicity);
unsigned int
toggle_endian(unsigned int x, int atomicity)
{
	unsigned int t = 0;
	unsigned int mask, sft_amt;

	switch (atomicity)
	{
	case 8:
		mask = 0xff;
		sft_amt = 8;
		break;

	case 16:
		mask = 0xffff;
		sft_amt = 16;
		break;

	default:
		/* Invalid atomicity value, return 0x0 */
		return 0x0;
	}

	while (x)
	{
		t <<= sft_amt;
		t |= (x & mask);
		x >>= sft_amt;
	}
	return t;
}




/* Function main. Drives the toggle_endian() function */
int
main(void)
{
	unsigned int hex;

	/*printf("\nEnter a Hex Number : ");
	scanf("%x", &hex);*/

	hex = -61138432;
	printf("\nEntered Number  : %X", hex);
	printf("\nOpposite Endian With 8bit atomicity : %X",
		toggle_endian(hex, 8));
	printf("\nOpposite Endian With 16bit atomicity : %X\n",
		toggle_endian(hex, 8));

	return 0;
}