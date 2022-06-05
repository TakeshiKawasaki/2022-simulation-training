#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <cfloat>

void damping(double a, double dt, double t_d, double t_0);

int main(){
    const double a = 10.;
    double dt = 1e-3, t_d = 0.25, t_0 = 1.0;
    damping(a, dt, t_d, t_0);
    t_d = 0.1;
    damping(a, dt, t_d, t_0);
    t_d = 4;
    damping(a, dt, t_d, t_0);
    return 0;
}

void damping(double a, double dt, double t_d, double t_0){
    char filename[128];
    std::ofstream file;
    int i = 0, div = (int)1/dt / 10;
    double v = a / t_0, x = 0.;
    sprintf(filename,"pos_%.2f_%.4f_%.2f_%.2f.csv", a, dt, t_d, t_0);
    file.open(filename);
    file << "t,v,x" << std::endl;
    file << (double)i*dt << "," << v << "," << x <<std::endl;
    std::cout << (double)i*dt << "," << v << "," << x <<std::endl;
    while(fabs(v) > 1e-4){
        v = v - (t_0/t_d)*dt*v - x*dt;
        x = x + v*dt;
        i++;
        if(i % div == 0){
            file << (double)i*dt << "," << v << "," << x <<std::endl;
            std::cout << (double)i*dt << "," << v << "," << x <<std::endl;
        }
  }
  file.close();
}