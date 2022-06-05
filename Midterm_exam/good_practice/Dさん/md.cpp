#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>
#include <boost/format.hpp>

/*
Compute motion of particle connected with string in viscous fluid
*/
void md(double a, double t_0, double T, double dt, int N)
{
    // initialize
    double v = a / t_0;
    double x = 0.0;

    // Pre-computation of constant value
    double prefactor_v = (1 - T * dt);

    // Output
    const std::string filename = (boost::format("%.1lf") % T).str() + ".txt";
    std::ofstream outputfile(filename);

    // Compute motion
    for (int i = 0; i < N; i++)
    {
        v = prefactor_v * v - x * dt;
        x = x + v * dt;
        outputfile << x << "\n";
    }
    outputfile.close();
}

int main(int argc, char const *argv[])
{
    double a = 1;
    double t_0 = 1;
    double dt = 0.001;
    int N = 30000;
#pragma omp parallel sections
    {
#pragma omp section
        {
            md(a, t_0, 0.5, dt, N);
        }
#pragma omp section
        {
            md(a, t_0, 1.0, dt, N);
        }
#pragma omp section
        {
            md(a, t_0, 1.5, dt, N);
        }
#pragma omp section
        {
            md(a, t_0, 2.0, dt, N);
        }
#pragma omp section
        {
            md(a, t_0, 3.0, dt, N);
        }
#pragma omp section
        {
            md(a, t_0, 4.0, dt, N);
        }
    }
    return 0;
}
