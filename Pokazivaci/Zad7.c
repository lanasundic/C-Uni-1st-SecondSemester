/*
Argumenti komandne linije su opcija (-m, -v ili -mv) i rijec. Ukoliko je opcija -m pretvoriti sva slova rijeci u mala slova, ukoliko je opcija -v pretvoriti sva slova
u rijeci u velika slova, a ukoliko je opcija -mv pretvoriti sva mala slova u velika, a sva velika slova u mala.
Ukoliko opcija nije zadata ili je netacno navedena ispisati -1 na standardni izlaz za greske.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>     //strcmp

int main(int argc, char *argv[]) {
    if(argc != 3) {     //mora postojati tacno 2 argumenta - opcija i rijec
        fprintf(stderr, "-1\n");
        return -1;
    }

    char *opcija = argv[1];     //prvi argument: opcija (-m, -v, -mv)
    char *rijec = argv[2];      //drugi argument: rijec koju obradjujemo
    char *p = rijec;            //pokazivac p pokazuje na prvi karakter rijeci

    if(strcpm(opcija, "-m") == 0) {     //ako su stringovi identicni, strcmp() vraca 0
        while(*p) {
            *p = tolower(*p);
            p++;    //zasto ovdje nismo stavili *p?
        }
    }
    else if(strcmp(opcija, "-v") == 0) {
        while(*p) {
            *p = toupper(*p);
            p++;
        }
    }
    else if(strcmp(opcija, "-mv") == 0) {
        while(*p) {
            if(islower(*p))
                *p = toupper(*p);
            else if(isupper(*p))
                *p = tolower(*p);

            p++;
        }
    } else {
        fprintf(stderr, "-1\n");
        return -1;
    }

    printf("%s", rijec);

    return 0;
}


/*
argc = 3

argv[0] = "./program"   ime programa
argv[1] = "-m"
argv[2] = "Pozdrav"
*/