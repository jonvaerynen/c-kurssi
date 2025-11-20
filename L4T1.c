#include <stdio.h>
#include <string.h>
#define LENGTH 50

struct Kirja
{
    char Nimi[LENGTH];
    int painovuosi;
    int hyllypaikka;

};


int main(void) {

    struct Kirja book;

    printf("Anna kirjan nimi: ");
    fgets(book.Nimi, LENGTH, stdin);

    if (book.Nimi[strlen(book.Nimi) - 1] == '\n') {
        book.Nimi[strlen(book.Nimi) - 1] = '\0';
    }

    printf("Anna kirjan painovuosi: ");
    scanf(" %d", &book.painovuosi);

    printf("Anna kirjan hyllypaikka: ");
    scanf(" %d", &book.hyllypaikka);

    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", book.Nimi, book.painovuosi, book.hyllypaikka);
    printf("Kiitos ohjelman käytöstä.");



    return 0;
}