#include <stdio.h>
#include <stdlib.h>

void kvadriraj(int *g){
    *g = *g * *g;
}

int main() {
    int n = 5;
    int *p = &n;
    kvadriraj(p);
    printf("%d", n);
}