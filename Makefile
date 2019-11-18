all:
	g++ classes/Window.cc classes/Player.cc classes/Blast.cc gravitron.cpp -Wall -lncurses

run:
	./a.out
