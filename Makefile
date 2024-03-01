CC=gcc

FLAGS=-Wall -g -ggdb3

MAIN_FILES= encodemain.o compress.o
COMPRESS=compress.c compress.h

all: digitcompress

digitcompress: $(MAIN_FILES)
	$(CC) $(FLAGS) -c encodemain.c -o $@
compress.o: $(COMPRESS)
	$(CC) $(FLAGS) -c compress.c -o $@ $^
encodemain.o: encodemain.c
	$(CC) $(FLAGS) -c encodemain.c -o $@ $^

.PHONY: clean all

clean:
	rm -f *.o digitcompress