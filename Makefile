all: test

test: test-memory test-unit

test-memory: bld/test
	valgrind --leak-check=yes bld/test

test-unit: bld/test
	bld/test

build/test: src/ll.c inc/ll.h bld test/main.c
	gcc -Iinc -I/usr/include -lcmocka src/ll.c test/main.c -o bld/test

bld:
	mkdir bld

clean:
	rm -r bld

install:
	mkdir -p /usr/include/ll
	cp inc/ll.h /usr/include/ll
	mkdir -p /usr/src/ll
	cp src/ll.c /usr/src/ll

uninstall:
	rm -r /usr/include/ll
	rm -r /usr/src/ll
