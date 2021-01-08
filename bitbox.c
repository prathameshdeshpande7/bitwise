/*
int32_t func(int32_t x) {

return (  x < 0 ) + ( ( x >> 31 ) ^ x );

}

What does this function do?
Does it perform the same function for all values of x?
#define MACRO(x)      ( sizeof(x) / sizeof( *(x) ) )

What is the function of this macro?
int32_t func( uint32_t x ) {

int32_t y;

for ( y=0; x; y = !y )

x ^= x & -x;

return y;

}

What does this function do?
What term can be used to describe this function?
*/

// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define MACRO(x)    ( sizeof(x) / sizeof( *(x) ) )
#define PRINT_BINARY_SEPARATOR		" "
#define PRINT_BINARY_PATTERN_INT8	"%c%c%c%c%c%c%c%c"

#define PRINT_BYTE_TO_BINARY_INT8(i)	\
	(((i) & 0x80ll) ? '1': '0'),		\
	(((i) & 0x40ll) ? '1': '0'),		\
	(((i) & 0x20ll) ? '1': '0'),		\
	(((i) & 0x10ll) ? '1': '0'),		\
	(((i) & 0x08ll) ? '1': '0'),		\
	(((i) & 0x04ll) ? '1': '0'),		\
	(((i) & 0x02ll) ? '1': '0'),		\
	(((i) & 0x01ll) ? '1': '0')

#define PRINT_BINARY_PATTERN_INT16	\
	PRINT_BINARY_PATTERN_INT8	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT8

#define PRINT_BYTE_TO_BINARY_INT16(i)	\
	PRINT_BYTE_TO_BINARY_INT8((i) >> 8), PRINT_BYTE_TO_BINARY_INT8(i)

#define PRINT_BINARY_PATTERN_INT32	\
	PRINT_BINARY_PATTERN_INT16	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT16

#define PRINT_BYTE_TO_BINARY_INT32(i)	\
	PRINT_BYTE_TO_BINARY_INT16((i) >> 16),	PRINT_BYTE_TO_BINARY_INT16(i)

#define PRINT_BINARY_PATTERN_INT64	\
	PRINT_BINARY_PATTERN_INT32	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT32

#define PRINT_BYTE_TO_BINARY_INT64(i)	\
	PRINT_BYTE_TO_BINARY_INT32((i) >> 32), PRINT_BYTE_TO_BINARY_INT32(i)
	
int32_t func2( uint32_t x ) {

    int32_t y, res;

    for ( y=0; x; y = !y )
    {
        printf("x:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", x, PRINT_BYTE_TO_BINARY_INT32(x));
        printf("-:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", -x, PRINT_BYTE_TO_BINARY_INT32(-x));
        printf("&:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", x & -x, PRINT_BYTE_TO_BINARY_INT32(x & -x));
        printf("y:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", y, PRINT_BYTE_TO_BINARY_INT32(y));
        printf("!y:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", !y, PRINT_BYTE_TO_BINARY_INT32(!y));
        res = x ^ (x & -x);
        printf("^:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", res, PRINT_BYTE_TO_BINARY_INT32(res));
        x ^= x & -x;
        printf("res :  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", x, PRINT_BYTE_TO_BINARY_INT32(x));
        printf("y:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", y, PRINT_BYTE_TO_BINARY_INT32(y));
        printf("\n\n");
    }
    
    printf("y:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", y, PRINT_BYTE_TO_BINARY_INT32(y));
    return y;
}

int32_t func(int32_t x) {
    int32_t y, res;
    
    printf("x:   %10.d " PRINT_BINARY_PATTERN_INT32"\n", x, PRINT_BYTE_TO_BINARY_INT32(x));
    printf("lt:  %10.lld " PRINT_BINARY_PATTERN_INT32"\n", x < 0, PRINT_BYTE_TO_BINARY_INT32(x < 0));
    printf("s:   %10.lld " PRINT_BINARY_PATTERN_INT32"\n", x >> 31, PRINT_BYTE_TO_BINARY_INT32(x >> 31));
    y = (x >> 31) ^ x;
    printf("^:   %10.lld " PRINT_BINARY_PATTERN_INT32"\n", y, PRINT_BYTE_TO_BINARY_INT32(y));
    res = (x < 0) + y;
    printf("+:   %10.lld " PRINT_BINARY_PATTERN_INT32"\n", res, PRINT_BYTE_TO_BINARY_INT32(res));
    return (  x < 0 ) + ( ( x >> 31 ) ^ x );
}

int main() {
    int i;
    int32_t x = 0;
    //int32_t result1 = func(x);
    
    /* this returns 1 if a number has odd bits set, otherwise 0 */
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 31, 32, 127, 128, 1023, 1024, INT_MIN, INT_MAX};
    int n_entries = MACRO(arr);
    int32_t result2;
    printf("\n\n\n");
    for (i = 0; i < n_entries; i++)
    {
        printf("x:   %10.d " PRINT_BINARY_PATTERN_INT32" has %s number of set bits\n", arr[i], PRINT_BYTE_TO_BINARY_INT32(arr[i]), func2(arr[i]) ? "odd" : "even");
        //printf("x = %d, result2: %d", arr[i], func2(arr[i]));
    }
    
    //printf("x:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", x, PRINT_BYTE_TO_BINARY_INT32(x));
    //printf("r1: %10.llu " PRINT_BINARY_PATTERN_INT32"\n", result1, PRINT_BYTE_TO_BINARY_INT32(result1));
    //printf("x:  %10.llu " PRINT_BINARY_PATTERN_INT32"\n", x, PRINT_BYTE_TO_BINARY_INT32(x));
    //printf("r2: %10.llu " PRINT_BINARY_PATTERN_INT32"\n", result2, PRINT_BYTE_TO_BINARY_INT32(result2));

    return 0;
}
