CC=g++
SRC=visual_featurs_yoda.cpp
EXEC=BFMatcher.o
CFLAGS=-o
PKGCONFIG=`pkg-config --cflags --libs opencv`

default:
	$(CC) $(SRC) $(CFLAGS) $(EXEC) $(PKGCONFIG)

clean:
	rm -f *.o
	rm -f result/*