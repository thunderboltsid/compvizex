CC=g++
SRC=eigenface.cpp
EXEC=eigenface.o
CFLAGS=-o
PKGCONFIG=`pkg-config --cflags --libs opencv`

default:
	$(CC) $(SRC) $(CFLAGS) $(EXEC) $(PKGCONFIG)

clean:
	rm -f *.o
