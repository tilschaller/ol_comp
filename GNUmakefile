#TODO: add header files (src/*.h) to dependencies 
OUTPUT = olc

CC = gcc
CFLAGS = -Wall -Wextra -O2 -pipe -ggdb

SRCFILES = $(shell cd src && find -L * -type f | LC_ALL=C sort)
CFILES = $(filter %.c,$(SRCFILES))
OBJS = $(addprefix obj/,$(CFILES:.c=.c.o))

.PHONY: run
run: bin/$(OUTPUT)
	./bin/$(OUTPUT) comp main.ol build/main.ol.o

bin/$(OUTPUT): $(OBJS) GNUmakefile
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

obj/%.c.o: src/%.c GNUmakefile
	mkdir -p "$$(dirname $@)"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf bin obj  
