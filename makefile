CC = clang
CFLAGS = -g --pedantic -Wall



app.exe : main.o matrix.o vector.o neural.o
	${CC} ${CFLAGS} -lm ./tmp/main.o ./tmp/vector.o ./tmp/matrix.o ./tmp/neural.o -o ./bin/app.exe

main.o : 
	${CC} ${CFLAGS} -c ./src/main.c -o ./tmp/main.o

matrix.o :
	${CC} ${CFLAGS} -c ./src/matrix.c -o ./tmp/matrix.o
	
vector.o : 
	${CC} ${CFLAGS} -c ./src/vector.c -o ./tmp/vector.o

neural.o : 
	${CC} ${CFLAGS} -c ./src/neural.c -o ./tmp/neural.o

clean:
	rm -f ./tmp/*
	rm ./bin/app.exe