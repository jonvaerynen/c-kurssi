#include <stdio.h>

int main(void) {

    int luku_1; 
    int luku_2;
    printf("Anna ensimmainen kokonaisluku: ");
    scanf("%d", &luku_1);

    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku_2);

    // summa * 2
    printf(" (%d + %d) * 2 = %d \n", luku_1, luku_2, (luku_1 + luku_2) * 2);

    // osamäärä - 3
    printf(" %d / %d -3 = %d \n", luku_1, luku_2, luku_1 / luku_2 - 3);

    // jakojäännös
    printf(" (%d + 1) %% (%d -1) = %d \n", luku_1, luku_2, (luku_1 + 1) % (luku_2 - 1));

    return(0);
}