//TECNICA DE INDEXACAO
//Criar ï¿½ndices e Utilizar os Mï¿½todos de Busca
//Bruno Silverio - RA: 16080293
//Iago Lourenço - RA: 15610116

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

tipoFilmes *carregarDados(int *, tipoFilmes *);
tipoFilmes *salvarNovoArquivo(tipoFilmes, tipoFilmes *, int *);
tipoFilmes *adicionarRegistros(tipoFilmes *, int *, char [][50]);
tipoFilmes *modificarRegistro(tipoFilmes *, listaDensa *, int);
tipoFilmes *eliminarRegistro(tipoFilmes *, listaDensa *, int *);
listaDensa *criarIndiceDenso(int, tipoFilmes *, listaDensa *);

int verificarChave(int chave, tipoFilmes *cadastrado, int TAM);
int consultarRegistro(tipoFilmes *, listaDensa *, int chave); //igual registroExiste(int chave);
int* tabelaInversa(int *, int *, tipoFilmes *, int);
void catAlfabetoOrd(tipoFilmes *, int[], int *, int, char[5][50]);
void catChaveOrd(tipoFilmes *, int[], int[], int, char[5][50]);
int impressao(tipoFilmes *, listaDensa *, int, int, int *, char[5][50], int[], int[], int[], int[]);//|int tipo| -> define o tipo de impressao

//FUNCOES - BUSCAR
void bubbleSort(listaDensa[], int);
int buscaBinaria(listaDensa *, int, int);

int main(){
	
	int option,option2;
	int qtdCadastros, count, posicao;
	tipoFilmes *cadastro = NULL;
	listaDensa *indiceDenso = NULL;
	int *ordemAlfabetica = NULL, pri;
	int pri_cat_alfabetico[5], pri_cat_chave[5], catNome[100], catChave[100];
	char genero[5][50] = { "Acao", "Terror", "Suspense", "Romance", "Comedia" };

	
	//FILE *arq = fopen("filmes.dat","rb");
	cadastro = carregarDados(&qtdCadastros, cadastro);
	
	if(!cadastro){
		printf("ERRO AO ABRIR ARQUIVO");
		system("pause");
		exit(-1);
	}
	
	indiceDenso = criarIndiceDenso(qtdCadastros, cadastro, indiceDenso);
	ordemAlfabetica = tabelaInversa(ordemAlfabetica, &pri, cadastro, qtdCadastros);
	catAlfabetoOrd(cadastro, pri_cat_alfabetico, catNome, qtdCadastros, genero);
	catChaveOrd(cadastro, pri_cat_chave, catChave, qtdCadastros, genero);

		
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
				cadastro = modificarRegistro(cadastro, indiceDenso, qtdCadastros);
				ordemAlfabetica = tabelaInversa(ordemAlfabetica, &pri, cadastro, qtdCadastros);
				catAlfabetoOrd(cadastro, pri_cat_alfabetico, catNome, qtdCadastros, genero);
				
				break;

			case 3:
			//entrada e pelo campo chave primaria;
			//Carregar indice denso (item a);
			//Chamar a funcao Busca Binaria para localizar a chave;
			//Eliminar (*) o registro procurado do arquivo;
			//Atualizar os respectivos indices; 
			//Caso nao exista o valor buscado: imprimir mensagem e nao fazer os passos iv e v, acima	
				printf("3 >> Eliminar um registro do arquivo\n");
				cadastro = eliminarRegistro(cadastro, indiceDenso, &qtdCadastros);
				indiceDenso = criarIndiceDenso(qtdCadastros, cadastro, indiceDenso);
				ordemAlfabetica = tabelaInversa(ordemAlfabetica, &pri, cadastro, qtdCadastros);
				catAlfabetoOrd(cadastro, pri_cat_alfabetico, catNome, qtdCadastros, genero);
				
				break;

			case 4:
			//ler as informacoes do novo registro. Fazer a validacao de o valor do campo chave primaria jï¿½ existir no arquivo. Caso jï¿½ exista, repetir a digitaï¿½ï¿½o do campo atï¿½ que se digite um valor vï¿½lido;
			//Inserir o novo registro no final do arquivo;
			//Atualizar os respectivos indices; 
			//Imprimir mensagem:!insercao feita com sucesso!;
				printf("4 >> Inserir um registro no arquivo\n");
				cadastro = adicionarRegistros(cadastro, &qtdCadastros, genero);
				indiceDenso = criarIndiceDenso(qtdCadastros, cadastro, indiceDenso);
				ordemAlfabetica = tabelaInversa(ordemAlfabetica, &pri, cadastro, qtdCadastros);
				catAlfabetoOrd(cadastro, pri_cat_alfabetico, catNome, qtdCadastros, genero);

				break;

			case 5:
				//IMPRESSAO
				impressao(cadastro, indiceDenso, qtdCadastros, pri, ordemAlfabetica, genero, pri_cat_alfabetico, pri_cat_chave, catNome, catChave);
				
				break;

			default:
				printf("\nOPCAO INVALIDA\n");
				break;
				
			system("pause");
		}
	}while(option!=6);
	
	free(indiceDenso);
	free(ordemAlfabetica);
	
	system("pause");
	return 0;
}

