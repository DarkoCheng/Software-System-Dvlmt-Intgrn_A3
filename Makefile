All:
		gcc -Wall -std=c11 -g -c listio.c -o listio.o
		ar cr liblistio.a listio.o
		gcc -g main.c listio.c -o A3
clean:
		$(RM)myprog
