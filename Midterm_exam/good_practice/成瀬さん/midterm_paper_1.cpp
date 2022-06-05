//実習中で行ったランダム関数のpiを求めるものは、ランダムな0< <1の範囲のx, y によって作成すればよかった。
//今回の整理 棒をばら撒く回数: ランダム関数 → 同じように0< <1の範囲の数値になるようにし、係数をつけて計算する
//programingはあくまで数値計算, なので具体的に条件に合うようにlやdの数値も指定する
//つまるところ今回目指すのは0< <1のx, yを作り、d/2*x*pi/2*y <= l/2 となるものをカウントする
//→ fault piを使っているので不適切 数えるための条件(y_s-l/2*cos)を使ってカウント
//具体的にはy_s=d/2*x<=l/2*y を使う → yは一様乱数ではなくcos\theta のラジアンの乱数にせよ!
//piの値とpi-M_piの値をデータファイルへ書き出しする

//一応randomとMT両方のデータを取れるように作成しておく.

#include<iostream>
#include<iomanip>
#include<fstream>
#include<time.h>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include"MT.h"// for Mersenne Twister
//using namespace std;

int main(){
    int i, count=0, n=1e+8;
    double l=10., d=100.;//l,dの数値 (l<d)
    double x,y,z,rad, pi, out=1.e+2;
    char fname[128];
    //sprintf(fname, "midterm1_random_exam.dat");
    //srand(time(NULL)); //今回はMTで試行
    
    std::ofstream file;
    // file.open(fname);
    // //randver
    // for(i=0;i<n;i++){
    //     x=(double)rand()/RAND_MAX;
    //     y=(double)rand()/RAND_MAX;
    //     //使用するのは一様乱数ではなく角度の乱数!!
    //     //z=d*x-l*y: fault! piは4で収束するようになる→ 乱数の取り方が問題!
    //     //ラジアン変換
    //     rad=90*y/180*M_PI;//ラジアンの乱数をとるとの意味でM_PIを使用している(これは許容)
    //     //定性的な意図で陽に書く→ なるべく簡潔にしたほうがプログラミングではいいか
    //     z=d*x-l*cos(rad);
    //     if(z<=0.){
    //         count++;
    //     }
    //     if(i>=(int)out){
    //         pi=2*l/d*i/count;
    //         // i番目, pi, 誤差の3つを書き出し
    //         file<< std::setprecision(16) << i << " " << pi << " " << abs(pi-M_PI) << std::endl;
    //         out*=1.2;
    //     }
    // }
    // file.close();
    // std::cout << count << std::endl;

    // out=1.e+2;
    // count=0;
    sprintf(fname,"midterm1_MT.dat");
    file.open(fname);
    init_genrand(time(NULL));//MTのseed
    //MTver
    for(i=0;i<n;i++){
        //genrand_res53は一様実乱数[0,1)をreturn
        x=genrand_res53();
        y=genrand_res53();
        rad=90*y/180*M_PI;
        z=d*x-l*cos(rad);//関係演算子を使う際のdouble型を減らすためにあらかじめ計算
        if(z <= 0.){
            count++;
        }
        if(i>=(int)out){
            pi=2*(l/d)*((double)i/count);
            file<< std::setprecision(16) << i << " " << pi << " " << abs(pi-M_PI) << std::endl;
            out*=1.2;
        }
    }
    file.close();
    std::cout << count << std::endl;

    //ostreamではファイルクローズは自動的にしてくれる(が、random関数verも同時に行う時のために明示している)
    return 0;

}
