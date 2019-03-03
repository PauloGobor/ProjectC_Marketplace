#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include "Variaveis_Sessao.h"

void s_logo(){
	printf("\n==================");
	printf("\nFuncionalidade: Sessao");
	printf("\n==================\n\n");
}

void lista_sessao(){
	int x = 0;
	
	system("cls");
	s_logo();
	printf("########################################################################################################################\n");
	printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
    printf("#\t\t\t\t\t\tSessões:\t\t\t\t\t\t\t       #\n");
	printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
	printf("########################################################################################################################\n\n");
	
	for(x=0;x<s_sessao;x++){
		printf("Sessão: %s\n", s[x].nome);
	}
	
	getch();
}

void exclui_sessao(){ ////   	EXCLUI A SESSÃO
	int x=0;
	char sessao[50];
	char op_exclui;
	char resp_exclui;
	
	do{
		system("cls");
		s_logo();
		printf("########################################################################################################################\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
	    printf("#\t\t\t\t\tExcluir Sessão:\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n\n");
		
		if(resp_exclui=='S' || resp_exclui=='s'){
			printf("\nDigite o nome da  sesão que deseja excluir\n");
			fflush(stdin);
			gets(sessao);	
			
			for(x=0;x<s_sessao;x++){
				if(strcmp(s[x].nome,sessao)==0){
					printf("\nEncontramos sua sessão\n");
					printf("Sessão: %s\n",s[x].nome);
			  
					printf("\nDeseja realmente excluir S/N?\n");
					scanf("%s",&op_exclui);
					if(op_exclui=='S'){
						for(x=0;x<s_sessao;x++){				/// 	PERCORRE A STRUCT ENCONTRA A SESSAO QUE O USUARIO SOLICITOU  E EXCLUI A SESSÃO
							if(strcmp(s[x].nome,sessao)==0){
								memset(s[x].nome, 0, sizeof(s[x].nome));
								strcpy(s[x].nome, "Vazio");
							}
						}	
						printf("\nSessão excluida com sucesso !\n");
						x=s_sessao;
				 	}else{
						printf("\nNenhuma Sessão excluida.\n");
						x=s_sessao;
					}
				}
			}	
			
			if(op_exclui != 'S' && op_exclui != 'N' && strcmp(s[x].nome,sessao)!=0){
				printf("\nDesculpe nao encontramos essa sessão\n");
				x=s_sessao;
			}
		}
		printf("\nDeseja excluir alguma Sessão S/N?\n");
		scanf("%s",&resp_exclui);
	}while(resp_exclui=='S' || resp_exclui=='s');
}

void cadastra_sessao(){ // 	CADASTRO SESSSAO  	 /////
	char resp;
	int x=0;
	char nnome[50];
	
	do{
		system("cls");
		s_logo();
		printf("########################################################################################################################\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\tCadastro Sessão\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n");
		
		/// PEDE AO USUÁRIO OS DADOS DO PRODUTO
		if(resp=='s' || resp=='S'){
			if(s_sessao > 0){
				for(x=0;x<s_sessao;x++){
					if(strcmp(s[x].nome,"Vazio")==0){
						printf("\nDigite o nome da sessão que o produto irá ficar: ");		
						fflush(stdin);
						gets(nnome);
						strcpy(s[x].nome,nnome);
						
						x = s_sessao;
					}else{
						printf("\nDigite o nome da sessão que o produto irá ficar: ");
						fflush(stdin);
						gets(s[s_sessao].nome);
						s_sessao++;
						x = s_sessao;
					}
				}
			}else{
				printf("\nDigite o nome da sessão que o produto irá ficar: ");
				fflush(stdin);
				gets(s[s_sessao].nome);
				s_sessao++;
				
			}
		}
		
		printf("\nDeseja Cadastrar alguma Sessão S/N? \n");
		scanf("%s",&resp);
	}while(resp=='s' || resp=='S');
}

void altera_sessao(){ 	 //			ALTERA SESSAO			///////
	int x=0;
	char sessao[50],op_altera;
	char new_session[50];
	char resp_altera;
	
	do{
		system("cls");
		s_logo();
		
		printf("########################################################################################################################\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
	    printf("#\t\t\t\t\tAlterar Sessão:\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n\n");
		
		if(resp_altera=='S' || resp_altera=='s'){
			printf("\nDigite o nome da sesão que deseja alterar\n");
			fflush(stdin);
			gets(sessao);
			
			for(x=0;x<s_sessao;x++){
				///PERCORRE A STRUCT ENCONTRA A SESSAO QUE O USUARIO SOLICITOU  E ALTERA COM UM NOVO NOME 
				if(strcmp(s[x].nome,sessao)==0){
					printf("\nEncontramos sua sessão\n");
					printf("Sessão: %s\n",s[x].nome);
			  
					printf("\nDeseja realmente alterar S/N?\n");
					scanf("%s",&op_altera);
					if(op_altera=='S'){
						printf("\nDigite o novo nome da sessão\n");
						fflush(stdin);
						gets(new_session);
						fflush(stdin);						
						for(x=0;x<s_sessao;x++){
							if(strcmp(s[x].nome,sessao)==0){
								strcpy(s[x].nome,new_session);
							}
						}		
						printf("\nSessão alterada com sucesso!\n");
						x=Z;
			 		}else{
						printf("\nNenhuma Sessão alterada.\n");
						x=s_sessao;
					}
				}
			}
			
			if(op_altera != 'S' && op_altera != 'N' && strcmp(s[x].nome,sessao)!=0){
				printf("\nDesculpe não encontramos essa sessão\n");
				x=s_sessao;
			}
		}
	
	printf("Deseja alterar alguma Sessão S/N?\n");
	scanf("%s",&resp_altera);
	}while(resp_altera=='S' || resp_altera=='s');
}

void s_menu_sessao(){ ///MENUUU
	system("color 0f");
	system("cls");
	s_logo();
	
	int op_prod=0;

	do{
		system("cls");
		s_logo();
		
		printf("########################################################################################################################");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t1 - Cadastrar Sessão\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t2 - Listar Sessão\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t3 - Alterar Sessão\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t4 - Excluir Sessão\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t0 - Sair\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################");
		printf("Digite a opção desejada: \n");
		scanf("%d",&op_prod);
		printf("########################################################################################################################");
		
		switch(op_prod){	///		 CASE OPÇOES    ///
			case 1:	///CADASTRAR SESSÃO
				cadastra_sessao();
				break;
			case 2: ///LISTAR SESSÃO
				lista_sessao();
				break;	
			case 3:	///ALTERAR SESSÃO
				altera_sessao();
				break;
			case 4:	///EXCLUIR SESSÃO
				exclui_sessao();
				break;
			case 0:	///SAIR
				op_prod=0;
				break;
		}
	}while(op_prod!=0);
}
