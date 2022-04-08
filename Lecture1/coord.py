%matplotlib inline
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
#Texフォント
plt.rcParams["text.usetex"] =True 
fig = plt.figure(figsize=(7,7))
ax = fig.add_subplot(111)
#各自ファイルのパスを変えること．
x, y  = np.loadtxt("./Documents/GitHub/2022-simulation-training-main/Lecture1/coord100000.dat", comments='#', unpack=True)
plt.plot(x, y, "o",markersize=0.5,color="b",label=r"$x^2+y^2\leq1$")


plt.tick_params(which='major',width = 1, length = 10)
plt.tick_params(which='minor',width = 1, length = 5)
ax.spines['top'].set_linewidth(3)
ax.spines['bottom'].set_linewidth(3)
ax.spines['left'].set_linewidth(3)
ax.spines['right'].set_linewidth(3)
plt.xlabel(r"$x$",color='k', size=30)
plt.ylabel(r"$y$",color='k', size=30)
plt.xticks(color='k', size=25)
plt.yticks(color='k', size=25)

plt.legend(ncol=1, loc=1, borderaxespad=0, fontsize=25,frameon=True)

ax.set_aspect('equal', adjustable='box')
#各自ファイルのパスを変えること．
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture1/coord.png')
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture1/coord.pdf')
