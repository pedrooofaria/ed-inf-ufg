#include <stdio.h>
unsigned int numeros;
unsigned int i;
unsigned int f[1000];

void fibonacci (int quant){

  f[0] = 0;
  f[1] = 1;
  printf ("%d", f[0]);
  if (numeros >= 1)
    {
      printf (" 1");
      if (numeros > 1)
	{
	  for (i = 2; i <= numeros; i++)
	    {
	      f[i] = f[i - 1] + f[i - 2];
	      printf (" %d", f[i]);
	    }
	}
    }
}

int main (){
  scanf ("%d", &numeros);
  fibonacci (numeros);
  printf("\n");
  return 0;

}