/*
Napisati f-ju void svakaNTa(char* ime, int n) koja prima ime datoteke i cijeli broj n i na standardni izlaz ispisuje svaku n-tu rijec iz datoteke. 
Napisati program koji testira napisanu f-ju. Ime datoteke i broj n se zadaju kao argumenti komandne linije.
U slucaju greske na standardni izlaz za greske ispisati -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//prima ime fajla i broj, otvara fajl i cita rijeci jednu po jednu, na kraju ispisuje svaku n-tu rijec
void svakaNTa(char *ime, int n) {
    FILE *f = fopen(ime, "r");      //FILE *f - pokazivac koji pokazuje na taj fajl,    otvori fajl za citanje("r" - read)
    if (f == NULL || n <= 0) {      
        fprintf(stderr, "-1\n");
        return;
    }

    char rijec[100];
    char cnt = 0;       //broji koliko smo do sada procitali rijeci

    while(fscanf(f, "%99s", rijec) == 1) {      //fscanf cita jednu rijec iz fajla,   "99s" cita najvise 99 slova(da ne predje velicinu niza),   ako uspjesno procita rijec vrati 1 da se petlja nastavlja
        cnt++;  //kad uspjesno procita rijec
        if(cnt % n == 0) {          //ako je broj rijeci ili cnt djeljiv sa n znaci da je to n-ta rijec
            printf("%s\n", rijec);  //ispisujemo rijec koju smo upravo procitali
        }
    }
    fclose(f);      //kad zavrsimo, zatvaramo fajl da ne ostane otvoren u memoriji
}

int main(int argc, char *argv[]) {  //0 - ime programa, 1 - ime fajla, 2 - broj n
    if (argc != 3) {
        fprintf(stderr, "-1\n");
        return -1;
    }

    char *ime = argv[1];       //argv[1] sadrzi ime fajla(kao tekst), smjestamo ga u pokazivac ime da bude lakse da ga koristimo
    int n = atoi(argv[2]);     //argv[2] je tekst(string) npr. "3", ali ga atoi pretvara u broj(int), pa je sada n = 3

    if (n <= 0) {
        fprintf(stderr, "-1\n");
        return -1;
    }

    svakaNTa(ime, n);

    return 0;
}