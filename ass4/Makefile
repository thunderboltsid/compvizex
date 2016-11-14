CC=g++
SRC=calibrate.cpp
EXEC=calibrate.o
CFLAGS=-g -o
PKGCONFIG=`pkg-config --cflags --libs opencv`

default:
	$(CC) $(SRC) $(CFLAGS) $(EXEC) $(PKGCONFIG)

test:
	./$(EXEC)

clean:
	rm -f *.o
