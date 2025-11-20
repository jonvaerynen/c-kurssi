#include <stdio.h>

#define MAX_PITUUS 30

int length(char *s);
char *kopiointi(char *kohde, char* lahde);


int main(void) {

    char merkkitaulukko[MAX_PITUUS];
    char merkkitaulukko_2[MAX_PITUUS];


    printf("Anna kopioitava merkkijono: ");
    fgets(merkkitaulukko, MAX_PITUUS, stdin);
    int pituus = length(merkkitaulukko);

    if (merkkitaulukko[pituus - 1] == '\n') {
        merkkitaulukko[pituus - 1] = '\0';
    }

    kopiointi(merkkitaulukko_2, merkkitaulukko);

    printf("Merkkijono 1 on '%s'.\n", merkkitaulukko);
    printf("Merkkijono 2 on '%s'.\n", merkkitaulukko_2);
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}

int length(char *s) {
    int pituus = 0;
    while (s[pituus] != '\0') {
        pituus++;
    }
    return pituus;
}

char *kopiointi(char *kohde, char* lahde) {

    char *alkuperainen = kohde;
    while (*lahde != '\0') {
        *kohde = *lahde;
        kohde++;
        lahde++;
    }
    *kohde = '\0';
    return alkuperainen;
}
