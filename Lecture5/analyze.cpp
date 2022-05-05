#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
#include "BM.h"

#define tmax 100
#define temp 1.
#define dt 0.01
#define ensemble 1000
#define dim 3
#define asize 52000 
#define wsize 52
//using namespace std;

void ini(double *dr2,double *corr){
  for(int i=0;i<wsize;i++){
    dr2[i]=0.0;
    corr[i]=0.0;
  }
}
void input(double (*x)[asize],double (*v)[asize],double *t){
  char filename[128];
  std::ifstream file;
  sprintf(filename,"coord_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename); 
  for(int i=0;i<asize;i++){
    file >> t[i] >> x[0][i] >> x[1][i] >> x[2][i];
    std::cout << t[i] <<"\t"<<x[0][i]<<"\t"<<x[1][i]<<"\t"<<x[2][i]<<std::endl;
  }
  file.close();

  
  sprintf(filename,"vel_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename); 
  for(int i=0;i<asize;i++){
    file >> t[i] >> v[0][i] >> v[1][i] >> v[2][i];
    std::cout << t[i] <<"\t"<<v[0][i]<<"\t"<<v[1][i]<<"\t"<<v[2][i]<<std::endl;
  }
  file.close();
  
}

void output(double *t,double *dr2,double *corr){
  char filename[128];
  std::ofstream file;
  sprintf(filename,"msd%.3fT%.3f.dat",dt,temp);
  file.open(filename);
  for(int i=0;i<wsize;i++)
    file<<t[i]-t[0]<<"\t"<<dr2[i]<<std::endl;
  file.close();

  sprintf(filename,"corr_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename);
  for(int i=0;i<wsize;i++)
    file<<t[i]-t[0]<<"\t"<<corr[i]<<std::endl;
  file.close();
}

void analyze(double (*x)[asize],double (*v)[asize],double *t,double *dr2,double *corr){
  double dx,dy,dz,corr_x,corr_y,corr_z;
  for(int i=0;i<ensemble;i++)
    for(int j=0;j<wsize;j++){
      dx=(x[0][j+wsize*i]-x[0][wsize*i]);
      dy=(x[1][j+wsize*i]-x[1][wsize*i]);
      dz=(x[2][j+wsize*i]-x[2][wsize*i]);
      corr_x=v[0][j+wsize*i]*v[0][wsize*i];
      corr_y=v[1][j+wsize*i]*v[1][wsize*i];
      corr_z=v[2][j+wsize*i]*v[2][wsize*i];
      dr2[j]+=(dx*dx+dy*dy+dz*dz)/ensemble;
      corr[j]+=(corr_x+corr_y+corr_z)/ensemble;
      std::cout<< v[0][j+wsize*i]  <<std::endl;
    }
}

int main(){
  double x[dim][asize],v[dim][asize],t[asize],dr2[wsize],corr[wsize];
  int i,j;
  ini(dr2,corr);
  input(x,v,t);
  analyze(x,v,t,dr2,corr);
  output(t,dr2,corr);
  return 0;
}
