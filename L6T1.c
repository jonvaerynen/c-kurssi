#include <stdio.h>
#include <stdlib.h>


typedef struct Luvut{
    int kokonaisluku;
    struct Luvut *seuraava;   
} Luvut;

Luvut *pointerAlku = NULL, *pointerLoppu = NULL;
Luvut *pointerUusi = NULL, *pointer = NULL;

int main(void) {

    printf("Anna listan luvut.\n");

    while (1) {

        if ((pointerUusi = (Luvut*)malloc(sizeof(Luvut))) == NULL ){
        perror("Muistin varaus epäonnistui, lopetetaan");
        exit(0);
        }


        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf(" %d", &pointerUusi->kokonaisluku);

        if(pointerUusi->kokonaisluku == 0) break;


        pointerUusi->seuraava = NULL;

        if (pointerAlku == NULL) {
            pointerAlku = pointerUusi;
            pointerLoppu = pointerUusi;
        }
        else {
            pointerLoppu->seuraava = pointerUusi;
            pointerLoppu = pointerUusi;
        }
    }
    printf("Listassa on seuraavat luvut: "); 
    pointer = pointerAlku;
    while (pointer != NULL) {
        printf("%d ", pointer->kokonaisluku);
        pointer = pointer->seuraava;
        
    }
    printf("\n");
    printf("Kiitos ohjelman käytöstä."); 


    return 0;
}