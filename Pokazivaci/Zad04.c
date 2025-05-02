/*
Napisati f-ju int veciOdProsjeka() koja ucitava cijele brojeve sa standardnog ulaza sve dok se ne ucita 0. Broj brojeva nije unaprijed poznat. F-ja vraca broj brojeva
vecih od prosjeka. Ako nema unijetih brojeva f-ja treba da vrati 0. Testirati napisanu f-ju pozivom iz glavnog programa i na standardni izlaz ispisati rezultat
izvrsavanja f-je. U slucaju greske, na standardni izlaz za greske ispisati -1.
*/

#include <stdio.h>

int veciOdProsjeka() {
    int broj;
    int suma = 0;
    int count = 0;

    int brojevi[1000];  //privremeni niz velicine 1000, u kojem cuvam sve unesene brojeve
    int *p = brojevi;   //pokazivac na prvi element niza brojevi(ili neki element)

    while (1) {     //znaci da petlja traje beskonacno sve dok se eksplicitno ne prekine sa break npr. Ova petlja je u osnovi infinite loop, koja omogućava da unosimo brojeve jedan za drugim bez unapred određenog broja unosa.
        int rezUnosa = scanf("%d", &broj);
        
        if(rezUnosa != 1) {
            fprintf(stderr, "-1\n");
            return -1;
        }

        if(broj == 0) {     //dok korisnik ne unese 0
            break;
        }

        if(count >= 1000) {         //provjera da li je korisnik slucano unio vise od 1000 brojeva
            fprintf(stderr, "-1\n");
            return -1;
        }

        *(p + count) = broj;    //unos brojeva preko pokazivaca     ekvivalentno sa    brojevi[count] = broj;
        suma += broj;
        count++;
    }

    if(count == 0) {
        return 0;
    }

    float prosjek = (float)suma / count;

    int veci = 0;
    for(int i = 0; i < count; i++) {
        if(*(p + i) > prosjek) {
            veci++;
        }
    }
    return veci;
}

int main() {
    int rezultat = veciOdProsjeka();

    if(rezultat == -1) {
        return 1;
    }

    printf("%d", rezultat);
    
    return 0;
}
