#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Os registros devem ter pelo menos 5 (cinco) campos, sendo:
    1. chave primária do tipo inteiro com 4 dígitos;
    2. nome do filme – tipo string;
    3. genero – tipo string;
    4. valor – tipo real;
    5. quantidade – qualquer tipo.
*/

typedef struct{
    int pKey;
    char nome[10];
    char genero[10];
    double valor;
    int quantidade;
}tipoFilmes;



void main(){


    FILE *arq = fopen("filmes.dat","wb");
    tipoFilmes films[50];

    if(!arq){
        printf("ERRO AO CRIAR ARQUIVO");
        exit(0);
    }


for(int i=0;i<50;i++){
    printf("campo 1\n");
    __fpurge(stdin);
    scanf("%i",&films[i].pKey);
    
    printf("campo 2\n");
    __fpurge(stdin);
    scanf("%s",films[i].nome);
    
    printf("campo 3\n");
    __fpurge(stdin);
    
    scanf("%s",films[i].genero);
    
    printf("campo 4\n");
    __fpurge(stdin);
    scanf("%lf",&films[i].valor);
    
    printf("campo 5\n");
    __fpurge(stdin);
    scanf("%i",&films[i].quantidade);
    
}
    fwrite(&films,sizeof(tipoFilmes),50,arq);

}