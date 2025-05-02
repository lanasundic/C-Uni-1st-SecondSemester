//Napisati rekurzivnu funkciju int ukloni(int x, int c) koja uklanja sva pojavljivanja date cifre c iz datog broja x

int ukloni(int x, int c) {
    if(x == 0) {
        return;
    }

    int posljednjaCifra = x % 10;
    int noviBroj = ukloni(x / 10, c);

    if(posljednjaCifra == c) {
        return noviBroj;
    } else {
        return noviBroj * 10 + posljednjaCifra;
    }
}