//Napisati rekurzivnu funkciju int najvecaCifra(int x) koja racuna najvecu cifru datog cijelog broja x

//Svaka cifra se upoređuje sa najvećom cifrom preostalih cifara, i na kraju se vraća najveća od svih.
int najvecaCifra(int x) {
    if(x < 10) {
        return x;
    }

    int najvecaLijevo = najvecaCifra(x / 10);

    if(x % 10 > najvecaLijevo) {
        return x % 10;
    } else {
        return najvecaLijevo;
    }
}