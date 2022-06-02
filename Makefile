
TEST_TARGET = ./test_graph

all: clean build test memtest

rebuild: clean build

build:
	./build.sh

test:
	./build/tests/${TEST_TARGET}

memtest:
	./tests/memtest.sh ./build/tests/${TEST_TARGET}

clean:
	rm -rf build valgrind.log graph

run:
	./build/graph