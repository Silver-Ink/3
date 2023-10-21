#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/mt19937ar.h"
#include "include/simPI.h"


int main()
{
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    //sim_pi(1000);
    //Pour n = 1 000
    //simulation de PI : 3.124000
    //Pour n = 1 000 000
    //simulation de PI : 3.144760
    //Pour n = 1 000 000 000
    //simulation de PI : 3.141546
    //moyenne_sim_pi(1000000000, 10);
    //Pour n = 1 000 000 000
    //simulation de 10 PI : 3.141563

    //moyenne_sim_pi_conf(1000000000, 30);
    // Pour n = 1 000 000 000
    // moyenne de 30 PI : 3.1415843373, intervalle de confiance á 95% [3.1415649339, 3.1416037408]
    return 0;
}