CFLAGS=-I
tokenizer:tokenizer.c history.h tokenizer.h
	gcc tokenizer.c -o tokenizer

all:run
run: tokenizer
	./tokenizer

.PHONY: all run


clean:
	rm tokenizer
