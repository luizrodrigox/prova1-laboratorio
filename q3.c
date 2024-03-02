#include <stdio.h>

void encontraTriplosPitagoricos(int n);

int main(){
  int limite;
  printf("Digite o valor de n: ");
  scanf("%d", &limite);

  encontraTriplosPitagoricos(limite);

  return 0;
}