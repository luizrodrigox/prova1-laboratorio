#include <stdio.h>

int A(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return A(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return A(m - 1, A(m, n - 1));
    } else {
        return -1;
    }
}

void apresentarResultados(int a, int b) {
    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            printf("A(%d, %d) = %d\n", x, y, A(x, y));
        }
    }
}

int main() {
    int a, b;

    printf("Digite dois inteiros a e b: ");
    scanf("%d %d", &a, &b);

    apresentarResultados(a, b);

    return 0;
}
