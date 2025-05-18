/*
Napisi f-ju unsigned invertBits(unsigned x, int p, int n) koja invertuje n bitova broja x pocevsi od pozicije p. Testirati f-ju pozivom u main-u, pri cemu se
brojevi x, p i n unose sa standardnog ulaza.
Provjeriti da li su brojevi p i p + n u odg opsegu i ispisati poruku ako nisu. Na standardni izlaz ispisi bitove unesenog broja x i bitove novodobijenog broja
*/

#include <stdio.h>

void printBits(unsigned x) {
    unsigned mask = 1 << (sizeof(int) * 8 - 1);

    while(mask) {
        mask & x ? printf("1") : printf("0");
        mask >>= 1;
    }
    putchar('\n');
}

unsigned invertBits(unsigned x, int p, int n) {
    unsigned mask = 1;      //00000000 00000000 00000000 00000001   
    unsigned mask1 = 0;     //00000000 00000000 00000000 00000000

    for(int i = 0; i < n; i++, mask <<= 1) {
        mask1 = mask1 | mask;   //samo 0 i 0 daju 0, ostalo je sve 1, tako da 0 i 1 daju 1, tako ideo sve do n.     npr. ako je n = 3 onda je mask1 = 00000111
    }

    mask1 = mask1 << p;     //sada tu masku sa n jedinica pomjeramo na pravu poziciju(p).   npr. ako je pozicija p = 4, onda mask1 postaje: 000...01110000

    return x ^ mask1;   //KLJUCNI KORAK!!!      ^ je bitwise XOR - invertuje samo bitove gdje maska ima 1
}

int main() {
    int n, p;
    unsigned x;

    printf("Unesi broj\n");
    scanf("%u", &x);
    
    printf("Unesite n i p\n");
    scanf("%d%d", &n, &p);

    if(p < 0 || n < 0 || p + n >= (int)(sizeof(int) * 8)) {
        printf("Pozicija nije u dobrom opsegu\n");
        return -1;
    }

    unsigned k = invertBits(x, p, n);

    printBits(x);   //ispisujemo bitove prije inverzije
    printBits(k);   //ispisujemo bitove poslije inverzije

    return 0;
}