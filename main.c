/*

 _____  ___   _____                                           
/__   \/ _ \ |___ /                                           
  / /\/ /_)/   |_ \                                           
 / / / ___/   ___) |                                          
 \/  \/      |____/                                           
 __ _                 _       _   _                   _       
/ _(_)_ __ ___  _   _| | __ _| |_(_) ___  _ __     __| | ___  
\ \| | '_ ` _ \| | | | |/ _` | __| |/ _ \| '_ \   / _` |/ _ \ 
_\ | | | | | | | |_| | | (_| | |_| | (_) | | | | | (_| |  __/ 
\__|_|_| |_| |_|\__,_|_|\__,_|\__|_|\___/|_| |_|  \__,_|\___| 
                    _           ___           _               
  /\/\   ___  _ __ | |_ ___    / __\__ _ _ __| | ___          
 /    \ / _ \| '_ \| __/ _ \  / /  / _` | '__| |/ _ \         
/ /\/\ | (_) | | | | ||  __/ / /__| (_| | |  | | (_) |        
\/    \/\___/|_| |_|\__\___| \____/\__,_|_|  |_|\___/         
  ___      _____       _                       _ _            
 ( _ )     \_   \_ __ | |_ ___ _ ____   ____ _| | | ___ ___   
 / _ \/\    / /\| '_ \| __/ _ | '__\ \ / / _` | | |/ _ / __|  
| (_>  < /\/ /_ | | | | ||  __| |   \ V | (_| | | |  __\__ \  
 \___/\/ \____/ |_| |_|\__\___|_|    \_/ \__,_|_|_|\___|___/  
      _                         __ _                          
   __| | ___    ___ ___  _ __  / _(_) __ _ _ __   ___ ___     
  / _` |/ _ \  / __/ _ \| '_ \| |_| |/ _` | '_ \ / __/ _ \    
 | (_| |  __/ | (_| (_) | | | |  _| | (_| | | | | (_|  __/    
  \__,_|\___|  \___\___/|_| |_|_| |_|\__,_|_| |_|\___\___|    

patorjk.com/software/taag/#p=display&f=Ogre                                                     
*/


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


    // moyenne_sim_pi(1000, 10);
    // moyenne de 10 PI : 3.1480000000, erreur : 1.0020395217
    // moyenne_sim_pi(1000000, 10);
    // moyenne de 10 PI : 3.1412544000, erreur : 0.9998923305
    // moyenne_sim_pi(1000000000, 10);
    // moyenne de 10 PI : 3.1415643560, erreur : 0.9999909926


    // moyenne_sim_pi_conf(1000, 30, 0.05);
    // moyenne de 30 PI : 3.1397333333, intervalle de confiance a 95% [3.1230125548, 3.1564541118]
    // moyenne_sim_pi_conf(1000000, 30, 0.05);
    // moyenne de 30 PI : 3.1411472000, intervalle de confiance a 95% [3.1405342225, 3.1417601775]
    // moyenne_sim_pi_conf(1000000000, 30, 0.05);
    // Pour n = 1 000 000 000
    // moyenne de 30 PI : 3.1415843373, intervalle de confiance á 95% [3.1415649339, 3.1416037408]

    // moyenne_sim_pi_conf(1000, 30, 0.01);
    // moyenne de 30 PI : 3.1397333333, intervalle de confiance a 99% [3.1172151449, 3.1622515218]
    // moyenne_sim_pi_conf(1000000, 30, 0.01);
    // moyenne de 30 PI : 3.1411472000, intervalle de confiance a 99% [3.1403216916, 3.1419727084]
    // moyenne_sim_pi_conf(1000000000, 30, 0.01);
    // moyenne de 30 PI : 3.1415843373, intervalle de confiance a 99% [3.1415582064, 3.1416104683]

    // moyenne_sim_pi_conf(1000, 60, 0.05);
    // moyenne de 60 PI : 3.1422666667, intervalle de confiance a 95% [3.1294156853, 3.1551176480]
    // moyenne_sim_pi_conf(1000000, 60, 0.05);
    // moyenne de 60 PI : 3.1409808000, intervalle de confiance a 95% [3.1405372495, 3.1414243505]
    // moyenne_sim_pi_conf(1000000000, 60, 0.05);
    // moyenne de 60 PI : 3.1415861654, intervalle de confiance a 95% [3.1415726300, 3.1415997008]

    // moyenne_sim_pi_conf(1000, 60, 0.01);
    // moyenne de 60 PI : 3.1422666667, intervalle de confiance a 99% [3.1251748615, 3.1593584718]
    // moyenne_sim_pi_conf(1000000, 60, 0.01);
    // moyenne de 60 PI : 3.1409808000, intervalle de confiance a 99% [3.1403908778, 3.1415707222]
    // moyenne_sim_pi_conf(1000000000, 60, 0.01);
    // moyenne de 60 PI : 3.1415861654, intervalle de confiance a 99% [3.1415681633, 3.1416041675]

    prompt_pi();
    return 0;
}