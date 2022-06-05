import numpy as np
import japanize_matplotlib
import matplotlib.pyplot as plt

# 0.5 < 2: 減衰振動
#   8 > 2: 過減衰
#   2 = 2: 臨界減衰
t0_td_list = [0.5,8.0,2.0] 
label_list = ["減衰振動","過減衰　","臨界減衰"]

dt = 1e-5
t_max = 20
t_len = int(t_max/dt)
t_list = np.arange(t_len)*dt

for index, t0_td in enumerate(t0_td_list):
    x = np.zeros(t_len, dtype=float)
    v = np.zeros(t_len, dtype=float)

    for i,t in enumerate(t_list):
        if i == 0:
            x[i] = 0.0
            v[i] = 1.0
        else:
            v[i] = (1-t0_td*dt)*v[i-1]-dt*x[i-1]
            x[i] = x[i-1]+v[i]*dt
        
    plt.plot(t_list, x, label=label_list[index]+",t$_0$/t$_d$={:1.1f}".format(t0_td))
plt.title("溶媒中におけるバネで繋がれた物体の運動, $\Delta t=${:.1E}".format(dt))
plt.legend()
plt.xlabel("$t/t_0$")
plt.ylabel(r"$\tilde{x}(t/t_0)$")
plt.savefig("spring.pdf")
