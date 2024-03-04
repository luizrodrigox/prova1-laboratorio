#include <stdio.h>

int isPrimeUtil(int n, int i) {
  if (n <= 2)
    return (n == 2) ? 1 : 0;
  if (i == 1)
    return 1;
  if (n % i == 0)
    return 0;
  return isPrimeUtil(n, i - 1);
}

int isPrime(int n) {
  if (n <= 1)
    return 0;
  return isPrimeUtil(n, n / 2);
}

int main() {
  int num;
  printf("Digite um número para verificar se é primo: ");
  scanf("%d", &num);

  if (isPrime(num))
    printf("%d é primo.\n", num);
  else
    printf("%d não é primo.\n", num);
  return 0; 
}