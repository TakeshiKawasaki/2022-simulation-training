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
plt.plot(x, y)

ax.spines['top'].set_linewidth(2)
ax.spines['bottom'].set_linewidth(2)
ax.spines['left'].set_linewidth(2)
ax.spines['right'].set_linewidth(2)
plt.xlabel(r"$x$",color='k', size=30)
plt.ylabel(r"$y$",color='k', size=30)
plt.xticks(color='k', size=25)
plt.yticks(color='k', size=25)

ax.set_aspect('equal', adjustable='box')
#各自ファイルのパスを変えること．
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture1/coord.png')
