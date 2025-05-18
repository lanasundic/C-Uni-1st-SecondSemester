//Napisati program koji provjerava da li je na k-tom mjestu jedinica u cijelom broju x. Cijeli brojevi k(neoznacen cio broj) i x se unose sa standardnog ulaza
//Pozicija se broji od najmanje tezine ka najvecoj pocevsi od 0. Ukoliko pozicija nije u dobrom opsegu ispisati poruku o gresci.

#include <stdio.h>

int main() {
    int x;
    unsigned int k;
    unsigned mask = 1;

    printf("Unesite broj i poziciju\n:");
    scanf("%d%d", &x, &k);

    //pozicija ne smije da bude negativna, i mora da bude manja od 32, odnosno manja od broja bajtova koji se koriste za int zapis
    if(k < 0 || k >= (int)(sizeof(int) * 8)) {
        printf("Pozicija nije u dobrom opsegu\n.");
        return -1;
    }

    mask = 1 << k;  //pomjeramo bit 1 na k-tu poziciju.
    
    x & mask ? printf("Jeste jedinica.") : printf("Nije jedinica.");

    return 0;
}