// Napisati program koji ucitava cifre za dva pozitivna velika broja u obliku stringa
// Potrebno je stampati zbir ucitanih brojeva
#include <stdio.h>
#include <stdlib.h>

int brojCifara(char br1[]) {
    int cnt = 0;
    for(int i = 0; br[i] != '\0'; i++) {
        cnt++;
    }
    return cnt;
}

void flip(char br[]) {  //123 ---> 321
    int n = brojcifara(br); //u n cuvamo br cifara, npr. n = 3
    for(int i = 0; i < n / 2; i++) {    //idemo samo do polovine stringa jer samo trebamo da zamijenimo 1. i poslednju, drugi i predzadnju cifru itd.
        char tmp = br[i];
        br[i] = br[n - 1 - i];  //karakter na kraju stringa stavljamo na pocetak
        br[n - 1 - i] = tmp;    //ovime zamijenimo mjesta 2 karaktera
    }
}

int saberi(char br1[], char br2[], char zbir[]) {
    flip(br1);
    flip(br2);

    int brCif1 = brojCifara(br1);
    int brCif2 = brojCifara(br2);
    int brCifZ;

    if(brCif1 > brCif2) {
        brCifZ = brCif1 + 1;    //dodajemo 1 zbog moguceg prenosa
    } else {
        brCifZ = brCif2 + 1;
    }

    for(int i = 0; i <= brCifZ; i++) {  //Zašto jedan više(<=)? Zato što sabiranje može da proizvede broj sa jednom cifrom više nego ulazni brojevi.
        zbir[i] = '0';  //svaki element u brojCifZ postavljamo na karakter 0
    }
    zbir[brCifZ] = '\0';    //moramo da ovo postavimo na kraju stringa, da bi znao dje je kraj stringa

    for(int i = 0; i < brCifZ; i++) {
        int c1 = 0;
        int c2 = 0;

        if(i < brCif1) {
           c1 = br1[i] - '0';   //pretvaranje u broj
        }
        if(i < brCif2) {
            c2 = br2[i] - '0';
        }
        prenos += c1 + c2;

        zbir[i] = '0' + prenos % 10;
        prenos /= 10;
    }
    if (zbir[br_cif_z - 1] == '0' && prenos == 0)
    zbir[br_cif_z - 1] = '\0';

    flip(br1);
    flip(br2);
    flip(zbir);

    return brojCifara(zbir);
}

int main() {
    char br1[100];
    char br2[100];
    char zbir[101]; //+1 za sigurnost

    scanf("%s", br1);
    scanf("%s", br2);

    saberi(br1, br2, zbir);
    printf("%s\n", zbir);

    return 0;
}