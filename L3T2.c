#include <stdio.h>
#include <string.h>

#define MAX_NIMI 48

void valikko();
void tulosta(char tiedostonNimi[]);
void lisaa(char tiedostonNimi[]);

int main(void) {

    valikko();

    return 0;
}

void valikko(void) {

    char tiedostonNimi[MAX_NIMI];
    int valinta = 1;
 

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf(" %s", tiedostonNimi);

    while (valinta != 0) { 

    printf("Valitse alla olevista valinnoista\n");
    printf("1) Lisää uusi nimi\n");
    printf("2) Tulosta nimet\n");
    printf("0) Lopeta\n");

    printf("Anna valintasi: ");
    scanf(" %d", &valinta);
    
    if (valinta == 1) {
        lisaa(tiedostonNimi);
    }
    else if (valinta == 2) {
        tulosta(tiedostonNimi);
    }
    else if (valinta == 0){
        printf("Kiitos ohjelman käytöstä.\n");

    }
    else {
        printf("Valinta ei vastaa vaihtoehtoja\n");
        printf("\n");
    }
}
}

void lisaa(char tiedostonNimi[]) {
    char lisattavaNimi[MAX_NIMI];

    FILE *Tiedosto;

    Tiedosto = fopen(tiedostonNimi, "a");
    if (Tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan: ");
        exit(0);
    }

    printf("Anna lisättävä nimi: ");
    while (getchar() != '\n');
    fgets(lisattavaNimi, MAX_NIMI, stdin);
    lisattavaNimi[strlen(lisattavaNimi) - 1] = '\0';

    fprintf(Tiedosto, "%s\n", lisattavaNimi);
    fclose(Tiedosto);
    printf("Nimi lisätty tiedostoon.\n");
    printf("\n");
    return;

}

void tulosta(char tiedostonNimi[]) {

    char rivi[50];

    FILE *Tiedosto;

    if ((Tiedosto = fopen(tiedostonNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan: ");
        printf("\n");
        exit(0);
    }

    printf("Tiedostossa olevat nimet:\n");

    while (fgets(rivi, MAX_NIMI, Tiedosto) != NULL) {
        printf("%s", rivi);
    }
    fclose(Tiedosto);
    printf("Tiedosto luettu ja tulostettu.\n");
    printf("\n");
    return;

}