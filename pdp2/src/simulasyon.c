#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/simulasyon.h"
#include "../include/dosyaOkuma.h"
#include "../include/gezegen.h"
#include "../include/uzayAraci.h"
#include "../include/kisi.h"
#include "../include/str.h"



Gezegen* gezegenByName(Gezegen** gezegenler, int gezegenSayisi, const char* ad) 
{
    for (int i = 0; i < gezegenSayisi; i++) 
    {
        if (strcmp(gezegenler[i]->isim, ad) == 0) return gezegenler[i];
    }
    return NULL;
}

void baslat(Simulasyon* sim) 
{
    int kisiSayisi = 0, gezegenSayisi = 0, aracSayisi = 0;
    Kisi** kisiler = kisileriOku("./doc/kisiler.txt", &kisiSayisi);
    Gezegen** gezegenler = gezegenleriOku("./doc/gezegenler.txt", &gezegenSayisi);
    UzayAraci** araclar = araclariOku("./doc/uzayAraclari.txt", &aracSayisi);

    // yolcu eşleştirme
    for (int i = 0; i < aracSayisi; i++) 
    {
        UzayAraci* a = araclar[i];
        for (int j = 0; j < kisiSayisi; j++) 
        {
            if (strcmp(kisiler[j]->aracAdi, a->ad) == 0) 
            {
                yolcuEkle(a, *kisiler[j]);
            }
        }
        Gezegen* varis = gezegenByName(gezegenler, gezegenSayisi, a->varisGezegen);
        char* varisStr = hesaplaVarisTarihi(varis, &a->cikisTarihi, a->mesafe);
        free(varisStr);
    }

    int tamamlandi = 0;
    while (!tamamlandi) 
    {
        for (int i = 0; i < gezegenSayisi; i++) 
        {
            saatiIlerle(gezegenler[i]);
        }
        for (int i = 0; i < kisiSayisi; i++) 
        {
            omruAzalt(kisiler[i]);
        }
        for (int i = 0; i < aracSayisi; i++) 
        {
            UzayAraci* a = araclar[i];
            if (!a->imha && a->kalanSaat > 0) 
            {
                Gezegen* c = gezegenByName(gezegenler, gezegenSayisi, a->cikisGezegen);
                hareketEt(a, c);
                kontrolEtImha(a);
            }
        }
        for (int i = 0; i < aracSayisi; i++) 
        {
            UzayAraci* a = araclar[i];
            Gezegen* v = gezegenByName(gezegenler, gezegenSayisi, a->varisGezegen);
            varisaVardiMiVeYolculariIndir(a, v);
        }

        printf("Gezegenler:\n\n");
        for (int i = 0; i < gezegenSayisi; i++) 
        {
            Gezegen* g = gezegenler[i];
            int nufus = 0;
            for (int j = 0; j < g->yasayanSayisi; j++) 
            {
                if (hayattaMi(g->yasayanlar[j])) nufus++;
            }
            for (int j = 0; j < aracSayisi; j++) 
            {
                UzayAraci* a = araclar[j];
                int hareketEttiMi = a->kalanSaat < a->mesafe;
                if (!hareketEttiMi && strcmp(a->cikisGezegen, g->isim) == 0) 
                {
                    for (int k = 0; k < a->yolcuSayisi; k++) 
                    {
                        if (hayattaMi(&a->yolcular[k])) nufus++;
                    }
                }
            }
            printf("Gezegen: %s | Nufus: %d\n", g->isim, nufus);
        }

        printf("\n*** UZAY ARACLARI ***\n");
        for (int i = 0; i < aracSayisi; i++) 
        {
            UzayAraci* a = araclar[i];
            char* durum = "YOLDA";
            if (a->imha) durum = "IMHA";
            else if (a->kalanSaat == a->mesafe) durum = "BEKLIYOR";
            else if (a->kalanSaat == 0) durum = "VARDI";

            char kalanSaatStr[10];
    if (a->imha)
        strcpy(kalanSaatStr, "--");
    else
        sprintf(kalanSaatStr, "%d", a->kalanSaat);

            printf("Arac: %s | Durum: %s | Hedef: %s | Kalan Saat: %s | Varis Tarihi: %s\n",
                   a->ad,
                   durum,
                   a->varisGezegen,
                   kalanSaatStr,
                   a->imha ? "--" : a->varisTarihiStr);
        }

        tamamlandi = 1;
        for (int i = 0; i < aracSayisi; i++) 
        {
            UzayAraci* a = araclar[i];
            if (!a->imha && !(a->kalanSaat == 0 && herkesOlmus(a))) 
            {
                tamamlandi = 0;
                break;
            }
        }

         
       
    }

    for (int i = 0; i < kisiSayisi; i++) {
        kisiYokEt(kisiler[i]);
    }
    free(kisiler);

    for (int i = 0; i < gezegenSayisi; i++) {
        gezegenYokEt(gezegenler[i]);
    }
    free(gezegenler);

    for (int i = 0; i < aracSayisi; i++) {
        uzayAraciYokEt(araclar[i]);
    }
    free(araclar);
}

int main()
{
    

    Simulasyon sim;
    baslat(&sim);
    
    return 0;
}