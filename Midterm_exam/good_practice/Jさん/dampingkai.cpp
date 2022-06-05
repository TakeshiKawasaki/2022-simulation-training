#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>
using namespace std;                                                                                                                                       

int position(int j){
  char filename[128];
  std::ofstream file;
  int i = 0;/* 横軸を数える変数*/
  double v = 1;/*初期測度*/
  double x = 0;/*初期位置*/
  double dt = 1e-4;/*時間間隔*/
  double e = 10;/*終了時間*/
  sprintf(filename,"position %d kaime.dat",j);
  file.open(filename);
  while (e > dt * i)
  {
      v = v - (double)j * v * dt - x * dt;
      x = x + v * dt;
    i++;
    file << (double)i * dt << " " << x << std::endl;
      std::cout << (double)i * dt << "  x=" << x << std::endl;
  }
  file.close();
  return 0;
}


int main(){
    /*j;試行回数を数える変数*/
    for (int j = 0; j < 5; j++)
    {
        position(j);
    }
  return 0;
}
