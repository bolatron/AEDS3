all:tp2
clean:
	del *.o *.exe
tp2: file.o functions.o generator.o tp2.o
	gcc file.o functions.o generator.o tp2.o -o tp2
tp2.o: tp2.c prototype.h
	gcc -g -c tp2.c
file.o: prototype.h file.c
	gcc -g -c file.c
functions.o: prototype.h functions.c
	gcc -g -c functions.c
generator.o: prototype.h generator.c
	gcc -g -c generator.c
