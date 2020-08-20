#include <stdio.h>

int main(){
	int num;

    do{
        scanf("%d", &num);
        /*if((num<1) && (num>1000000)){
            printf("valor invalido\n");
        }*/
    }while((num<1) && (num>1000000));
    
    int vet1[num], vet2[num];
    int cont;
    for(cont=0; cont<num; cont++){
        scanf("%d", &vet1[cont]);
        //printf("valor inserido\n");
    }

    for(cont=0; cont<num; cont++){
        vet2[cont]=0;
    }

    int i;
    for(cont=0; cont<num; cont++){
        for(i=0; i<num; i++){
            if(vet1[cont] == vet1[i]){
                vet2[cont]++;
            }
        }
    }

    int maior = 0;
    int pos;
    for(i=0; i<num; i++){
        if(maior < vet2[i]){
            maior = vet2[i];
            pos = i;
        }
    }

    printf("%d\n", vet1[pos]);
    printf("%d\n", maior);
    


}
