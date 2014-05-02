#include <stdio.h>
#include <stdlib.h>

#define NUMTESTS 1000000
#define SIZE 10

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
        int_arr[pos] != 0 ? (int_arr[pos] = 0) : (int_arr[pos] = 1);
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

void fill_all(int *int_arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int_arr[i] = 1;
    }
}

/*int main()
{

    for (int i = 0; i < NUMTESTS; i++)
    {
    
        int *int_arr = calloc(SIZE, sizeof(int)); 
        for (int j = 0; j < SIZE; j++)
        {
            set_val(int_arr, 1, j);
            get_val(int_arr, j);
            flip_val(int_arr, j);
        }
        fill_all(int_arr, SIZE);
        clear_all(int_arr, SIZE);

        free(int_arr); 
    }
    return 0;
}*/
