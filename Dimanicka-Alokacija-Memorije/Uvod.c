#include<stdio.h>
#include<stdlib.h>

/*
Dinamicka alokacija memorije u C-u je mehanizam koji omogucava programu da tokom izvodjenja(runtime) zatrazi memoriju iz heap segmenta - za razliku od staticke alokacije
npr. lokalne promjenljive koja se vrsi u stacku i odredjuje u vrijeme kompajliranja.

Kljucne f-je za dinamicku alokaciju (iz <stdlib.h>)
1. malloc(size_t size)
    alocira blok memorije od size bajtova.
    ne inicijalizuje memoriju(sadrzaj je nedefinisan)
    vraca pokazivac (void*) na pocetak alociranog bloka.
*/
int *arr = (int *) malloc(5 * sizeof(int));     //prostor za 5 intova