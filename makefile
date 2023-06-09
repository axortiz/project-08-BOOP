CFLAGS=-Wall -Werror -Wfatal-errors

boop: boop.o game.o player.o piece.o cat.o kitten.o empty.o
	g++ -o boop game.o boop.o player.o piece.o cat.o kitten.o empty.o

boop.o: boop.cpp game.h player.h piece.h cat.h kitten.h empty.h
	g++ -c $(CFLAGS) boop.cpp

piece.o: piece.cc piece.h
	g++ -c $(CFLAGS) piece.cc 

player.o: player.cc player.h 
	g++ -c $(CFLAGS) player.cc

kitten.o: kitten.h kitten.cc piece.h
	g++ -c $(CFLAGS) kitten.cc 

cat.o: cat.h cat.cc piece.h
	g++ -c $(CFLAGS) cat.cc

empty.o: empty.h empty.cc piece.h
	g++ -c $(CFLAGS) empty.cc

game.o: game.h game.cc piece.h player.h cat.h kitten.h
	g++ -c $(CFLAGS) game.cc 

clean: 
	rm -rf *.o boop
