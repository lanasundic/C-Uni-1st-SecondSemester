/*
Zadatak 1: Pokazivaci na funkcije
a) Napisati funkciju koja prima ceo broj i vraca njegovu vrijednost uvecanu za 1
b) Napisati funkciju koja prima ceo broj i vraca njegovu vrijednost na kvadrat
c) Napisati funkciju koja prima ceo broj i vraca -1*vrijednost posljednjeg broja

Napisati funkciju modifikuj moja prima niz, dimenziju niza i funkciju modifikacije koju treba primijeniti na svaki clan niza. Testirati ovu funkciju pozivom i main-a,
za gore navedene funkcije.
*/
 #include<stdio.h>
 #include<stdlib.h>

void greska() {
    fprintf(stderr, "-1");  //fprintf - kao printf samo sto mozemmo da biramo gdje da pisemo, ovdje pisemo u stderr(standardni tok za greske, eng. standard error)
    exit(EXIT_FAILURE);
}                           //stderr se koristi za poruke o greskama, da bi korisnik znao da nesto nije u redu, a -1 je ono sto ispisuje ako dodje do greske

int uvecajZa1(int x) {
    return x + 1;
}

int kvadriraj(int x) {
    return x*x;
}

int promijeniZnak(int x) {
    return -x;
}

//f-ja koja mijenja svaki element niza tako sto na njega primjenjuje f-ju modifikacija
void modifikuj(int* niz, int n, int (*modifikacija)(int)) { //f-ja koja: prima niz brojeva(int* niz), prima broj elemenata(int n), prima pokazivac na f-ju koja uzima 1 int i vraca 1 int ---> int(*modifikacija)(int)
	int i;
	for(i=0; i<n; i++) {
		niz[i] = modifikacija(niz[i]);  //element = nova_vrednost(element)
	}
 }

 void stampaj(int* niz, int n) {  //moj niz i koliko el ima niz
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
 }

 int main() {
    int* niz;   //deklarisanje pokazivaca na prvi el niza
    int n;      //broj el koje cemo imati u nizu

    scanf("%d", &n);    //ucitavamo velicinu niza
    if(n < 0) {
        greska();   //pozovi f-ju greska
    }

    niz = malloc(n * sizeof(int));  //dinamicka alokacija memorije. Malloc - f-ja koja u RAM-u pravi prostor za podatke. n * sizeof(int) pravi dovoljno mjesta za n cijelih brojeva
    if(niz == NULL) {   //provjerava da li je alokacija uspjela
        greska();
    }

    for(int i = 0; i < n; i++) {    //ucitavanje elemenata niza
        scanf("%d", &niz[i]);
    }
 }

 /*
 Zasto koristimo malloc?
 U c-u, dinamicka alokacija memorije je veoma bitna jer omogucava da se rezervisanje memorije vrsi tokom izvrsavanja programa, a ne unaprijed.
 Kada kreiramo niz na staticki nacin npr. int niz[10]; velicina niza je fiksirana i poznata tokom kompajliranja. Tu se ne moze promijeniti velicina niza tokom izvrsavanja programa

 Dimanicka (fleksibilna alokacija):
 malloc omogucava da dodijelis memoriju za niz tokom izvrsavanja programa, sto znaci da:
    -Ne moras unaprijed da znas koliko memorije ti je potrebno
    -Mozes promijeniti velicinu niza na osnovu unosa korisnika ili drugih faktora tokom programa

Dakle, malloc je korisno kad ne znaš unapred koliko tačno memorije trebaš, a korisnik može da unese tu vrednost (kao u ovom kodu gde unosiš veličinu niza n).

n * sizeof(int) — računa ukupnu količinu memorije koju trebaš:
n je broj elemenata niza,
sizeof(int) daje broj bajtova koji su potrebni za jedan element niza (npr. za tip int, obično 4 bajta).
 */