CC=clang
CFLAGS =-Weverything -std=c89 -pedantic-errors
OBJECTS=main.o iodata.o displaydata.o editdata.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c definedata.h iodata.h editdata.h displaydata.h
	$(CC) $(CFLAGS) -c main.c

iodata.o: iodata.h iodata.c
	$(CC) $(CFLAGS) -c iodata.c

displaydata.o: displaydata.h displaydata.c
	$(CC) $(CFLAGS) -c displaydata.c

editdata.o: editdata.h editdata.c
	$(CC) $(CFLAGS) -c editdata.c

clean:
	rm -f *.o *~ contacts
