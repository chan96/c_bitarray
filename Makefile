bitarray_char:
	gcc -std=gnu99 -Werror -Wall -g bitarray_char.c testdriver.c
	./a.out

bitarray_int:
	gcc -std=gnu99 -Werror -Wall -g bitarray_int.c testdriver.c
	./a.out
