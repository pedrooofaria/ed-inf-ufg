#include <stdio.h>
#include <stdlib.h>


int main(){
	int n;

    do{
        scanf("%d", &n);
    }while((n<1) && (n>5000));

    
    int vet1[n];
    int cont;
    int i;
    int qtde = 0;
    int unico;
    
    for(cont=0; cont<n; cont++){
        scanf("%d", &vet1[cont]);
    }

    for(cont=0; cont<n; cont++){
        unico = 1;
        for(i=0;i<n;i++){
            if((cont != i) && (vet1[cont] == vet1[i])){
                unico = 0;
            }
        }
        if(unico == 1)
            qtde++;
    }

    

    printf("%d\n", qtde);


}