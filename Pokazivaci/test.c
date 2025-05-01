/*
Zadatak 1: Pokazivaci na funkcije
a) Napisati funkciju koja prima ceo broj i vraca njegovu vrijednost uvecanu za 1
b) Napisati funkciju koja prima ceo broj i vraca njegovu vrijednost na kvadrat
c) Napisati funkciju koja prima ceo broj i vraca -1*vrijednost posljednjeg broja

Napisati funkciju modifikuj moja prima niz, dimenziju niza i funkciju modifikacije koju treba primijeniti na svaki clan niza. Testirati ovu funkciju pozivom i main-a,
za gore navedene funkcije.
*/

#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uvecajZa1(int x) {
    return x + 1;
}
int naKvadrat(int x) {
    return x*x;
}
int promjenaZnaka(int x) {
    return -x;
}

int modifikuj(int *niz, int *n, int (*modifikacija)(int)) {
    for(int i = 0; i < n; i++) {
        printf("%d", niz[i]);
    }
    printf("\n");
}

void stampaj(int* niz, int n) {  //moj niz i koliko el ima niz
    for(int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
 }

int main() {
    int *niz;
    int n;
}