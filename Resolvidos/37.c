#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int x;
    int resto;
    int qtd = 0;
    char value[10] = "";

    scanf("%d", &x);

    do{
        resto = x%4;
        switch (resto)
        {
        case 0:
            if(qtd==0)
                strcat(value, "C");
            strcat(value, "A");
            printf("%d\n", resto);
            break;
        case 1:
            strcat(value, "C");
            printf("%d\n", resto);
            break;
        case 2:
            strcat(value, "G");
            printf("%d\n", resto);
            break;
        case 3:
            strcat(value, "T");
            printf("%d\n", resto);
            break;
        default:
            break;
        }
        x = x/4;
        qtd++;
    }while(x>0);


    printf("resultado: %s\n", value);
}