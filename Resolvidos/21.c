#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursivo(int n, int i){
    if(i!=n){
        printf("%d ", i);
        return recursivo(n, i+1);
    } else {
        return 0;
    }
}

int main(){
	int n;
    int i = 1;

    do{
        scanf("%d", &n);
    }while((n<1) && (n>5000));

    i = recursivo(n,i);
    printf("%d", n);


   
    
}