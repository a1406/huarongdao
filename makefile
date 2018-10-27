all: test

test: caocao.cpp map.cpp test.cpp
	gcc -g -O0 -o test caocao.cpp map.cpp test.cpp

clean:
	rm -f test

