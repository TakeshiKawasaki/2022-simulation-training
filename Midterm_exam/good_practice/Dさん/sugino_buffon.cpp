#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for cout, etc
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc


const double l=1.0,d=1.0;

double get_cos_theta(){
    
    while(true){
        double x=(double)rand()/RAND_MAX;
        double y=(double)rand()/RAND_MAX;
        double r=sqrt(x*x+y*y);
        if(r<1){
            return x/r;
        }   
    }
}

double calc_buffon_no_hari(int num){
    srand(time(NULL));
    double ys_max=d/2;
    int count=0;
    for(int i=0;i<num;i++){
        double ys=(double)rand()/RAND_MAX*ys_max;
        double cos_theta=get_cos_theta();
        if(ys<l/2*cos_theta) 
            count++;
    }
    return (double)count/num;
}



int main(){
    char fname[128];
    std::ofstream file;
    sprintf(fname,"buffon.txt");
    file.open(fname);
    int max=1e+9;
    for(int i=0,n=0;n<max;i++){
        n=(int)pow(10,2+i*0.2);
        double value=2*l/(d*calc_buffon_no_hari(n));
        file<<std::setprecision(16)<<n<<" "<<value<<" "<<value - M_PI << std::endl;
        std::cout<<std::setprecision(5)<<n<<" "<<value<<std::endl;
    }
    file.close();
    return 0;
}

