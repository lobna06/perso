p:main.o fonction.o 
	gcc main.o fonction.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer  -o p -g -lm
main.o:main.c
	gcc -c main.c -g -lm
fonction.o:fonction.c
	gcc -c fonction.c -g

