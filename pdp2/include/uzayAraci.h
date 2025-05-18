#ifndef uzayAraci_H
#define uzayAraci_H
#define MAX_STR 100000
#include "zaman.h"
#include "kisi.h"
#include "gezegen.h"

typedef struct{
    char ad[MAX_STR];
    char cikisGezegen[MAX_STR];
    char varisGezegen[MAX_STR];
    char varisTarihiStr[MAX_STR];
    Zaman cikisTarihi;
    int mesafe, kalanSaat, imha;
    Kisi* yolcular;
    int yolcuSayisi, yolcuKapasite;
}UzayAraci;

void yolcuEkle(UzayAraci* a, Kisi k);
void yolculariTemizle(UzayAraci* a);
int herkesOlmus(UzayAraci* a);
void kontrolEtImha(UzayAraci* a);
void hareketEt();
char* hesaplaVarisTarihi(Gezegen* varisGezegeni, Zaman* cikisTarihi, int mesafe);
void varisaVardiMiVeYolculariIndir(UzayAraci* arac, Gezegen* varisGezegen);
UzayAraci* uzayaraci_olustur(char* ad, char* cikis, char* varis, Zaman* zaman, int mesafe);
void uzayAraciYokEt(UzayAraci* a);

#endif 