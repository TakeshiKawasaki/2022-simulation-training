#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

#define L 40.0
#define a 1.0
#define Np 512
#define Nn 100
#define dim 2
#define cut 5.0

void setmap(int (*list)[Nn],double (*x)[dim]){
  double dx,dy,dr2;
  
  for(int i=0;i<Np;i++)
    for(int j=0;j<Nn;j++)
      list[i][j]=0;
  
  for(int i=0;i<Np;i++){
    for(int j=0;j<Np;j++){
      if(j!=i){
	dx=x[i][0]-x[j][0];
	dy=x[i][1]-x[j][1];
	//	dx-=L*floor(dx/(0.5*L));
	//	dy-=L*floor(dy/(0.5*L));
	
	if(dx>0.5*L)
	  dx-=L;
	if(dx<-0.5*L)
	  dx+=L;
	if(dy>0.5*L)
	  dy-=L;
	if(dy<-0.5*L)
	  dy+=L;
	
	dr2=dx*dx+dy*dy;
	if(dr2<cut*cut){
	  list[i][0]++;
	  list[i][(int)list[i][0]]=j;
	}
      }
    }
  }
}

void ini_hex(double (*x)[dim]){
  int num_x = (int)sqrt(Np)+1;
  int num_y = (int)sqrt(Np)+1;
  int i,j,k=0;
  double shift;
  for(j=0;j<num_y;j++){
    for(i=0;i<num_x;i++){
      shift=(double)j*0.5-j/2;
      x[i+num_x*j][0] = (shift+i)*L/(double)num_x;
      x[i+num_x*j][1] = j*L/(double)num_y;
      k++;
      if(k==Np)
	break;
    }
  }
}


void output(int (*list)[Nn]){
  char filename[128];
  std::ofstream file;
  sprintf(filename,"list_L%.1fN%d.dat",L,Np);
  file.open(filename);
  
  for(int i=0;i<Np;i++){
    std::cout<<"i="<<i<<" Nn = "<< list[i][0]<<std::endl;
    file<<list[i][0]<<std::endl;
    for(int j=1;j<=list[i][0];j++){
      std::cout<< list[i][j]<<std::endl;
    }
  }
  file.close();
}

int main(){
  double  (*x)[dim] = new double[Np][dim];
  int  (*list)[Nn] = new int[Np][Nn];
  
  ini_hex(x);
  setmap(list,x);
  output(list);
  delete[] x;
  delete[] list;
  return 0;
}
