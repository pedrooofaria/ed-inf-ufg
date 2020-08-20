#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int ano;
    int qtde;

    do{
        scanf("%d", &ano);
    }while((ano<0) && (ano>10000));
    

    qtde = (int)((ano-10)/76);
    qtde++;
    

    printf("%d\n", qtde * 76 + 10);
    


}