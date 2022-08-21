#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
#include "BM.h"

#define tmax 100
#define dt 0.01
#define mass 0.1
#define ensemble 1000
#define dim 2
//using namespace std;

void ini_phase(double *x,double *v){
  int i;
  for(i=0;i<dim;i++){
    x[i]=0.;
    v[i]=0.;
  }
}

void ini_clock(int *j,double *tout){
  *j=0;
  *tout=1.e-2;
}

void eom(double *v,double *x){
  for(int i=0;i<dim;i++){
    v[i]+=-v[i]*dt/mass + sqrt(2.*dt)*gaussian_rand()/mass;
    x[i]+=v[i]*dt;
  }
}

void output_traj(double *x,int j){
  char filename[128];
  std::ofstream file;
  sprintf(filename,"traj_mass%.3f.dat",mass);
  file.open(filename,std::ios::app); //append
  file <<j*dt<<"\t"<<x[0]<<"\t"<<x[1]<<std::endl;
  file.close();
}

void output(double *x,int j){
  char filename[128];
  std::ofstream file;
  sprintf(filename,"coord_mass%.3f.dat",mass);
  file.open(filename,std::ios::app); //append
  file <<j*dt<<"\t"<<x[0]<<"\t"<<x[1]<<std::endl;
  file.close();
}

int main(){
  double x[dim],v[dim],t,tout=0.;
  int i,j=0;

  while(j*dt < tmax){
    j++;
    eom(v,x);
    if(j*dt >= tout){
      output_traj(x,j);
      tout+=0.1;
    }
  }
  

  ini_phase(x,v);
  for(i=0;i<ensemble;i++){
    ini_clock(&j,&tout);
    output(x,j);
    while(j*dt < tmax){
      j++;
      eom(v,x);
      if(j*dt >= tout){
	output(x,j);
	tout*=1.2;
      }
    }
  }
  return 0;
}
