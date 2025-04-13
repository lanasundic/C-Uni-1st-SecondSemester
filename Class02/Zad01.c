/*
Napisati program koji za unijete dimenzije matrice popunjava i stampa matricu kao u  primjeru
Ulaz: 4 5
Izlaz:
0 1 2 3 4 5
11 10 9 8 7 6
12 13 14 15 16 17
23 22 21 20 19 18
*/

#include <stdio.h>
int[] stampajMatricu (matr[n][m], int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d ", matr[i][j]);
        
        printf("\n");
    }
}

void zmija(int n, int m, int matr[n][m]) {
    int br = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                matr[i][j] = br++;
            }
        } else {
            for(int j = m-1; j >= 0; j--) {
                matr[i][j] = br++;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matr[n][m];

    zmija1(n, m, matr);
    stampajMatricu(n, m, matr);

    return 0;
}