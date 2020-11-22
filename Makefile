all: main
p1: server.cpp 
	g++ -g main.cpp -o main
clean:
	rm -rf main
