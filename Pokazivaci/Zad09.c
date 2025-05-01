/*
Napisati program koji ispisuje na standardni izlaz kloliko elemenata u njegovoj komandnoj liniji jesu palindromi
palindromi - rijeci koje se isto citaju sa lijeva na desno, i sa desna na lijevo.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int jePalindrom(char *rijec) {
    char *pocetak = rijec;      //pokazivac pocetak koji pokazuje na pocetak rijeci, npr. ako je rijec "ana", onda *pocetak pokazuje na "a"
    char *kraj = rijec + strlen(rijec) - 1;     //pokazivac na posljednje slovo, rijec-pokazivac na prvi znak stringa, Da dođemo do posljednjeg znaka, moramo ići od početka (rijec) plus taj broj minus 1.

    while(pocetak < kraj) {
        if (*pocetak != *kraj) {
            return 0;
        }
        pocetak++;
        kraj--;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    int brojPalindroma = 0;

    for(int i = 1; i < argc; i++) {
        if(jePalindrom(argv[i])) {
            brojPalindroma++;
        }
    }

    printf("%d\n", brojPalindroma);

    return 0;
}