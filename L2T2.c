#include <stdio.h>

int main(void) {

    int luku;
    int summa = 0;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &luku);

    if (luku >= 10 && luku <= 200) {
        for (int i = 0; i <= luku; ++i) {
            summa = summa + i;

        }
        printf("Lukujen 0 - %d summa on %d\n", luku, summa);
    }
    else
        printf("Antamasi luku ei ole annetulla välillä.\n");

    return 0;
}