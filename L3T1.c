#include <stdio.h>

int potenssiinLasku(int kokonaisluku, int potenssi);

int main(void) {

    int kokonaisluku;
    int potenssi;

    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");

    scanf("%d", &kokonaisluku);

    printf("Anna potenssi, jonka haluat laskea: ");
    scanf(" %d", &potenssi);

    int vastaus = potenssiinLasku(kokonaisluku, potenssi);
    printf("%d ^ %d = %d\n", kokonaisluku, potenssi, vastaus);
    printf("Kiitos ohjelman käytöstä.");
    return 0;
}

int potenssiinLasku(int kokonaisluku, int potenssi) {
    int vastaus = 1;

    for (int i = 0; i < potenssi; i++) {

        vastaus *= kokonaisluku;

    }

    return vastaus;
}