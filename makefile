CFLAGS=-Wall -Werror -Wfatal-errors

boop.o: boop.cpp game.h
	g++ -c $(CFLAGS) boop.cpp

piece.o: piece.cc piece.h
	g++ -c $(CFLAGS) piece.cc piece.h

player.o: player.h player.cc 
	g++ -c $(CFLAGS) player.h player.cc

kitten.o: kitten.h kitten.cc piece.o
	g++ -c $(CFLAGS) kitten.h kitten.cc piece.o

cat.o: cat.h cat.cc piece.o
	g++ -c $(CFLAGS) cat.h cat.cc piece.o

game.o: game.h game.cc piece.o player.o
	g++ -c $(CFLAGS) game.cpp game.h piece.o player.o

boop: boop.o game.o
	g++ -o boop game.o boop.o 

clean: 
	rm -rf *.o main
