// Napisati funkciju void zamijeniKolone(int mat[][], int r, int s) koja mijenja datu matricu cijelih
//brojeva tako sto zamijeni r-tu i s-tu kolonu*/

void stamapaj_matricu(int n, int m, int matr[n][m]) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%d ", matr[i][j]);
        
        printf("\n");
    }
}


void zamijeniKolone(int matr[][], int r, int s) {
    for(int i = 0; i < n; i++) {
        int temp = matr[i][r];
        matr[i][r] = matr[i][s];
        matr[i][s] = temp;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matr[n][m];

    printf("Unesite elemente matrice:");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
    int r, s;
    printf("Unesite indexe kolona koje zelite da zamijenite:");
    scanf("%d %d", &r, &s);

    zamijeniKolone(n, m, matr, r, s);
    stampajMatricu(n, m, matr);
}