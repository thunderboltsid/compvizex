CC=g++
SRC=calibrate.cpp
EXEC=calibrate.o
CFLAGS=-g -o
PARAMS=calibrate.xml
PKGCONFIG=`pkg-config --cflags --libs opencv`

default:
	$(CC) $(SRC) $(CFLAGS) $(EXEC) $(PKGCONFIG)

test:
	./$(EXEC) $(PARAMS)

clean:
	rm -f *.o
