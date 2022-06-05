#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

  double i;
  int j;

  // ratio r = t_s/t_d
  // 0 < r < 2 : underdamped, r = 2 : critically damped, r > 2 : overdamped
  // choose three appropriate parametes
  double r[3] = {1,2,3};

  // initial condition
  double x0 = 0, v0 = 1;

  // time step
  double dt = 0.0001;

  // time range 0 to t_e
  double t_e = 15;

  char fname [128];
  ofstream file;

  for(j=0; j<=2; j++){

    double x = x0, v = v0;

    sprintf(fname, "plot2_4_%.3f.dat",r[j]);
    file.open(fname);

    for(i = 0; i*dt <= t_e; i ++){

      file << i*dt << " " << x <<std::endl;

      v = (1 - r[j]*dt)*v - x*dt;
      x = x + v*dt;

    };

    file.close();

  };

  return 0;

}