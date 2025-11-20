#include <stdio.h>
#include <stdlib.h>

void valikko();
void varaaMuisti();
void tulostus();
void vapautaMuisti();

typedef struct Lista
{
    int taulukko;
    int taulukonkoko;
    struct Lista *next;
} Lista;
Lista *ptrAlku = NULL, *ptrLoppu = NULL;



int main(void) {

    while (1){
    valikko();
    }

    return 0;
}

void valikko() {

    int valinta;

    printf("1) Tulosta listan alkiot\n");
    printf("2) Muuta listan pituutta\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf(" %d", &valinta);
    while (getchar() != '\n');

    switch (valinta)
    {
    case 1: tulostus(); break;
    case 2: varaaMuisti(); break;
    case 0: vapautaMuisti();
        printf("Kiitos ohjelman käytöstä.\n");
        exit(0);
    default:
        printf("Tuntematon valinta, yritä uudestaan.\n");
        break;
    }
    return;
}
void varaaMuisti() {

    if (ptrAlku != NULL) 
        vapautaMuisti();
    int koko;

    printf("Anna listan uusi pituus: ");
    scanf(" %d", &koko);
    while (getchar() != '\n');

    if (koko < 0) {
        printf("Listan koko ei voi olla negatiivinen.\n");
        return;
    }

    for (int i = 0; i < koko; i++){
    Lista *pointerUusi = malloc(sizeof(Lista));
        if (pointerUusi == NULL) {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }
    if (i == 0) {
        pointerUusi->taulukonkoko = koko;
    }

    pointerUusi->taulukko = i;
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
}
void tulostus() {

    if (ptrAlku == NULL) {
        printf("Lista on tyhjä.\n");
    return;
    }
    

    printf("Listassa on seuraavat luvut: \n");
    Lista *ptr = ptrAlku;
    for (int i = 0; i < ptrAlku->taulukonkoko; i++){
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
