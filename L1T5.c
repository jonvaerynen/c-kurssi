#include <stdio.h>

int main(void) {

    char etunimi[20];
    char sukunimi[20];
    int ika;
    float paino;

    printf("Anna etunimesi: ");
    scanf("%s", etunimi);

    printf("Anna sukunimesi: ");
    scanf("%s", sukunimi);

    printf("Anna ikasi: ");
    scanf("%d", &ika);

    printf("Anna painosi: ");
    scanf("%f", &paino);

    printf("Nimesi on %s %s, ikäsi on %d ja painat %.1f kg.\n", etunimi, sukunimi, ika, paino);


    return (0);
}