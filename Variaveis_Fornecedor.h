#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>

int escolha, op, c_fornecedor = 0; 
char emp; 
char forn[50];

struct empresa {
	char nome[50], razao[50], ramo[50], end[50], cidade[50];
	int telefone;
	int status;
};

empresa e[3];
