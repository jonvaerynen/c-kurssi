#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(int argc, char *argv[]);
int *varaaMuisti(int luku);
int *taytaTaulukko(int *taulukko, int luku);
void tulostaTaulukko(int *taulukko, int luku);
void vapautaMuisti(int *taulukko);


int main(int argc, char *argv[]) {

    int luku = tarkistaSyote(argc, argv);
    int *taulukko = varaaMuisti(luku);
    taulukko = taytaTaulukko(taulukko, luku);
    tulostaTaulukko(taulukko, luku);
    vapautaMuisti(taulukko);

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}

int tarkistaSyote(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Et antanut taulukon kokoa.\n");
        printf("Kiitos ohjelman käytöstä.");
        exit(0);
    }   
    
    int luku = atoi(argv[1]);

    if (luku <= 0) {
        printf("Parametri ei ollut positiivinen kokonaisluku.\n");
        printf("Kiitos ohjelman käytöstä.");

        exit(0);
    }
    return luku;
}

int *varaaMuisti(int luku) {

    int *taulukko = malloc(luku * sizeof(int));

    if (taulukko == NULL) {
        perror("Muistin varaus epäonnistui\n");
        exit(EXIT_FAILURE);
    }

    printf("Muistin varaus onnistui.\n");
    return taulukko;
}

int *taytaTaulukko(int *taulukko, int luku) {

    printf("Taulukossa on tilaa %d alkiolle.\n", luku);
    
    for (int i = 0; i < luku; i ++) {
    printf("Anna %d. luku: ", i + 1);
    scanf(" %d", &taulukko[i]);
    }
    printf("Taulukko täytetty.\n");
    return taulukko;
}

void tulostaTaulukko(int *taulukko, int luku) {

    printf("Taulukossa on luvut: ");
    for (int i = 0; i < luku; i++) {
    printf("%d ", taulukko[i]);
    }
    printf("\n");
    printf("Taulukko tulostettu.\n");
}

void vapautaMuisti(int *taulukko) {
    free(taulukko);
    taulukko = NULL;
    printf("Muisti vapautettu.\n");

}
