main: geometry.c
	gcc -Wall -Werror -o geometry geometry.c

run: geometry
	./geometry
