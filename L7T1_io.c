#include <stdio.h>
#include "L7T1_io.h"

int lueAskeleetListaan(int *lista, int *koko) {
    printf("Askelanalyysi\n");

    FILE *Tiedosto = fopen("askeldata.txt", "r");

    if (Tiedosto  == NULL) {
        printf("Tiedoston avaus epäonnistui.\n");
        printf("Kiitos ohjelman käytöstä.");
        exit(0);
    }

    int i = 0;
    int summa = 0;
    char rivi[100];
    while (fgets(rivi, sizeof(rivi), Tiedosto) != NULL && i < 10) {
        rivi[strcspn(rivi, "\n")] = '\0';
          
        char *osoitin = strchr(rivi, ':'); // etsi ensimmäinen ':'
        if (osoitin != NULL) {
            osoitin++; // siirrytään merkin ':' jälkeen
            int askeleet = atoi(osoitin);
            lista[i] = askeleet;
            summa += askeleet;
            i++;
        }
    }

    fclose(Tiedosto);
    *koko = i;
    return summa;


}


void tulostaLista(int *lista, int koko) {
    
    printf("Listan askeleet: ");
    for (int i = 0; i < koko; i++) {
        printf ("%d ", lista[i]);
    }
    printf("\n");

}

