all: test

test: caocao.cpp mymap.cpp test.cpp zhangfei.cpp guanyu.cpp xiaobing.cpp base.cpp
	g++ -g -O0 -o $@ $^

clean:
	rm -f test *~