void impressao(tipoFilmes *cadastro, listaDensa *lista, int qtd, int pri, int *tabelaInversaAlfabeto, char genero[5][50], int pri_cat_alfabeto[], int pri_cat_chave[], int catNome[], int catChave[]){
	
	int i = 0, j = 0, po = 0, option2 = 0;
	int posicao = 0;
	
	do{
		system("cls");
		
		printf("[IMPRESSAO]\n");
		printf("1 >> Ordenacao por Chave Primaria\n");
		printf("2 >> Ordenacao pelo campo2(Nome).\n");
		printf("3 >> Por Categoria ordenado pelo campo chave.\n");
		printf("4 >> Por categoria ordenado pelo campo2(Nome).\n");
		printf("5 >> Dados do arquivo desordenado.\n");
		scanf("%d",&option2);

		if(option2 > 5 || option2 < 1){
			printf("OPCAO INVALIDA\n");
		}
		
		switch (option2)
		{
			case 1:
				printf("1 >> Ordenacao por Chave Primaria\n");
				printf(" Chave   Nome filme      Genero       Valor   Quantidade\n\n");

				for (i = 0; i < qtd; i++)
				{
					posicao = lista[i].posicao;

					printf(" %i   ", cadastro[posicao].chave);
					printf("%s ", cadastro[posicao].nome);
					for (j = 15 - strlen(cadastro[posicao].nome); j > 0; j--) printf(" ");
					printf("%s ", cadastro[posicao].genero);
					for (j = 15 - strlen(cadastro[posicao].genero); j > 0; j--) printf(" ");
					if (cadastro[posicao].valor < 10) printf("0");
					printf("%.2f ", cadastro[posicao].valor);
					printf("   %i\n", cadastro[posicao].quantidade);
				}
			break;

			case 2:
				printf("2 >> Ordenacao pelo campo2(Nome).\n");
				printf(" Chave   Nome filme      Genero       Valor   Quantidade\n\n");

				posicao = pri;
				i = qtd;

				while (i > 0)
				{
					printf(" %i   ", cadastro[posicao].chave);
					printf("%s ", cadastro[posicao].nome);
					for (j = 15 - strlen(cadastro[posicao].nome); j > 0; j--) printf(" ");
					printf("%s ", cadastro[posicao].genero);
					for (j = 15 - strlen(cadastro[posicao].genero); j > 0; j--) printf(" ");
					if (cadastro[posicao].valor < 10) printf("0");
					printf("%.2f ", cadastro[posicao].valor);
					printf("   %i\n", cadastro[posicao].quantidade);

					posicao = tabelaInversaAlfabeto[posicao];
					i--;
				}
			break;
			
			case 3:
				printf("3 >> Por Categoria ordenado pelo campo chave.\n");
				for (i = 0; i < 5; i++)
				{
					printf("\n\n --------------  %s  --------------\n\n", genero[i]);
					printf(" Chave  Nome Filme      Valor  Quantidade\n\n");

					posicao = pri_cat_chave[i];

					do
					{
						printf(" %i   ", cadastro[posicao].chave);
						printf("%s ", cadastro[posicao].nome);
						for (j = 15 - strlen(cadastro[posicao].nome); j > 0; j--) printf(" ");
						if (cadastro[posicao].valor < 10) printf("0");
						printf("%.2f ", cadastro[posicao].valor);
						printf("   %i\n", cadastro[posicao].quantidade);
						posicao = catChave[posicao];

					} while (posicao != -1);

				}
			break;
			
			case 4:
				printf("4 >> Por categoria ordenado pelo campo2(Nome).\n");
				for (i = 0; i < 5; i++)
				{	
					printf("\n\n --------------  %s  --------------\n\n", genero[i]);
					printf(" Chave  Nome Filme      Valor  Quantidade\n\n");

					posicao = pri_cat_alfabeto[i];

					do
					{
						printf(" %i   ", cadastro[posicao].chave);
						printf("%s ", cadastro[posicao].nome);
						for (j = 15 - strlen(cadastro[posicao].nome); j > 0; j--) printf(" ");
						if (cadastro[posicao].valor < 10) printf("0");
						printf("%.2f ", cadastro[posicao].valor);
						printf("   %i\n", cadastro[posicao].quantidade);
						posicao = catNome[posicao];

					} while (posicao != -1);
				}
			break;		
			
			case 5:
				printf("5 >> Dados do arquivo desordenado.\n");
				printf(" Chave   Nome filme      Genero       Valor   Quantidade\n\n");

				for (i = 0; i < qtd; i++)
				{
					printf(" %i   ", cadastro[i].chave);
					printf("%s ", cadastro[i].nome);
					for (j = 15 - strlen(cadastro[i].nome); j > 0; j--) printf(" ");
					printf("%s ", cadastro[i].genero);
					for (j = 15 - strlen(cadastro[i].genero); j > 0; j--) printf(" ");
					if (cadastro[i].valor < 10) printf("0");
					printf("%.2f ", cadastro[i].valor);
					printf("   %i\n", cadastro[i].quantidade);
				}
			break;
		
			default:
			break;
		}	
	}while(option2 > 5 || option2 < 1);
	system("cls");

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

tipoFilmes* carregarDados(int *qtd, tipoFilmes *cadastro){
	
	tipoFilmes aux;
	int i, qtdCadastros;

	FILE *arquivo = fopen("filmes.dat", "rb");
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

tipoFilmes *salvarNovoArquivo(tipoFilmes novo, tipoFilmes *cadastro, int *qtd){
	
	FILE *arquivo = fopen("filmes.dat", "wb");
	int i, sub;

	if (novo.chave != -1)
	{
		(*qtd)++;
		sub = 1;
	}
	else
		sub = 0;

	fwrite(qtd, sizeof(int), 1, arquivo);

	for (i = 0; i < ((*qtd) - sub); i++)
		fwrite(&cadastro[i], sizeof(no), 1, arquivo);

	if (novo.chave != -1)
		fwrite(&novo, sizeof(no), 1, arquivo);

	fclose(arquivo);

	return(carregarBaseDados(qtd, cadastro));
}

tipoFilmes *adicionarRegistros(tipoFilmes *cadastro, int *qtd, char genero[][50]){
	//FILE *arq = fopen("FILMES.dat", "a+b"); Adiciona uma nova struct carro
	no aux;
	int aleatorio, op, i;

	system("cls");

	do
	{
		printf("[ADICIONAR REGISTRO]\n\n");

		getchar();

		do
		{
			printf("Digite o nome do filme: ");
			fgets(aux.nome, 50, stdin);
			if (aux.nome[0] == '\n') printf("Valor nulo nao eh valido!Digite novamente.\n\n");
		} while (aux.nome[0] == '\n');

		for (i = 0; i < strlen(aux.nome); i++)
			if (aux.nome[i] == '\n')
				aux.nome[i] = '\0';

		do
		{
			printf("Qual genero deseja escolher?Insira de acordo com os numeros abaixo:\n");
			for (int k = 0; k < 5; k++) printf("%i. %s\n", k + 1, genero[k]);
			printf("\nOpcao: ");
			scanf("%i", &op);
			op--;
			if (op < 0 || op > 4)
			{
				printf("Nao existe tal valor! Digite novamente!\n");
				system("pause");
				printf("\n");
			}//const char não é permitido!
			
			else
			{
				switch (op)
				{
				case 0:
					strcpy(aux.genero, "Acao");
					break;
				case 1: 
					strcpy(aux.genero, "Terror");
					break;
				case 2:
					strcpy(aux.genero, "Suspense");
					break;
				case 3:
					strcpy(aux.genero, "Romance");
					break;
				case 4:
					strcpy(aux.genero, "Comedia");
					break;
				}
			}
		} while (op < 0 || op > 4);

		
		for (i = 0; i < strlen(aux.genero); i++)
			if (aux.genero[i] == '\n')
				aux.genero[i] = '\0';

		printf("Digite o valor do filme: ");
		scanf("%f", &aux.valor);

		printf("Digite a quantidade do filme: ");
		scanf("%i", &aux.quantidade);

		do
		{
			aleatorio = 1000 + (rand() % 9999);

		} while (verificaChave(aleatorio, cadastro, (*qtd)) != 0 || aleatorio <= 1000 || aleatorio >= 9999);

		aux.chave = aleatorio;

		cadastro = salvarNovoArquivo(aux, cadastro, qtd);

		do
		{
			printf("\n Deseja cadastrar outro filme?\n");
			printf(" 1. SIM;\n");
			printf(" 2. NAO;\n\n");
			printf(" Opcao: ");
			scanf("%i", &op);
			if (op < 1 || op > 2)
			{
				printf("Nao existe esta opcao! Digite novamente!\n");
				system("pause");
				system("cls");
			}
		} while (op < 1 || op > 2);

	} while (op != 2);

	return (cadastro);
}

tipoFilmes *modificarRegistro(tipoFilmes *cadastro, listaDensa *indice, int qtd){
	int posicao, codigo, op, i, j, peso;
	char aux[50];
	float consumo;
	no x;

	system("cls");

	printf("----- Modificar Registro -----\n\n");
	printf("Digite o codigo que deseja encontrar (caso queira retornar insira 0)\nOpcao: ");
	scanf("%i", &codigo);
	if (codigo == 0) return(cadastros);
	posicao = buscaBinaria(indice, qtd, codigo);
	if (posicao != -1)
	{
		printf("\n Chave  Nome Carro      Montadora       Consumo  Peso\n\n");

		printf(" %i   ", cadastros[posicao].chave);
		printf("%s ", cadastros[posicao].nomeCarro);
		for (j = 15 - strlen(cadastros[posicao].nomeCarro); j > 0; j--) printf(" ");
		printf("%s ", cadastros[posicao].montadora);
		for (j = 15 - strlen(cadastros[posicao].montadora); j > 0; j--) printf(" ");
		if (cadastros[posicao].consumo < 10) printf("0");
		printf("%.2f ", cadastros[posicao].consumo);
		if (cadastros[posicao].peso < 1000) printf("0");
		printf("   %i\n", cadastros[posicao].peso);

		do
		{
			printf("\nDeseja alterar o nome do carro?\n\n");
			printf("1. Sim;\n2. Nao;\n\nOpcao: ");
			scanf("%i", &op);
			if (op > 2 || op < 1) printf("Digite uma opcao valida!\n");
		} while (op > 2 || op < 1);

		if (op == 1)
		{
			getchar();
			printf("\nDigite o novo nome ao carro: ");
			fgets(aux, 50, stdin);
			for (i = 0; i < strlen(aux); i++)
				if (aux[i] == '\n')
					aux[i] = '\0';
			strcpy(cadastros[posicao].nomeCarro, aux);
		}
		do
		{
			printf("\nDeseja alterar o nome da montadora?\n\n");
			printf("1. Sim;\n2. Nao;\n\nOpcao: ");
			scanf("%i", &op);
			if (op > 2 || op < 1) printf("Digite uma opcao valida!\n");
		} while (op > 2 || op < 1);

		if (op == 1)
		{
			getchar();
			printf("\nDigite o novo nome a montadora:");
			fgets(aux, 50, stdin);
			for (i = 0; i < strlen(aux); i++)
				if (aux[i] == '\n')
					aux[i] = '\0';
			strcpy(cadastros[posicao].montadora, aux);
		}

		do
		{
			printf("\nDeseja alterar o consumo do carro?\n\n");
			printf("1. Sim;\n2. Nao;\n\nOpcao: ");
			scanf("%i", &op);
			if (op > 2 || op < 1) printf("Digite uma opcao valida!\n");
		} while (op > 2 || op < 1);

		if (op == 1)
		{
			printf("\nDigite o novo consumo: ");
			scanf("%f", &consumo);
			cadastros[posicao].consumo = consumo;
		}

		do
		{
			printf("\nDeseja alterar o peso do carro?\n\n");
			printf("1. Sim;\n2. Nao;\n\nOpcao: ");
			scanf("%i", &op);
			if (op > 2 || op < 1) printf("Digite uma opcao valida!\n");
		} while (op > 2 || op < 1);

		if (op == 1)
		{
			printf("\nDigite o novo peso: ");
			scanf("%i", &peso);
			cadastros[posicao].peso = peso;
		}

		x.chave = -1;

		printf("\n\n Atualizado com Sucesso!\n");

		return(salvarNovoArquivo(x, cadastros, &qtd));

	}
	else
	{
		printf("Erro! Nao foi encontrado o cadastro de chave %i na base de dados. Retornando ao menu...\n", codigo);
		system("pause");
		system("cls");
		return(cadastros);
	}
}

tipoFilmes *eliminarRegistro(tipoFilmes *cadastro, listaDensa *indice, int *qtd){
	int posicao, codigo, j, i;
	no aux;
	aux.chave = -1;
	do
	{
		system("cls");

		printf("----- Eliminar Registro -----\n\n");
		printf("Digite a chave que deseja do registro, eliminar:\n\n");
		printf(" Chave  Nome Carro      Montadora       Consumo  Peso\n\n");

		for (i = 0; i < *qtd; i++)
		{
			printf(" %i   ", cadastros[i].chave);
			printf("%s ", cadastros[i].nomeCarro);
			for (j = 15 - strlen(cadastros[i].nomeCarro); j > 0; j--) printf(" ");
			printf("%s ", cadastros[i].montadora);
			for (j = 15 - strlen(cadastros[i].montadora); j > 0; j--) printf(" ");
			if (cadastros[i].consumo < 10) printf("0");
			printf("%.2f ", cadastros[i].consumo);
			printf("   %i\n", cadastros[i].peso);
		}


		printf("Opcao: ");
		scanf("%i", &codigo);
		posicao = buscaBinaria(indice, *qtd, codigo);
		if (posicao == -1)
		{
			printf("Nao existe esta chave! Insira novamente!\n");
			system("pause");
		}
	} while (posicao == -1);

	printf("\n\nEncontrada:\n Chave  Nome Carro      Montadora       Consumo  Peso\n\n");

	printf(" %i   ", cadastros[posicao].chave);
	printf("%s ", cadastros[posicao].nomeCarro);
	for (j = 15 - strlen(cadastros[posicao].nomeCarro); j > 0; j--) printf(" ");
	printf("%s ", cadastros[posicao].montadora);
	for (j = 15 - strlen(cadastros[posicao].montadora); j > 0; j--) printf(" ");
	if (cadastros[posicao].consumo < 10) printf("0");
	printf("%.2f ", cadastros[posicao].consumo);
	printf("   %i\n", cadastros[posicao].peso);

	do
	{
		printf("\nTem certeza que deseja excluir esse registro?");
		printf("\n 1. Sim;\n 2. Nao;\n\nOpcao: ");
		scanf("%i", &codigo);
		if (codigo < 1 || codigo > 2)
		{
			printf("Nao existe tal opcao!\n\n");
			system("pause");
		}
	} while (codigo < 1 || codigo > 2);

	if (codigo == 1)
	{
		for (i = posicao; i < *qtd; i++)
			cadastros[i] = cadastros[i + 1];

		(*qtd)--;

		return(salvarNovoArquivo(aux, cadastros, qtd));

	}
	return (cadastros);
}

listaDensa *criarIndiceDenso(int qtdCadastro, tipoFilmes *cadastro, listaDensa *indice){
	int i;

	indice = (listaDenso*)malloc(qtdCadastros * sizeof(listaDenso));

	for (i = 0; i < qtdCadastros; i++)
	{
		indice[i].chave = cadastros[i].chave;
		indice[i].posicao = i;
	}

	bubble(indice, qtdCadastros);

	return (indice);
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
			printf("%.2f ", cadastro[posicao].valor);
			printf("   %i\n", cadastro[posicao].quantidade);
		}
		else
		{
			printf("Erro! Nao foi encontrado o cadastro de chave %i na base de dados. Insira outro!\n", codigo);
			system("pause");
		}
	} while (posicao == -1);
}

