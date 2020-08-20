#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaPrimo(int x){
    int i;
    int d = 2;
    int primo = 1;

    if (x <= 1 || (x != 2 && (x%2) == 0))
	    primo = 0;


    while (primo==1  && d <= x / 2) {
	    if (x % d == 0){
            primo = 0;
        }
	    d = d + 2;
    }

    if (primo == 1)
        printf("primo\n");
    else
        printf("composto\n");
}


int main(){
	int n;

    do{
        scanf("%d", &n);
    }while((n<1) && (n>100));

    int vet[n];

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    for(i=0; i<n; i++){
        verificaPrimo(vet[i]);
    }


}