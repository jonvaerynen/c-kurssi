#include <stdio.h>
#include <math.h>

int main(void) { 
    double pi = acos(-1.0);
    double liukuluku; 
    int valinta; 

    printf("Anna liukuluku: "); 
    scanf("%lf", &liukuluku); 
    printf("\n"); 

    printf("Valikko\n"); 

    printf("1) Kerro piin arvo luvulla %.3f.\n", liukuluku);
    printf("2) Jaa piin arvo luvulla %.3f.\n", liukuluku); 
    printf("Valitse: "); scanf("%d", &valinta); 
    printf("\n"); 
    
    switch (valinta) { 
        case 1: 
            printf("Pii * %.3f = %.3f.\n", liukuluku, liukuluku * pi); 
            break; 
        case 2: 
            printf("Pii / %.3f = %.3f.\n", liukuluku, pi / liukuluku); 
            break; 
        default: 
        printf("Tuntematon valinta."); 
        break; 
    } 
    return 0; 
}