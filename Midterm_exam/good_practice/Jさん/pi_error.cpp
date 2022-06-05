#include <stdio.h> // for printf, etc
#include <stdlib.h> // for rand(), etc
#include <math.h> // for sin(),cos(), etc
#include <iostream>// for cout, etc
#include <iomanip>// for setprecision()
#include <fstream> // for ifstream/ofstream
#include <time.h>// for time(NULL), etc
#include "MT.h"// for MT

using namespace std;

int calc(void)
{
    int i, count = 0;
    int max=1.e+8;
    double y, theta, pi, z, out = 1.e+2;
    char fname[128];
    ofstream file;
    srand(time(NULL));
    sprintf(fname, "pi-error.dat");
    file.open(fname);
    for (i = 0; i < max; i++) 
    {
        y = (double)rand() / RAND_MAX;
        theta = 0.5*M_PI*(double)rand() / RAND_MAX;
        z = 0.5*cos(theta);

        if (y < z)
            count++;
        if (i >= (int)out) 
        {
            pi = i / (double)count;//Ç±Ç±Ç™ñ êœî‰Ç…ëäìñ
            file << setprecision(16) << i << " " << pi << " " << abs(pi - M_PI) << endl;
            cout << setprecision(16) <<"i=" << i << " pi=" << pi << " delta=" << abs(pi - M_PI) << endl;
            out *= 1.2;
        }
    }
    file.close();

}

int main(void)
{
    calc();    

  return 0;
}

