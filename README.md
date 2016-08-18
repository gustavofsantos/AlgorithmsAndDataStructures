Como foi testado?
	gcc main.c listaligada.h -o main -Wall
	valgrind --leak-check=full -v ./main
