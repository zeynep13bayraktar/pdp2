#include "stdio.h"
#include "stdbool.h"
#include "../include/zaman.h"
#include "../include/gazDeviGezegen.h"
#include <stdlib.h>
#include <string.h>

void saatiIlerlet (Zaman* zaman, int gezegenGunlukSaat)
{
    zaman->saatIlerlet(zaman);

    if(zaman->saat>=gezegenGunlukSaat)
    {
        zaman->saat=0;
        zaman->gun++;
        ayYilGuncelle(zaman);
    }
}
void ayYilGuncelle(Zaman* zaman)
{
    int gunSayisi = getGunSayisi( zaman->ay, zaman-> yil);
}
int getGunSayisi(int ay, int yil)
{
    switch (ay) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return artikYilMi(yil) ? 29 : 28;
        default:
            return 0;  // geçersiz ay
    }
}
bool artikYilMi(int yil) 
{
    return (yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0);
}
bool esitMiDegilMi(Zaman* a, Zaman* b) //aracin kalkis tarihine gelmis miyiz kontrolumuz
{
    if(a->yil > b->yil) return true;
    if(a->yil < b->yil) return false;
    if(a->ay > b->ay) return true;
    if(a->ay < b->ay) return false;
    if(a->gun > b->gun) return true;
    if(a->gun < b->gun) return false;
    return true; //gun, ay ve yil esitse
}
Zaman* zaman_olustur(int gun, int ay, int yil) {
    Zaman* z = (Zaman*)malloc(sizeof(Zaman));
    if (!z) {
        perror("Zaman malloc hatası");
        exit(1);
    }
    z->gun = gun;
    z->ay = ay;
    z->yil = yil;
    z->saat = 0;              // Başlangıçta saat 0 olabilir
    z->saatIlerlet = NULL;    // Fonksiyon main programda atanıyor (setSaatIlerletFonksiyonu)
    return z;
}
char* zaman_toString(Zaman* z) {
    char* str = malloc(20); // Örnek: "dd.mm.yyyy" için yeterli
    if (str != NULL) {
        snprintf(str, 20, "%02d.%02d.%04d", z->gun, z->ay, z->yil);
    }
    return str;
}

