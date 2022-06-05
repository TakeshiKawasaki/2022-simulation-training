import matplotlib.pyplot as plt
import pandas as pn
import matplotlib.cm as cm


def draw(pos, a, dt, t_d, t_0):
    csv_path = 'pos_{:.2f}_{:.4f}_{:.2f}_{:.2f}.csv'.format(a, dt, t_d, t_0)
    position = int('22{}'.format(pos))
    plt.subplot(position)
    csv_input = pn.read_csv(csv_path, header=0)
    t = csv_input['t'].to_numpy(dtype=float)
    v = csv_input['v'].to_numpy(dtype=float)
    x = csv_input['x'].to_numpy(dtype=float)
    plt.plot(t, x, 'x-', ms=3, color=cm.jet(t_d), label=r'$t_s$ = {:.2}, $t_0$ = {:.2}'.format(t_d, t_0))
    plt.legend(loc=0, borderaxespad=0, fontsize=15)
    plt.xlabel(r'$t/t_0(=\tilde{t})$', fontsize=15)
    plt.ylabel(r'$x(t)/a(=\tilde{x}(t))$', fontsize=15)
    if t_d < t_0 / 4:
        plt.title('over damping', fontsize=20)
    elif t_d > t_0 /4:
        plt.title('under damping', fontsize=20)
    else:
        plt.title('critical damping', fontsize=20)


plt.rcParams['text.usetex'] = True
a = 10.
fig = plt.figure(figsize=(11.69, 8.27), tight_layout=True)
fig.suptitle('simulated position (a = {:.2f})'.format(a), fontsize=30)
dt = 1e-3
t_d = 0.1
t_0 = 1.
draw(1, a, dt, t_d, t_0)
t_d = 0.25
draw(2, a, dt, t_d, t_0)
t_d = 4.
draw(3, a, dt, t_d, t_0)

plt.show()
plt.savefig('plot_dampingEoM.png')
