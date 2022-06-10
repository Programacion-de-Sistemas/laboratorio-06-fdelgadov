all: main.o chess.o
	g++ main.o chess.o $(HW).c -lglut -lGL -lGLU -w -o $(HW)
main.o: main.c
	g++ -c main.c
chess.o: chess.c
	g++ -c chess.c
