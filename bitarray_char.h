/* 
 * Defines the bit array struct. "data" is the actual bit array 
 * (normally 32 bits and is the default word size), and "size" 
 * is the multiple length of the array.
 */

typedef struct bitarr
{
    char *data;
    int size;			/* number of bits */
	int num_bytes;		/* number of bytes required for the array */

} BitArr;

/* 
 * Initializes and returns a BitArr with number of bits = size * sizeof(int)
 */
BitArr *make_bit_arr(int size);

/* 
 * Returns the bit value at the given offset of bit_arr, 0 or positive value.
 */
int get_bit(BitArr *bit_arr, int offset);

/* 
 * Sets the bit value in bit_arr to val (0 or 1) at offset in bit_arr.
 */
void set_bit(BitArr *bit_arr, int offset, int val);

/*
 * Zeros out the bit array.
 */
void clear_bit_arr(BitArr *bit_arr);

/*
 * Sets the bits of the bit array to all 1s
 */
void fill_bit_arr(BitArr *bit_arr);

/* 
 * Returns a copy of the passed bit_arr.
 */
BitArr *copy_bit_arr(BitArr *bit_arr);

/* 
 * Returns 0 if the bit array is empty, else a non-negative number.
 */
int is_empty_bit_arr(BitArr *bit_arr);

/* 
 * Flips the current state of the bit at offset (0 or 1).
 */
void flip_bit(BitArr *bit_arr, int offset);

/* 
 * Converts the bit array to a string representation of <0>* <1>*
 */
char *bit_to_string(BitArr *bit_arr, int left_right);

/* 
 * Prints the given bit array in format <0>* <1>* with an appended
 * '\n' character. Direction of 1 to print L to R, or 0 to print R to L.
 */
void print_bit_arr(BitArr *bit_arr, int direction);

/* 
 * Frees the given bit array and its pointers.
 */
void free_bit_arr(BitArr *bit_arr);
