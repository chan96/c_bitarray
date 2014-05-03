/* 
 * Defines the bit array struct. "data" is the actual bit array 
 * and based on char. size is the number of bits. 
 */

typedef struct bitarr
{
    char *data;
    unsigned short size;			/* use unsigned short to store size (save memory and will unlikely
                            be so big*/
	unsigned short num_bytes;		/* use unsigned short to store  number of bytes required for the array */

} BitArr;

/*
 * Reset the entire bit_arr with the input value 0 or 1.
 */
void reset_bit_arr(BitArr *bit_arr, int value);

/* 
 * Initializes and returns a BitArr with number of bits = size.
 */
BitArr *make_bit_arr(int size);

/* 
 * Returns a non-zero number if the bit is set.
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
 * Returns 0 if the bit array is empty, else 1
 */
int is_empty_bit_arr(BitArr *bit_arr);

/* 
 * Flips the current state of the bit at offset (0 or 1).
 */
void flip_bit(BitArr *bit_arr, int offset);

/* 
 * Returns the length of the bit array in num bits.
 */
int get_bit_len(BitArr *bit_arr);
    
/* 
 * Converts a bit array to a human readable string either from left to right
 * or right to left depending on the input direction. (1 is L-R, 0 is R-L).
 */
char *bit_to_string(BitArr *bit_arr, int left_right);

/* 
 * Prints the given bit array in format <0>* <1>* with an appended
 * '\n' character and given direction (1 is L-R, 0 is R-L).
 */
void print_bit_arr(BitArr *bit_arr, int direction);

/* 
 * Frees the given bit array and its pointers.
 */
void free_bit_arr(BitArr *bit_arr);
