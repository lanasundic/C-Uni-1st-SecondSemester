/*
Napisati f-ju koja ispituje da li je dati cio broj n stepen broja 2. Koristeci bitovske operatore.

znaci provjeriti da li je x == 2^n
*/

#include <stdio.h>

int main() {
    unsigned int x, i = 0;
    unsigned int mask = 1;

    scanf("%u", &x);

    while(mask != 0) {
        if(mask & x) {
            i++;
        }        //i na kraju broji koliko jedinica ima u x.
        mask <<= 1;
        
    }
    if(i == 1) {
        printf("Jeste.");   //ako broj ima tacno jednu jedinicu u binarnom zapisu onda je stepen broja 2.
    } else {
        printf("Nije.");
    }
}