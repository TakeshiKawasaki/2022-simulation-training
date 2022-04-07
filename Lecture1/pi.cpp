#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;
int main(void){
  int i, count = 0, max = 1e+5;
  double x,y,z,pi;
  char fname[128];
  ofstream file;
  srand(time(NULL));

  sprintf(fname,"coord%d.dat",max);
  file.open(fname);
  for(i=0;i<max;i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    z = x*x + y*y;
    if(z<1){
      count++;
      file << x <<" "<<y <<endl;
    }
  }
    pi = (double)count / max * 4;
    printf("%.20f\n",pi); //by C, %.20f -- Display with 20 decimal precision                                                    
    cout<< std::setprecision(21)  <<  pi  << endl; // by C++ 
    return 0;
}

