/*
Napisati f-ju unsigned getBits(int x, int p, int n) koja vraca broj dobijen od broja x tako da mu je izdvojeno n bita pocev od pozicije p, a ostalo su 0.
Testirati f-ju pozivom u main-u, pri cemu se brojevi x, p i n unose sa standardnog ulaza.
Provjeriti da li su brojevi p i p + n u odgovarajucem opsegu i ispisati poruku o gresci ako nisu.
Na standardni izlaz ispisati bitove unesenog broja x i bitove novodobijenog broja.
*/
#include <stdio.h>

void printBits(int x) {
    unsigned mask = 1 << (sizeof(int) * 8 - 1);

    while(mask) {
        mask & x ? printf("1") : printf("0");
        mask >>= 1;
    }
    putchar('\n');
}

unsigned getBits(int x, int p, int n) {     //izdvaja n bitova iz broja x pocevsi od pozicije p
    unsigned mask1 = 1;
    unsigned mask0 = 0;

    for(int i = 0; i < n; i++, mask1 <<= 1) 
        mask0 = mask0 | mask1;

    mask0 = mask0 << p;

//    printBits(mask0);
    
    return x & mask0;
}

int main() {
    int x;
    int p;  //pozicija
    int n;  //n bita
    
    printf("Unesi broj\n");
    scanf("%d", &x);
    
    printf("Unesite p i n\n");
    scanf("%d %d", &p, &n);

    if(p < 0 || n < 0 || (p + n) >= (int)(sizeof(int) * 8)) {
        printf("Pozicija nije u dobrom opsegu.\n");

        return -1;
    }

    unsigned k = getBits(x, p, n);
    printf("%u\n", k);
    printBits(x);
    printBits(k);
}