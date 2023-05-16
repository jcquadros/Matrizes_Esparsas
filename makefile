LIBS := libs/sparse_matrix.c libs/forward_list.c libs/node.c
SRCS := $(wildcard *.c)
EXECUTABLES := $(SRCS:.c=)

all: $(EXECUTABLES)

%: %.c
	gcc -Wall -g -o $@ $< $(LIBS)

clean:
	rm -f $(EXECUTABLES) matriz.bin
