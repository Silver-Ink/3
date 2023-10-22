#include "../include/simPI.h"

/// @brief Simule PI avec n lancés de points sur un quart de cerlce sur la méthode de MC
/// @param n nombre de lancés
/// @return valeur hestimée de PI
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
    //printf("Simulation de PI : %1.10f\n", pi);
    return pi;
}

/// @brief Répète plusieur fois la fonction sim_pi, et calcule la moyenne
/// @param n nombre de points par fonctions simp_pi
/// @param nb_exp nombre de fonctions sim_pi
/// @return la moyenne de toutes les expériences
double moyenne_sim_pi(unsigned long n, int nb_exp)
{
    double somme_exp = 0;
    for (int i = 0; i < nb_exp; i++)
    {
        somme_exp += sim_pi(n);
    }
    
    double moyenne = somme_exp / (double)nb_exp;
    printf("moyenne de %d PI : %1.10f, erreur : %1.10f\n", nb_exp, moyenne, moyenne / M_PI);
    return moyenne;

}

/// @brief Répète plusieur fois la fonction sim_pi, et calcule la moyenne en donnant l'intervalle de confiance
/// @param n nombre de points par fonctions simp_pi
/// @param nb_exp nombre de fonctions sim_pi ( [2 - 60] par tranches de 10)
/// @param alpha précision de l'intervalle de confiance (0.05 ou 0.01)
/// @return la moyenne de toutes les expériences
double moyenne_sim_pi_conf(unsigned long n, int nb_exp, float alpha)
{
    if (nb_exp < 2 || nb_exp > 70) {printf("le nombre d'experiences doit être compris dans l'intervalle [2, 60]\n"); return -1;}


    int idx_student = nb_exp / 10;
    if (idx_student != 0)
    {
        printf("Calcul de %d experiences\n", idx_student * 10);
    }
    else
    {
        printf("Calcul de 2 experiences\n", idx_student * 10);
    }
    double somme_exp = 0; 
    //                         2     10      20     30     40     50     60 
    double student_large[7] = {4.303, 2.228, 2.086, 2.042, 2.021, 2.009, 2    }; // alpha = 0.05
    double student_small[7] = {9.925, 3.169, 2.845, 2.750, 2.704, 2.678, 2.660}; // alpha = 0.01
    double* resultats = (double*)malloc(sizeof(double)* nb_exp);

    for (int i = 0; i < nb_exp; i++)
    {
        resultats[i] = sim_pi(n);
        somme_exp += resultats[i];
    }
    
    double moyenne = somme_exp / (double)nb_exp;
    double s = 0;
    for (int i = 0; i < nb_exp; i++)
    {
        s += pow(resultats[i] - moyenne, 2);
    }
    s /= (double)(nb_exp - 1);

    double r;
    if (alpha >= 0.05)
    {
        r = student_large[idx_student] * sqrt(s / (double)nb_exp);
        printf("moyenne de %d PI : %1.10f, intervalle de confiance a 95%% [%1.10f, %1.10f]\n",
                nb_exp, moyenne, moyenne - r, moyenne + r);
    }
    else
    {
        r = student_small[idx_student] * sqrt(s / (double)nb_exp);
        printf("moyenne de %d PI : %1.10f, intervalle de confiance a 99%% [%1.10f, %1.10f]\n",
                nb_exp, moyenne, moyenne - r, moyenne + r);
    }

    free(resultats);
    return moyenne;
}
