//TECNICAS DE INDEXAÇÃO
//Arquivo.dat
#include <stdio.h>

#define max 50

void main()
{
    int chavePrimaria[max]; //4 digitos
    string Nome[max], Categoria[max]; //4 a 5 categorias
    double campo4, campo5;
    FILE *arq;
    int result;
    int i,  op;

	printf(" 	1 -> Escrever Arquivo.bat\n		2 -> Abrir Arquivo.bat\n");
	scanf("%d",&op);
	
	switch(op){
		case 1: // Cria um arquivo binário para gravação 
    	arq = fopen("Arquivo.dat", "wb");

    	if (arq == NULL) // Se não conseguiu criar
    	{
	        printf("Problemas na CRIACAO do arquivo\n");
   			return;
    	}
    	// Grava 50 números do vetor a partir da posição 0 
    	result = fwrite (&Notas[0], sizeof(double), 50, arq);

    	printf("Nro de elementos gravados: %d", result); 
    	fclose(arq);
    	break;
//===========================================================================
    	case 2: // Abre um arquivo BIN�RIO para LEITURA
		arq = fopen("Arquivo.dat", "rb");
  		if (arq == NULL)  // Se houve erro na abertura
  		{
	     	printf("Problemas na abertura do arquivo\n");
    	 	return;
  		}
  		result = fread (&Notas[0], sizeof(double), 50, arq);
  		printf("\nnNro de elementos lidos: %d\n", result);

  		for (i=0; i<result; i++){
	    	printf("%lf\n", Notas[i]);
		}
	  	fclose(arq);
	  	break;
	}
	
}
