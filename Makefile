# Makefile
# Complile the whole Tree:

#Macros:
CC = gcc
CFLAGS = -0 -ggdb3
LDFLAGS = 
BINDIR = ./bin/

#testing the libraries
tests : tests.c lib/hash.c lib/spottlib.c
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@
	mv $@* $(BINDIR)
