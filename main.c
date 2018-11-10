//TECNICA DE INDEXACAO
//Criar ï¿½ndices e Utilizar os Mï¿½todos de Busca
//Bruno Silverio - RA: 16080293
//Iago Lourenço - RA: 15

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//STRUCT ARQUIVOS
typedef struct{
	int chave;
	char nome[50];
	char genero[50];
	float valor;
	int quantidade;
}tipoFilmes;

//STRUCT LISTA DENSA
typedef struct{
	int chave;
	int posicao;
}listaDensa;

//STRUCT TABELA INVERTIDA
typedef struct{
	int posicao;
	char nome[50];
}tabelaInvertida;

tipoFilmes* carregarDados(int*, tipoFilmes*);

int verificaChave(int chave, no* cadastrados, int TAM);
int consultaRegistro(tipoFilmes*, listaDensa*, int chave); //igual registroExiste(int chave);
int alteraRegistro(int chave);
int eliminaRegistro(int chave);
int insereRegistro(tipoFilmes filme);
int impressao(int tipo);//|int tipo| -> define o tipo de impressao

//FUNCOES - BUSCAR
void bubbleSort(listaDensa[], int);
int buscaBinaria(listaDensa*, int, int);

void main(){
	
	int option,option2;
	int chave;
	tipoFilmes filme;
	
	FILE *arq = fopen("filmes.dat","rb");
	
	if(!arq){
		printf("ERRO AO ABRIR ARQUIVO");
		exit(-1);
	}
		
	//MENU PRINCIPAL
	do{
		system("cls");
		printf("\tTrabalho de ERDB\n\n");
		printf("1 >> Consultar um registro\n");
		printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave primria)\n");
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
			//Chamar a funcao Busca Binaria(consultaRegistro) para localizar a chave;
			//Ler no arquivo o registro procurado;
			//Imprimir todas as informacoes do registro buscado;
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos iv e v, acima
				printf("1 >> Consultar um registro\n");
				//printf("Digite a chave primaria: ");
				//scanf("%i",&chave);
				
				consultaRegistro(cadastros, indiceDenso, qtdCadastros);
				
				break;

			case 2:
			//entrada e pelo campo chave primaria;
			//Carregar indice denso (item a);
			//Chamar a funcao Busca Binaria para localizar a chave;
			//Ler no arquivo o registro procurado;
			//Perguntar qual campo sera modificado, um a um;
			//Alterar o(s) campo(s) no arquivo;
			//Caso a alteracao ocorra no campo 2 e/ou no da categoria (campo3): atualizar os respectivos ï¿½ndices; 
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos de iv a vii, acima
				printf("2 >> Alterar/Atualizar campo(s) de um registro (menos o campo chave primaria)\n");
				printf("Digite a chave primaria: ");
				scanf("%i",&chave);
				if(alteraRegistro(chave) != 0){//falha
					printf("REGISTRO NAO ENCONTRADO\n");
				}else{
					printf("REGISTRO ALTERADO\n");
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
				}else{
					printf("REGISTRO ELIMINADO\n");
				}
				break;

			case 4:
			//ler as informacoes do novo registro. Fazer a validacao de o valor do campo chave primaria jï¿½ existir no arquivo. Caso jï¿½ exista, repetir a digitaï¿½ï¿½o do campo atï¿½ que se digite um valor vï¿½lido;
			//Inserir o novo registro no final do arquivo;
			//Atualizar os respectivos indices; 
			//Imprimir mensagem:!insercao feita com sucesso!;
				
				
				printf("4 >> Inserir um registro no arquivo\n");
				printf("Digite a chave primaria: ");
				scanf("%d",&filme.pKey);
				printf("Digite o nome do filme: ");
				scanf("%s",filme.nome);
				printf("Digite o genero do filme: ");
				scanf("%s",filme.genero);
				printf("Digite o valor do filme: ");
				scanf("%lf",&filme.valor);
				printf("Digite a quantidade do filme: ");
				scanf("%i",&filme.quantidade);
				
				while(consultaRegistro(filme.pKey) == 1){
					//chave existente
					system("clear");
					printf("\nCHAVE EXISTENTE\n");
					printf("Digite a chave primaria: ");
					scanf("%d",&filme.pKey);
				}
				
				if(insereRegistro(filme)== 1){
					printf("\nINSERCAO FEITA COM SUCESSO\n");
				}else{
					printf("\nERRO AO INSERIR\n");
				}

				break;

			case 5:
			do{
				printf("[IMPRESSAO]\n");
				printf("1 >> Ordenacao por Chave Primaria\n");
				printf("2 >> Ordenacao pelo campo2.\n");
				printf("3 >> Por Categoria ordenado pelo campo chave.\n");
				printf("4 >> Por categoria ordenado pelo campo2.\n");
				printf("5 >> Dados do arquivo desordenado.\n");
				printf("6 >> Voltar Menu Principal\n\nOpcao >> ");
				scanf("%d",&option2);

				system("cls");

				if(impressao(option2) != 0){
					printf("OPCAO INVALIDA\n");
				}
			}while(option2 != 6);

				break;

			default:
				printf("\nOPCAO INVALIDA\n");
				break;
		}
	}while(option!=6);
}

