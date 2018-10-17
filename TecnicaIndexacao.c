//TECNICA DE INDEXACAO
//Criar índices e Utilizar os Métodos de Busca
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
	printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave primária)\n");
	printf("3 >> Eliminar um registro do arquivo\n");
	printf("4 >> Inserir um registro no arquivo\n");
	printf("5 >> Impressao\n");
	printf("6 >> Sair\n\nOpcao >> ");
	scanf("%d",&op);
	
	system("cls");
	
	switch(op)
	{
		case 1:
		//entrada é pelo campo chave primária;
		//Carregar Índice denso (item a);
		//Chamar a função Busca Binária para localizar a chave;
		//Ler no arquivo o registro procurado;
		//Imprimir todas as informações do registro buscado;
		//Caso não exista o valor buscado: imprimir mensagem e não fazer os passos iv e v, acima
			printf("1 >> Consultar 'um registro'\n");
			
			
			main();
			break;
			
		case 2:
		//entrada é pelo campo chave primária;
		//Carregar Índice denso (item a);
		//Chamar a função Busca Binária para localizar a chave;
		//Ler no arquivo o registro procurado;
		//Perguntar qual campo será modificado, um a um;
		//Alterar o(s) campo(s) no arquivo;
		//Caso a alteração ocorra no campo 2 e/ou no da categoria (campo3) – atualizar os respectivos Índices; 
		//Caso não exista o valor buscado: imprimir mensagem e não fazer os passos de iv a vii, acima
			printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave primária)\n");
			
			
			main();
			break;
		
		case 3:
		//entrada é pelo campo chave primária;
		//Carregar Índice denso (item a);
		//Chamar a função Busca Binária para localizar a chave;
		//Eliminar (*) o registro procurado do arquivo;
		//Atualizar os respectivos Índices; 
		//Caso não exista o valor buscado: imprimir mensagem e não fazer os passos iv e v, acima	
			printf("3 >> Eliminar um registro do arquivo\n");
			
			
			main();
			break;
			
		case 4:
		//ler as informações do novo registro. Fazer a validação de o valor do campo chave primária já existir no arquivo. Caso já exista, repetir a digitação do campo até que se digite um valor válido;
		//Inserir o novo registro no final do arquivo;
		//Atualizar os respectivos Índices; 
		//Imprimir mensagem:” inserção feita com sucesso”;
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
