#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

int kirjoitus(char *TiedostonNimi, int arvo);
int luku(char *TiedostonNimi);

int main(void) {

    char TiedostonNimi[MAX_SIZE];
    int arvo;
    printf("Anna käsiteltävän tiedoston nimi: ");
    fgets(TiedostonNimi, MAX_SIZE, stdin);
    if (TiedostonNimi[strlen(TiedostonNimi) - 1] == '\n') {
        TiedostonNimi[strlen(TiedostonNimi) - 1] = '\0';
    }

    printf("Anna satunnaisluvuille lähtöarvo: ");
    scanf(" %d", &arvo);

    kirjoitus(TiedostonNimi, arvo);

    luku(TiedostonNimi);
    printf("Kiitos ohjelman käytöstä.");


    return 0;
}

int kirjoitus(char *TiedostonNimi, int arvo) {

    FILE *Tiedosto;
    Tiedosto = fopen(TiedostonNimi, "wb");
    if (Tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan: ");
        exit(0);
    }


    // randomien lukujen lisääminen tiedostoon
    int random;
    srand(arvo);
    for (int i = 0; i < 20; i++) {
        int value = rand() % 1000;
        fwrite(&value, sizeof(int), 1, Tiedosto);
    }
    fclose(Tiedosto);
    printf("Tiedoston kirjoitus onnistui.\n");
    return 0;

}

int luku(char *TiedostonNimi) {

    FILE *Tiedosto;
    Tiedosto = fopen(TiedostonNimi, "rb");
    if (Tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan: ");
        exit(0);
    }

    int value;

    printf("Tiedostossa on seuraavat luvut:\n");
    while (fread(&value, sizeof(int), 1, Tiedosto) == 1) {
        printf("%d ", value);
    }
    printf("\n");
    fclose(Tiedosto);
    printf("Tiedoston lukeminen onnistui.\n");
    return 0;

}
