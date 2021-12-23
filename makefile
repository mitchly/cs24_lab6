CXX_FLAG = --std=c++11 -g

all: examheap

examheap: examheap.cpp heap.cpp
	g++ $(CXX_FLAG) -o examheap examheap.cpp heap.cpp

clean:
	rm -vf examheap