#include <stdio.h>
#define MatriisinKoko 2

void TulostaMatriisi(int Matriisi[MatriisinKoko][MatriisinKoko], char *MatriisinNimi);


int main(void) {

    int Matriisi_1[MatriisinKoko][MatriisinKoko];
    int Matriisi_2[MatriisinKoko][MatriisinKoko];
    int Summamatriisi[MatriisinKoko][MatriisinKoko];

    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    printf("Matriisin 1 alkiot:\n");
    for (int i = 0; i < MatriisinKoko; i++) {
        for (int y = 0; y < MatriisinKoko; y++) {
            printf("Rivi %d alkio %d: ", i + 1, y + 1);
            scanf(" %d" , &Matriisi_1[i][y]);
        }
    }
    TulostaMatriisi(Matriisi_1, "Matriisi 1");

    printf("\n");

    printf("Matriisin 2 alkiot:\n");
    for (int i = 0; i < MatriisinKoko; i++) {
        for (int y = 0; y < MatriisinKoko; y++) {
            printf("Rivi %d alkio %d: ", i + 1, y + 1);
            scanf(" %d" , &Matriisi_2[i][y]);
        }
    }
    TulostaMatriisi(Matriisi_2, "Matriisi 2");

    for (int i = 0; i < MatriisinKoko; i++) {
        for (int y = 0; y < MatriisinKoko; y++) {
            Summamatriisi[i][y] = Matriisi_1[i][y] + Matriisi_2[i][y];
        }
    }
    TulostaMatriisi(Summamatriisi, "Summamatriisi");

    printf("\n");

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}

void TulostaMatriisi(int Matriisi[MatriisinKoko][MatriisinKoko], char *MatriisinNimi) {

        printf("\n");
        printf("%s:\n", MatriisinNimi);

        for (int i = 0; i < MatriisinKoko; i++) {
        for (int y = 0; y < MatriisinKoko; y++) {
            printf("%4d ",Matriisi[i][y]);
        }
        printf("\n");
    }

    return;
}
