CC = g++
CPPFLAGS = -Wall -std=c++11 -g

main: main.o data.o

main.o: myutil.h data.h

data.o: data.h myutil.h

clean:
	rm main *.o

check:
	valgrind --leak-check=full ./main
