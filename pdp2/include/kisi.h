#ifndef KISI_H
#define KISI_H
#include <stdbool.h>


typedef struct{
    char* isim;
    char* aracAdi;
    int yas, kalanOmur;
}Kisi;

bool hayattaMi(Kisi* kisi);
void omruAzalt(Kisi* kisi);
Kisi* kisiOlustur(const char* isim, int yas, int kalanOmur, const char* aracAdi);
void kisiYokEt(Kisi* kisi);
#endif