int* tabelaInversa(int *ordem, int *pri, tipoFilmes *cadastro, int qtd){
	int i;
	tabInv *aux;

	ordem = (int*)malloc(qtd * sizeof(int));
	aux = (tabInv*)malloc(qtd * sizeof(tabInv));

	for (i = 0; i < qtd; i++)
	{
		strcpy(aux[i].nome, cadastros[i].nomeCarro);
		aux[i].posicao = i;
	}

	bubbleString(aux, qtd);

	for (i = 0; i < qtd; i++)
	{
		if (i == 0)
			*pri = aux[i].posicao;
		ordem[aux[i].posicao] = aux[i + 1].posicao;
	}

	return (ordem);
}

void catAlfabetoOrd(tipoFilmes *cadastro, int pri_cat[], int *cadas, int qtd, char genero[5][50]){
	int count[5] = { 0 }; //quantas montadoras
	int i, j;
	int countMont[5] = { 0 };

	for (i = 0; i < 100; i++)
		cadas[i] = -1;

	for (i = 0; i < qtd; i++)
	{
		if (strcmp(cadastros[i].montadora, montadoras[0]) == 0)
			count[0]++;
		else if (strcmp(cadastros[i].montadora, montadoras[1]) == 0)
			count[1]++;
		else if (strcmp(cadastros[i].montadora, montadoras[2]) == 0)
			count[2]++;
		else if (strcmp(cadastros[i].montadora, montadoras[3]) == 0)
			count[3]++;
		else if (strcmp(cadastros[i].montadora, montadoras[4]) == 0)
			count[4]++;
	}

	tabInv *mont[5];

	for (int k = 0; k < 5; k++) mont[k] = (tabInv*)malloc(count[k] * sizeof(tabInv));

	for (i = 0; i < qtd; i++)
	{
		if (strcmp(cadastros[i].montadora, montadoras[0]) == 0) //VOLKSWAGEN
		{
			strcpy(mont[0][countMont[0]].nome, cadastros[i].nomeCarro);
			mont[0][countMont[0]].posicao = i;
			countMont[0]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[1]) == 0) //CHEVROLET
		{
			strcpy(mont[1][countMont[1]].nome, cadastros[i].nomeCarro);
			mont[1][countMont[1]].posicao = i;
			countMont[1]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[2]) == 0) //FORD
		{
			strcpy(mont[2][countMont[2]].nome, cadastros[i].nomeCarro);
			mont[2][countMont[2]].posicao = i;
			countMont[2]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[3]) == 0) //FIAT
		{
			strcpy(mont[3][countMont[3]].nome, cadastros[i].nomeCarro);
			mont[3][countMont[3]].posicao = i;
			countMont[3]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[4]) == 0) //HYUNDAI
		{
			strcpy(mont[4][countMont[4]].nome, cadastros[i].nomeCarro);
			mont[4][countMont[4]].posicao = i;
			countMont[4]++;
		}
	}

	for (int k = 0; k < 5; k++) bubbleString(mont[k], countMont[k]);

	for (int k = 0; k < 5; k++) pri_cat[k] = mont[k][0].posicao;

	for (i = 0; i < countMont[0]; i++)
		cadas[mont[0][i].posicao] = mont[0][i + 1].posicao;

	cadas[mont[0][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[1]; i++)
		cadas[mont[1][i].posicao] = mont[1][i + 1].posicao;

	cadas[mont[1][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[2]; i++)
		cadas[mont[2][i].posicao] = mont[2][i + 1].posicao;

	cadas[mont[2][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[3]; i++)
		cadas[mont[3][i].posicao] = mont[3][i + 1].posicao;

	cadas[mont[3][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[4]; i++)
		cadas[mont[4][i].posicao] = mont[4][i + 1].posicao;

	cadas[mont[4][i - 1].posicao] = (-1);

	for (int k = 0; k < 5; k++)	free(mont[k]);
}

void catChaveOrd(tipoFilmes *cadastro, int pri_cat[], int *cadas, int qtd, char genero[5][50]){
		int count[5] = { 0 };
	int i, j;
	int countMont[5] = { 0 };

	for (i = 0; i < 100; i++)
		cadas[i] = -1;


	listaDenso *mont[5];

	for (i = 0; i < qtd; i++)
	{
		if (strcmp(cadastros[i].montadora, montadoras[0]) == 0)
			count[0]++;
		else if (strcmp(cadastros[i].montadora, montadoras[1]) == 0)
			count[1]++;
		else if (strcmp(cadastros[i].montadora, montadoras[2]) == 0)
			count[2]++;
		else if (strcmp(cadastros[i].montadora, montadoras[3]) == 0)
			count[3]++;
		else if (strcmp(cadastros[i].montadora, montadoras[4]) == 0)
			count[4]++;
	}

	for (int k = 0; k < 5; k++) mont[k] = (listaDenso*)malloc(count[k] * sizeof(listaDenso));

	for (i = 0; i < qtd; i++)
	{
		if (strcmp(cadastros[i].montadora, montadoras[0]) == 0) //VOLKSWAGEN
		{
			mont[0][countMont[0]].chave = cadastros[i].chave;
			mont[0][countMont[0]].posicao = i;
			countMont[0]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[1]) == 0) //CHEVROLET
		{
			mont[1][countMont[1]].chave = cadastros[i].chave;
			mont[1][countMont[1]].posicao = i;
			countMont[1]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[2]) == 0) //FORD
		{
			mont[2][countMont[2]].chave = cadastros[i].chave;
			mont[2][countMont[2]].posicao = i;
			countMont[2]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[3]) == 0) //FIAT
		{
			mont[3][countMont[3]].chave = cadastros[i].chave;
			mont[3][countMont[3]].posicao = i;
			countMont[3]++;
		}
		else if (strcmp(cadastros[i].montadora, montadoras[4]) == 0) //HYUNDAI
		{
			mont[4][countMont[4]].chave = cadastros[i].chave;
			mont[4][countMont[4]].posicao = i;
			countMont[4]++;
		}
	}

	for (int k = 0; k < 5; k++) bubble(mont[k], countMont[k]);

	for (int k = 0; k < 5; k++) pri_cat[k] = mont[k][0].posicao;

	for (i = 0; i < countMont[0]; i++)
		cadas[mont[0][i].posicao] = mont[0][i + 1].posicao;

	cadas[mont[0][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[1]; i++)
		cadas[mont[1][i].posicao] = mont[1][i + 1].posicao;

	cadas[mont[1][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[2]; i++)
		cadas[mont[2][i].posicao] = mont[2][i + 1].posicao;

	cadas[mont[2][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[3]; i++)
		cadas[mont[3][i].posicao] = mont[3][i + 1].posicao;

	cadas[mont[3][i - 1].posicao] = (-1);

	for (i = 0; i < countMont[4]; i++)
		cadas[mont[4][i].posicao] = mont[4][i + 1].posicao;

	cadas[mont[4][i - 1].posicao] = (-1);

	for (int k = 0; k < 5; k++) free(mont[k]);
	//free(mont);
}

