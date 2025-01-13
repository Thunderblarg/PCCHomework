main: dungeonmanager.c dungeonhelper.o
	gcc dungeonmanager.c dungeonhelper.o -lm

dungeonhelper.o: dungeonhelper.c dungeonhelper.h
	gcc -o dungeonhelper.o -c dungeonhelper.c -lm

clean:
	rm -f a.out
	rm -f *.o
