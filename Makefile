bitarray_char: 
	gcc -std=gnu99 -Werror -Wall -g bitarray_char.c testdriver.c -o bc.out
	./bc.out

bitarray_int:
	gcc -std=gnu99 -Werror -Wall -g bitarray_int.c testdriver.c -o bi.out
	./bi.out
clean:
	rm -f *.out
