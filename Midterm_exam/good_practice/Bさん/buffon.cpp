#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <time.h>
#include "MT.h"

double calc_buffon(int n, double d, double l);

int main(){
    const double d = 2.0;
    const double l = 1.0;
    int n_lim = 100;
    std::ofstream outfile;
    std::string filename = "calc_buffone.csv";
    outfile.open(filename);
    outfile << "n_lim,pi,pi_error" << std::endl;
    double answer, pi, pi_error;
    while (n_lim <= (int)1e8)
    {
        answer = calc_buffon(n_lim, d, l);
        pi = 1 / answer;
        pi_error = fabs(pi - M_PI);
        outfile << n_lim << "," << std::setprecision(7) << pi << "," << std::setprecision(7) << pi_error << std::endl;
        std::cout << n_lim << "," << std::setprecision(7) << pi << "," << std::setprecision(7) << pi_error << std::endl;
        n_lim *= 1.2;
    }
    n_lim = (int)1e8;
    answer = calc_buffon(n_lim, d, l);
    pi = (2.0 * l) / (answer * d);
    pi_error = fabs(pi - M_PI);
    outfile << n_lim << "," << std::setprecision(7) << pi << "," << std::setprecision(7) << pi_error << std::endl;
    std::cout << n_lim << "," << std::setprecision(7) << pi << "," << std::setprecision(7) << pi_error << std::endl;
    outfile.close();
    return 0;
}

double calc_buffon(int n, double d, double l){
    int count = 0;
    init_genrand(time(NULL));
    for (int i = 0; i < n + 1; i++)
    {
        double y_s = d / 2 * genrand_res53();
        double theta = genrand_res53() / 2 * M_PI;
        if (l / 2 * cos(theta) > y_s)
        {
            count++;
        } 
    }
    double p = count / (double)n;
    return p;
}