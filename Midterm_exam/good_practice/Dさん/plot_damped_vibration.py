import matplotlib
import matplotlib.pyplot as plt
import numpy as np
plt.rcParams["text.usetex"] =True 
fig = plt.figure(figsize=(14,14))
plt.subplots_adjust(wspace=0.5, hspace=0.5)

array=[0.1,1,2,3,10]
sub=[231,232,233,234,235]
for i in range(len(array)):
    ax = fig.add_subplot(sub[i])
    t,x,v=np.loadtxt("../spring_code/damped_vibration_tstd={:.1f}.txt".format(array[i]), comments='#', unpack=True)
    plt.plot(t,x,marker="o",linestyle="-",color="b",label="ts/td={:.1f}".format(array[i]),markersize =2)
    plt.legend(ncol=1, loc='upper right', borderaxespad=0, fontsize=15,frameon=False)
    plt.xlabel(r"$\tilde{t}$",color='k', size=0)
    plt.ylabel(r"$\tilde{x}$",color='k', size=20)
    ax.set_ylim(top=1)
plt.show()


