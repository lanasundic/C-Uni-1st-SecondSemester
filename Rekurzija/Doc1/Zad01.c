//napisati rekurzivnu funkciju koja prikazuje sve cifre datog pozitivnog cijelog broja i to:
//a) void ispis1(int x) - koja ispisuje s lijeva na desno
//b) void ispis2(int x) - koja ispisuje s desna na lijevo

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void ispis1(int x) {
    if(x < 10) {    //ako je x < 10 (ako je jednocifren broj) - samo ga ispisi
        printf("%d", x);
        return;
    }
    ispis1(x / 10);    //1234 ----> 123 itd. saljemo sve kraci i kraci broj u funkciju, rekurzija ide dok ne dodje do prve cifre
    printf("%d", x % 10);   
    return;
}

void ispis2(int x) {
    if(x < 10) {
        printf("%d", x);
        return;
    }
    printf("%d", x % 10);   //prvo ispisi zadnju cifru
    ispis2(x / 10);     //zatim rekurzivno obradi ostatak
    return;
}

int main() {
    ispis1(1234);
}
