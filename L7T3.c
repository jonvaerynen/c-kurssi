#include <stdio.h>
#include "L7T3_muisti.h"
#include "L7T3_io.h"

int main (void) {

    int maara;
    int lisnum; 
    printf("Lottoarvonta\n");
    printf("Kuinka monta numeroa arvotaan: ");
    scanf(" %d", &maara);
    
    printf("Kuinka monta lisänumeroa arvotaan: ");
    scanf(" %d", &lisnum);

    printf("\n");
    
    int *numerot = varaaMuistiaNumeroille(maara);
    int *lisanumerot = varaaMuistiaNumeroille(lisnum);


    arvoNumerot(numerot, maara);
    arvoNumerot(lisanumerot, lisnum);

    printf("Arvottiin seuraavat numerot ja lisänumerot.\n");
    printf("Numerot: ");

    tulostaNumerot(numerot, maara);

    printf("Lisänumerot: ");
    tulostaNumerot(lisanumerot, lisnum);

    printf("Kiitos ohjelman käytöstä.");

    vapautaMuisti(numerot);
    vapautaMuisti(lisanumerot);

    return 0;
}