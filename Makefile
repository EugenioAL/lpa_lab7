lab7:	main.o myFile.o  
		gcc main.c myFile.c -o lab7

main.o: main.c myFile.c
		gcc -c main.c

myFile.o: myFile.c myLib.h
		gcc -c myFile.c


run:
	./lab7 trans.png
clear:
	rm -rf *.exe
	rm -rf *.o