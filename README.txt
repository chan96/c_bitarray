I have created:
    -bitarray/bitvector library (bitarray_char.c with bitarray_char.h header)

    -int array implementation for comparison with bitarray (std_int_arr.c)

    -Makefile (make sure to comment out main() function in bitarray_char.c
    if you want to use) Compiles bit_array_char.c with the testdriver.

    -testdriver (testdriver.c) which tests bit_array_char.c 

    -benchmark (benchmark.c) which is a model for what is put in the main()
    method of bitarray_char.c and is used for benchmarking the bitarray vs
    the std_int_arr.c. You should not link benchmark.c with anything, as it
    is put in the main method of bitarray_char.c and std_int_arr.c.

    -A report.pdf that explains the things I learned about bitvectors, and 
    some analysis of performance and memory consumption comparisons.





    For the below, you can modify the DEFINE and NUMTESTS definitions in 
    bitarray_char.c and std_int_arr.c and compare results. Also, you must
    uncomment the main() functions in bit_array_char.c and std_int_arr.c
    in order for the below to work.


    -BenchCompare script that compares the execution time of bitarray_char.c
    and std_intarr.c

    -GenPerfStats that uses Gprof to generate execution statistics on both     
    bitarray_char.c and std_int_arr.c.

    -MemCompare script that compares the memory allocation of bitarray_char.c
    and std_int_arr.c. You can modify the NUMTESTS and SIZE definitions in 
    bitarray_char.c and std_int_arr.c




    (note: there is an "other" folder that has an older implementation of an int
    based bitarray I used to compare with the char based bit array. This int
    version has most methods, but was used for different older testing.)

    

This was a lot of work but well worth the time. Originally I though bitarrays
would be annoying to work with, but it is actually very interesting, and has
peaked my interest in analysis of algorithms and operating systems (bit shifting
is fun), and I hope to work more with these kinds of projects in the future.
Also, feel free to try out my scripts and do different tests. Enjoy :)
