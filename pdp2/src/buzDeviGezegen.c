#include "stdio.h"
#include "stdbool.h"
#include "../include/buzDeviGezegen.h"
#include "../include/zaman.h"
#include <stdlib.h>
#include <string.h>


void buzDeviSaatIlerleme(Zaman* zaman)
{
   zaman->saat+=0.5; 
}