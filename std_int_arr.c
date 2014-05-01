#include <stdio.h>
#include <stdlib.h>

#define NUMTESTS 10000000
#define SIZE 5

void set_val(int *int_arr, int val, int offset)
{
    int_arr[offset] = val;
}

int get_val(int *int_arr, int offset)
{
    return int_arr[offset];
}

void flip_val(int *int_arr, int offset)
{
    int_arr[offset] != 0 ? (int_arr[offset] = 0) : (int_arr[offset] = 1);
}

void flip_all(int *int_arr, int len)
{
    for (int pos = 0; pos < len; pos++)
    {
        flip_val(int_arr, pos);
    }
}

void clear_all(int *int_arr, int len)
{
    for (int pos = 0; pos < len; pos++)
    {
        int_arr[pos] = 0;
    }
}

void print_int_arr(int *int_arr, int len)
{
    for (int pos = 0; pos < len; pos++)
    {
        printf("%d", int_arr[pos]);
    }
    printf("\n");
}

int main()
{

    for (int i = 0; i < NUMTESTS; i++)
    {
    
        int *int_arr = calloc(SIZE, sizeof(int)); 
        for (int j = 0; j < SIZE; j++)
        {
            set_val(int_arr, 1, j);
            get_val(int_arr, j);
            flip_val(int_arr, j);
            flip_all(int_arr, SIZE);
            clear_all(int_arr, SIZE);
        }

        free(int_arr); 
    }
    return 0;
}
