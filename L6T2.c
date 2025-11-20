#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void muistinVaraus(int argc, char *argv[]);
void tulostus();
void muistinVapautus();


typedef struct Cars
{
    char *Model;
    int year;
    struct Cars *next;  
} Cars;

Cars *pointerAlku = NULL, *pointerLoppu = NULL;

int main(int argc, char *argv[]) {

    muistinVaraus(argc, argv);
    tulostus();
    muistinVapautus();

    printf("Kiitos ohjelman käytöstä.");

    return 0;
}

void muistinVaraus(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Et antanut tiedoston nimeä.\n");
        printf("Kiitos ohjelman käytöstä.");
        exit(0);
    }

    FILE *Tiedosto = fopen(argv[1], "r");
    printf("Luetaan tiedot tiedostosta %s.\n", argv[1]);
    if (Tiedosto  == NULL) {
        printf("Tiedoston avaus epäonnistui.\n");
        printf("Kiitos ohjelman käytöstä.");
        exit(0);
    }
 
    char rivi[100];
    while (fgets(rivi, sizeof(rivi), Tiedosto) != NULL) {
        rivi[strcspn(rivi, "\n")] = '\0';

        if (rivi[0] == '\0')
            continue;

        char *model = strtok(rivi, " ");
        char *yearStr = strtok(NULL, " ");

        if (model == NULL || yearStr == NULL)
            continue;

        Cars * pointerUusi = malloc(sizeof(Cars));
        if (pointerUusi == NULL) {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }

        pointerUusi->Model = malloc(strlen(model)+1);
        strcpy(pointerUusi->Model, model);
        pointerUusi->year = atoi(yearStr);
        pointerUusi->next = NULL;

        if (pointerAlku == NULL) {
            pointerAlku = pointerUusi;
            pointerLoppu = pointerUusi;
        }
        else {
            pointerLoppu->next = pointerUusi;
            pointerLoppu = pointerUusi;
        }
    }
    fclose(Tiedosto);
    printf("Tiedot luettu linkitettyyn listaan.\n");

}

void tulostus() {

    Cars *ptr = pointerAlku;
    int i = 1;
    if (ptr == NULL) {
        printf("Ajoneuvoja ei löytynyt.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d. ajoneuvo: %s vuosimalli %d.\n", i, ptr->Model, ptr->year);
        ptr = ptr->next;
        i++;
    }
}

void muistinVapautus() {

    Cars *ptr = pointerAlku;
    while (ptr != NULL) {
        Cars *temp = ptr;
        ptr = ptr->next;
        free(temp->Model);
        free(temp);
    }
    pointerAlku = pointerLoppu = NULL;
    printf("Muisti vapautettu.\n");
}