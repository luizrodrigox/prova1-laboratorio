#include <stdio.h>
#include <stdlib.h>

int mdc_recursivo (int a, int b){ 
  if (b==0) { 
    return 0; 
  }else{ 
    return mdc_recursivo(b,a%b); 
  } 
}
        
int main (){ 
  int n1=48; 
  int n2=18; 
         
  printf("O MDC de %d e %d he: %d\n", n1,n2,mdc_recursivo(n1,n2));
  return 0; 
}