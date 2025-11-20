#include <stdio.h>
#include "L7T1_io.h"

int main(void) {

    int askeleet[10];
    int lkm;


    int summa = lueAskeleetListaan(askeleet, &lkm);
    tulostaLista(askeleet, lkm);

    printf("Askelia yhteensä: %d\n", summa);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}