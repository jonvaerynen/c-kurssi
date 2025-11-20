#include <stdio.h>
#include <stdlib.h>
#include "L7T3_muisti.h"


int* varaaMuistiaNumeroille(int maara) {

    int *numerot = malloc(sizeof(int) * maara);
    if (numerot == NULL) {
        printf("Muistin varaus epäonnistui\n");
        exit(0);
    }

    return numerot;

}
void vapautaMuisti(int *taulukko) {
    
    free(taulukko);
}
