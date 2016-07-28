all:plop

plop: main wc map

main.o:main.c
	gcc -c main.c

wc.o:wc.c
	gcc -c wc.c

map.o:map.c
	gcc -c map.c
