/*
Sta su bitwise operatori:
Bitwise operatori su operatori koji rade na nivou bitova, tj. direktno manipulisu binarnim prikazom cjelobrojnih vrijednosti. Znaci, gledaju 0 i 1 u memoriji
i izvrsavaju logicke operacije nad njima.

Prvo, kako izgledea broj u binarnom obliku?
npr:
int x = 5;      u binarnoj formi: 00000101
int y = 3;      u binarnoj formi: 00000011

Bitwise operatori u C-u:
OPERATOR        IME         ZNACENJE/PRIMJER
&               AND         x & y ---> radi logicki AND nad bitovima
|               |           OR
^               XOR         x ^ y ---> ekskluzivni OR   1 0 --> 1, 0 1 --> 1 ostalo su 0
~               NOT         ~x ---> inverzija svih bitova (0 <-> 1)
<<              shift left  x << n ---> pomjeri bitove ulijevo za n mjesta
>>              shift right x >> n ---> pomjeri bitove udesno za n mjesta

*/

//Tipicne primjene bitwise operatora:

//1. Provjera da li je paran ili neparan:

if (x & 1) {    //ako je poslednji bit = 1, x & 1 daje 1 -> neparan, ako je poslednji bit = 0, x & 1 daje 0 -> paran
    printf("Neparan");
} else {
    printf("Paran");
}

/*
OBJASNJENJE: Sta znaci x & 1?
Binarnim jezikom, svaki broj u racunaru se cuva kao niz bitova(0 i 1). Najmanje znacajan bit(zadnji iliti krajnji desni bit) odlucuje da li je broj paran ili neparan
 4 ---> 0100 ---> poslednji bit je 0 ---> Paran
 5 ---> 0101 ---> poslednji bit je 1 ---> Neparan

Ako je poslednji bit 0, onda je broj paran, a ako je psolednji bit 1 broj je neparan.

Mogli smo i da provjerimo da li je broj paran ili neparan sa if(x % 2 == 1), ali bitwise verzija x & 1 je brza, jer koristi direktne operacije nad bitovima
(brza je nego dijeljenje sa %).
*/

//2. Postavi odredjeni bit:

x = x | (1 << 2);   //postavlja 3. bit (broji se od 0)

/*
OBJASNJENJE: Ova linija postavlja odredjeni bit na 1, bez mijenjanja ostalih bitova u broju x.

(1 << 2)
Ovo znaci:
Uzmi broj 1, koji u binarnom zapisu izgleda ovako: 00000001
Posmjeri sve birove ulijevo za 2 mjesta (<< 2)

Rezultat:
1 = 00000001
1 << 2 = 00000100   to je broj 4

x | (1 << 2)
Operator | je bitwise OR. Njegovo pravilo:
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1

Znaci: sada OR-ujes x sa 00000100, postavljas 3. bit na 1
Ostali bitovi ostaju nepromijenjeni
*/

//3. Obrisi odredjeni bit:
x = x & ~(1 << 2);  //resetuje 3. bit (postavlja bit na 0)

/*
Ova linija koda resetuje (odnosno postavlja na 0) bez mijenjanja ostalih bitova bit broj 2(treci s desna)
(1 << 2)
pocetno: 1 = 00000001
Pomjeri ulijevo za 2 mjesta: 1 << 2 = 00000100

~(1 << 2)
~ je NOT inverzija svih bitova: znaci: 11111011

x & ~(1 << 2);
& je AND koristi se da zadrzi bitove koji su 1, a postavi 0 sve gdje je 0

znqaci ako imamo x = 00001101 a da nam je ovo sa desne strane 11111011 onda je rezultat = 00001001
*/

//Maska(mask) ---> maska je broj koji koristis da "pregledas" jedan po jedan bit iz broja x