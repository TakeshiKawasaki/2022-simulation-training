
#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for cout, etc
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc
#include "MT.h"// for MT

using namespace std;

char fname[128];
ofstream file;

#define d 1.0
#define l 1.0

void buffon(int n){
	int i, count = 0; //交わったらcountをインクリメント
	double y_s, x, y, sq_r, p, pi, error;
	double out = 1;
  	for(i=0;i<n;i++){
    	y_s = genrand_res53()*d/2;
    	do {
    	    x = genrand_res53();
    	    y = genrand_res53();
    	    sq_r = x*x + y*y;
    	} while (sq_r > 1);
    	
    	if(y_s*y_s <x*x/sq_r*l*l/4){
      		count++;
    	}
    	if(i>=(int)out){
    		p = (double)count/i;
    		pi = 2*l/(p*d);
    		error = abs(pi - M_PI);
    		// 針を投げた回数 線を踏む確率 見積もられる円周率 円周率の誤差 で出力
      		file<<setprecision(16)<<i<<" "<<p<<" "<<pi<<" "<<error<<endl;
      		cout<<setprecision(16)<<i<<" "<<p<<" "<<pi<<" "<<error<<endl;
      		out*=1.2;
      	}
    }
  }


int main(void){
	init_genrand(time(NULL));
	sprintf(fname,"buffon_l%.4fd%.4f.dat", l, d);
	file.open(fname);
	buffon((int)1.0e8);
	file.close();
  	return 0;
}