#include<stdio.h>

#define SEPARATOR	" "
#define PRINT_BINARY8	"%c%c%c%c%c%c%c%c"

#define PRINT_BINARY16		\
	PRINT_BINARY8	SEPARATOR	PRINT_BINARY8

#define PRINT_BINARY32		\
	PRINT_BINARY16 	SEPARATOR	PRINT_BINARY16

#define PRINT_BYTE8(i)			\
	(((i) & 0x80) ? '1' : '0'),	\
	(((i) & 0x40) ? '1' : '0'),	\
	(((i) & 0x20) ? '1' : '0'),	\
	(((i) & 0x10) ? '1' : '0'),	\
	(((i) & 0x08) ? '1' : '0'),	\
	(((i) & 0x04) ? '1' : '0'),	\
	(((i) & 0x02) ? '1' : '0'),	\
	(((i) & 0x01) ? '1' : '0')

#define PRINT_BYTE16(i)			\
	PRINT_BYTE8((i) >> 8),	PRINT_BYTE8(i)

#define PRINT_BYTE32(i)			\
	PRINT_BYTE16((i) >> 16),	PRINT_BYTE16(i)
void update_fields(int *p, unsigned char c)
{
	unsigned int mask = (0x3 << 17);

	printf("Mask value is: " PRINT_BINARY32"\n", PRINT_BYTE32(mask));

	*p = (*p & ~mask) | ((c << 17) & mask);
	printf("Value is: " PRINT_BINARY32"\n", PRINT_BYTE32(*p));
}

void main()
{
	int val = 458752;
	unsigned char c = 1;


	printf("Binary value of %u is: " PRINT_BINARY32"\n", val, PRINT_BYTE32(val));
	update_fields(&val, c);
	printf("Output value of %u is: " PRINT_BINARY32"\n", val, PRINT_BYTE32(val));
}
