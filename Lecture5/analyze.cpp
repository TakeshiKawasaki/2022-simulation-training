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
#define twsize 52
#define dim 3
//using namespace std;

void ini(double *dr2,double *corr){
  for(int i=0;i<twsize;i++){
    dr2[i]=0.0;
    corr[i]=0.0;
  }
}
void input(double (*x)[ensemble*twsize],double (*v)[ensemble*twsize],double *t){
  char filename[128];
  std::ifstream file;
  sprintf(filename,"coord_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename);
  int asize=ensemble*twsize;
  for(int i=0;i<asize;i++){
    file >> t[i] >> x[0][i] >> x[1][i] >> x[2][i];
    std::cout << t[i] <<"\t"<<x[0][i]<<"\t"<<x[1][i]<<"\t"<<x[2][i]<<std::endl;
  }
  file.close();

  sprintf(filename,"vel_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename); 
  for(int i=0;i<asize;i++){
    file >> t[i] >> v[0][i] >> v[1][i] >> v[2][i];
    // std::cout << t[i] <<"\t"<<v[0][i]<<"\t"<<v[1][i]<<"\t"<<v[2][i]<<std::endl;
  }
  file.close();
  
}

void output(double *t,double *dr2,double *corr){
  char filename[128];
  std::ofstream file;
  sprintf(filename,"msd%.3fT%.3f.dat",dt,temp);
  file.open(filename);
  for(int i=0;i<twsize;i++)
    file<<t[i]-t[0]<<"\t"<<dr2[i]<<std::endl;
  file.close();

  sprintf(filename,"corr_dt%.3fT%.3f.dat",dt,temp);
  file.open(filename);
  for(int i=0;i<twsize;i++)
    file<<t[i]-t[0]<<"\t"<<corr[i]<<std::endl;
  file.close();
}

void analyze(double (*x)[ensemble*twsize],double (*v)[ensemble*twsize],double *t,double *dr2,double *corr){
  double dx[dim],corr_x[dim];
  for(int i=0;i<ensemble;i++)
    for(int j=0;j<twsize;j++){
      for(int k=0;k<dim;k++){
	dx[k]=(x[k][j+twsize*i]-x[k][twsize*i]); //k=0:x, k=1:y, k=2:z
	corr_x[k]=v[k][j+twsize*i]*v[k][twsize*i];
	dr2[j]+=(dx[k]*dx[k])/ensemble;
	corr[j]+=(corr_x[k])/ensemble;
      }
    }
}

int main(){
  double x[dim][ensemble*twsize],v[dim][ensemble*twsize],t[ensemble*twsize],dr2[twsize],corr[twsize];
  int i,j;
  ini(dr2,corr);
  input(x,v,t);
  analyze(x,v,t,dr2,corr);
  output(t,dr2,corr);
  return 0;
}
