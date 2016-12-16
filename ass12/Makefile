CC=g++
SRC=visual_features_fundamental_matrix_template.cpp
EXEC=fundamental.o
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