#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define PITUUS 30


typedef struct
{
    char etunimi[PITUUS];
    int ika;

} HENKILO;

void KysyNimi(HENKILO *henkilo_1, HENKILO *henkilo_2);
HENKILO *kopioiTietue(HENKILO *henkilo_1);
bool vertaa(HENKILO *henkilo_1, HENKILO *henkilo_2);
void vapautaMuisti(HENKILO *henkilo_3);

int main(void) {

    HENKILO henkilo_1;
    HENKILO henkilo_2;


    KysyNimi(&henkilo_1, &henkilo_2);
    HENKILO *henkilo_3 = kopioiTietue(&henkilo_1);
    if (henkilo_3 == NULL) {
        fprintf(stderr, "Muistin varaus epäonnistui.\n");
        return 1;
    }


    if (vertaa(&henkilo_1, &henkilo_2)) {
        printf("Annetut tiedot ovat samoja.\n");

        if (vertaa(&henkilo_1, henkilo_3)) {
            printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");

        }
        else {
            printf("Kopioinnin jälkeen tietueiden tiedot eivät ovat samoja.\n");

        }
        if (&henkilo_1 == henkilo_3) {
            printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
        }
        else 
            printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");

    }
    else {
        printf("Annetut tiedot eivät ole samoja.\n");
        
                if (vertaa(&henkilo_1, henkilo_3)) {
                    printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");

        }
                else {
                    printf("Kopioinnin jälkeen tietueiden tiedot eivät ovat samoja.\n");

        }
                if (&henkilo_1 == henkilo_3) {
            printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
        }
        else 
            printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");

    }
    vapautaMuisti(henkilo_3);

    printf("Kiitos ohjelman käytöstä.");


    return 0;
}

void KysyNimi(HENKILO *henkilo_1, HENKILO *henkilo_2) {

    printf("Anna ensimmäisen henkilön etunimi: ");  
    fgets(henkilo_1->etunimi, PITUUS, stdin);
    henkilo_1->etunimi[strcspn(henkilo_1->etunimi, "\n")] = '\0';


    printf("Anna ensimmäisen henkilön ikä: ");
    scanf(" %d", &henkilo_1->ika);
    getchar();

    printf("Anna toisen henkilön etunimi: ");
    fgets(henkilo_2->etunimi, PITUUS, stdin);
    henkilo_2->etunimi[strcspn(henkilo_2->etunimi, "\n")] = '\0';


    printf("Anna toisen henkilön ikä: ");
    scanf(" %d", &henkilo_2->ika);   
    getchar();
    return; 
}

bool vertaa(HENKILO *henkilo_1, HENKILO *henkilo_2) {

    return (strcmp(henkilo_1->etunimi, henkilo_2->etunimi) == 0 &&
        (henkilo_1->ika == henkilo_2->ika));
}



HENKILO *kopioiTietue(HENKILO *henkilo_1) {
    
    HENKILO *henkilo_3 = malloc(sizeof(HENKILO)); 
    if (henkilo_3 == NULL) {
        perror("Muistin varaus epäonnistui");
    }
    else {
    strcpy(henkilo_3->etunimi, henkilo_1->etunimi);
    henkilo_3->ika = henkilo_1->ika;
    }

    return henkilo_3;
}
void vapautaMuisti(HENKILO *henkilo_3) {
    free(henkilo_3);
    printf("Muisti vapautettu.\n");
    return;
}