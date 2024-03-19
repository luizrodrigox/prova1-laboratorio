#include <stdio.h>

int main(){
  int n, aux;
  
  for (int i = 0; i < 5; i++){
    do{
      printf("digite cinco numeros entre 1 e 30: ");
      scanf("%d", &n);

      if (n < 1 || n > 30){
        printf("numero fora do intervalo !");
      }
      
    } while(n < 1 || n > 30);

    for (int j = 0; j < n; j++){
      printf("*");
    }

    printf("\n");
  }
  return 0;
}