all: test

test: caocao.cpp map.cpp test.cpp zhangfei.cpp guanyu.cpp xiaobing.cpp
	g++ -g -O0 -o $@ $^

clean:
	rm -f test *~

