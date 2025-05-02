//saberi brojeve od 1 do n:
//baza: ako je n==1, onda je rezultat samo 1
//rekurzija: sabiranje od 1 do n je: n + sabiranje od 1 do n-1

int suma(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n + suma(n - 1);
    }
}

int faktorijel(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * faktorijel(n - 1);
    }
}

int sabiranjeCifaraBroja(int n) {   //1234 - 1+2+3+4
    if(n == 0) {
        return 0;
    } else {
        return (n % 10) + sabiranjeCifaraBroja(n / 10);
    }
}

int obrniString(char *rijec) {
    if(*rijec == '\0') {
        return;
    } else {

    }
}

int kolikoCifaraImaBroj(int n) {
    if(n == 0) {
        return 0;
    } else if(n < 10) {     //ako je broj jednoscifren vracaj 1
        return 1;
    } else {
        return 1 + kolikoCifaraImaBroj(n / 10);
    }
}