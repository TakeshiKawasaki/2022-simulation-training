#include <stdio.h> // for printf, etc                                                                                                                                       
#include <stdlib.h> // for rand(), etc                                                                                                                                      
#include <math.h> // for sin(),cos(), etc                                                                                                                                   
#include <iostream>// for cout, etc 
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream                                                                                                                                 
#include <time.h>// for time(NULL), etc           
#include "MT.h"// for MT
//コード引用元:
//第2回講義資料
//https://omitakahiro.github.io/random/random_variables_generation.html
using namespace std;
int main(void){
  int i, count = 0,max;
  std::cin >> max;
  double x,y,z;
  char fname[128];
  ofstream file;
  srand(time(NULL));
  for(i=0;i<max;){
    x = genrand_real3();
    y = genrand_real3();
    z = x*x + y*y;
    if(z<1){
      cout<< setprecision(20)  <<  "A"  <<  x  <<  "B"  <<  y  <<  "C" << endl;
      i++;
    }      
  }                                                                            
    return 0;
}

