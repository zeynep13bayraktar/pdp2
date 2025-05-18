#include "stdio.h"
#include "stdbool.h"
#include "../include/cuceGezegen.h"
#include "../include/zaman.h"
#include <stdlib.h>
#include <string.h>


void cuceSaatIlerleme(Zaman* zaman)
{
   zaman->saat+=0.01; 
}