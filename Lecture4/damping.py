# 第3回自主課題(主計算)
# written in python
import numpy as np
import sys

def damp(dt):
    v=10. 
    i=0 
    out=1
    f = open("damp_dt_{:.4f}.dat".format(dt), 'w')
    while v> sys.float_info.epsilon: # numerical epsilon wherein  the "float" corresponds to the double in C 
        v -= v*dt
        i+=1.
        if(i>=out):
            print("{:.4f}  {:.20f}".format(i*dt, v))
            f.write("{:.4f}  {:.20f}\n".format(i*dt, v))
            out*=1.5
    f.close()

for k in range (0,4):
    print("dt={:.5f}".format(1.e-4*10**k))
    damp(1.e-4*10**k) 
