#include <stdio.h>
#include <stdlib.h>
#include "L7T2_lista.h"


Lista* ptrAlku = NULL;
Lista* ptrLoppu = NULL;
int seuraavaNumero = 1;

void varaaMuisti() {


    int koko;

    printf("Anna listan pituus: ");
    scanf(" %d", &koko);
    while (getchar() != '\n');

    if (koko < 0) {
        printf("Listan koko ei voi olla negatiivinen.\n");
        return;
    }

    for (int i = 0; i < koko; i++) {
        Lista *pointerUusi = malloc(sizeof(Lista));
            if (pointerUusi == NULL) {
                perror("Muistin varaus epäonnistui");
                exit(1);
            }

    pointerUusi->taulukko = seuraavaNumero++;
    pointerUusi->next = NULL;

    if (ptrAlku == NULL) {
        ptrAlku = pointerUusi;
        ptrLoppu = pointerUusi;
    }
    else {
        ptrLoppu->next = pointerUusi;
        ptrLoppu = pointerUusi;
    }
    }
    tulostus();
}

void tulostus() {

    if (ptrAlku == NULL) {
    printf("\n");
    return;
    }

    Lista *ptr = ptrAlku;
    while (ptr != NULL) {
        printf("%d ", ptr->taulukko);
        ptr = ptr->next;
    }

    printf("\n");
}

void vapautaMuisti() {
    
    Lista *ptr = ptrAlku;
    while (ptr != NULL) {
        Lista *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    ptrAlku = ptrLoppu = NULL;
}

void lisaaAlkio() {

    Lista *temp = malloc(sizeof(Lista));
    if (temp == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    temp->taulukko = seuraavaNumero++;
    temp->next = NULL;

    if (ptrLoppu != NULL) {
        ptrLoppu->next = temp;
        ptrLoppu = temp;
    }
    else {
        ptrAlku = ptrLoppu = temp;
    }
    tulostus();
}

void lisaaKeskelle() {

    int vastaus;

    if (ptrAlku == NULL) {
        printf("Lista on tyhjä.\n");
        return;
    }

    printf("Monenneksi solmuksi alkio lisätään: ");
    scanf(" %d", &vastaus);
    while (getchar() != '\n');

    if (vastaus <= 0) {
        printf("Luvun pitää olla suurempi kuin 0\n");
        return;
    }

    Lista *uusi = malloc(sizeof(Lista));
    uusi->taulukko = seuraavaNumero++;
    uusi->next = NULL;

    if (vastaus == 1) {
        uusi->next = ptrAlku;
        ptrAlku = uusi;
        if (ptrLoppu == NULL) ptrLoppu = uusi;
        tulostus();
        return;
    }

    Lista *ptr = ptrAlku;
    for (int i = 1; i < vastaus - 1; i++) {
        if (ptr == NULL || ptr->next == NULL && i < vastaus - 1) {
            printf("Antamasi luku ei ole listan alkioiden määrän sisällä\n");
            free(uusi);
            return;
        }
        ptr = ptr->next;
    }

    uusi->next = ptr->next;
    ptr->next = uusi;

    if (uusi->next == NULL)
        ptrLoppu = uusi;

    tulostus();
}


void poistaAlkio() {

    int vastaus;

    printf("Monesko alkio poistetaan: ");
    scanf(" %d", &vastaus);
    while (getchar() != '\n');

    if (vastaus <= 0) {
    printf("Poistettavan alkio ei voi olla negatiivinen tai 0.\n");
    return;
    }

    
    if (ptrAlku == NULL) {
        printf("Lista on tyhjä.\n");
        return;
    }

    Lista *ptr = ptrAlku;
    Lista *prev = NULL;
    for (int i = 1; i < vastaus; i++) {
        if (ptr->next == NULL) {
            printf("Antamasi luku ei ole listan alkioiden määrän sisällä\n");
            return;
        } 
        prev = ptr;
        ptr = ptr->next;            
    }

    if (prev == NULL) {
        ptrAlku = ptr->next;
        if (ptrAlku == NULL) ptrLoppu = NULL;
    } else {
        prev->next = ptr->next;
        if (ptr->next == NULL) ptrLoppu = prev;
    }
    free(ptr);
    tulostus();

}