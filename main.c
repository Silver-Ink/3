#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/mt19937ar.h"
#include "include/simPI.h"


int main()
{
   unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
   init_by_array(init, length);

   printf("simulation de PI : %f\n", sim_pi(1000));
   //Pour n = 1 000
   //simulation de PI : 3.124000
   //Pour n = 1 000 000
   //simulation de PI : 3.144760
   //Pour n = 1 000 000 000
   //simulation de PI : 3.141546

    return 0;
}