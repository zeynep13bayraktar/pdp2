#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dosyaOkuma.h"
#include "../include/buzDeviGezegen.h"
#include "../include/cuceGezegen.h"
#include "../include/gazDeviGezegen.h"
#include "../include/kayacGezegen.h"
#include "../include/kisi.h"
#include "../include/zaman.h"
#include "../include/uzayAraci.h"



Kisi** kisileriOku(const char* dosyaYolu, int*kisiSayisi)
{
    FILE* dosya = fopen(dosyaYolu,"r");
    if(!dosya)
    {
        perror("kisiler dosyasi okunamadi:(");
        *kisiSayisi=0;
        return NULL;
    }
    Kisi** kisiler= NULL;
    *kisiSayisi=0;
    char satir[100];

    while(fgets(satir,sizeof(satir),dosya))
    {
        char* isim=strtok(satir,"#");
        char*yas_str=strtok(NULL,"#");
        char* omur_str=strtok(NULL,"#");
        char* arac=strtok(NULL,"#\n");

        if(isim&&yas_str&&omur_str&&arac)
        {
            kisiler=realloc(kisiler,(*kisiSayisi+1)*sizeof(Kisi*));
            kisiler[*kisiSayisi]=kisiOlustur(isim, atoi(yas_str),atoi(omur_str),arac);
            (*kisiSayisi)++;
        } 
        
    }

    fclose(dosya);
    return kisiler;
}

void setSaatIlerletFonksiyonu(Zaman* zaman, int turKod) {
    switch(turKod) {
        case 0:
            zaman->saatIlerlet = kayacSaatIlerleme;
            break;
        case 1:
            zaman->saatIlerlet = gazDeviSaatIlerleme;
            break;
        case 2:
            zaman->saatIlerlet = buzDeviSaatIlerleme;
            break;
        case 3:
            zaman->saatIlerlet = cuceSaatIlerleme;
            break;
        default:
            zaman->saatIlerlet = kayacSaatIlerleme;
    }
}

Gezegen** gezegenleriOku(const char* dosyaYolu, int* gezegenSayisi)
{
    FILE* dosya=fopen(dosyaYolu,"r");
    if(!dosya)
    {
        perror("gezegenler dosyasi okunamadi:<");
        *gezegenSayisi=0;
        return NULL;
    }
    Gezegen** gezegenler=NULL;
    gezegenSayisi=0;
    char satir[100];



    while(fgets(satir,sizeof(satir),dosya))
    {
        char* isim = strtok(satir,"#");
        char* gezegenTuru = strtok(NULL,"#");
        char* saat=strtok(NULL,"#");
        char* tarih=strtok(NULL,"#\n");

        int turKod = atoi(gezegenTuru);

        


        if(isim&&gezegenTuru&&saat&&tarih)
        {
            int gun, ay, yil;

            sscanf(tarih, "%d.%d.%d", &gun, &ay, &yil);
            Zaman* zaman = zaman_olustur(gun, ay, yil);
            gezegenler = realloc(gezegenler, (*gezegenSayisi + 1) * sizeof(Gezegen*));
            gezegenler[*gezegenSayisi] = gezegenOlustur(isim, atoi(saat), zaman);
            (*gezegenSayisi)++;

            int turKod = atoi(gezegenTuru);
            setSaatIlerletFonksiyonu(zaman, turKod);
            free(zaman);
            
        }
    }

    fclose(dosya);
    return gezegenler;

}

UzayAraci** araclariOku(const char* dosyaYolu, int* arac_sayisi) 
{
    FILE* dosya = fopen(dosyaYolu, "r");

    if (!dosya) 
    {
        perror("araclar dosyasi okunamadi:<");
        *arac_sayisi = 0;
        return NULL;
    }

    UzayAraci** araclar = NULL;
    *arac_sayisi = 0;
    char satir[100];

    while (fgets(satir, sizeof(satir), dosya)) 
    {
        char* ad = strtok(satir, "#");
        char* cikis = strtok(NULL, "#");
        char* varis = strtok(NULL, "#");
        char* tarih = strtok(NULL, "#");
        char* mesafe_str = strtok(NULL, "#\n");

        if (ad && cikis && varis && tarih && mesafe_str) 
        {
            int gun, ay, yil;
            sscanf(tarih, "%d.%d.%d", &gun, &ay, &yil);
            Zaman* z = zaman_olustur(gun, ay, yil);

            araclar = realloc(araclar, (*arac_sayisi + 1) * sizeof(UzayAraci*));
            araclar[*arac_sayisi] = uzayaraci_olustur(ad, cikis, varis, z, atoi(mesafe_str));
            (*arac_sayisi)++;
            free(z);
        }
    }

    fclose(dosya);
    return araclar;
}