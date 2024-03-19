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

//Item b)

#include <stdio.h>
#include <math.h>

void calculaRaizesReais(int a, int b, int c){
  int delta = b * b - 4 * a * c;

  if(delta>=0){
    double raiz1 = (- b + sqrt(delta))/(2.0*a);
    double raiz2 = (- b - sqrt(delta))/(2.0*a);

    printf("As raízes reais da função do segundo grau são: %.2lf e %.2lf", raiz1, raiz2);
  } else{
    printf("A função do segundo não tem raizes reais.\n");
  }
}

int main(){
  int a, b, c;

  printf("Digite os coeficiente (a, b, c) da função do segundo grau:\n");
  scanf("%d %d %d", &a, &b, &c);

  calculaRaizesReais(a, b,c);

  return 0;
}