output: Main.o llist.o
	cc Main.o llist.o -o output

Main.o: Main.c
	cc -c Main.c

llist.o: llist.c
	cc -c llist.c

clean:
	rm -f *.o output

main:
	./output
