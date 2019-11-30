all:
	g++ classes/Entity.cc classes/Window.cc classes/Player.cc classes/Blast.cc gravitron.cpp -Wall -pthread -lncurses

run:
	./a.out
