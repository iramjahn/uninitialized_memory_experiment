#include <stdio.h>

void writer(void) {
    int secret = 12345;
    printf("writer: secret is at %p\n", (void *)&secret);
}

void reader(void) {
    int x;
    printf("reader: x is at      %p, value of x = %d\n", (void *)&x, x);
}

int main(void) {
    writer();
    reader();
    return 0;
}
