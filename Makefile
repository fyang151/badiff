main: src/main.c src/find_middle.c src/ses.c
	gcc -Wall src/main.c src/find_middle.c src/ses.c -o bin/main

run: main
	./bin/main
	
clean:
	rm -f bin/main
