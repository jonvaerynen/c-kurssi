#ifndef L7T2_LISTA_H
#define L7T2_LISTA_H
#include <stdio.h>


void varaaMuisti();
void tulostus();
void vapautaMuisti();
void lisaaAlkio();
void lisaaKeskelle();
void poistaAlkio();


typedef struct Lista
{
    int taulukko;
    struct Lista *next;
} Lista;

extern Lista* ptrAlku;
extern Lista* ptrLoppu;
extern int seuraavaNumero;


#endif