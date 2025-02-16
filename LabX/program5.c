#include <stdio.h>

void add(int *x, int *y, int *z, int *sum) {
    *sum = *x + *y + *z;
}

int main() {
    int a = 2, b = 3, c = 4, result = 0;
    add(&a, &b, &c, &result);
    printf("The total is: %d\n", result);
    return 0;
}
