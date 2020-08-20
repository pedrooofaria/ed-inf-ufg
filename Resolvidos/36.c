#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaCapicua(int x){
    int vet[4];
    int i;
    for(i=0; i<4; i++){
        vet[i] = x % 10;
        x = x / 10;
    }

    if((vet[0]==vet[3]) && (vet[1]==vet[2])){
        printf("yes");
    } else {
        printf("no");
    }
        

}


int main(){
	int n;

    scanf("%d", &n);

    int vet[n];

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    for(i=0; i<n; i++){
        verificaCapicua(vet[i]);
        printf(" ");
        if(i != n-1){
            printf(" ");
        }
    }
    printf("\n");


}