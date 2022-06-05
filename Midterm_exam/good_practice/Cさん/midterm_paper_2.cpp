#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cfloat>

//自主課題同様 v>DBL_EPSILON で行けるはず

//dt: 時間幅 T: パラメータ
int damped_vibration(double T, double dt){
    char fname[128];
    sprintf(fname, "dampingdata_%.2f_%.4f.dat",T, dt);//for文で繰り返して効率化したいので→ int main()参照
    std::ofstream file;
    file.open(fname);

    int i=0;
    double x0=0., v0=1., x1, v1, out=1.;
    while(abs(v0) > DBL_EPSILON){
        v1=(1-T*dt)*v0 - dt*x0;
        x1=(1-dt*dt)*x0 + (1-T*dt)*dt*v0;
        i++;
        //以下では要素数の制限を行う
        if((double)i >= out){
            file << (double)i*dt << " " << x1 << " " << v1 << std::endl;
            out*=1.2;
        }
        v0=v1;
        x0=x1;
    }

    file.close();
    return 0;
}

//減衰振動、過減衰、臨界減衰の3パターン(3kind of parameters) それぞれで、時間分解能1.e-4~1.e-2を行う
int main(){
    double dt, T;
    for(T=1.;T<=3.;T++){
        for(dt=1.e-4;dt<=1.e-2;dt*=10.)
        damped_vibration(T, dt);
    }
    return 0;
}
