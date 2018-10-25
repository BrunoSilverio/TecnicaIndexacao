//TECNICA DE INDEXACAO
//Criar �ndices e Utilizar os M�todos de Busca
#include<stdio.h>
#include<stdlib.h>

int leituraArqBinario();

void main()
{
	FILE *arq;
	int op, op1, r;
	double Teste;
	
	//MENU PRINCIPAL
	printf("1 >> Consultar 'um registro'\n");
	printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave prim�ria)\n");
	printf("3 >> Eliminar um registro do arquivo\n");
	printf("4 >> Inserir um registro no arquivo\n");
	printf("5 >> Impressao\n");
	printf("6 >> Sair\n\nOpcao >> ");
	scanf("%d",&op);
	
	system("cls");
	
	switch(op)
	{
		case 1:
		//entrada � pelo campo chave prim�ria;
		//Carregar �ndice denso (item a);
		//Chamar a fun��o Busca Bin�ria para localizar a chave;
		//Ler no arquivo o registro procurado;
		//Imprimir todas as informa��es do registro buscado;
		//Caso n�o exista o valor buscado: imprimir mensagem e n�o fazer os passos iv e v, acima
			printf("1 >> Consultar 'um registro'\n");
			
			
			main();
			break;
			
		case 2:
		//entrada � pelo campo chave prim�ria;
		//Carregar �ndice denso (item a);
		//Chamar a fun��o Busca Bin�ria para localizar a chave;
		//Ler no arquivo o registro procurado;
		//Perguntar qual campo ser� modificado, um a um;
		//Alterar o(s) campo(s) no arquivo;
		//Caso a altera��o ocorra no campo 2 e/ou no da categoria (campo3) � atualizar os respectivos �ndices; 
		//Caso n�o exista o valor buscado: imprimir mensagem e n�o fazer os passos de iv a vii, acima
			printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave prim�ria)\n");
			
			
			main();
			break;
		
		case 3:
		//entrada � pelo campo chave prim�ria;
		//Carregar �ndice denso (item a);
		//Chamar a fun��o Busca Bin�ria para localizar a chave;
		//Eliminar (*) o registro procurado do arquivo;
		//Atualizar os respectivos �ndices; 
		//Caso n�o exista o valor buscado: imprimir mensagem e n�o fazer os passos iv e v, acima	
			printf("3 >> Eliminar um registro do arquivo\n");
			
			
			main();
			break;
			
		case 4:
		//ler as informa��es do novo registro. Fazer a valida��o de o valor do campo chave prim�ria j� existir no arquivo. Caso j� exista, repetir a digita��o do campo at� que se digite um valor v�lido;
		//Inserir o novo registro no final do arquivo;
		//Atualizar os respectivos �ndices; 
		//Imprimir mensagem:� inser��o feita com sucesso�;
			printf("4 >> Inserir um registro no arquivo\n");
			
			
			main();
			break;
		
		case 5:
			printf("[IMPRESSAO]\n");
			printf("1 >> Ordenacao por Chave Primaria\n");
			printf("2 >> Ordenacao pelo campo2.\n");
			printf("3 >> Por Categoria ordenado pelo campo chave.\n");
			printf("4 >> Por categoria ordenado pelo campo2.\n");
			printf("5 >> Dados do arquivo desordenado.\n");
			printf("6 >> Voltar Menu Principal\n\nOpcao >> ");
			scanf("%d",&op1);
			
			system("cls");
			
			switch(op1)
			{
				case 1:
					printf("1 >> Ordenacao por Chave Primaria\n");
					
					
					break;
			
				case 2:
					printf("2 >> Ordenacao pelo campo2.\n");
			
					
					break;
		
				case 3:
					printf("3 >> Por Categoria ordenado pelo campo chave.\n");
			
					
					break;
			
				case 4:
					printf("4 >> Por categoria ordenado pelo campo2.\n");
			
					
					break;
					
				case 5:
					printf("5 >> Dados do arquivo desordenado.\n");
					
					
					break;
					
				case 6:
					main();
					break;
			}
			
			break;
			
		case 6:
			exit(0);
			break;
	}
}

int leituraArqBinario(){
	
 	
 	return 0;
}
