#include "fct.h"

#include <stdio.h>
#include <stdlib.h>

//alea crée un nombre aleatoire en min et max ou entre 0 et n
int aleat(int min,int max)
{
   return (rand()%(max-min+1))+min;
}

int aleat(int n)
{
   return rand()%n;
}


bool est_dans_ecrant(int x,int y,int W,int H)
{
    if (x<0 ||y<0)
        return false;
    if(x>=W/5 || y>=H/5)
        return false;
    return true;
}
