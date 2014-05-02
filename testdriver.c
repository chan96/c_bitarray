#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitarray_char.h"

/* 
 * TESTDRIVER
 * To be used with bitarray_char.c
 */

BitArr *bit_arr;

void test_get_bit(int offset)
{
    int bit_val = get_bit(bit_arr,offset);
    printf("Bit returned at offset  %d (non-zero if set to 1): %d\n", offset, bit_val);
}

void test_set_bit(int offset, int val)
{
    set_bit(bit_arr, offset, val);
    printf("Bit at offset %d set to %d\n", offset, val);
}

void test_clear_bit_arr(BitArr *bit_arr)
{
    clear_bit_arr(bit_arr);
    printf("Bit array cleared\n");
}

void test_fill_bit_arr(BitArr *bit_arr)
{
    fill_bit_arr(bit_arr);
    printf("Bit array filled with 1s\n");
}

void test_copy_bit_arr(BitArr *bit_arr)
{
    BitArr *copy = copy_bit_arr(bit_arr);
    char *copy_str = bit_to_string(copy, 1);

    printf("Copied bit array is: %s (L-R)\n", copy_str);

    free_bit_arr(copy);
    free(copy_str);
}

void test_is_empty_bit_arr(BitArr *bit_arr)
{
    printf("Test is empty bit array: %d\n", is_empty_bit_arr(bit_arr));
}

void test_flip_bit(BitArr *bit_arr, int offset)
{
    print_bit_arr(bit_arr, 1);
    flip_bit(bit_arr, offset);
    printf("Flipped bit at offset %d\n", offset);
    print_bit_arr(bit_arr, 1);
}

void test_free_bit_arr()
{
    free_bit_arr(bit_arr);
    printf("Bit array freed\n");
}

void test_print_bit_arr(BitArr *bit_arr, int direction)
{
    printf("Printed bit string: ");
    print_bit_arr(bit_arr, direction);
}

int main()
{
	int num_bits = 36;

    printf("----------Bit Array Test Driver----------\n\n");
    printf("Number of bits specified (and will be printed): %d\n", num_bits);

	//printf("Enter Bit Array Size (number of bits): ");
	//scanf ("%d", &num_bits);
    bit_arr = make_bit_arr(num_bits);
    printf("Number of bytes actually allocated: %d\n", bit_arr->num_bytes);

	test_print_bit_arr(bit_arr, 1);

    test_fill_bit_arr(bit_arr);
	test_print_bit_arr(bit_arr, 1);
    test_clear_bit_arr(bit_arr);
    test_print_bit_arr(bit_arr, 1);

    test_set_bit(5, 1);
    test_set_bit(1, 1);
    test_set_bit(18, 1);
    test_set_bit(32, 1);

    test_flip_bit(bit_arr, 5);
    test_get_bit(5);
    test_get_bit(1);

    test_print_bit_arr(bit_arr, 1);
    test_copy_bit_arr(bit_arr);
    printf("Reversed bit string (R-L): ");
    test_print_bit_arr(bit_arr, 0);
    test_is_empty_bit_arr(bit_arr);
    test_clear_bit_arr(bit_arr);
    test_is_empty_bit_arr(bit_arr);

    test_print_bit_arr(bit_arr, 1);
    test_free_bit_arr();

    printf("-----------End of Test Driver------------\n");
}

