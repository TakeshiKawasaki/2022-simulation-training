#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cfloat>

#define asize (int)3e4

const double t_delta=1e-3;


double v_next(double v_prev,double x_prev,double t_delta,double tstd){
    return (1-tstd*t_delta)*v_prev - x_prev*t_delta;
}

double x_next(double x_prev,double v_next,double t_delta){
    return x_prev + v_next * t_delta;
}

int calc_damped_vibration(double *x_array,double *v_array,double *t_array,double t_delta,double x_0,double v_0,double tstd){
    x_array[0]=x_0;
    v_array[0]=v_0;
    t_array[0]=0;
    for(int i=0;i<asize-1;i++){
        v_array[i+1]=v_next(v_array[i],x_array[i],t_delta,tstd);
        x_array[i+1]=x_next(x_array[i],v_array[i+1],t_delta);
        t_array[i+1]=t_array[i]+t_delta;
    }
    std::cout<<"a"<<std::endl;
    return 0;
}

int output_file(double *x_array,double *v_array,double *t_array,char *fname){
    std::ofstream file;
    file.open(fname);
    for(int i=0;i<asize;i++){
        file << t_array[i]<<" "<<x_array[i]<<" "<<v_array[i]<<std::endl;
    }
    file.close();
    return 0;
}


double x_array[asize],v_array[asize],t_array[asize];
int main(){
    double x_0=0.0, v_0=1.0 ;
    double tstd_list[]={0.1,1,2,3,10};
    
    char fname[128];
    for(int i=0;i<5;i++){
        double tstd=tstd_list[i];
        sprintf(fname,"damped_vibration_tstd=%.1f.txt",tstd_list[i]);
        calc_damped_vibration(x_array,v_array,t_array,t_delta,x_0,v_0,tstd);
        output_file(x_array,v_array,t_array,fname);
    }

    

    return 0;
}

