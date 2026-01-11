CMAKE := /usr/bin/cmake

build:
	$(CMAKE) -S . -B build
	$(CMAKE) --build build

build_wasm:
	emcmake $(CMAKE) -S . -B build_wasm
	emmake $(CMAKE) --build build_wasm

run: build
	./build/log

clean:
	rm -rf build

clean_wasm:
	rm -rf build_wasm
