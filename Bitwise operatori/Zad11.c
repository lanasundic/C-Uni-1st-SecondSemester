/*
Napisati program koji broji koliko se puta kombinacija 11(dvije uzastopne jedinice) pojavljuje u binarnom zapisu cijelog broja x.
Broj x se unosi sa standardnog ulaza, a rezultat se ispisuje na standardni izlaz.
*/

#include <stdio.h>

int main() {
    int x = 0;
    int i = 0;
    unsigned int mask1 = 1;     //000...0001
    unsigned int mask2 = 2;     //000...0010

    printf("Unesite x:");
    scanf("%d", &x);

    while(mask2 != 0) {
        if(x & mask1 && x & mask2) {        //ako su oba uslova true, ako je bit u x = 1, onda sa povecava i sto nam broji 11
            i++;
        }
        mask2 <<= 1;
        mask1 <<= 1;
    }

    printf("%d", i);    //ispisi broj pojavljivanja 11

    return 0;
}