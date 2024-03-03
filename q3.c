#include <stdio.h>

void encontraTriplosPitagoricos(int n){
  printf("Triplos Pitagóricos até %d:\n", n);
  for (int cateto1 = 1; cateto1 <= n; cateto1++) {
    for (int cateto2 = cateto1; cateto2 <= n; cateto2++) {
      for (int hipotenusa = cateto2; hipotenusa <= n; hipotenusa++) {
        if (cateto1 * cateto1 + cateto2 * cateto2 == hipotenusa * hipotenusa) {
          printf("(%d, %d, %d)\n", cateto1, cateto2, hipotenusa);
        }
      }
    }
  }
}

int main(){
  int limite;
  printf("Digite o valor de n: ");
  scanf("%d", &limite);

  encontraTriplosPitagoricos(limite);

  return 0;
}