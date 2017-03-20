CXXFLAGS = -std=c++11

all: LinkedList.cpp
	g++ $(CXXFLAGS) -c LinkedList.cpp -o LinkedList.o

	ar rcs linkedlist.a LinkedList.o

	g++ $(CXXFLAGS) test.cpp linkedlist.a -o test
	rm *.o
	./test


clean:
	rm *.o
	rm *.a
