#ifndef GEZEGEN_H
#define GEZEGEN_H 
#include "zaman.h"
#include "kisi.h"

typedef struct{
char* isim;
int gunlukSaat;
Zaman* zaman;
Kisi** yasayanlar;
int yasayanSayisi;
}Gezegen;

void saatiIlerle(Gezegen* gezegen);
Gezegen* gezegenOlustur(const char* isim, int gunlukSaat, Zaman* zaman);
void gezegenYokEt();

#endif