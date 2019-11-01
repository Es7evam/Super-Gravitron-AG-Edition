all:
	g++ classes/Window.cc classes/Player.cc gravitron.cpp -Wall -lncurses

run:
	./a.out
