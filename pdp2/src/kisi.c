#include "stdio.h"
#include "stdbool.h"
#include "../include/kisi.h"
#include <stdlib.h>
#include <string.h>
#include "../include/str.h"


bool hayattaMi(Kisi* kisi)
{
    return kisi->kalanOmur>0;
}
void omruAzalt(Kisi* kisi)
{
    if(hayattaMi(kisi))
    {
        kisi->kalanOmur--;
    }
}

Kisi* kisiOlustur(const char* isim, int yas, int kalanOmur, const char* aracAdi) {
    Kisi* yeniKisi = malloc(sizeof(Kisi));
    yeniKisi->isim = strdup(isim);
    yeniKisi->yas = yas;
    yeniKisi->kalanOmur = kalanOmur;
    yeniKisi->aracAdi = strdup(aracAdi);
    return yeniKisi;
}

void kisiYokEt(Kisi* kisi) {
    if (kisi == NULL) return;
    free(kisi->isim);
    free(kisi->aracAdi);
    free(kisi);
}