all:
	g++ classes/Window.cc classes/Player.cc classes/Blast.cc classes/AG.cc gravitron.cpp -Wall -lncurses

run:
	./a.out