int impressao(int tipo){

	switch(tipo)
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
						return 0;
						break;

					default:
					
						return -1;
						break;
				}
	return 0;
}

void bubbleSort(listaDensa lista[], int TAM){
	int i, j;
	listaDenso aux;
	int contador = 1;

	for (i = 0; i < tam - 1 && teste; i++)
	{
		contador = 0;

		for (j = 0; j < tam - i - 1; j++)
		{
			if (lista[j].chave > lista[j + 1].chave)
			{
				contador = 1;
				aux.chave = lista[j].chave;
				aux.posicao = lista[j].posicao;

				lista[j].chave = lista[j + 1].chave;
				lista[j].posicao = lista[j + 1].posicao;

				lista[j + 1].chave = aux.chave;
				lista[j + 1].posicao = aux.posicao;
			}
		}
	}
}

int buscaBinaria(listaDensa* indice, int TAM, int x){
	int sup = 0, inf = tam - 1, meio = 0;

	while (inf >= sup)
	{
		meio = (sup + inf) / 2;

		if (indice[meio].chave == x)
			return (indice[meio].posicao);
		if (indice[meio].chave > x)
			inf = meio - 1;
		else
			sup = meio + 1;
	}
	return (-1);
}

tipoFilmes* carregarDados(int *qtd, tipoFilmes *cadastro)
{
	tipoFilmes aux;
	int i, qtdCadastros;

	FILE *arquivo = fopen("database.dat", "rb");
	if (!arquivo) return NULL;

	fread(qtd, sizeof(int), 1, arquivo);

	qtdCadastros = *qtd;

	cadastro = (tipoFilmes*)malloc(qtdCadastros * sizeof(tipoFilmes));

	for (i = 0; i < qtdCadastros; i++)
	{
		fread(&aux, sizeof(no), 1, arquivo);
		cadastro[i] = aux;
	}
	fclose(arquivo);

	return(cadastro);
}

int verificaChave(int chave, tipoFilmes* cadastrado, int TAM){
	int i;
	
	for(i=0; i <= TAM; i++){
		
		if(chave == cadastrado[i].chave){
			return 1;
		}
	}
	return 0;	
}

int consultaRegistro(tipoFilmes *cadastro, listaDensa *indice, int qtd){ 
	//carregar indice na memoria, usar busca binaria para achar
	//retornar o resultado
	
	int codigo = 0, posicao = 0, j = 0;

	do
	{
		system("cls");

		printf("----- Consultar Registro -----\n\n");
		printf("Digite o codigo que deseja encontrar: ");
		scanf("%i", &codigo);

		posicao = buscaBinaria(indice, qtd, codigo);

		system("cls");

		if (posicao != -1)
		{
			printf(" Chave   Nome filme      Genero       Valor   Quantidade\n\n");

			printf(" %i   ", cadastro[posicao].chave);
			printf("%s ", cadastro[posicao].nome);
			for (j = 15 - strlen(cadastro[posicao].nome); j > 0; j--) printf(" ");
			printf("%s ", cadastro[posicao].genero);
			for (j = 15 - strlen(cadastro[posicao].genero); j > 0; j--) printf(" ");
			//if (cadastro[posicao].valor < 10) printf("0");
			printf("%.2f ", cadastros[posicao].valor);
			printf("   %i\n", cadastros[posicao].quantidade);
		}
		else
		{
			printf("Erro! Nao foi encontrado o cadastro de chave %i na base de dados. Insira outro!\n", codigo);
			system("pause");
		}
	} while (posicao == -1);
}

int alteraRegistro(int chave){

}

int eliminaRegistro(int chave){

}

int insereRegistro(tipoFilmes filme){

}

