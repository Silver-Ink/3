#include "../include/simPI.h"

double sim_pi(long n)
{
    double x;
    double y;
    long count = 0;
    for (long i = 0; i < n; i++)
    {
        x = genrand_real1();
        y = genrand_real1();
        
        if (x*x + y*y < 1)
        {
            count++;
        }
    }
    return 4. * (double)count / (double)n;
}