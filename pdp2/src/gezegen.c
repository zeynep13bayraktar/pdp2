#include "stdio.h"
#include "stdbool.h"
#include "../include/gezegen.h"
#include <stdlib.h>
#include <string.h>


void saatiIlerle(Gezegen* gezegen)
{
    if(gezegen && gezegen->zaman)
    {
        saatiIlerlet(gezegen->zaman, gezegen->gunlukSaat);
    }
}

Gezegen* gezegenOlustur(const char* isim, int gunlukSaat, Zaman* zaman)
{
    Gezegen* g = malloc(sizeof(Gezegen));
    g->isim = strdup(isim);
    g->gunlukSaat=gunlukSaat;
    g->zaman=zaman;
    g->yasayanlar=NULL;
    g->yasayanSayisi=0;
    return g;
}

void gezegenYokEt(Gezegen* gezegen)
{
    if(!gezegen)return;
    free(gezegen->isim);
    free(gezegen->yasayanlar);
    free(gezegen);
}