#include <stdio.h>
#include <stdlib.h>
#include "L7T2_lista.h"

void valikko();


int main(void) {

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
    while (1){
    valikko();
    }

    return 0;
}

void valikko() {

    int valinta;

    printf("1) Luo lista\n");
    printf("2) Lisää alkio listan loppuun\n");
    printf("3) Lisää alkio listan keskelle\n");
    printf("4) Tyhjennä lista\n");
    printf("5) Poista alkio listasta\n");
    printf("6) Tulosta lista\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf(" %d", &valinta);
    while (getchar() != '\n');

    switch (valinta)
    {
    case 1: varaaMuisti(); break;
    case 2: lisaaAlkio(); break;
    case 3: lisaaKeskelle(); break;
    case 4: vapautaMuisti(); break;
    case 5: poistaAlkio(); break;
    case 6: tulostus(); break;
    case 0: vapautaMuisti();
        printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    default:
        printf("Tuntematon valinta, yritä uudestaan.\n");
        break;
    }
    return;
}