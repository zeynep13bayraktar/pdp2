#include "stdio.h"
#include "stdbool.h"
#include "../include/gazDeviGezegen.h"
#include "../include/zaman.h"
#include <stdlib.h>
#include <string.h>


void gazDeviSaatIlerleme(Zaman* zaman)
{
   zaman->saat+=0.1; 
}