#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
#include "BM.h"

void ini_array1(double *a){
  for(int i=0;i<10;i++)
    a[i]=i;
  
}
void ini_array2(double a[10]){
  for(int i=1;i<10;i++)
    a[i]=2*i;
  std::cout<< *(a+2)<<std::endl;
}

void ini_matrix1(double (*b)[10]){
  for(int i=0;i<1000;i++)
    for(int j=0;j<10;j++)
      b[i][j]=i*j;
}
void ini_matrix2(double b[1000][10]){
  for(int i=0;i<1000;i++)
    for(int j=0;j<10;j++)
      b[i][j]=i*j;
}

int main(){
  double a[10],b[1000][10];
  int i,j;
  double *x = new double;
  double *y = new double[10000]; 
  double (*z)[10] = new double[10000][10];
  
  ini_array1(a);
  ini_array2(a);
  ini_matrix1(b);
  ini_matrix2(b);

  delete x;
  delete [] y;
  delete [] z;
  
  //  for(int i=0;i<10;i++){
  //  a[i]=i;
  //  std::cout<<a[i]<<std::endl;
  // }
  
  //  for(int i=0;i<1000;i++)
  // for(int j=0;j<10;j++)
  //   std::cout<<b[i][j]<<std::endl;

  return 0;
}
