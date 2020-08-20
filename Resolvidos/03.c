#include <stdio.h>


int main(){
	int num;

    do{
        scanf("%d", &num);
        /*if((num<1) && (num>1000000)){
            printf("valor invalido\n");
        }*/
    }while((num<1) && (num>1000000));
    
    int vet1[num];
    int i, j;
    for(i=0; i<num; i++){
        scanf("%d", &vet1[i]);
    }

    //ordenar
    int aux;
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            if(vet1[i]<vet1[j]){
                aux = vet1[i];
                vet1[i] = vet1[j];
                vet1[j] = aux;
            }
        }
    }

    double soma = 0;
    double mediana;
    if((num%2)==0){
        soma = soma + vet1[(num/2)];
        soma = soma + vet1[(num/2)-1];
        mediana = soma / 2;
    }else{
        for(i=0; i<num; i++){
            mediana = vet1[(num/2)];
        }
    }
    printf("%.2f\n", mediana);
    


}
