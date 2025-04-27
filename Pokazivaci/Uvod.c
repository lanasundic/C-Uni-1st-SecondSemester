/*pokazivac - promjenljiva koja cuva adresu neke druge promjenljive u memoriji 
Znaci, pokazivac ne cuva direktno vrijednost, nego gdje se nalazi ta vrijednost.

int x = 5
int *p;     p je pokazivac na int
p = &x      p sada pokazuje na x

x ima vrijednost 5
&x znaci "adresa od x"
p sada cuva adresu x

Ako zelimo da pristupimo vrijednost na koju pokazuje pokazivac koristimo *
printf("%d\n", *p)  ispisuje 5
p* znaci idi na adresu na koju pokazuje p, i procitaj vrijednost

Zasto su pokazivaci korisni?
-Omogucavaju dinamicku alokaciju memorije (malloc, free)
-Omogucavaju da funkcije mijenjaju ono sto im proslijedis
-Neophodni su za rad sa nizovima, strukturama, funkcijama itd.
*/

void promijeni(int *x) {
    *x = 10;
}

int main() {
    int a = 5;
    promijeni(&a);
    printf("%d\n", a);  //sada ispisuje 10
}

/*
x    = kutija u kojoj je broj 5
&p   = adresa kutije x
*p   = uzmi vrednost iz kutije na koju pokazuje p
*/