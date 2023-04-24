CFLAGS=-Wall -Werror -Wfatal-errors

boop.o: boop.cpp game.h
	g++ -c $(CFLAGS) boop.cpp

board.o: board.cc board.h
	g++ -c $(CFLAGS) board.cc 


game.o: board.o game.h game.cc
	g++ -c $(CFLAGS) game.cpp game.h board.o

boop: boop.o game.o
	g++ -o boop game.o boop.o 

clean: 
	rm -rf *.o main
