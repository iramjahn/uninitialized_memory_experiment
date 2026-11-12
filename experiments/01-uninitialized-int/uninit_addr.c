#include <stdio.h>

int main(void) {
    int x;
    printf("value of x:   %d (hex %x)\n", x, x);
    printf("address of x: %p\n", (void *)&x);
    return 0;
}
