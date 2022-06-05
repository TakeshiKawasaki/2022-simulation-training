#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
//using namespace std;                                                                                                                                       

int damp(double dt, double tstd){
  char filename[128];
  std::ofstream file;
  int i=0;
  double v=1., x = 0, out=1.;
  double oldX, oldV;
  sprintf(filename,"damp_dt%.4f_tstd%.4f.dat", dt, tstd);
  file.open(filename);
  while(abs(v) > DBL_EPSILON || abs(x) > DBL_EPSILON){ //absをつけないと、不都合が生じる
  	//不要
  	//oldX = x;
  	//oldV = v;
  	
    v += -v*tstd*dt - x*dt;
    x += v*dt;
    i++;
    
    if((double)i >= out){
      file << (double)i*dt << "   " << x << "   " << v <<std::endl;
      std::cout << (double)i*dt << "   " << x  << "   " << v <<std::endl;
      out*=1.15; //*=1.3
      //out += 5000;
    }
  }
  file.close();
  return 0;
}


int main(){
  double dt = 1.e-4;
  damp(dt, 0.5);
  damp(dt, 1.0);
  damp(dt, 2.0);
  damp(dt, 3.0);
  damp(dt, 5.0);
  return 0;
}