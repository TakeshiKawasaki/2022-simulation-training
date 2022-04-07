#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;
int main(void){
  int i, count = 0, max = 1e+7;
  double x,y,z,pi;
  srand(time(NULL));
  for(i=0;i<max;i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    z = x*x + y*y;
    if(z<1) count++; }
    pi = (double)count / max * 4;
    printf("%.20f¥n",pi); //by C, %.20f -- Display with 20 decimal precision                                                                           
    cout<< std::setprecision(21)  <<  pi  << endl; // by C++                                                
    return 0;
}
