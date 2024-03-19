#include <stdio.h>

int inverteNumero(int numero) {
   int numeroInvertido = 0;
    
   while (numero > 0) {
      int digito = numero % 10;
        
      numeroInvertido = numeroInvertido * 10 + digito;
      numero /= 10;
   }
    
   return numeroInvertido;
}

int main() {
   int numeroOriginal = 1234;
   int numeroInvertido = inverteNumero(numeroOriginal);
    
   printf("Original: %d, Invertido: %d\n", numeroOriginal, numeroInvertido);
    
   return 0;
}