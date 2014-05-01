#include "bitarray_char.h"
#include <stdlib.h>
#include <stdio.h>

#define NUMTESTS 10000000
#define SIZE 5

int main()
{

    for (int i = 0; i < NUMTESTS; i++)
    {
        BitArr *bit_arr = make_bit_arr(SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            set_bit(bit_arr, j, 1);
            get_bit(bit_arr, j);
            flip_bit(bit_arr, j);
            fill_bit_arr(bit_arr);
            clear_bit_arr(bit_arr);
        }

        free_bit_arr(bit_arr);
    }
    return 0;
}
