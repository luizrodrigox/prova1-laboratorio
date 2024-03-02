//Item a)

#include <stdio.h>
#include <math.h>

int temRaizesReais(int a, int b, int c) {
  int delta = b * b - 4 * a * c;
  return delta >= 0;
}

int main() {
  int a, b, c;

  printf("Digite os coeficientes (a, b, c) da função do segundo grau: ");
  scanf("%d %d %d", &a, &b, &c);

  if (temRaizesReais(a, b, c)) {
    printf("A função do segundo grau tem raízes reais.\n");
  } else {
    printf("A função do segundo grau não tem raízes reais.\n");
  }

  return 0;
}