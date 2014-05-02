test_bitarray_char: 
	gcc -std=gnu99 -Werror -Wall -g bitarray_char.c testdriver.c -o bc.out
	./bc.out

clean:
	rm -f *.out
