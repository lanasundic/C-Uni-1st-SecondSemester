/*
Napisati program koji postavlja na k-to mjesto jedinicu u cijelom broju x. Cijeli brojevi k (neoznaceni cijeli broj) i x se unose sa standardnog ulaza.
Pozicija se broji od najmanje tezine ka najvecoj pocevsi od 0.
Ukoliko pozicija nije u dobrom opsegu ispisati poruku o gresci.

npr. ulaz: 78 4     izlaz: 94
*/

#include <stdio.h>

void printBits(int x) {     //pomocna f-ja koja ispisuje broj u binarnom obliku(korisna za provjeru)
    unsigned mask = 1 << (sizeof(int) * 8 - 1);

    while(mask) {
        mask & x ? printf("1") : printf("0");
        mask >>= 1;     //pomsjera se za jedno mjesto u svakom koraku
    }
    putchar('\n');
}

int main() {
    int x;
    int k;
    unsigned mask = 1;

    printf("Unesite broj i poziciju\n:");
    scanf("%d%d", &x, &k);

    if(k < 0 || k >= (int)(sizeof(int) * 8)) {      //provjeravamo da li je k validna pozicija: ne smije da bude negativna i ne smije da bude veca od 32
        printf("Pozicija nije u dobrom opsegu.")

        return -1;
    }

    mask = 1 << k;      //1 pomjeramo na k-toj poziciji
    //printBits(x);     //provjera

    x = x | mask;   //mijenjamo broj koji je korisnik unio tako sto postavimo or | koji je takav da samo ako je 0 i 0 = 0
    //printBits(x)      //provjera

    printf("%d\n", x);
    
    return 0;
}