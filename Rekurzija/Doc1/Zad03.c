//Napisati rekurzivnu funkciju int najvecaCifra(int x) koja racuna najvecu cifru datog cijelog broja x

//Svaka cifra se upoređuje sa najvećom cifrom preostalih cifara, i na kraju se vraća najveća od svih.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
int najvecaCifra(int x) {
    if(x < 10) {
        return x;   //ako broj ima samo jednu cifru, taj je i najveci
    }

    int zadnjaCifra = x % 10;
    int najvecaOdOstalih = najvecaCifra(x / 10);

    if(zadnjaCifra > najvecaOdOstalih) {
        return zadnjaCifra;
    } else {
        return najvecaOdOstalih;
    }
}
*/
int najvecaCifra(int x) {
    if(x < 10) {
        return x;
    }

    int najvecaCifraDoSada = najvecaCifra(x / 10);

    if(x % 10 > najvecaCifraDoSada) {
        return x % 10;
    } else {
        return najvecaCifraDoSada;
    }
}

int main() {
    int najveca = najvecaCifra(15264);
    printf("%d", najveca);
}
