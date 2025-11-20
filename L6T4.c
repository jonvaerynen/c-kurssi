#include <stdio.h>
#include <stdlib.h>

void valikko();
void varaaMuisti();
void tulostus();
void lisaaAlkio();
void lisaaKeskelle();
void poistaAlkio();
void vapautaMuisti();

typedef struct Lista
{
    int taulukko;
    struct Lista *next;
} Lista;
Lista *ptrAlku = NULL, *ptrLoppu = NULL;

int seuraavaNumero = 1;


int main(void) {

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
    while (1){
    valikko();
    }

    return 0;
}

void valikko() {

    int valinta;

    printf("1) Luo lista\n");
    printf("2) Lisää alkio listan loppuun\n");
    printf("3) Lisää alkio listan keskelle\n");
    printf("4) Tyhjennä lista\n");
    printf("5) Poista alkio listasta\n");
    printf("6) Tulosta lista\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf(" %d", &valinta);
    while (getchar() != '\n');

    switch (valinta)
    {
    case 1: varaaMuisti(); break;
    case 2: lisaaAlkio(); break;
    case 3: lisaaKeskelle(); break;
    case 4: vapautaMuisti(); break;
    case 5: poistaAlkio(); break;
    case 6: tulostus(); break;
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

    printf("Minkä alkion jälkeen alkio lisätään: ");
    scanf(" %d", &vastaus);
    while (getchar() != '\n');

    if (vastaus <= 0) {
        printf("Luvun pitää olla suurempi kuin 0\n");
        return;
    }
    Lista *ptr = ptrAlku;
    for (int i = 1; i < vastaus; i++) {

        if (ptr == NULL) {
            printf("Antamasi luku ei ole listan alkioiden määrän sisällä\n");
            return;
        }
        else
            if(ptr->next != NULL) {
                ptr = ptr->next;
            }
            else {
                printf("Antamasi luku ei ole listan alkioiden määrän sisällä\n");
                return;
            }

        }
    
    Lista *Uusi = malloc(sizeof(Lista));
    if (Uusi == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    Uusi->taulukko = seuraavaNumero++;
    Uusi->next = ptr->next;
    ptr->next = Uusi;
    if (Uusi->next == NULL) ptrLoppu = Uusi;
    tulostus();

}

void poistaAlkio() {

    int vastaus;

    printf("Mikä alkio poistetaan: ");
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