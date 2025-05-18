#include "stdio.h"
#include "stdbool.h"
#include "../include/uzayAraci.h"
#include <stdlib.h>
#include <string.h>
#include "../include/gezegen.h"
#include "../include/str.h"
#include "../include/zaman.h"
#include "../include/kisi.h" 


void yolcuEkle(UzayAraci* a, Kisi k) {
    if (a->yolcuSayisi >= a->yolcuKapasite) {
        a->yolcuKapasite += 10;
        a->yolcular = realloc(a->yolcular, a->yolcuKapasite * sizeof(Kisi));
        if (a->yolcular == NULL) {
            perror("Yolcu bellek hatası");
            exit(1);
        }
    }
    a->yolcular[a->yolcuSayisi++] = k;
}
void varisaVardiMiVeYolculariIndir(UzayAraci* arac, Gezegen* varisGezegen) {
    if (!arac->imha && arac->kalanSaat == 0 && arac->yolcuSayisi > 0) {
        for (int i = 0; i < arac->yolcuSayisi; i++) {
            Kisi* k = &(arac->yolcular[i]);  // ← struct'ın adresi alınıyor
            if (hayattaMi(k)) {
                varisGezegen->yasayanlar[varisGezegen->yasayanSayisi++] = k; // struct kopyalanıyor
            }
        }

        arac->yolcuSayisi = 0; // Araçtan tüm yolcular indirildi
    }
}
void hareketEt(UzayAraci* arac, Gezegen* cikisGezegeni) {
    if (!arac->imha && arac->kalanSaat > 0) {
        if (esitMiDegilMi(cikisGezegeni->zaman, &arac->cikisTarihi)) {
            arac->kalanSaat--;
        }
    }
}
void kontrolEtImha(UzayAraci* a) {
    bool herkesOlmus = true;

    // Yolcu sayısı kadar dön
    for (int i = 0; i < a->yolcuSayisi; i++) {
        // Eğer yolculardan biri hayattaysa (kalanÖmür > 0)
        if (hayattaMi(&(a->yolcular[i]))) {
            herkesOlmus = false;
            break;  // Bir kişi bile hayattaysa, daha fazla aramaya gerek yok
        }
    }

    // Eğer herkes ölmüşse, imha işlemi yap
    if (herkesOlmus) {
        a->imha = true;
    }
}
void yolculariTemizle(UzayAraci* a) {
    a->yolcuSayisi = 0;
    // Belleği koruyabilirsin ya da realloc ile sıfırlayabilirsin.
}
int herkesOlmus(UzayAraci* a) {
    for (int i = 0; i < a->yolcuSayisi; i++) {
        if (hayattaMi(&a->yolcular[i])) return 0; // En az bir kişi yaşıyor
    }
    return 1; // Hepsi ölmüş
}
char* hesaplaVarisTarihi(Gezegen* varisGezegeni, Zaman* cikisTarihi, int mesafe) {
    Zaman* varis = zaman_olustur(cikisTarihi->gun, cikisTarihi->ay, cikisTarihi->yil);
    int gunlukSaat = varisGezegeni->gunlukSaat;
    int toplamSaat = mesafe;

    Gezegen tempGezegen = *varisGezegeni; // Diğer özellikleri kopyala
    tempGezegen.zaman = varis;

    for (int i = 0; i < mesafe; i++) {
        saatiIlerle(&tempGezegen);
    }

    char* varisTarihiStr = zaman_toString(varis);
    free(varis); // Bellek sızıntısı olmaması için
    
}

UzayAraci* uzayaraci_olustur(char* ad, char* cikis, char* varis, Zaman* zaman, int mesafe) {
    UzayAraci* a = (UzayAraci*)malloc(sizeof(UzayAraci));
    if (!a) {
        perror("Uzay Aracı malloc hatası");
        exit(1);
    }

    strncpy(a->ad, ad, MAX_STR);
    strncpy(a->cikisGezegen, cikis, MAX_STR);
    strncpy(a->varisGezegen, varis, MAX_STR);
    a->cikisTarihi = *zaman;
    a->mesafe = mesafe;
    a->kalanSaat = mesafe;
    a->imha = 0;

    a->yolcuSayisi = 0;
    a->yolcuKapasite = 10;
    a->yolcular = malloc(a->yolcuKapasite * sizeof(Kisi));
    if (!a->yolcular) {
        perror("Yolcu dizisi malloc hatası");
        free(a);
        exit(1);
    }

    // Tarih stringini oluştur
    char* tarihStr = zaman_toString(zaman);
    strncpy(a->varisTarihiStr, tarihStr, MAX_STR);
    free(tarihStr);
    
    tarihStr=NULL;
    

    return a;
}

void uzayAraciYokEt(UzayAraci* a) {
   
    free(a->yolcular); // Eğer malloc ile alındıysa

    free(a);
}