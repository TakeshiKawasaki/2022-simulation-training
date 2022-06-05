#include <stdio.h>
#include "MT.h"
#include <math.h>

/*Compute pi by buffon's needle problem
N is sample number (configurable)
Each 100 steps output computed pi
*/
int main(int argc, char const *argv[])
{
    init_genrand(3);
    int approved = 0, N = 1e8;
    double y, cos_theta, computed_pi;
    for (int i = 0; i <= N; i++)
    {
        y = genrand_real1();
        cos_theta = cos(genrand_real1() * M_PI);
        if (y <= cos_theta)
        {
            approved += 1;
        }
        // observation
        if (i >= 1e2 & i % 100 == 0)
        {
            int sample_number = i + 1;
            computed_pi = static_cast<double>(sample_number) / static_cast<double>(approved);
            printf("%i %.20f\n", sample_number, computed_pi);
        }
    }

    return 0;
}
