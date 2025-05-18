/*
Napisati program koji odredjuje najveci pozitivan broj koji se moze zapisati istim binarnim ciframa kao dati broj.
Koristiti bitovske operatore. Sa standardnog ulaza se unose broj, a na standardni izlaz se ispisuje razultat.

Znaci: Ako broj ima npr. 5 jedinica, onda je najveći broj koji možemo formirati sa 5 jedinica: 11111...000, dakle stavljamo jedinice na najvise moguce
       pozicije a to je lijevo, desno nule stavljamo
*/

#include <stdio.h>

int main() {
    int x;
    int rezultat = 0;

    printf("Unesite broj:");
    scanf("%d", &x);

    unsigned mask1 = 1;
    unsigned int mask2 = 1 << ((sizeof(int) * 8) - 2);  //idemo 30 mjesta ulijevo, ne 31 jer bi to onda bio bit za znak, 01000000 00000000 00000000 00000000

    while(mask1 != 0) {     //dok ne predjemo sve bitove x
        if(x & mask1) {
            rezultat = rezultat | mask2;      //Ona postavlja jedan bit u rezultat — tačno na onom mestu gde trenutno pokazuje mask2.
            mask2 >>= 1;
        }
        mask1 <<= 1;
    }

    printf("%d\n", y);
   
    return 0;
}

//Cilj: proći kroz sve bitove broja x, s desna na levo, i za svaku 1 u x, postaviti 1 u rezultujućem broju y, ali s leva na desno.