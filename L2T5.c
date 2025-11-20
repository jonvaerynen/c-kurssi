#include <stdio.h>
#include <string.h>


int main(void) {

    char merkkitaulukko[200] = "";
    int pituus = strlen(merkkitaulukko);
    char merkki;
    int valinta = 1;

    while (valinta != 0) {
        printf("\n");
        printf("Valikko\n");
        printf("1) Lisää uusi merkki\n");
        printf("2) Tyhjennä merkkijono\n");
        printf("3) Tulosta merkkijono\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &valinta);

        printf("\n");
        
        
        switch (valinta) {
            case 1 :    if (pituus >= sizeof(merkkitaulukko) - 1) {
                            printf("Merkkijonoon ei mahdu enempää merkkejä\n");
                        }
                        else {
                        printf("Anna jokin merkki: "); 
                        scanf(" %c", &merkki); 
                        merkkitaulukko[pituus] = merkki; pituus++; 
                        merkkitaulukko[pituus] = '\0'; 
                        }
                        break;

            case 2 :    memset(merkkitaulukko, 0, sizeof(merkkitaulukko));  
                        printf("Merkkijono on tyhjennetty.\n"); 
                        pituus = 0; 
                        break;

            case 3 :    if (pituus == 0){
                            printf("Merkkijono on tyhjä.\n");
                        }
                        else {
                            printf("Merkkijono: %s\n", 
                            merkkitaulukko);
                        } 
                        break;

            case 0 :    printf ("Ohjelman lopetus."); 
                        break;

            default :   printf("Tuntematon valinta.\n");

        }


    }


    return 0;
}