import matplotlib
import matplotlib.pyplot as plt
%matplotlib inline
%config InlineBackend.figure_format = 'retina'
import matplotlib.cm as cm  # colormap
import numpy as np
plt.rcParams["text.usetex"] =True 
fig = plt.figure(figsize=(8,8))

plt.subplot(111)
ax1 = fig.add_subplot(111)
symbol =['o-','D-','x-','>-']
dt=[0.0001,0.0010,0.0100,0.1000]


for i in range (0,4): 
    print(i,symbol[i],dt[i])  # for check on the arrays
    time,vel= np.loadtxt("./Documents/GitHub/2022-simulation-training-main/Lecture3/velo_{:.4f}.dat".format(dt[i]), comments='#', unpack=True)
    plt.plot(time,vel, "{}".format(symbol[i]) ,markersize=10,color=cm.jet(i/4),label=r"$\Delta t/t_0={}$".format(dt[i]))
    
plt.yscale('log')

###Drawing a line ######
time= np.linspace(1e-4, 4e1, 1000) 
vel= 10.*np.exp(-time)
plt.plot(time,vel, "--",markersize=3,linewidth = 2.0, color="k",label=r"$10\exp{(-t/t_0)}$")
#########

#図の書式設定
plt.tick_params(which='major',width = 1, length = 10)
plt.tick_params(which='minor',width = 1, length = 5)
ax1.spines['top'].set_linewidth(3)
ax1.spines['bottom'].set_linewidth(3)
ax1.spines['left'].set_linewidth(3)
ax1.spines['right'].set_linewidth(3)
plt.xlabel(r"$t/t_0(=\tilde{t})$",color='k', size=30)
plt.ylabel(r"$v(t)t_0/a(=\tilde{v}(t))$",color='k', size=30)
plt.xticks(color='k', size=25)
plt.yticks(color='k', size=25)
#図の凡例の有無や位置，サイズを調整
plt.legend(ncol=1, loc=1, borderaxespad=0, fontsize=25,frameon=False)
#################################
#各自ファイルのパスを変えること．
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture3/velo_dt.png')
plt.savefig('./Documents/GitHub/2022-simulation-training-main/Lecture3/velo_dt.pdf')
plt.show()
