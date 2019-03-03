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
    printf("#\t\t\t\t\t\tSess�es:\t\t\t\t\t\t\t       #\n");
	printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
	printf("########################################################################################################################\n\n");
	
	for(x=0;x<s_sessao;x++){
		printf("Sess�o: %s\n", s[x].nome);
	}
	
	getch();
}

void exclui_sessao(){ ////   	EXCLUI A SESS�O
	int x=0;
	char sessao[50];
	char op_exclui;
	char resp_exclui;
	
	do{
		system("cls");
		s_logo();
		printf("########################################################################################################################\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
	    printf("#\t\t\t\t\tExcluir Sess�o:\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n\n");
		
		if(resp_exclui=='S' || resp_exclui=='s'){
			printf("\nDigite o nome da  ses�o que deseja excluir\n");
			fflush(stdin);
			gets(sessao);	
			
			for(x=0;x<s_sessao;x++){
				if(strcmp(s[x].nome,sessao)==0){
					printf("\nEncontramos sua sess�o\n");
					printf("Sess�o: %s\n",s[x].nome);
			  
					printf("\nDeseja realmente excluir S/N?\n");
					scanf("%s",&op_exclui);
					if(op_exclui=='S'){
						for(x=0;x<s_sessao;x++){				/// 	PERCORRE A STRUCT ENCONTRA A SESSAO QUE O USUARIO SOLICITOU  E EXCLUI A SESS�O
							if(strcmp(s[x].nome,sessao)==0){
								memset(s[x].nome, 0, sizeof(s[x].nome));
								strcpy(s[x].nome, "Vazio");
							}
						}	
						printf("\nSess�o excluida com sucesso !\n");
						x=s_sessao;
				 	}else{
						printf("\nNenhuma Sess�o excluida.\n");
						x=s_sessao;
					}
				}
			}	
			
			if(op_exclui != 'S' && op_exclui != 'N' && strcmp(s[x].nome,sessao)!=0){
				printf("\nDesculpe nao encontramos essa sess�o\n");
				x=s_sessao;
			}
		}
		printf("\nDeseja excluir alguma Sess�o S/N?\n");
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
		printf("#\t\t\t\t\t\tCadastro Sess�o\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n");
		
		/// PEDE AO USU�RIO OS DADOS DO PRODUTO
		if(resp=='s' || resp=='S'){
			if(s_sessao > 0){
				for(x=0;x<s_sessao;x++){
					if(strcmp(s[x].nome,"Vazio")==0){
						printf("\nDigite o nome da sess�o que o produto ir� ficar: ");		
						fflush(stdin);
						gets(nnome);
						strcpy(s[x].nome,nnome);
						
						x = s_sessao;
					}else{
						printf("\nDigite o nome da sess�o que o produto ir� ficar: ");
						fflush(stdin);
						gets(s[s_sessao].nome);
						s_sessao++;
						x = s_sessao;
					}
				}
			}else{
				printf("\nDigite o nome da sess�o que o produto ir� ficar: ");
				fflush(stdin);
				gets(s[s_sessao].nome);
				s_sessao++;
				
			}
		}
		
		printf("\nDeseja Cadastrar alguma Sess�o S/N? \n");
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
	    printf("#\t\t\t\t\tAlterar Sess�o:\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################\n\n");
		
		if(resp_altera=='S' || resp_altera=='s'){
			printf("\nDigite o nome da ses�o que deseja alterar\n");
			fflush(stdin);
			gets(sessao);
			
			for(x=0;x<s_sessao;x++){
				///PERCORRE A STRUCT ENCONTRA A SESSAO QUE O USUARIO SOLICITOU  E ALTERA COM UM NOVO NOME 
				if(strcmp(s[x].nome,sessao)==0){
					printf("\nEncontramos sua sess�o\n");
					printf("Sess�o: %s\n",s[x].nome);
			  
					printf("\nDeseja realmente alterar S/N?\n");
					scanf("%s",&op_altera);
					if(op_altera=='S'){
						printf("\nDigite o novo nome da sess�o\n");
						fflush(stdin);
						gets(new_session);
						fflush(stdin);						
						for(x=0;x<s_sessao;x++){
							if(strcmp(s[x].nome,sessao)==0){
								strcpy(s[x].nome,new_session);
							}
						}		
						printf("\nSess�o alterada com sucesso!\n");
						x=Z;
			 		}else{
						printf("\nNenhuma Sess�o alterada.\n");
						x=s_sessao;
					}
				}
			}
			
			if(op_altera != 'S' && op_altera != 'N' && strcmp(s[x].nome,sessao)!=0){
				printf("\nDesculpe n�o encontramos essa sess�o\n");
				x=s_sessao;
			}
		}
	
	printf("Deseja alterar alguma Sess�o S/N?\n");
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
		printf("#\t\t\t1 - Cadastrar Sess�o\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t2 - Listar Sess�o\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t3 - Alterar Sess�o\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t4 - Excluir Sess�o\t\t\t\t\t\t\t\t               #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t0 - Sair\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("#\t\t\t\t\t\t\t\t\t\t\t\t\t\t       #\n");
		printf("########################################################################################################################");
		printf("Digite a op��o desejada: \n");
		scanf("%d",&op_prod);
		printf("########################################################################################################################");
		
		switch(op_prod){	///		 CASE OP�OES    ///
			case 1:	///CADASTRAR SESS�O
				cadastra_sessao();
				break;
			case 2: ///LISTAR SESS�O
				lista_sessao();
				break;	
			case 3:	///ALTERAR SESS�O
				altera_sessao();
				break;
			case 4:	///EXCLUIR SESS�O
				exclui_sessao();
				break;
			case 0:	///SAIR
				op_prod=0;
				break;
		}
	}while(op_prod!=0);
}
