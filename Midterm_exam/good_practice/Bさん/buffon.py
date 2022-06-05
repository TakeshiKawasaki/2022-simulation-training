import matplotlib.pyplot as plt
import numpy as np
import pandas as pn
import math

plt.rcParams['text.usetex'] = True
xrange = (1e2, 1e8)
yrange_1 = (2.5, 4)
yrange_2 = (1e-6, 1)
xtitle = 'Number of trials'

fig = plt.figure(figsize=(8.27, 11.69))
plt.subplots_adjust(hspace=0.3)
csv_path = 'calc_buffone.csv'
csv_input = pn.read_csv(csv_path, header=0)
n = csv_input['n_lim'].to_numpy(dtype=int)
pi = csv_input['pi'].to_numpy(dtype=float)
pi_error = csv_input['pi_error'].to_numpy(dtype=float)

ax1 = fig.add_subplot(211, xscale='log', xlim=xrange, ylim=yrange_1)
ax1.plot(n, pi, 'x-', ms=5, color="r", label=r'Calculated $\pi$')
ax1.plot(xrange, [math.pi, math.pi], '--', color='k', label='$\pi$')
ax1.legend(loc=0, borderaxespad=0, fontsize=15)
ax1.set_title(r'Calculate $\pi$ by buffon', fontsize=20)
ax1.set_xlabel(xtitle, fontsize=15)
ax1.set_ylabel('Calculated data', fontsize=15)
ax1.spines['top'].set_linewidth(1.5)
ax1.spines['bottom'].set_linewidth(1.5)
ax1.spines['left'].set_linewidth(1.5)
ax1.spines['right'].set_linewidth(1.5)

ax2 = fig.add_subplot(212, xscale='log', yscale='log', ylim=yrange_2)
ax2.plot(n, pi_error, '+-', ms=5, color='b', label='error')
x = np.linspace(100, int(1e8), int(1e3))
y = 1 / x ** 0.5
ax2.plot(x, y, '--', color='k', label=r'$\propto \frac{1}{\sqrt{n}}$')
ax2.legend(loc=0, borderaxespad=0, fontsize=15)
ax2.set_title(r'Error between calculate and $\pi$', fontsize=20)
ax2.set_xlabel(xtitle, fontsize=15)
ax2.set_ylabel('Error', fontsize=15)
ax2.spines['top'].set_linewidth(1.5)
ax2.spines['bottom'].set_linewidth(1.5)
ax2.spines['left'].set_linewidth(1.5)
ax2.spines['right'].set_linewidth(1.5)
plt.savefig('calc_buffon_plot.png')
