#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H
#include "kisi.h"
#include "gezegen.h"
#include "uzayAraci.h"
#include "zaman.h"

Kisi** kisileriOku(const char* dosyaYolu, int* kisiSayisi);
Gezegen** gezegenleriOku(const char* dosyaYolu, int* gezegenSayisi);
UzayAraci** araclariOku(const char* dosyaYolu, int* aracSayisi);

#endif