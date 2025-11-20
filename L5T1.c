#include <stdio.h>
#include <stdlib.h>

void nelio(int *kokonaisluku);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Et antanut lukua!\n");
        printf("Kiitos ohjelman käytöstä.");

        return 0;
    }
    
    int kokonaisluku = atoi(argv[1]);

    printf("Luku on %d.\n", kokonaisluku);
    nelio(&kokonaisluku);
    
    printf("Luvun neliö on %d.\n", kokonaisluku);
    printf("Kiitos ohjelman käytöstä.");


    return 0;
}

void nelio(int *kokonaisluku) {

    *kokonaisluku = *kokonaisluku * *kokonaisluku;
    }
