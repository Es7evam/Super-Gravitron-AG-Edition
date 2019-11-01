all:
	g++ classes/Window.cc classes/Player.cc gravitron.cpp -Wall -pthread -lncurses

run:
	./a.out
