//Naredna 3 zad se nalaze u zbirci: http://www.programiranje2matf.bg.ac.rs/zbirka/p2_zbirka. pdf u dijelu Pokazivaci na funkcije, str 85.

/*
Zdatak 2: Napisati program koji tabelarno stampa vrijednost proizvoljne realne f-je sa jednim realnim argumentom, odnosno izracunava i ispisuje vrijednost date f-je
unekvidistantnih tacaka na intervalu [a, b].
Realni brojevi a i b (a < b), kao i cijeli broj n (n >= 2), ucitavaju se sa standardnog ulaza. Ime f-je se zadaje kao argument komandne linije(sin, cos, tan, atan,
acos, asin, exp, log, log10, sqrt, floor, ceil, sqr).

pr1:
./a.out sin
Unesite krajeve intervala: -0.5 1
Broj tacka: 4

-0.479443 0.00000 0.47943 0.84147
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //strcmp, strcpy
#include <math.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void tabela(int n, double a, double b, double (*fp)(double)) {  //pokazivac na f-ju fp koja prima double i vraca double
    double x;   //trenutna tacka na intervalu gdje racunam f-ju

    printf("--------------------\n");   //ispis zaglavlja tabele

    for(int i = 0; i < n; i++) {
        x = a+i * (b-a) / (n-1);
        printf("| %8.5f | %8.5f |\n", x, (*fp)(x));
    }
}