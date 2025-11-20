#include <stdio.h>
#include <stdlib.h>
#include "L7T3_io.h"



void arvoNumerot(int *taulukko, int maara) {

    for (int i = 0; i < maara; i++) {
    int numero = rand() % (37 + 1);

    if (!tarkistaNumero(taulukko, i, numero)) {
        taulukko[i] = numero;
    }
    else {
        i--;
    }
    }

}

int tarkistaNumero(int *taulukko, int maara, int numero) {

    for (int i = 0; i < maara; i++) {

        if (numero == taulukko[i]) {
            return 1;
        }

    }
    return 0;

    
}

void tulostaNumerot(int *taulukko, int maara) {

    
    for (int i = 0; i < maara; i++) {
        printf("%d ", taulukko[i]);
    }
    printf("\n");


}