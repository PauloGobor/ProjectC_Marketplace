#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include "Funcionalidades_Produto.h"
#include "Funcionalidades_MenuPrincipal.h"
#include "Funcionalidades_Fornecedor.h"
#include "Funcionalidades_Sessao.h"
#include "Funcionalidades_Prateleira.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opm = 0;
	
	do{
		system("cls");
		system("color f0");
		logo_principal();
		
		printf("\n1)Funcionalidade Fornecedor");
		printf("\n2)Funcionalidade Produto");
		printf("\n3)Funcionalidade Prateleira");
		printf("\n4)Funcionalidade Sessao");
		printf("\n0)Sair");
		printf("\nDigite sua opção:");
		
		scanf("%i", &opm);
		
		switch(opm){
			case 1:
				f_menu_fornecedor();
				break;
			case 2:
				e_menu_produto();
				break;
			case 3:
				p_menu_prateleira();
				break;
			case 4:
				s_menu_sessao();
				break;
			default:
				opm = 0;
				printf("\nObrigado por usar nosso programa!\n\nEsperamos que você tenha gostado!\n");
				getch();
				break;
		}
	}while(opm != 0);
}
