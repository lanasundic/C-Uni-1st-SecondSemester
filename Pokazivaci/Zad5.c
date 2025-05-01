/*
Zadatak 5: Napisati rekurzivnu f-ju int izmijeni(int n) koja svaku parnu cifru c u broju n zamjenjuje sa c/2. Napisati glavni program koji kao argument komandne linije
dobija broj n, a na standardni izlaz ispisuje novi broj. U slucaju greske na standardni izlaz za greske ispisati -1.
*/

#include <stdio.h>
#include <stdlib.h>

int izmijeni(int n) {
    if (n == 0) {   //zaustavi rekurziju kada vise nema cifara u broju n
        return 0;
    }
    int cifra = n % 10; //uzmi posljednju cifru od n
    if(cifra % 2 == 0) {    //ako je cifra parna
        cifra /= 2;         //podijeli je da 2
    }
    izmijeni(n / 10) * 10 + cifra;
}

int main(int argc, char *argv[]) {  //argc - broj argumenata, argv - niz stringova, npr. argv[1] je broj koji korisnik unese

}
