#include <stdio.h>
#include <stdlib.h>

void valikko(int *taulukonkoko, int **taulukko);
void varaaMuisti(int *taulukonkoko, int **taulukko);
void tulostus(int *taulukonkoko, int **taulukko);
void vapautaMuisti(int **taulukko);

int main(void) {
    int taulukonKoko = 0;
    int *taulukko = NULL;

    while (1){
    valikko(&taulukonKoko, &taulukko);
    }

    return 0;
}

void valikko(int *taulukonkoko, int **taulukko) {

    int valinta;

    printf("1) Tulosta taulukon alkiot\n");
    printf("2) Muuta taulukon kokoa\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf(" %d", &valinta);
    while (getchar() != '\n');

    switch (valinta)
    {
    case 1:
        tulostus(taulukonkoko, taulukko);
        break;
    case 2:
        varaaMuisti(taulukonkoko, taulukko);
        break;
    case 0:
        vapautaMuisti(taulukko);
        printf("Muisti vapautettu.\n");
        printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    default:
        printf("Tuntematon valinta, yritä uudestaan.\n");
        break;
    }
    
    return;
}
void varaaMuisti(int *taulukonkoko, int **taulukko) {

    if (*taulukko != NULL) 
        vapautaMuisti(taulukko);

    printf("Anna taulukon uusi koko: ");
    scanf(" %d", taulukonkoko);
    while (getchar() != '\n');

    if (*taulukonkoko < 0) {
        printf("Taulukon koko ei voi olla negatiivinen.\n");
        return;
    }

    *taulukko = malloc(*taulukonkoko * sizeof(int));
    
    if (*taulukko == NULL) {
        perror("Muistin varaus epäonnistui.\n");
        return;
    }

    for (int i = 0; i < *taulukonkoko; i++) {
        (*taulukko)[i] = i;
    }

    return;
}
void tulostus(int *taulukonkoko, int **taulukko) {
    
    if (*taulukko == NULL || *taulukonkoko <= 0) {
        printf("Taulukko on tyhjä.\n");
        return;
    }

    printf("Taulukon alkiot ovat: ");
    for (int i = 0; i < *taulukonkoko; i++){
    printf("%d ", (*taulukko)[i]);
    }
    printf("\n");
}

void vapautaMuisti(int **taulukko) {
    if (*taulukko != NULL) {
    free(*taulukko);
    *taulukko = NULL;
    }
}
