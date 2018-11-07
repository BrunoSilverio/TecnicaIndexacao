//TECNICA DE INDEXACAO
//Criar �ndices e Utilizar os M�todos de Busca
#include<stdio.h>
#include<stdlib.h>

int consultaRegistro(int chave);
int alteraRegistro(int chave);
int eliminaRegistro(int chave);
int insereRegistro();

//|int tipo| -> define o tipo de impressao
int impressao(int tipo);

void main()
{
	FILE *arq = fopen("filmes.dat","rb");
	if(!arq){
		printf("ERRO AO ABRIR ARQUIVO");
		exit(-1);
	}
	int option,option2;
	int chave;

	//MENU PRINCIPAL
	do{
		printf("1 >> Consultar um registro\n");
		printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave prim�ria)\n");
		printf("3 >> Eliminar um registro do arquivo\n");
		printf("4 >> Inserir um registro no arquivo\n");
		printf("5 >> Impressao\n");
		printf("6 >> Sair\n\nOpcao >> ");
		scanf("%d",&option);

		system("cls");

		switch(option)
		{
			case 1:
			//entrada eh pelo campo chave primaria;
			//Carregar indice denso (item a);
			//Chamar a funcao Busca Binaria para localizar a chave;
			//Ler no arquivo o registro procurado;
			//Imprimir todas as informacoes do registro buscado;
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos iv e v, acima
				printf("1 >> Consultar 'um registro'\n");
				printf("Digite a chave primaria: ");
				scanf("%i",&chave);
				if(consultaRegistro(chave)!= 0){//falha
					printf("REGISTRO NAO ENCONTRADO\n");
				}
				break;

			case 2:
			//entrada e pelo campo chave primaria;
			//Carregar indice denso (item a);
			//Chamar a funcao Busca Binaria para localizar a chave;
			//Ler no arquivo o registro procurado;
			//Perguntar qual campo sera modificado, um a um;
			//Alterar o(s) campo(s) no arquivo;
			//Caso a alteracao ocorra no campo 2 e/ou no da categoria (campo3): atualizar os respectivos �ndices; 
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos de iv a vii, acima
				printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave primaria)\n");
				printf("Digite a chave primaria: ");
				scanf("%i",&chave);
				if(alteraRegistro(chave) != 0){//falha
					printf("REGISTRO NAO ENCONTRADO\n");
				}
				break;

			case 3:
			//entrada e pelo campo chave primaria;
			//Carregar indice denso (item a);
			//Chamar a funcao Busca Binaria para localizar a chave;
			//Eliminar (*) o registro procurado do arquivo;
			//Atualizar os respectivos indices; 
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos iv e v, acima	
				printf("3 >> Eliminar um registro do arquivo\n");
				printf("Digite a chave primaria: ");
				scanf("%i",&chave);
				if(eliminaRegistro(chave)!= 0){
					printf("REGISTRO NAO ENCONTRADO\n");	
				}
				break;

			case 4:
			//ler as informacoes do novo registro. Fazer a validacao de o valor do campo chave primaria j� existir no arquivo. Caso j� exista, repetir a digita��o do campo at� que se digite um valor v�lido;
			//Inserir o novo registro no final do arquivo;
			//Atualizar os respectivos indices; 
			//Imprimir mensagem:!insercao feita com sucesso!;
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
				scanf("%d",&option2);

				system("cls");

				switch(option2)
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
			
			default:
				printf("\nOPCAO INVALIDA\n");
				break;
		}
	}while(option!=6);
}