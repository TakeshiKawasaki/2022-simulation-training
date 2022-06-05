import matplotlib
import matplotlib.pyplot as plt
import numpy as np
plt.rcParams["text.usetex"] =True 
fig = plt.figure(figsize=(8,6))
plt.subplots_adjust(wspace=0.4, hspace=0)
ax1 = fig.add_subplot(211)
n, pi,error  = np.loadtxt("../../report_1/Buffon_code/buffon.txt", comments='#', unpack=True)
plt.plot(n,pi,marker="o",linestyle="-",color="b",label="buffon result")
x= np.linspace(1e4, 1e9, 100) 
y= np.pi+0*x
plt.plot(x,y,marker="None",linestyle="--",color="k",label=r"$\pi$")


plt.xscale('log')
plt.ylabel(r"$\pi(n)$",color='k', size=20)

plt.legend(ncol=1, loc='upper right', borderaxespad=0, fontsize=15,frameon=False)





ax2 = fig.add_subplot(212,sharex=ax1,)
error=[abs(x) for x in error]
plt.plot(n,error,marker="x",linestyle="-",color="g",label="buffon error")

plt.xscale('log')
plt.yscale('log')

x= np.linspace(1e2, 1e9, 100) 
y= 1/np.sqrt(x)
plt.plot(x,y,marker="None",linestyle="--",color="k",label=r"$1/ \sqrt{n}$")

plt.xlabel(r"$n$",color='k', size=20)
plt.ylabel(r"$|\delta(n)|$",color='k', size=20)

plt.legend(ncol=1, loc='upper right', borderaxespad=0, fontsize=15,frameon=False)


plt.show()

