.PHONY: run
run: olc
	./olc comp main.ol build/main.ol.o

olc: main.c.o
	gcc -o olc build/main.c.o

main.c.o:
	mkdir -p build
	gcc -c main.c -o build/main.c.o

.PHONY: clean
clean:
	rm -r build
	rm olc
