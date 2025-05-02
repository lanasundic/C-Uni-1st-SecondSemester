//Napisati rekurzivnu f-ju void heksaZapis(int x) koja odredjuje heksadekadni zapis datog cijelog broja

void heksaZapis(int x) {            //samo u baznom slucaju koristimo return jer je f-ja void, da je bila int morali bi da vratimo rezultat sa return
    if(x == 0) {
        return;
    }

    heksaZapis(x / 16);
    int posljednjaCifra = x % 16;

    if(posljednjaCifra < 10) {
        printf("%d", posljednjaCifra);
    } else {
        printf("%c", 'A' + (posljednjaCifra - 10));
    }
}