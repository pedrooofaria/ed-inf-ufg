#include <stdio.h>


int main(){
	int n, k;

    do{
        scanf("%d %d", &n, &k);
    }while((n<1) && (n>1000000)&&(k<1) && (k>1000000));

    
    int aux;
    int vet1[n];
    int cont;
    int cedo = 0;
    int tarde;
    for(cont=0; cont<n; cont++){
        scanf("%d", &vet1[cont]);
        if(vet1[cont]<1){
            cedo++;
        }
    }
    
    aux = cedo;
    if(cedo<k){
        printf("SIM\n");
    } else {
        printf("NAO\n");
        for(cont=0; cont<cedo; cont++){
            printf("%d\n", aux);
            aux--;
        }
    }
    


}