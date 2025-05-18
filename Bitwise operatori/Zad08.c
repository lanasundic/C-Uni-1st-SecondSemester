//Napisati f-ju unsigned rightRotate(unsigned x, int n) koja vrsi rotaciju neoznacenog broja x za n pozicija u desno. Testirati f-ju pozivom u main-u.
//Brojevi x i n se unose sa standardnog ulaza. Na standardni izlaz ispisati binarnu reprezentaciju broja x i novodobijenog broja.
//Ukoliko je broj n negativan ispisati poruku o gresci

#include <stdio.h>

void print_bits(int x)
{
    unsigned mask = 1 << (sizeof(int)*8-1);
    
    while(mask)
    {
	mask & x ? printf("1") : printf("0");
	mask >>= 1;
    }
    putchar('\n');
}

unsigned right_rotate(unsigned x, int n) {
    unsigned mask = 1;  //00000000 00000000 00000000 00000001   koristi se da postepeno pravi mask sa jedinicama
    unsigned mask1 = 0;  //00000000 00000000 00000000 00000000

    for(int i = 0; i < n; i++, mask <<= 1) {
        mask1 = mask1 | mask;
    }

    mask1 = mask1 & x;  //da dobijemo n bitova broja x

    mask1 = mask1 << (sizeof(unsigned) * 8 - n);    //pomjeramo ih na pocetak, odnosno na lijevu stranu. ako je n = 3, pomjeramo tih 3 bita za 29 mjesta ulijevo
    x = x >> n;     //ovo radi desnu rotaciju: x se pomjeri n mjesta udesno. Lijeva strana se popunjava nulama

    return x | mask1;   //SPOJI IH. On je stqavio ^ ali to vljd nije tacno

    /*
    FUNKCIJA RADI OVO:
        Pravi masku da uzme zadnjih n bitova.

        Izvlači te bitove i pomjera ih lijevo.

        Pomjera x udesno.

        Kombinuje sve u novi broj.
    */
}

int main()
{
    int n;
    unsigned x;
    
    printf("Unesi broj\n");
    scanf("%u", &x);
    
    printf("Unesite n\n");
    scanf("%d", &n);

	if (n < 0)
	{
		printf("greska u stepenu rotacije\n");
		return -1;
	}
    
    unsigned k = right_rotate(x, n);
    
    print_bits(x);
    print_bits(k);
    
    return 0;
}