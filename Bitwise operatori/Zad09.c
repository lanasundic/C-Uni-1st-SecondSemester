/*
Napisati f-ju unsigned mirror(unsigned x) koja obrce zapis broja x. Testirati f-ju pozivom u main-u. Broj x se unosi sa standardnog ulaza.
Na standardni izlaz ispisati binarnu reprezentaciju broja x i novodobijenog broja.
*/

#include <stdio.h>

void print_bits(unsigned x)
{
    unsigned mask = 1 << (sizeof(int)*8-1);
    
    while(mask) {
        mask & x ? printf("1") : printf("0");
        mask >>= 1;
    }
    putchar('\n');
}

unsigned mirror(unsigned x) {
    unsigned mask = 1 << (sizeof(unsigned) * 8 - 1);    //pravimo mask koja ima samo najvisi bit postavljen na 1, 10000000 00000000 00000000 00000000
    //Ova maska će se koristiti da u rezultujući broj (resenje) postavimo bitove na pravo mjesto s lijeva ka desno.

    unsigned mask1 = 1;
    unsigned rjesenje = 0;

    while(mask1) {
        if(mask1 & x) {     //ako je bit na toj poziciji jednak 1
            rjesenje = rjesenje ^ mask;     
        }
        mask >>= 1;
        mask1 <<= 1;
    }
    return rjesenje;
}

int main()
{
    unsigned x;
    
    printf("Unesi broj\n");
    scanf("%u", &x);
    
    unsigned k = mirror(x);

    print_bits(x);
    print_bits(k);
    
    return 0;
}