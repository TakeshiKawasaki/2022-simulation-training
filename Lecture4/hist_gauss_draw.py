#第3回自主課題 (3) 作図
import matplotlib
import matplotlib.pyplot as plt
%matplotlib inline
%config InlineBackend.figure_format = 'retina'
import matplotlib.cm as cm  # colormap
import numpy as np
import math
plt.rcParams["text.usetex"] =True 
fig = plt.figure(figsize=(8,8))

plt.subplot(111)
ax1 = fig.add_subplot(111)
x,hist= np.loadtxt("./Documents/GitHub/2022-simulation-training-main/Lecture4/hist_gauss.dat", comments='#', unpack=True)
plt.plot(x,hist, "-o" ,markersize=3,color=cm.jet(3/4),label=r"$P(X)$")
    
###Drawing a gaussian curve ######
x= np.linspace(-6, 6, 100) 
f= (2.*3.14)**(-0.5)*np.exp(-x**2./2.)
plt.plot(x,f, "--",markersize=3,linewidth = 2.0, color="k",label=r"$\frac{1}{\sqrt{2\pi}}e^{-X^2/2}$")
#########
plt.tick_params(which='major',width = 1, length = 10)
plt.tick_params(which='minor',width = 1, length = 5)
ax1.spines['top'].set_linewidth(3)
ax1.spines['bottom'].set_linewidth(3)
ax1.spines['left'].set_linewidth(3)
ax1.spines['right'].set_linewidth(3)
plt.xlabel(r"$X$",color='k', size=25)
plt.ylabel(r"$P(X)$",color='k', size=25)
plt.xticks(color='k', size=25)
plt.yticks(color='k', size=25)

plt.legend(ncol=1, loc=1, borderaxespad=0, fontsize=25,frameon=False)
#################################
plt.subplots_adjust(wspace=0.5, hspace=0.25)
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture4/hist_gauss.pdf')
plt.show()
