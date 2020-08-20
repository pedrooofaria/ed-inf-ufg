#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
}

int main(){
	int num;

    do{
        scanf("%d", &num);
        /*if((num<1) && (num>1000000)){
            printf("valor invalido\n");
        }*/
    }while((num<1) && (num>1000000));
    
    int vet1[num];
    int cont;
    for(cont=0; cont<num; cont++){
        scanf("%d", &vet1[cont]);
        //printf("valor inserido\n");
    }

    bubbleSort(vet1, num);

    
    for(cont=0; cont<num; cont++){
        printf("%d\n", vet1[cont]);
    }
    


}
