#include <stdio.h> // for printf, etc                                                                                                                                       
#include <stdlib.h> // for rand(), etc                                                                                                                                      
#include <math.h> // for sin(),cos(), etc                                                                                                                                   
#include <iostream>// for cout, etc 
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream                                                                                                                                 
#include <time.h>// for time(NULL), etc           
#include "MT.h"// for MT

//コード引用元:
//第2回講義資料
//https://omitakahiro.github.io/random/random_variables_generation.html

using namespace std;
int main(void){
  int i, count = 0,max;
  std::cin >> max;
  double out;
  char fname[128];
  ofstream file;
  init_genrand((unsigned)time(NULL));
  if(max){
    for(i=0;i<max;i++){
		printf("%ld\n",genrand_int32());
      }}
  else{
    out = 4294967295;
    cout<< setprecision(15)  <<  out << endl;
    }
    return 0;
}
