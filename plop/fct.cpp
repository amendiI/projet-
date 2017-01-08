#include "fct.h"
#include <iostream>

#include <Windows.h>//ne pas bouger!!!


//alea crée un nombre aleatoire en min et max ou entre 0 et n
int aleat(int min,int max)
{
   return (rand()%(max-min+1))+min;
}

int aleat(int n)
{
   return rand()%n;
}

void attendre(int n)
{
    Sleep(n);
}
