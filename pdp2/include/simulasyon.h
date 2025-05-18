#ifndef SIMULASYON_H
#define SIMULASYON_H
#include "uzayAraci.h"
#include "kisi.h"
#include "gezegen.h"

typedef struct{
    Kisi* kisiler;
    Gezegen* gezegenler;
    int kisiSayisi;
    int aracSayisi;
    int gezegenSayisi;
}Simulasyon;


void baslat(Simulasyon* sim);

#endif