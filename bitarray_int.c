#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitarray_int.h"
#define MASK 0x1f

/*
 * Bitvector (ie. bitarray) library
 * Author: Brian Chan
 */

/*
reset the entire bit_arr with the input value 0 or 1
*/
void reset_bit_arr(BitArr *bit_arr, int value)
{
	memset(bit_arr->data, value, bit_arr->numBytes);
}

/*
 * Zeros out the bit array.
 */
void clear_bit_arr(BitArr *bit_arr)
{
	reset_bit_arr(bit_arr, 0);
}

/* 
 * Initializes and returns a BitArr with number of bits = size * sizeof(int).
 */
BitArr *make_bit_arr(int size)
{
	int sizeDiv32 = size >> 5;		/* 32 bits per 4 byte int */
	int sizeMod32 = size & MASK;

    BitArr *bit_arr = (BitArr *) calloc(1, sizeof(BitArr));
    bit_arr->size = size;

	/* add one int to hold the partial bits if needed */
	bit_arr->numBytes = (sizeDiv32 * sizeof(int))  + (sizeMod32 != 0 ?  sizeof(int) : 0);

	bit_arr->data = (int *) malloc(bit_arr->numBytes);					
	clear_bit_arr(bit_arr);
	
    return bit_arr;
}

/* 
 * Returns the bit value at the given offset of bit_arr, 0 or 1.
 */
int get_bit(BitArr *bit_arr, int offset)
{
	/*
    return (bit_arr->data[offset >> 5] & (1 << (offset & MASK))) != 0 ? 1 : 0;
	*/
	return (bit_arr->data[offset / 32 ] & (1 << (offset % 32))) != 0 ? 1 : 0;

}

/* 
 * Sets the bit value in bit_arr to val (0 or 1) at offset in bit_arr.
 */
void set_bit(BitArr *bit_arr, int offset, int val)
{
    int arr_index = offset >> 5;
/*    int arr_bit_pos = offset & MASK;
*/
	int arr_bit_pos = offset % 32;

    if (val) { bit_arr->data[arr_index] |= (1 << arr_bit_pos); }
    else { bit_arr->data[arr_index] &= ~(1 << arr_bit_pos); }
}

/*
 * Sets the bits of the bit array to all 1s.
 */
void fill_bit_arr(BitArr *bit_arr)
{
	reset_bit_arr(bit_arr, ~0);
}

/*
converts a bit array to a string either from left to right or right to left depending on the input direction
*/
char *bit_to_string(BitArr *bit_arr, int left_right)
{
   int size = bit_arr->size;
   int bit = 0;
   int j;

   char *bit_str = (char *) malloc(bit_arr->size + 1);	

   if (bit_str != NULL)
   {
	   if (left_right)
	   {
		   for (j=0; j<size; j++)
			{
				bit = get_bit(bit_arr, j);
				*(bit_str + j) = (bit > 0 ? '1':'0');
			}
	   }
	   else  /* from right to left */
	   {
		   for (j=0; j<size; j++)
			{
				bit = get_bit(bit_arr, j);
				*(bit_str + (size - j - 1)) = (bit > 0 ? '1':'0');
			}
	   }
   *(bit_str + size) = '\0';	
   }

   return bit_str;
}

/* 
 * Prints the given bit array in format <0>* <1>* with an appended
 * '\n' character.
 */
void print_bit_arr(BitArr *bit_arr)
{
    char *bit_str = bit_to_string(bit_arr, 0 ); /* print the string using the right to left option */
    //printf("%s\n", bit_str);

    free(bit_str);
}

void print_reverse_bit_arr(BitArr *bit_arr)
{
    char *bit_str = bit_to_string(bit_arr, 1); /* print the string using the left to right option */
    //printf("%s\n", bit_str);
	
    free(bit_str);
}

/* 
 * Frees the given bit array and its pointers.
 */
void free_bit_arr(BitArr *bit_arr)
{

    free(bit_arr->data);
    free(bit_arr);
}
