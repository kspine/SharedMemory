all:out

out:demo.cpp SharedMemory.cpp
	g++ -Wall -g -o out demo.cpp SharedMemory.cpp -std=c++0x

clean:
	rm out

