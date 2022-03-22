CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o generic_vector.o 
TESTOBJ = unit_test.o test_defs.o my_string.o
HANGMANOBJ = hangmain.o string.o generic_vector.o avl_tree.o

hang_man: $(HANGMANOBJ)
	$(CC) $(CFLAGS) -o hang_man $(HANGMANOBJ)

avl_tree.o: avl_tree.c
	$(CC) $(CFLAGS) -c avl_tree.c -o avl_tree.o -c

hangmain.o: hangmain.c
	$(CC) $(CFLAGS) -c hangmain.c -o hangmain.o -c

string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o string.o -c

generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o -c

unit_test: $(TESTOBJ)
	$(CC) $(CFLAGS) -o unit_test $(TESTOBJ)

unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

test_defs.o: test_defs.c
	$(CC) $(CFLAGS) -c test_defs.c -o test_defs.o

string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o string.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o string.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o -c

clean_unit_test:
	rm unit_test $(TESTOBJ)

clean_string_driver:
	rm string_driver $(OBJECTS)

clean_hang_man:
	rm hang_man $(HANGMANOBJ)
