#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "Variaveis_Fornecedor.h"

void f_logo(){
	printf("\n==================");
	printf("\nFuncionalidade: Fornecedor");
	printf("\n==================\n");
}

void f_menu_fornecedor(){
	setlocale(LC_ALL,"portuguese");
	system("color f2");
	
	int op = 0, i = 0;
	
	do{
		system("cls");
		f_logo();
		
		printf("\n### 1 - Cadastrar fornecedor ###");
		printf("\n### 2 - Ativar/Desativar fornecedor ###");
		printf("\n### 3 - Listar fornecedor ativos ###");
		printf("\n### 0 - Sair ###");
		printf("\nDigite sua opção:");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				system("cls");
				f_logo();
				
				printf("\nEntre com o nome do fornecedor para cadastro: ");
				fflush(stdin);
				gets(e[c_fornecedor].nome);
				printf("\nEntre com a Razão social do fornecedor: ");
				fflush(stdin);
				gets(e[c_fornecedor].razao);
				printf("\nEntre com o Ramo do fornecedor: ");
				fflush(stdin);
				gets(e[c_fornecedor].ramo);
				printf("\nEntre com o Endereço do fornecedor: ");
				fflush(stdin);
				gets(e[c_fornecedor].end);
				printf("\nEntre com a Cidade do fornecedor: ");
				fflush(stdin);
				gets(e[c_fornecedor].cidade);
				printf("\nEntre com o Telefone do fornecedor: ");
				fflush(stdin);
				scanf("%d", &e[c_fornecedor].telefone);
				e[c_fornecedor].status = 1;
				i= i+1;
				
				system("cls");
				f_logo();
				
				printf("\n\nFornecedor cadastrado com sucesso!");
				c_fornecedor++;
				break;
	
	
			case 2: // excluir fornecedor
				system("cls");
				f_logo();
				
				printf("\nDeseja [A]tivar ou [D]esativar um fornecedor?");
				scanf("%s", &emp);
				fflush(stdin);
				
				switch(emp){
					case 'a':
						printf("\n\nFornecedores não ativos:\n");
						
						for(i=0; i<3; i++){
							if(e[i].status == 0){
								printf("\n%s\n", e[i].nome);
							}
						}
						
						printf("\nQual fornecedor você quer ativar?");
						scanf("%s", &forn);
						
						for(i=0; i<3;i++){
							if(strcmp(e[i].nome, forn) == 0){
								e[i].status = 1;
							}
						}
						
						break;
			
					case 'd':
						printf("\n\nFornecedores ativos:\n");
						
						for(i=0; i<3;i++){
							if(e[i].status == 1){
								printf("\n%s\n", e[i].nome);
							}
						}
				
						printf("\nQual fornecedor você deseja desativar?");
						scanf("%s", &forn);
						
						for(i=0; i<3;i++){
							if(strcmp(e[i].nome, forn) == 0){
								e[i].status = 0;
							}
						}
						
						break;
				}
				break;
		
			case 3:
				system("cls");
				f_logo();
				
				printf("\nFornecedores Ativos\n");
				
				for(i=0; i<3; i++){
					if(e[i].status == 1){
						printf("\n\nNome: %s", e[i].nome);
					}
				}
				
				printf("\n\nPressione qualquer tecla para voltar ao menu.");
				getch();
				break;
				
			default:
				op = 0;
				break;
		} 
	}while (op != 0);
}

