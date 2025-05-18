/*
Napisati f-ju unsigned setbits(unsigned x, int p, int n, unsigned y) koja vraca modifikovano x tako sto mu je izmijenjeno n bitova pocevsi od pozicije p
i na ta mjesta je upisano posljednjih n bitova broja y. Testirati f-ju pozivom u main-u, pri cemu se brojevi x, y, p i n unose sa standardnog
ulaza. Provjeriti da li su brojevi p i p + n u odg. opsegu i ispisati posuku o gresci ako nisu.
Na standardnoi izlaz ispisti bitove unesenog broja x i y i bitove novodobijenog broja.

Znaci, treba da uzme n posljednih bitova iz broja y, upise ih u broj x, pocevsi od pozicije p, i vrati modifikovani broj x.
Dakle, x se mijenja tako da n bitova na poziciji p postaju isti kao zadnjih n bitova iz y.
*/

#include <stdio.h>

void print_bits(int x)
{
    unsigned mask = 1 << (sizeof(int)*8-1);
    while(mask) {
    
	mask & x ? printf("1") : printf("0");
	mask >>= 1;
    }

    putchar('\n');
}

unsigned set_bits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask1 = 1, mask0 = 0;
    
    for(int i=0; i<n; i++, mask1 <<= 1) {  //pravimo masku sa n jedinica, npr. sko je n=3 mask0 ce da bude 000...000111
	mask0 = mask0 | mask1;       //sada imamo mask0 = 000...000111 ---> ako je npr. n = 3
    }
    
    unsigned mask3 = mask0 << p;    //sada je mask3 = pomjeramo mask0 za p mjesta ulijevo, npr ako je p = 4 ---> mask3 = 000...01110000, znaci da mask3 ima jedinice bas na poziciji koje zelimo da izmijenimo u broju x
    mask3 = ~mask3;     //invertujemo: mask3 = 111...10001111
    x = x & mask3;      //e sad, nuliramo ovo unutra
    
    unsigned mask2 = mask0 & y;     //Na ovaj način "izvlačimo" samo one bitove iz y koje želimo da umetnemo u x.
    mask2 = mask2 << p; //Bitove koje smo izdvojili iz y pomeramo ulevo na poziciju p, kako bismo ih postavili tačno tamo gde treba u x.
    
    return mask2 | x;
}

int main()
{
    unsigned x, y;
    int n, p;
    
    printf("Unesi brojeve\n");
    scanf("%u%u", &x, &y);
    
    printf("Unesite n i p\n");
    scanf("%d%d", &n, &p);

    if (p < 0 || n < 0 || p+n >= (int)(sizeof(int)*8))
	{
		printf("pozicija nije u dobrom opsegu\n");
		return -1;
	}
    
    unsigned k = set_bits(x, p, n, y);
    
    printf("x:");print_bits(x);
    printf("y:");print_bits(y);
    printf("k:");print_bits(k);
    
    return 0;
}
