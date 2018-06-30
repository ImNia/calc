CC = gcc -Wall
OBJDIR = ./object_file
CDIR = ./c_file

all: dir libcalc.a test

dir: ./object_file

./object_file:
	mkdir ./object_file

libcalc.a: library
	ar rc libcalc.a $(OBJDIR)/sum.o $(OBJDIR)/sub.o $(OBJDIR)/mul.o $(OBJDIR)/divis.o

library: $(CDIR)/sum.c $(CDIR)/sub.c $(CDIR)/mul.c $(CDIR)/divis.c
	$(CC) -c $(CDIR)/sum.c -o $(OBJDIR)/sum.o -I./
	$(CC) -c $(CDIR)/sub.c -o $(OBJDIR)/sub.o -I./
	$(CC) -c $(CDIR)/mul.c -o $(OBJDIR)/mul.o -I./
	$(CC) -c $(CDIR)/divis.c -o $(OBJDIR)/divis.o -I./

test: $(OBJDIR)/main.o
	$(CC) -o test $(OBJDIR)/main.o -lcalc -L.

$(OBJDIR)/main.o: $(CDIR)/main.c
	$(CC) -g -c $(CDIR)/main.c -o $(OBJDIR)/main.o -I./

clean:
	rm -rf ./object_file
	rm test
