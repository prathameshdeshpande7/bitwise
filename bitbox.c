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

x: -2147483648  10000000 00000000 00000000 00000000  absolute value:   2147483648
x:       -4096  11111111 11111111 11110000 00000000  absolute value:         4096
x:       -1024  11111111 11111111 11111100 00000000  absolute value:         1024
x:       -1023  11111111 11111111 11111100 00000001  absolute value:         1023
x:        -512  11111111 11111111 11111110 00000000  absolute value:          512
x:        -511  11111111 11111111 11111110 00000001  absolute value:          511
x:        -128  11111111 11111111 11111111 10000000  absolute value:          128
x:        -127  11111111 11111111 11111111 10000001  absolute value:          127
x:          -2  11111111 11111111 11111111 11111110  absolute value:            2
x:          -1  11111111 11111111 11111111 11111111  absolute value:            1
x:           0  00000000 00000000 00000000 00000000  absolute value:            0
x:           1  00000000 00000000 00000000 00000001  absolute value:            1
x:           2  00000000 00000000 00000000 00000010  absolute value:            2
x:         127  00000000 00000000 00000000 01111111  absolute value:          127
x:         128  00000000 00000000 00000000 10000000  absolute value:          128
x:         511  00000000 00000000 00000001 11111111  absolute value:          511
x:         512  00000000 00000000 00000010 00000000  absolute value:          512
x:        1023  00000000 00000000 00000011 11111111  absolute value:         1023
x:        1024  00000000 00000000 00000100 00000000  absolute value:         1024
x:  2147483647  01111111 11111111 11111111 11111111  absolute value:   2147483647



x: -2147483648  10000000 00000000 00000000 00000000  has odd(1) number of set bits
x:       -4096  11111111 11111111 11110000 00000000  has even(20) number of set bits
x:       -1024  11111111 11111111 11111100 00000000  has even(22) number of set bits
x:       -1023  11111111 11111111 11111100 00000001  has odd(23) number of set bits
x:        -512  11111111 11111111 11111110 00000000  has odd(23) number of set bits
x:        -511  11111111 11111111 11111110 00000001  has even(24) number of set bits
x:        -128  11111111 11111111 11111111 10000000  has odd(25) number of set bits
x:        -127  11111111 11111111 11111111 10000001  has even(26) number of set bits
x:          -2  11111111 11111111 11111111 11111110  has odd(31) number of set bits
x:          -1  11111111 11111111 11111111 11111111  has even(32) number of set bits
x:           0  00000000 00000000 00000000 00000000  has even(0) number of set bits
x:           1  00000000 00000000 00000000 00000001  has odd(1) number of set bits
x:           2  00000000 00000000 00000000 00000010  has odd(1) number of set bits
x:         127  00000000 00000000 00000000 01111111  has odd(7) number of set bits
x:         128  00000000 00000000 00000000 10000000  has odd(1) number of set bits
x:         511  00000000 00000000 00000001 11111111  has odd(9) number of set bits
x:         512  00000000 00000000 00000010 00000000  has odd(1) number of set bits
x:        1023  00000000 00000000 00000011 11111111  has even(10) number of set bits
x:        1024  00000000 00000000 00000100 00000000  has odd(1) number of set bits
x:  2147483647  01111111 11111111 11111111 11111111  has odd(31) number of set bits


*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define MACRO(x)    ( sizeof(x) / sizeof( *(x) ) )
#define PRINT_BINARY_SEPARATOR          " "
#define PRINT_BINARY_PATTERN_INT8       "%c%c%c%c%c%c%c%c"

#define PRINT_BYTE_TO_BINARY_INT8(i)    \
        (((i) & 0x80ll) ? '1': '0'),            \
        (((i) & 0x40ll) ? '1': '0'),            \
        (((i) & 0x20ll) ? '1': '0'),            \
        (((i) & 0x10ll) ? '1': '0'),            \
        (((i) & 0x08ll) ? '1': '0'),            \
        (((i) & 0x04ll) ? '1': '0'),            \
        (((i) & 0x02ll) ? '1': '0'),            \
        (((i) & 0x01ll) ? '1': '0')

#define PRINT_BINARY_PATTERN_INT16      \
        PRINT_BINARY_PATTERN_INT8       PRINT_BINARY_SEPARATOR  PRINT_BINARY_PATTERN_INT8

#define PRINT_BYTE_TO_BINARY_INT16(i)   \
        PRINT_BYTE_TO_BINARY_INT8((i) >> 8), PRINT_BYTE_TO_BINARY_INT8(i)

#define PRINT_BINARY_PATTERN_INT32      \
        PRINT_BINARY_PATTERN_INT16      PRINT_BINARY_SEPARATOR  PRINT_BINARY_PATTERN_INT16

#define PRINT_BYTE_TO_BINARY_INT32(i)   \
        PRINT_BYTE_TO_BINARY_INT16((i) >> 16),  PRINT_BYTE_TO_BINARY_INT16(i)

#define PRINT_BINARY_PATTERN_INT64      \
        PRINT_BINARY_PATTERN_INT32      PRINT_BINARY_SEPARATOR  PRINT_BINARY_PATTERN_INT32

#define PRINT_BYTE_TO_BINARY_INT64(i)   \
        PRINT_BYTE_TO_BINARY_INT32((i) >> 32), PRINT_BYTE_TO_BINARY_INT32(i)

    
/* computes the absolute value of a 32-bit signed integer */
int32_t func1(int32_t x) {
    return (  x < 0 ) + ( ( x >> 31 ) ^ x );
}

/* this function returns 1 if a 32-bit signed integer
 * has an odd number of bits set, 0 otherwise.
 */
int32_t func2( uint32_t x, int *count_set_bits ) { 

    int32_t y, res;

    for ( y=0; x; y = !y )
    {   
        x ^= x & -x; 
        (*count_set_bits)++;
    }
    return y;
}

int main() {
    int i;
    int32_t arr[] = {INT_MIN, -4096, -1024, -1023, -512, -511, -128, -127, -2, -1, 0, 1, 2, 127, 128, 511, 512, 1023, 1024, INT_MAX};

    /* MACRO returns the number of elements in the object passed.
     * sizeof operator yields the size in bytes of its operand. 
     * In this case, the object is an array, so sizeof(arr) is the
     * number of bytes occupied by the array. sizeof(*arr) is dereferencing
     * the first element of the array and calculating its size, which is typically
     * 4 bytes for an integer type. Thus, the macro returns the number of elements
     * in the array.
     */
    int n_entries = MACRO(arr);
    int32_t result;

    int count_one_bits = 0;
    for (i = 0; i < n_entries; i++)
    {
        /* returns absolute value of a number */
        result = func1(arr[i]);
        printf("x:%12.1d  " PRINT_BINARY_PATTERN_INT32"  absolute value: %12.1u\n", arr[i], PRINT_BYTE_TO_BINARY_INT32(arr[i]), result);
    }

    printf("\n\n\n");

    for (i = 0; i < n_entries; i++)
    {
        /* modified func2 for returning number of set bits */
        result = func2(arr[i], &count_one_bits);
        printf("x:%12.1d  " PRINT_BINARY_PATTERN_INT32"  has %s(%d) number of set bits\n", arr[i], PRINT_BYTE_TO_BINARY_INT32(arr[i]), result ? "odd" : "even", count_one_bits);
        count_one_bits = 0;
    }
    return 0;
}
