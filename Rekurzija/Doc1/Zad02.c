//Napisati rekurzivnu funkciju int brojParnih(int x) koja racuna broj parnih cifara datog cijelog broja x

int projParnih(int x) {

    if(x < 10) {
        if(x % 2 == 0) {
            return 1;
        } else{
            return 0;
        }
    }

    if(x % 2 == 0) {    //ako je posljednja cifra parna
        return 1 + brojParnih(x / 10);  //dodaj 1 i nastavi rekurzivno sa ostatkom broja x / 10
    } else {
        return brojParnih(x / 10);  //samo nastavi sa x / 10 bez dodavanja
    }
    
}