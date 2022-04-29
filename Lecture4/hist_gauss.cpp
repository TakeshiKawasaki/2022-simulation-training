#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
#include "BM.h"

#define asize (int)1e5
#define hsize 1200
//using namespace std;

int histgram(double bin,double *array,double *hist){
  int i;
  char filename[128];
  std::ofstream file;
  sprintf(filename,"hist_gauss.dat");
  file.open(filename);
  for(i=0;i<hsize;i++)
    hist[i]=0;
  for(i=0;i<asize;i++)
    hist[(int)floor(array[i]/bin)+hsize/2]+=1.0/asize/bin;
  
  for(i=0;i<hsize;i++){
    file<<(i-hsize/2)*bin <<"\t"<< hist[i]<<std::endl;
    std::cout<<(i-hsize/2)*bin <<"\t"<< hist[i]<<std::endl;
  }
  return 0;
}

int main(){
  double array[asize],hist[hsize],bin=1.e-2;
  int i;
  for(i=0;i<asize;i++)
    array[i]=gaussian_rand();
  histgram(bin,array,hist);
  return 0;
}
