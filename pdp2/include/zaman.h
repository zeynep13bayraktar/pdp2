#ifndef ZAMAN_H
#define ZAMAN_H
#include <stdbool.h>

typedef struct Zaman{
int gun, ay, yil;
float saat;
void (*saatIlerlet)(struct Zaman*);
}Zaman;

void saatiIlerlet(Zaman* zaman, int gezegenGunlukSaat);
bool esitMiDegilMi(Zaman* a, Zaman* b);
void ayYilGuncelle(Zaman* zaman);
int getGunSayisi(int ay, int yil);
bool artikYilMi(int yil);
Zaman* zaman_olustur(int gun, int ay, int yil);
char* zaman_toString(Zaman* z);


#endif