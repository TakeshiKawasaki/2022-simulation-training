#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for cout, etc
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream

using namespace std;
int damp(int b){ //b:=t_0/t_d
  int i=0, j=0;
  double v=1,x=0,dt=0.0001;
  char fname[128];
  ofstream file;
  sprintf(fname,"tyuukann2_%d.dat",b);
  file.open(fname);
  file<<setprecision(16)<<(double)i*dt<<" "<<x<<endl;
  cout<<setprecision(16)<<(double)i*dt<<" "<<x<<endl;
  for(i=1;i<=(int)(20/dt);i++){
    v=(1-b*dt)*v-x*dt;
    x=x+v*dt;
    j++;
    if(j==(int)(0.01/dt)){
      file<<setprecision(16)<<(double)i*dt<<" "<<x<<endl;
      cout<<setprecision(16)<<(double)i*dt<<" "<<x<<endl;
      j=0;
    }
  }
  file.close();
  return 0;
}

int main(){
  int b;
  for(b=1;b<=4;b*=2){
    damp(b);
  }
  return 0;
}
