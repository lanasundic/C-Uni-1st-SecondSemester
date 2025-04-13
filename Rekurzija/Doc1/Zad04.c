//Napisati rekurzivnu funkciju int ukloni(int x, int c) koja uklanja sva pojavljivanja date cifre c iz datog broja x

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ukloni(int x, int c) {
    if(x == 0) {    //ako je broj 0, nema vise cifara za provjeru
        return 0;
    }

    int ostatak = x % 10;   //uzmi posljednju cifru broja
    int noviBroj = ukloni(x / 10, c);

    if(ostatak == c) {
        return noviBroj;    //preskacemo tu cifru, ne dodajemo je
    } else {
        return noviBroj * 10 + ostatak;
 
    }
}

int main() {
    printf("%d", ukloni(123435, 3));

    return 0;
}