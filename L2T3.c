#include <stdio.h>

int main(void) {

    int luku;
    int kierros = 1;

    printf("Anna jokin luku väliltä 1-10: ");
    scanf("%d", &luku);

    if (luku < 1 || luku > 10) {
        printf("Antamasi luku ei ole välillä 1-10.");
        return 0;
    }

    while (kierros <= luku) {     

         printf("%d kierros.\n", kierros);
         kierros++;
    } 
   


    return 0;
}