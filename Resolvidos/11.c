#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i, j;
    int linha = 3;
    int coluna = 3;
    int mat[linha][coluna];
	
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            scanf("%d", &mat[i][j]);
            /*do{
                scanf("%d ", &mat[linha][0]);
            }while((mat[linha][coluna] < -9)||(mat[linha][coluna] > 9));*/
        }
    }

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("%d    ", mat[i][j]);
        }
        printf("\n");
    }

    int ampulheta[8];
    for(i=0; i<8; i++){
        ampulheta[i] = 0;
    }

    int soma = somaAmpulheta(mat);

    

    printf("Soma = %d\n", soma);

}

int somaAmpulheta(int mat[3][3]){
    int i, j;
    int soma = 0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i==1 && (j==0 || j==2)){
                printf("mat[%d][%d]\n", i,j);
            } else {
                soma = soma + mat[i][j];
            }
        }
    }
    return soma;
}