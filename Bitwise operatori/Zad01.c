//Napisati f-ju printBits koja stampa bitove u zapisu datog cijelog broja x

#include <stdio.h>  //printf, scanf itd.

void printBits(int x) {
    unsigned mask = 1 << (sizeof(int)*8 - 1);   //pravimo masku,  a unsigned je tip koji ne koristi negativne brojeve

    while(mask) {   //sve dok je mask razlicito od 0
        mask & x ? printf("1") : printf("0");
        mask >>= 1;     //svakim korakom pomjeramo tu 1 za mjesto udesno - sve dok ne postane 0 sto prekida petlju
    }
    putchar('\n');
}

int main() {
    int x;
    printf("Unesite broj\n");
    scanf("%d", &x);

    printBits(x);
    
    return 0;
}

/*
mask & x ---> ovo koristi AND operator koji poredi bitove mask i x
1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0
Dakle, mask & x ispituje da li je taj konkretan bit u broju x jednak 1.

Ternarni operator: ako je mask & x razlicito od 0 izvrsi printf("1"), inace printf("0")
Znaci, ako je bit u x na toj poziciji 1 ---> ispisi 1, a ako je 0 ---> ispisi 0
*/