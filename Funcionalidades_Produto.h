#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include "Variaveis_Produto.h"

void e_logo(){
	printf("\n==================");
	printf("\nFuncionalidade: Produto");
	printf("\n==================\n");
}

void e_cadastrar_produto(){
	system("cls");
	e_logo();
	
	int i = 0;
	char nnome[20];
	float nquantidade = 0;
	
	if(c_produto > 0){
		for(i=0;i<c_produto;i++){
			if(strcmp(p[i].nome, "vazio") == 0){
				printf("\n\nCadastrando produto.");
				printf("\nInsira o nome: ");
				scanf("%s", &nnome);
				strcpy(p[i].nome, nnome);
				fflush(stdin);
				printf("\nInsira a quantidade: ");
				scanf("%f", &nquantidade);
				p[i].quantidade = nquantidade;
				
				i = 9999;
			}else{
				printf("\n\nCadastrando produto.");
				printf("\nInsira o nome: ");
				scanf("%s", &p[c_produto].nome);
				printf("\nInsira a quantidade: ");
				scanf("%f", &p[c_produto].quantidade);
				
				c_produto = c_produto + 1;
				i = 9999;
			}
		}
	}else{
		printf("\n\nCadastrando produto.");
		printf("\nInsira o nome: ");
		scanf("%s", &p[c_produto].nome);
		printf("\nInsira a quantidade: ");
		scanf("%f", &p[c_produto].quantidade);
		
		c_produto = c_produto + 1;
	}
	
}

void e_listar_produto(){
	system("cls");
	e_logo();
	
	int i = 0;
	
	printf("\n\nLista de produtos.");
	
	for(i=0;i<c_produto;i++){
		printf("\n\nProduto: %s", p[i].nome);
		printf("\nQuantidade: %0.2f", p[i].quantidade);
	}
	getch();
}

void e_alterar_produto(){
	system("cls");
	e_logo();
	
	char prod[20];
	float quant;
	int i = 0;
	
	printf("\n\nAlterar produto.");
	
	printf("\nInsira o nome do produto a ser alterado: ");
	scanf("%s", &prod);
	
	system("cls");
	e_logo();
	
	for(i=0;i<c_produto;i++){
		if(strcmp(p[i].nome, prod) == 0){
			printf("\n\nProduto atual");
			printf("\nNome: %s", p[i].nome);
			
			printf("\n\nInsira o novo nome: ");
			scanf("%s", p[i].nome);
			
			if(strcmp(p[i].nome, prod) == 0){
				printf("\n\nFalha ao alterar o produto.");
			}else{
				printf("\n\nProduto alterado com sucesso.");
			}
		}
	}
	
	getch();
}

void e_excluir_produto(){
	system("cls");
	e_logo();
	
	char prod[20];
	float quant;
	int i = 0, op = 0;
	
	printf("\n\nExcluir produto.");
	
	printf("\nInsira o nome do produto a ser excluido: ");
	scanf("%s", &prod);
	
	for(i=0;i<c_produto;i++){
		if(strcmp(p[i].nome, prod) == 0){
			printf("\n\nVocê realmente deseja excluir o produto?");
			printf("\n1) Sim");
			printf("\n2) Não");
			printf("\nDigite sua opção:");
			scanf("%i", &op);
			
			if(op == 1){
				memset(p[i].nome, 0, sizeof(p[i].nome));
				strcpy(p[i].nome, "vazio");
				p[i].quantidade = 0;
				
				if(strcmp(p[i].nome, prod) == 0){
					printf("\n\nFalha ao excluir o produto.");
					printf("\nVoltando ao menu...");
					sleep(1);
				}else{
					printf("\n\nProduto excluido com sucesso.");
					printf("\nVoltando ao menu...");
					sleep(1);
				}
			}else{
				printf("\n\nVocê desistiu de excluir o produto.");
				printf("\nVoltando ao menu...");
				sleep(1);
			}
			
		}
	}
	
	getch();
}

void e_menu_produto(){
	int op = 0;
	
	do{
		system("cls");
		e_logo();
		
		printf("\n1)Cadastrar");
		printf("\n2)Listar");
		printf("\n3)Alterar");
		printf("\n4)Excliur");
		printf("\n0)Sair");
		printf("\nDigite sua opção:");
		
		scanf("%i", &op);
		
		switch(op){
			case 1:
				e_cadastrar_produto();
				break;
			case 2:
				e_listar_produto();
				break;
			case 3:
				e_alterar_produto();
				break;
			case 4:
				e_excluir_produto;
				break;
			default:
				op = 0;
				break;
		}
		
	}while(op != 0);
}









