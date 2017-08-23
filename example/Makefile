all:server client

server:server.cpp SharedMemory.cpp
	g++ -Wall -g -o server server.cpp SharedMemory.cpp -std=c++0x

client:client.cpp SharedMemory.cpp
	g++ -Wall -g -o client client.cpp SharedMemory.cpp -std=c++0x

clean:
	rm server client

