CC = gcc
CFLAGS = -Wall -c
OBJECTS =  edit.o utils.o matrix_t.o main.o
SRCDIR = ./src
OPTL = -O3
CLEANUP = edit_d *.o
all: edit_d

edit_d: $(OBJECTS)
	$(CC) $(OBJECTS) $(OPTL) -o edit_d

edit.o: $(SRCDIR)/edit.c
	$(CC) $(CFLAGS) $(SRCDIR)/edit.c

utils.o: $(SRCDIR)/utils.c
	$(CC) $(CFLAGS) $(SRCDIR)/utils.c

matrix_t.o: $(SRCDIR)/matrix_t.c
	$(CC) $(CFLAGS) $(SRCDIR)/matrix_t.c

main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(SRCDIR)/main.c

clean:
	rm -rf $(CLEANUP)
