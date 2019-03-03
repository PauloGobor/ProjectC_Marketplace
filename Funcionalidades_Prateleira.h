#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include "Variaveis_Prateleira.h"

void p_logo(){
	printf("\n==================");
	printf("\nFuncionalidade: Prateleira");
	printf("\n==================\n\n");
}

void cadastrar_prateleira(){ //Cadastrar ID
	int i=0;
	char respo;
	
	system("cls");
	p_logo();
	for (i=0; i<N; i++){
		if (pr[i].Prateleira == 0){
			printf("\nEntre com o ID da prateleira\n");
			scanf("%d", &pr[i].Prateleira);
			i=N;
			/* printf("\n\n\t\t\t\t\tEscolha a Sessão da Prateleira : \n");
			lista_sessao();
			scanf("%s", &respo); */
		}
	}
}

void listar_prateleira(){ //Listar ID
	int i=0;
	system("cls");
	p_logo();
	for (i=0; i<N; i++){
		printf("\nPrateleira : %d\n", pr[i].Prateleira);
	}	
}

void alterar_prateleira(){  //Alterar ID
	system("cls");
	p_logo();
	int id,i=0,novaid;
	char resp, resp_altera;
	
	printf("\nAlterar ID da prateleira\n");
	do{
		
		if(resp_altera=='S' || resp_altera=='s'){
		printf("\nEntre com a ID que deseja alterar\n");
		scanf("%d", &id);
		
			for (i=0; i<N; i++){
				if (pr[i].Prateleira == id){
					printf("\n\nID encontrada deseja alterar? S/N\n");
					scanf("%s", &resp);
					
					if (resp == 'S' || resp == 's'){
							printf("\nEntre com a nova ID\n");
							scanf("%d", &novaid);
							pr[i].Prateleira = novaid;
							i=N;
					}else{
						printf("\n\nNão foi possível alterar ID\n");
						i=N;
					}
				}
			}
		}
	printf("\nDeseja alterar uma ID? S/N\n");
	scanf("%s", &resp_altera);	
	}while (resp_altera == 'S'|| resp_altera == 's');
}

void excluir_prateleira(){  //Excluir ID
	system("cls");
	p_logo();
	int id,i=0;
	char resp, resp_excluir;
	
	printf("\nExcluir ID\n");
	do{
		if(resp_excluir=='S' || resp_excluir=='s'){
		printf("\n\nEntre com a ID que deseja excluir\n");
		scanf("%d", &id);
		
			for (i=0; i<N; i++){
				if (pr[i].Prateleira == id){
					printf("\n\nID encontrada deseja excluir? S/N\n");
					scanf("%s", &resp);
					
					if (resp == 'S' || resp == 's'){
							pr[i].Prateleira = 0;
							printf("\n\nID Excluida com sucesso\n");
							i=N;
					}else{
						printf("\n\nNão foi possível excluir ID\n");
						i=N;
					}
				}
			}
		}
		printf("\nDeseja excluir uma ID? S/N\n");
		scanf("%s", &resp_excluir);	
	}while (resp_excluir == 'S'|| resp_excluir == 's');
}

void p_menu_prateleira(){ 
	system("color f0");
	///Lista as opções para o usuario escolher
	
	do{
		system("cls");
		p_logo();
		printf("########################################################################################################################");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");		
		printf("#\t\t\t1 - Cadastrar Patreleira\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t2 - Listar Prateleiras\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t3 - Alterar Prateleiras\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t4 - Remover Produto da Prateleira\t\t\t\t\t\t               #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t0 - Sair\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################");
		
		printf("\nDigite a opção desejada:\n");	
		scanf("%d",&op_prod);
		printf("########################################################################################################################");
		
		switch(op_prod){
			case 1:
				cadastrar_prateleira();
				break;
			case 2:
				listar_prateleira();
				getch();
				break;
			case 3:
				alterar_prateleira();
				break;
			case 4:
				excluir_prateleira();
				break;
			default:
				op_prod = 0;
				break;
		}
	}while(op_prod != 0);
}
