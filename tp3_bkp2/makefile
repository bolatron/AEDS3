all:tp3
clean:
	del *.o *.exe
tp3: grafo.o file.o quicksort.o tp3.o
	gcc grafo.o file.o quicksort.o tp3.o -o tp3
tp3.o: tp3.c prototipo.h
	gcc -g -c tp3.c
grafo.o: prototipo.h grafo.c
	gcc -g -c grafo.c
file.o: prototipo.h file.c
	gcc -g -c file.c
quicksort.o: prototipo.h quicksort.c
	gcc -g -c quicksort.c
