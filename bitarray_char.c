#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitarray_char.h"

#define MASK 0x07

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
    int size_div8 = size >> 3;		/* 8 bits per 1 byte */
	int size_mod8 = size & MASK;

    BitArr *bit_arr = (BitArr *) calloc(1, sizeof(BitArr));
    bit_arr->size = size;

	/* add one int to hold the partial bits if needed */
	bit_arr->numBytes = (size_div8 * sizeof(char))  + (size_mod8 != 0 ?  sizeof(char) : 0);

	bit_arr->data = (char *) malloc(bit_arr->numBytes);					
	clear_bit_arr(bit_arr);
	
    return bit_arr;
}

/* 
 * Returns the bit value at the given offset of bit_arr, 0 or 1.
 */
int get_bit(BitArr *bit_arr, int offset)
{
    return (bit_arr->data[offset / 8 ] & (1 << (offset % 8))) != 0 ? 1 : 0;
}

/* 
 * Sets the bit value in bit_arr to val (0 or 1) at offset in bit_arr.
 */
void set_bit(BitArr *bit_arr, int offset, int val)
{
	int arr_index = offset >> 3;	 /* index to the closest byte */
    int bit_index = offset & MASK;

	if (val)	
    {
        /*  use bitwise OR on bitmask with all zeros except 1 in the desired position */	
		bit_arr->data[arr_index] |= (1 << bit_index);		    
    }
	else				
    {
	    /* otherwise set the bit to zero */
    	bit_arr->data[arr_index] &= (~ (1 << bit_index));	
    }
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
void print_bit_arr(BitArr *bit_arr, int direction)
{
    char *bit_str = bit_to_string(bit_arr, direction ); /* print the string using the right to left option */
    printf("%s\n", bit_str);

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
