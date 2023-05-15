LIBS:= sparse_matrix.c forward_list.c node.c


all:
	gcc -Wall -g -o convolution convolution.c $(LIBS)
	gcc -Wall -g -o get get.c $(LIBS)
	gcc -Wall -g -o mult_point_by_point mult_point_by_point.c $(LIBS)
	gcc -Wall -g -o read_and_write_bin read_and_write_bin.c $(LIBS)
	gcc -Wall -g -o set_and_print set_and_print.c $(LIBS)
	gcc -Wall -g -o slice slice.c $(LIBS)
	gcc -Wall -g -o sum_mult_scalar_mult_matrix sum_mult_scalar_mult_matrix.c $(LIBS)
	gcc -Wall -g -o swap swap.c $(LIBS)
	gcc -Wall -g -o transpose transpose.c $(LIBS)
clean:
	rm -f main mult_point_by_point read_and_write_bin set_and_print sum_mult_scalar_mult_matrix swap transpose get slice convolution