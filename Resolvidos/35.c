#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int maior, n1, n2, resp;
    char op;

    scanf("%d", &maior);
    scanf("%d %c %d", &n1, &op, &n2);

    if(op=='+')
        resp = n1 + n2;

    if(op=='x')
        resp = n1 * n2;

    
    if(resp > maior){
        printf("overflow\n");
    } else {
        printf("no overflow\n");
    }


   
    
}