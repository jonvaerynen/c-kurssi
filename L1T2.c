#include <stdio.h>

int main(void) {

    int kokonaisluku; 
    float liukuluku;
    printf("Anna kokonaisluku: ");
    scanf("%d", &kokonaisluku);

    printf("Anna liukuluku: ");
    scanf("%f", &liukuluku);

    printf("Annoit luvut %d ja %.2f \n", kokonaisluku, liukuluku);
    return(0);
}