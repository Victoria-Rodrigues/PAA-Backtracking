all:
	gcc main.c -o run sources/geradorMapa.c sources/heroi.c sources/mapa.c sources/modoAnalise.c sources/monstro.c sources/pilha.c
	./run