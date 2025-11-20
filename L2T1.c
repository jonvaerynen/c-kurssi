#include <stdio.h>

int main(void) {

    int luku_1;
    int luku_2;
    int choice;

    printf("Anna kaksi kokonaislukua: ");
    scanf("%d", &luku_1);
    scanf("%d", &luku_2);

    
    printf("Valikko\n"
    "1) Summaa luvut yhteen.\n"
    "2) Kerro luvut keskenään.\n"
    "Valitse: ");
    scanf("%d", &choice);

    if (choice == 1) {
         printf("Luvut laskettiin yhteen. Tulos = %d.\n", luku_1 + luku_2);
    }
    else if (choice == 2) {
         printf("Luvut kerrottiin keskenään. Tulos = %d.\n", luku_1 * luku_2);
    }
    else 
        printf("Tuntematon valinta.");

    return 0;
}