EXE = midterm_practice_tester
OBJ = main.o BookStore.o
CC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o: main.cc BookStore.h
	$(CC) -c main.cc

BookStore.o: BookStore.cc BookStore.h
	$(CC) -c BookStore.cc

clean:
	rm -f $(EXE) $(OBJ)