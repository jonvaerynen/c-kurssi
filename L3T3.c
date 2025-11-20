#include <stdio.h>
#include <string.h>

int suurin(int luku_1, int luku_2);
float suurinf(float liukuluku_1, float liukuluku_2);
void pisin(char sana_1[50], char sana_2[50]);


int main(void) {


    // kokonaisluvut
    int luku_1;
    int luku_2;
    int pienin;

    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf(" %d", &luku_1);
    printf("Luku 2: ");
    scanf(" %d", &luku_2);

    int isoin = suurin(luku_1, luku_2);
    if (luku_1 == isoin) {
        pienin = luku_2; 
        printf("Luku %d on suurempi ja %d pienempi.\n", isoin, pienin);
    }
    else if (luku_2 == isoin){
        pienin = luku_1;
        printf("Luku %d on suurempi ja %d pienempi.\n", isoin, pienin);
    }
    else {
        printf("Luvut %d ja %d ovat yhtä suuria.\n", luku_1, luku_2);
    }



    // liukuluvut
    float liukuluku_1;
    float liukuluku_2;
    float lpienin;

    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf(" %f", &liukuluku_1);
    printf("Luku 2: ");
    scanf(" %f", &liukuluku_2);

    float isoinf = suurinf(liukuluku_1, liukuluku_2);
    if (liukuluku_1 == isoinf) {
        lpienin = liukuluku_2; 
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", isoinf, lpienin);    
    }
    else if (liukuluku_2 == isoinf){
        lpienin = liukuluku_1;
        printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", isoinf, lpienin);    

    }
    else {
        printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", liukuluku_1, liukuluku_2);    

    }


    // merkkijono
    char nimi_1[50];
    char nimi_2[50];

    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf(" %49s", nimi_1);
    printf("Nimi 2: ");
    scanf(" %49s", nimi_2);

    pisin(nimi_1, nimi_2);
    
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}
int suurin(int luku_1, int luku_2) {

    if (luku_1 > luku_2) {
        return luku_1;
    }
    else if (luku_2 > luku_1) {
        return luku_2;
    }
    else {
        return 0;
    }

}

float suurinf(float liukuluku_1, float liukuluku_2) {

    if (liukuluku_1 > liukuluku_2) {
        return liukuluku_1;
    }
    else if (liukuluku_2 > liukuluku_1) {
        return liukuluku_2;
    }
    else {
        return 0;
    }
}

void pisin(char sana_1[50], char sana_2[50]) {
    int tulos = strcmp(sana_1, sana_2);

    if (tulos > 0)
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", sana_1, sana_2);
    else if (tulos < 0)
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", sana_2, sana_1);
    else
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", sana_1, sana_2);
    return;
}

