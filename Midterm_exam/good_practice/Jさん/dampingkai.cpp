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
  int i = 0;/* �����𐔂���ϐ�*/
  double v = 1;/*�������x*/
  double x = 0;/*�����ʒu*/
  double dt = 1e-4;/*���ԊԊu*/
  double e = 10;/*�I������*/
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
    /*j;���s�񐔂𐔂���ϐ�*/
    for (int j = 0; j < 5; j++)
    {
        position(j);
    }
  return 0;
}
