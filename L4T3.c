#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Et antanut syötteitä.\n");
        printf("Kiitos ohjelman käytöstä.\n");
        return 0;
    }

    float luku_1 = atof(argv[1]);
    float luku_2 = atof(argv[3]);

    if (strcmp(argv[2], "+") == 0) {
        printf("%.1f + %.1f = %.2f\n", luku_1 , luku_2 ,luku_1 + luku_2);
    }
    else if (strcmp(argv[2], "-") == 0) {
        printf("%.1f - %.1f = %.2f\n", luku_1 , luku_2 ,luku_1 - luku_2);
    }
    else if (strcmp(argv[2], "/") == 0) {
        printf("%.1f / %.1f = %.2f\n", luku_1 , luku_2 ,luku_1 / luku_2);
    }
   else if (strcmp(argv[2], "x") == 0 || strcmp(argv[2], "*") == 0) {
        printf("%.1f x %.1f = %.2f\n", luku_1, luku_2, luku_1 * luku_2);
    }
    else
    printf("Virheellinen syöte.\n");


    printf("Kiitos ohjelman käytöstä.");

    return 0;
}