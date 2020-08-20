#include <stdio.h>
#include <stdlib.h>

#define SUCESSO                1
#define FALHA                 -1
#define CHAVE_INVALIDA         0

#define TAMANHO_MAXIMO_FILA 100

typedef struct { 
     unsigned int chave;
     unsigned int dado;
} Elemento;  


typedef struct {
    Elemento elementos  [TAMANHO_MAXIMO_FILA];
    unsigned int    tamanho; 
} Fila;


int criarFilaVazia(Fila *fila){
    fila->tamanho = 0;
    return SUCESSO;
}

int tamanhoFila(Fila fila){
    return fila.tamanho;
}

int enfileirar(Fila *fila, Elemento elemento){

    if(fila->tamanho == TAMANHO_MAXIMO_FILA){
        return FALHA;
    }else{
        fila->elementos[fila->tamanho] = elemento;
        fila->tamanho++;

        return SUCESSO;
    }
}

Elemento desenfileirar(Fila *fila){
    Elemento elem;
    
    if(fila->tamanho == 0){
        elem.chave = CHAVE_INVALIDA;
    }else{
        elem = fila->elementos[0];

        for(int i = 1; i < fila->tamanho; i++){
            fila->elementos[i-1] = fila->elementos[i];
        }        
        fila->tamanho--;
    }

    return elem;
}

void mostrarElemento(Elemento elemento){
    printf("Chave: %u\n", elemento.chave);
    printf("Dado: %u\n", elemento.dado);
}

void mostrarFila(Fila fila){

    printf("Fila:\t");
    for(int i =0 ; i < fila.tamanho; i++)
        printf("%u ", fila.elementos[i].dado);

    printf("\n");
}

int main(){

    Elemento elemento;
    Fila fila;
    char opcao;
    int contadorSenha=0;

    criarFilaVazia(&fila);

    do{

        printf("Deseja gerar senha (s ou n): \n");
        scanf(" %c", &opcao);

        if(opcao == 's'){
            contadorSenha++;
            elemento.chave = contadorSenha;
            elemento.dado = contadorSenha;

            enfileirar(&fila, elemento);
        }

        mostrarFila(fila);

    }while(opcao != 'n');

    do{

        printf("Deseja chamar senha: \n");
        scanf(" %c", &opcao);

        if(opcao == 's'){
            elemento = desenfileirar(&fila);
            mostrarElemento(elemento);
        }

        mostrarFila(fila);

    }while(opcao != 'n');

    return EXIT_SUCCESS;
}