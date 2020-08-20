#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverterNumero(int num){
    int novo = num % 10;
    novo = novo * 100;
    num = num / 10;
    novo = (num % 10) * 10 + novo;
    num = num / 10;
    novo = (num % 10) + novo;
    return novo;
}


int main(){
	int n1, n2;

    scanf("%d %d", &n1, &n2);

    int novo1, novo2;
    novo1 = inverterNumero(n1);
    novo2 = inverterNumero(n2);
    
    if(novo1 > novo2){
        printf("%d\n", novo1);
    } else {
        printf("%d\n", novo2);
    }
    
}