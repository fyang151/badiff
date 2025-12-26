main: src/main.c src/diff.c
	gcc -Wall src/main.c src/diff.c -o bin/main

run: main
	./bin/main
	
clean:
	rm -f bin/main