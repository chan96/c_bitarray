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
	memset(bit_arr->data, value, bit_arr->num_bytes);
}

/*
 * Zeros out the bit array.
 */
void clear_bit_arr(BitArr *bit_arr)
{
	reset_bit_arr(bit_arr, 0);
}

/* 
 * Initializes and returns a BitArr with number of bits = size * sizeof(char).
 */
BitArr *make_bit_arr(int size)
{
    BitArr *bit_arr = (BitArr *) calloc(1, sizeof(BitArr));
    bit_arr->size = size;

	/* add one char to hold the partial bits if needed */
	bit_arr->num_bytes = ((size >> 3) + ((size & MASK) !=0 ? 1 : 0));

	bit_arr->data = (char *) malloc(bit_arr->num_bytes);					
    clear_bit_arr(bit_arr);

    return bit_arr;
}

/* 
 * Returns the bit value at the given offset of bit_arr, 0 or 1.
 */
int get_bit(BitArr *bit_arr, int offset)
{
    int arr_index = offset >> 3;
    int bit_index = offset & MASK;

    return (bit_arr->data[arr_index] & (1 << bit_index)) != 0 ? 1 : 0;
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
 * Returns a copy of the passed bit_arr.
 */
BitArr *copy_bit_arr(BitArr *bit_arr)
{
    int num_bits = bit_arr->size;

    BitArr *copy = make_bit_arr(num_bits);
    memcpy(copy->data, bit_arr->data, bit_arr->num_bytes);

    return copy;
}

/* 
 * Returns 0 if the bit array is empty, else a non-zero number.
 */
int is_empty_bit_arr(BitArr *bit_arr)
{
    return !(*bit_arr->data & (~0));
}

/*
 * Converts a bit array to a human readable string either from left to right
 * or right to left depending on the input direction.
 */
char *bit_to_string(BitArr *bit_arr, int left_right)
{
    int size = bit_arr->size;
    int bit = 0;

    char *bit_str =  malloc((bit_arr->size * sizeof(char)) + 1);	

    if (bit_str != NULL)
    {
	    if (left_right)
	    {
		    for (int pos = 0; pos < size; pos++)
			{
				bit = get_bit(bit_arr, pos);
				bit_str[pos] = (bit > 0 ? '1':'0');
		    }
	    }
	    else  /* from right to left */
	    {
	        for (int pos = 0; pos < size; pos++)
			{
				bit = get_bit(bit_arr, pos);
			    bit_str[size - pos - 1] = (bit > 0 ? '1':'0');
		    }
	    }
        bit_str[size] = '\0';	
    }    

   return bit_str;
}

/* 
 * Prints the given bit array in format <0>* <1>* with an appended
 * '\n' character and given direction.
 */
void print_bit_arr(BitArr *bit_arr, int direction)
{
    char *bit_str = bit_to_string(bit_arr, direction );
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
