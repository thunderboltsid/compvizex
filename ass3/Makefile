CC=g++
SRC=eigenface.cpp
EXEC=eigenface.o
CFLAGS=-o
PARAMS=csv result
PKGCONFIG=`pkg-config --cflags --libs opencv`

default:
	$(CC) $(SRC) $(CFLAGS) $(EXEC) $(PKGCONFIG)

test:
	./$(EXEC) $(PARAMS)

clean:
	rm -f *.o
	rm -f result/*
