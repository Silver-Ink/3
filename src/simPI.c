#include "../include/simPI.h"

double sim_pi(unsigned long n)
{
    double x;
    double y;
    unsigned long somme = 0;
    for (unsigned long i = 0; i < n; i++)
    {
        x = genrand_real1();
        y = genrand_real1();
        
        if (x*x + y*y < 1)
        {
            somme++;
        }
    }
    double pi = 4. * (double)somme / (double)n;
    printf("Simulation de PI : %f\n", pi);
    return pi;
}


double moyenne_sim_pi(unsigned long n, int nb_exp)
{
    double somme_exp = 0;
    for (int i = 0; i < nb_exp; i++)
    {
        somme_exp += sim_pi(n);
    }
    
    double moyenne = somme_exp / (double)nb_exp;
    printf("moyenne de %d PI : %f\n", nb_exp, moyenne);
    return moyenne;

}

double moyenne_sim_pi_conf(unsigned long n, int nb_exp)
{
    double student[29] = {4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.308, 2.262, 2.228, 2.201, 2.179, 2.160, 2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086, 2.080, 2.074, 2.064, 2.060, 2.056, 2.052, 2.048, 2.045, 2.042};
    double* resultats = (double*)malloc(sizeof(double)* nb_exp);

    for (int i = 0; i < nb_exp; i++)
    {
        resultats[i] = sim_pi(n);
    }
    
    double moyenne = somme_exp / (double)nb_exp;
    double s = 0;
    for (int i = 0; i < nb_exp; i++)
    {
        s += pow(resultats[i] - moyenne, 2);
    }
    s /= (nb_exp - 1);

    printf("moyenne de %d PI : %f\n", nb_exp, moyenne);

    free(resultats);
    return moyenne;
}