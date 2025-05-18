/*
Napisi f-ju koja odredjuje najmanj pozitivan broj koji se moze zapisati istim binarnim ciframa kao dati broj.
Koristiti bitovske operatore. Sa standardnog ulaza se unose broj, a na standardni izlaz se ispisuje razultat.
*/

#include <stdio.h>

int main() {
  int x;
  int rezultat = 0;
  unsigned int mask1 = 1;
  unsigned int mask2 = 1;
  
  printf("Unesite broj:");
  scanf("%d", &x);
  
  while(mask1 != 0) {
    if (x & mask1) {
        y = y | mask2;
        mask2 <<= 1;
        }
    
    mask1 <<= 1;
  }
  
  printf("%d\n", y);
   
  return 0;
}