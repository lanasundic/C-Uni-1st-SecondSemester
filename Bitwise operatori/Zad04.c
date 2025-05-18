//Napisati f-ju sumaBitova koja izracunava sumu bitova datog broja. Testirati f-ju pozivom u main-u, broj x se unosi sa standardnog ulaza.
//npr. Ulaz: 78     Izlaz: 4

#include <stdio.h>

void printBits(int x) {
    unsigned mask = 1 << (sizeof(int) * 8 - 1);

    while(mask) {
        mask & x ? printf("1") : printf("0");
        mask >>= 1;
    }
    putchar('\n');
}

int sumaBitova(int x) {
    unsigned mask = 1 << (sizeof(int) * 8 - 1);
    int suma = 0;

    while(mask) {
        if(mask & x) {
            suma++;
            mask >>= 1;
        }
    }
    return suma;
}

int main() {
    int x;
    printf("Unesite broj:");
    scanf("%d", &x);

    printBits(x);
    printf("Suma je: ", sumaBitova(x));

    return 0;
}