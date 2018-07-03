CC = gcc -Wall
OBJDIR = ./object_file
CDIR = ./c_file

all: dir libcalc.a test main

dir: ./object_file

./object_file:
	mkdir ./object_file

libcalc.a: library
	$(CC) -shared $(OBJDIR)/sum.o $(OBJDIR)/sub.o $(OBJDIR)/mul.o $(OBJDIR)/divis.o -o $(CDIR)/libcalc.so

library: $(CDIR)/sum.c $(CDIR)/sub.c $(CDIR)/mul.c $(CDIR)/divis.c
	$(CC) -fPIC -c $(CDIR)/sum.c -o $(OBJDIR)/sum.o -I./
	$(CC) -fPIC -c $(CDIR)/sub.c -o $(OBJDIR)/sub.o -I./
	$(CC) -fPIC -c $(CDIR)/mul.c -o $(OBJDIR)/mul.o -I./
	$(CC) -fPIC -c $(CDIR)/divis.c -o $(OBJDIR)/divis.o -I./

test: $(OBJDIR)/main.o
	$(CC) -o $(CDIR)/test $(OBJDIR)/main.o -ldl -L.

$(OBJDIR)/main.o: $(CDIR)/main.c
	$(CC) -g -c $(CDIR)/main.c -o $(OBJDIR)/main.o -ldl -I./

main: main_file.c
	$(CC) -o main main_file.c

clean:
	rm -rf ./object_file
	rm $(CDIR)/test
	rm main
	rm $(CDIR)/libcalc.so
