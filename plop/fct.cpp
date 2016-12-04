#include "fct.h"
#include <iostream>


//alea crée un nombre aleatoire en min et max ou entre 0 et n
int aleat(int min,int max)
{
   return (rand()%(max-min+1))+min;
}

int aleat(int n)
{
   return rand()%n;
}

