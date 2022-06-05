#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "MT.h"
using namespace std;

int main(){

  double i, count = 0, out = 1e+2;

  // number of trials
  int N = 1e+8;

  // set d>l
  double d = 5;
  double l = 4;

  // parametors
  double y_s, cos;

  // make cos
  double x, y, r;

  double pi, delta;

  char fname [128];
  ofstream file;
  sprintf(fname, "plot1_23.dat");
  file.open(fname);
  init_genrand(time(NULL));

  for(i = 0; i < N; i++){

    y_s = genrand_res53()*d/2;

    for( ; ; ){
      x = genrand_res53();
      y = genrand_res53();
      r = sqrt(x*x + y*y);
      if(r<=1){
        break;
      }
    };

    cos = x/r;

    if(l*cos/2 >= y_s){
      count++;
    };

    if(i >= out){
      pi = 2*l*i/(count*d);
      delta = abs(pi - M_PI);
      file<<setprecision(16)<<i<<" "<<pi<<" "<<delta<<endl;
      out*=1.01;
    }

  }

  file.close();

  cout<<setprecision(16)<<"pi = "<<pi<<" (for N = "<<N<<")"<<endl;

  return 0;
}