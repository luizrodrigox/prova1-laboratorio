#include <stdio.h>

void retorna_y (int x1, int x2) {
    printf("y = %d,%d\n", x1, x2);
}

int main( ) {
    int x1 = 10;
    int x2 = 20;
    
    retorna_y(x1, x2);

    return 0;
}