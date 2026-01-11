build:
	cmake -S . -B build

run: build
	cmake --build build
	./build/diff

clean:
	rm -rf build

restart: clean build
