CC = g++
CFLAGS = -Wall -Wextra

OBJECTS = game.o move.o legalmove.o

main.exe : clean $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o game main.cpp

game.o : src/game.cpp
	$(CC) $(CFLAGS) -c src/game.cpp

move.o : src/move.cpp
	$(CC) $(CFLAGS) -c src/move.cpp

legalmove.o : src/legalmove.cpp
	$(CC) $(CFLAGS) -c src/legalmove.cpp

clean:
	rm game *.o *.exe -rf

