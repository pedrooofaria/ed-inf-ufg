#include <stdio.h>
#include <stdlib.h>

#define SUCESSO                1
#define FALHA                 -1
#define CHAVE_INVALIDA         0

#define TAMANHO_MAXIMO_LISTA 100

typedef struct { 
     unsigned int chave;
     unsigned int dado;
} Celula;  


typedef struct {
    Celula celulas  [TAMANHO_MAXIMO_LISTA];
    unsigned int    tamanho; //quantidade de elementos dentro da lista
} ListaLinear; 

int criarListaVazia(ListaLinear * lista) {
    lista->tamanho = 0;
    return (SUCESSO);
}

int criarListaChave(ListaLinear * lista, Celula celula) {
    lista->celulas[0] = celula;
    lista->tamanho    = 1;
    return (SUCESSO);
}

int insInicio (ListaLinear * lista, Celula celula) {

    int i;

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA){
        return FALHA;
    }else{

        for(i = lista->tamanho; i > 0; i--){
            lista->celulas[i] = lista->celulas[i-1];
        }

        lista->celulas[0] = celula;
        lista->tamanho++;

        return SUCESSO;

    }

}

int insFinal (ListaLinear * lista, Celula celula) {

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA){
        return FALHA;
    }else{
        lista->celulas[lista->tamanho] = celula;
        lista->tamanho++;
        return SUCESSO;
    }

}

Celula remInicio (ListaLinear * lista) {

    Celula celulaRemovida;

    if(lista->tamanho == 0){
        celulaRemovida.chave = CHAVE_INVALIDA;
        return celulaRemovida;
    }else{
        
        celulaRemovida = lista->celulas[0];

        for(int i=1; i<lista->tamanho; i++){
            lista->celulas[i-1] = lista->celulas[i];
        }
        lista->tamanho--;

        return celulaRemovida;

    }
}

Celula remFinal (ListaLinear * lista) {
    
    Celula celulaRemovida;

    if(lista->tamanho == 0){
        celulaRemovida.chave = CHAVE_INVALIDA;
        return celulaRemovida;
    }else{
        
        celulaRemovida = lista->celulas[lista->tamanho-1];
        lista->tamanho--;

        return celulaRemovida;

    }

}

void remChave (ListaLinear * lista, Celula celula) {

    Celula celulaRemovida;

    if(lista->tamanho == 0){
        celulaRemovida.chave = CHAVE_INVALIDA;
        //return celulaRemovida;
    }else{
        
        //remover do inicio: chave da celula a ser removida é igual a chave da primeira celula
        if(celula.chave == lista->celulas[0].chave){
            while(celula.chave == lista->celulas[0].chave){
            celulaRemovida = remInicio(lista);

                if(celulaRemovida.chave == CHAVE_INVALIDA){
                    //return celulaRemovida;
                }

            }

        }else if(celula.chave == lista->celulas[lista->tamanho-1].chave){

            while(celula.chave == lista->celulas[lista->tamanho-1].chave){
                
                celulaRemovida = remFinal(lista);

                if(celulaRemovida.chave == CHAVE_INVALIDA){
                    //return celulaRemovida;
                }
            }

        }else{

            int i=0;

            while((celula.chave > lista->celulas[i].chave) && (i < lista->tamanho)){
                i++;
            }

            if(i == lista->tamanho){
                celulaRemovida.chave = CHAVE_INVALIDA;
                //return celulaRemovida; //Não encontrou a chave a ser removida
            }

            int qtdRemocao = 0;
            int j = i;
            while((celula.chave == lista->celulas[j].chave) && (j<lista->tamanho)){
                j++;
                qtdRemocao++;
            }

            celulaRemovida = lista->celulas[i];

            for(int k=i; k<lista->tamanho-qtdRemocao; k++){
                if(k+qtdRemocao < lista->tamanho)
                    lista->celulas[k] = lista->celulas[k+qtdRemocao];
            }

            lista->tamanho -= qtdRemocao;
            //return celulaRemovida;

        }
    }

}

void mostrarLista(ListaLinear lista) {
    if(lista.tamanho == 0){
       printf("A lista está vazia!\n"); 
    }else{
        for(int i = 0; i < lista.tamanho; i++){
            printf("%u  ", lista.celulas[i].chave);
        }
        printf("\n");
    }
}



int main(){
    unsigned int i;
    int          intResultado;
    ListaLinear  listaLinear;
    Celula       celula;
    
    criarListaVazia(&listaLinear);

    int tam, result;
    do{
        scanf("%d", &tam);
    }while(1>tam && tam>60000);

    for(i=0; i<tam; i++){
        if(i==0){
            scanf("%u", &celula.chave);
            result = insInicio(&listaLinear, celula);
        }else{
            scanf("%u", &celula.chave);
            result = insFinal(&listaLinear, celula);
        }
    }

    int qtd;
    do{
        scanf("%d", &qtd);
    }while(1>qtd && qtd>tam);

    int vet[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }

    Celula removido;
    for(i=0; i<qtd; i++){
        celula.chave = vet[i];
        remChave(&listaLinear, celula);
    }

    mostrarLista(listaLinear);

}