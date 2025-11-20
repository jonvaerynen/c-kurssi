#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxPituus 50

typedef struct
{
    char Kauttajatunnus[maxPituus];
    char salasana[maxPituus];
    int ID;
    
} Tili;

void valikko(Tili tilit[maxPituus], int *i);
void tulostus(Tili tilit[maxPituus], int *i);
void lisays(Tili tilit[maxPituus], int *i);



int main(void) {
    Tili tilit[maxPituus];

    int i = 0;

    printf("Käyttäjätunnusten hallinta.\n");

    while (1) {
    valikko(tilit, &i);
    printf("\n");
    }

    return 0;
}

void valikko(Tili tilit[maxPituus], int *i){


    int valinta = 5;

    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lisää uusi tunnus\n");
    printf("2) Tulosta tunnukset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf(" %d", &valinta);
    printf("\n");
    getchar();

    if(valinta == 1) {
        lisays(tilit, i);
    }
    else if (valinta == 2) {
        tulostus(tilit, i);
    }
    else if (valinta == 0) {
        printf("Kiitos ohjelman käytöstä.");
        exit(0);
    }
    else {
        printf("Väärä syöte\n");

    }

    return;
}

void lisays(Tili tilit[maxPituus], int *i) {
    printf("Anna käyttäjätunnus: ");
    fgets(tilit[*i].Kauttajatunnus, maxPituus, stdin);

    if (tilit[*i].Kauttajatunnus[strlen(tilit[*i].Kauttajatunnus) - 1] == '\n') {
        tilit[*i].Kauttajatunnus[strlen(tilit[*i].Kauttajatunnus) - 1] = '\0';
    }
    printf("Anna salasana: ");
    fgets(tilit[*i].salasana, maxPituus, stdin);

    if (tilit[*i].salasana[strlen(tilit[*i].salasana) - 1] == '\n') {
        tilit[*i].salasana[strlen(tilit[*i].salasana) - 1] = '\0';
    }
    tilit[*i].ID = *i;
    
    printf("Tunnus '%s' lisättiin listaan.\n", tilit[*i].Kauttajatunnus);

    (*i)++;

}

void tulostus(Tili tilit[maxPituus], int *i) {

    if (*i == 0) {
        printf("Listalla ei ole yhtään tunnusta.\n");
        return;
    }

    printf("Listalla olevat tunnukset:\n");

    for (int y = 0; y < *i; y++) {
        printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", y + 1, tilit[y].Kauttajatunnus, tilit[y].salasana, tilit[y].ID);

    }

    return;
}
