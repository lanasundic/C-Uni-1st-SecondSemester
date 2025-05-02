//Napisati rekurzivnu f-ju int dodaj0(int x) koja posle svake neparne cifre datog broja dodaje 0.

int dodaj0(int x) {
    if(x == 0) {
        return 0;
    }

    int noviBroj = dodaj0(x / 10);      //u rekurziji se uvijek prvo radi rekurzivni poziv pa onda sve ostalo.
    int posljednjaCifra = x % 10;

    if(posljednjaCifra % 2 == 0) {
        return noviBroj * 10 + posljednjaCifra;
    } else {
        return noviBroj * 100 + posljednjaCifra * 10;   //dodaj cifru i nulu iza nje
    }
}