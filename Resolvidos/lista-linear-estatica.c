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

/*
 * Determina, e retorna, o número de células presentes na lista linear.
 */
int tamanhoLista(ListaLinear lista) {
    if(lista.tamanho >= 0){ //se tiver sido criada
        return lista.tamanho;
    }else{
        return (FALHA);
    }
}

/*
 *  A inserção de uma <chave/dado> pode ocorrer...
 *    - no início da lista: antes da primeira célula;
 *    - no final da lista: após a última célula;
 *    - em ordem ASCENDENTE de chave. 
 */
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

//Inserir no inicio, no fim ou no "meio"
int insOrdem (ListaLinear * lista, Celula celula) {

    int inteiroRetornado;

    if(lista->tamanho == TAMANHO_MAXIMO_LISTA){
        return FALHA;
    }else{
        
        //criterio 1: chave da celula é menor que a chave do primeiro elemento
        if(lista->tamanho == 0 || celula.chave <= lista->celulas[0].chave){
            inteiroRetornado = insInicio(lista, celula);
            return inteiroRetornado;
        }
        //criterio 2: chave da celula é maior que a chave do ultimo elemento
        else if(celula.chave >= lista->celulas[lista->tamanho-1].chave){
            inteiroRetornado = insFinal(lista, celula);
            return inteiroRetornado;
        }else{
            
            int i = 0;

            while(celula.chave >= lista->celulas[i].chave){
                i++;
            }

            //Inserção no meio
            for(int j = lista->tamanho; j > i; j--){
                lista->celulas[j] = lista->celulas[j-1];
            }

            lista->celulas[i] = celula;
            lista->tamanho++;

            return SUCESSO;
        }

    }

}

/*
 *  A remoção de uma <chave/dado> pode ocorrer...
 *    - no início da lista: a primeira célula;
 *    - no final da lista: a última célula;
 *    - baseada no valor da chave (a lista está em ordem ASCENDENTE de chaves).
 *   
 *  Observação: A remoção devolve a célula removida ou uma célula com chave 
 *              igual a CHAVE_INVALIDA, indicando erro na remoção. 
 */
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

Celula remChave (ListaLinear * lista, Celula celula) {

    Celula celulaRemovida;

    if(lista->tamanho == 0){
        celulaRemovida.chave = CHAVE_INVALIDA;
        return celulaRemovida;
    }else{
        
        //remover do inicio: chave da celula a ser removida é igual a chave da primeira celula
        if(celula.chave == lista->celulas[0].chave){
            while(celula.chave == lista->celulas[0].chave){
            celulaRemovida = remInicio(lista);

                if(celulaRemovida.chave == CHAVE_INVALIDA){
                    return celulaRemovida;
                }

            }

        }else if(celula.chave == lista->celulas[lista->tamanho-1].chave){

            while(celula.chave == lista->celulas[lista->tamanho-1].chave){
                
                celulaRemovida = remFinal(lista);

                if(celulaRemovida.chave == CHAVE_INVALIDA){
                    return celulaRemovida;
                }
            }

        }else{

            int i=0;

            while((celula.chave > lista->celulas[i].chave) && (i < lista->tamanho)){
                i++;
            }

            if(i == lista->tamanho){
                celulaRemovida.chave = CHAVE_INVALIDA;
                return celulaRemovida; //Não encontrou a chave a ser removida
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
            return celulaRemovida;

        }
    }

}

/*
 * Retorna a célula (primeira) cuja chave é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não encontrou a
 * célula desejada na lista. 
 */
Celula consultaChave(ListaLinear lista, Celula celula) {}

/*
 * Retorna a célula cuja posição é igual à solicitada ou 
 * uma célula com chave igual a CHAVE_INVALIDA, indicando que não existe a
 * célula desejada na lista. 
 * 
 * A primeira célula está na posição UM.
 */
Celula consultaPosicao(ListaLinear lista, unsigned int intPosicao) {}


/*
 * Apresenta, no dispositivo de saída (monitor de vídeo), o valor
 * da <chave> e do <dado> de uma célula recebida como entrada.
 */
void mostrarCelula(Celula celula) {
    printf("Chave:  %u\n", celula.chave);
    printf("Dado:  %u\n", celula.dado);
}

/*
 * Mostra as células da lista, a partir de sua 'cabeça' até sua 'cauda'.
 */
void mostrarLista(ListaLinear lista) {
    if(lista.tamanho == 0){
       printf("A lista está vazia!\n"); 
    }else{
        printf("Lista:\t");
        for(int i = 0; i < lista.tamanho; i++){
            printf("%u  ", lista.celulas[i].dado);
        }
        printf("\n");
    }
}

/*
 * Programa principal: utiliza as funções de lista linear
 * 
 */
int main() {
    unsigned int i;
    int          intResultado;
    ListaLinear  listaLinear;
    Celula       celula;
    
    //Antes de manipular a lista precisamos criá-la
    criarListaVazia(&listaLinear);

    int opcao;

    do{
        printf("Informe a opcao desejada: \n");
        printf("1-Inserir no inicio\n");
        printf("2-Inserir no final\n");
        printf("3-Inserir em ordem\n");
        printf("4-Remover do inicio\n");
        printf("5-Remover no final\n");
        printf("6-Remover pela chave\n");
        printf("7-Consulta pela chave\n");
        printf("8-Consulta pela posição\n");
        printf("9-Mostrar lista\n");
        printf("0-Sair\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Finalizando...\n");
                break;
            case 1: //insercao no inicio

                printf("Chave:  ");
                scanf("%u", &celula.chave);
                printf("Dado:   ");
                scanf("%u", &celula.dado);

                insInicio(&listaLinear, celula);

                break;
            case 2: //insercao no final

                printf("Chave:  ");
                scanf("%u", &celula.chave);
                printf("Dado:   ");
                scanf("%u", &celula.dado);

                insFinal(&listaLinear, celula);

                break;

            case 3: //insercao em ordem

                printf("Chave:  ");
                scanf("%u", &celula.chave);
                printf("Dado:   ");
                scanf("%u", &celula.dado);

                insOrdem(&listaLinear, celula);

                break;

            case 4: //imprimir a lista
                celula = remInicio(&listaLinear);
                if(celula.chave == CHAVE_INVALIDA){
                    printf("Não foi possível remover o elemento!\n");
                }else{
                    printf("Celula removida!\n");
                    mostrarCelula(celula);
                }
                break;
            case 5:
                celula = remFinal(&listaLinear);
                if(celula.chave == CHAVE_INVALIDA){
                    printf("Não foi possível remover o elemento!\n");
                }else{
                    printf("Celula removida!\n");
                    mostrarCelula(celula);
                }
                break;

            case 6:
                printf("Informe a chave para remocao: ");
                scanf("%u", &celula.chave);

                celula = remChave(&listaLinear, celula);

                if(celula.chave == CHAVE_INVALIDA){
                    printf("Não foi possível remover o elemento!\n");
                }else{
                    printf("Celula removida!\n");
                    mostrarCelula(celula);
                }
                break;
            case 7:

                break;
            case 8:

                break;

            case 9:    
                mostrarLista(listaLinear);

                break;

            default:
                printf("Opção inválida\n");


        }

    }while(opcao != 0);

    return (EXIT_SUCCESS);
}