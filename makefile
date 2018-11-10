### Makefile ###
## Projeto 2 Indexacao
## Iago Lourenço 15610116
## Bruno Camilo 16080293
all: prog run clean

prog: main.o filmes.dat
	gcc -g -o main main.o -lm
	
main.o: main.c
	gcc -g -c main.c

filmes.dat: input.txt criaArquivo.o
	gcc -g -o fileCreator criaArquivo.o -lm
	./fileCreator < input.txt 

criaArquivo.o: criaArquivo.c
	gcc -g -c criaArquivo.c

clean:
	rm -rf *.o

run: prog clean
	clear
	./main
