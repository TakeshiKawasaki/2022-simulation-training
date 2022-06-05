#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for cout, etc
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc

using namespace std;
int main(void){
  int i, count = 0, max = 1e+8;
  double x,y,r,pi,ys,d=1.125,l=1, out=1.e+2;
  char fname[128];
  ofstream file;
  srand(time(NULL));
  sprintf(fname,"tyuukann1.dat");
  file.open(fname);
  for(i=1;i<=max;i++){
    ys = (double)rand()/RAND_MAX*d/2;
    do{
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      r = sqrt(x*x + y*y);
    }while(r>1 || r==0);
    if(ys<l/2*x/r){
      count++;
    }
    if(i>=(int)out){
      pi=2*l/(d*count /i);
      file<<setprecision(16)<<i<<" "<<pi<<" "<<abs(pi-M_PI)<<endl;
      cout<<setprecision(16)<<i<<" "<<pi<<" "<<abs(pi-M_PI)<<endl;
      out*=1.2;
    }
  }
  file.close();
  return 0;
}
