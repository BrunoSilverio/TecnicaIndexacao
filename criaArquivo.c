#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTERS_MAX 50 //define the max registers to the file

/*
Os registros devem ter pelo menos 5 (cinco) campos, sendo:
    1. chave primária do tipo inteiro com 4 dígitos;
    2. nome do filme – tipo char[];
    3. genero – tipo char[];
    4. valor – tipo double;
    5. quantidade – tipo inteiro.
*/
typedef struct{
    int pKey;
    char nome[50];
    char genero[50];
    double valor;
    int quantidade;
}tipoFilmes;

int numberExists(int v[],int n){

    for(int i=0; i< REGISTERS_MAX;i++){
        if(v[i] == n){// if the element is equal return yes
            return -1;
        }
    }
    return 1; // if not return no
}

void primaryKeyGenerator(int primaryKeys[]){
    
    int number;
    for (int i=0;i<50;i++){

        number = 1000+ rand() % 9999; // Rand a number from 1000 to 9999
        
        while(numberExists(primaryKeys,number) != 1){ // while the sorted number exists
            number = 1000+ rand() % 9999; //Rand another
        }

        primaryKeys[i] = number; // finally save the number to the vector
    }
}

void main(){

    tipoFilmes films[REGISTERS_MAX]; // the structure who it will be wroted to the file
    int primaryKeys[REGISTERS_MAX];  //the primaryKeys vector 

    FILE *arq = fopen("filmes.dat","wb"); // open the files
    FILE *input =fopen("input.txt","r");
    
    if(!arq ){                           //check errors
        printf("ERRO AO CRIAR/ABRIR ARQUIVO");
        exit(0);
    }

    //generation of the primary keys 
    primaryKeyGenerator(primaryKeys);

    size_t len1 = strlen(films[0].nome),len2=strlen(films[0].genero);
    for(int i=0;i<REGISTERS_MAX;i++){
        //each for loop populate the struct with the informations

        films[i].pKey = primaryKeys[i];

        //read from a prebuilt file 
        fgets(films[i].nome,sizeof(films[i].nome),input); 
        fgets(films[i].genero,sizeof(films[i].genero),input);
        films[i].valor = 10 + rand() % 80;
        films[i].quantidade = rand() % 100;
        
        //remove the '\n' caracter
        strtok(films[i].nome,"\n");
        strtok(films[i].genero,"\n");
        
            /* 
            printf("reg_no:%i\npKey:%i\nname:%s\ngenre:%s\nvalue:%.2lf\nqtd:%i\n\n",i+1,
            films[i].pKey,films[i].nome,films[i].genero,films[i].valor,films[i].quantidade);
             */
        
        if(feof(input))
            break;
    }
    //with the structure vector populated
    //i wrote to the file and close him
    fwrite(&films[0],sizeof(tipoFilmes),REGISTERS_MAX,arq);

    fclose(arq);
}
