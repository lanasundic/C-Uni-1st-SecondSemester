//Napisati rekurzivnu f-ju void trougao(int n, int trenutnaLinija) koja za dato n iscrtava trougao dimenzije n.
//Npr. za n = 5:

/*
    +
   ++
  +++
 ++++
+++++

*/
void ispisiRazmake(int br) {
    if(br == 0) {
        return;
    }
    printf(" ");
    ispisiRazmake(br - 1);
}

void ispisiPluseve(int br) {
    if(br == n) {
        return;
    }
    printf("+");
    ispisiPluseve(br - 1);
}

void trougao(int n, int trenutnaLinija) {
    if(trenutnaLinija > n) {
        return;
    }

    ispisiRazmake(n - trenutnaLinija);
    ispisiPluseve(trenutnaLinija);
    printf("\n");

    trougao(n, trenutnaLinija + 1);
}