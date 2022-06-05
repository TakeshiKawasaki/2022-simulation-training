import numpy as np
import japanize_matplotlib
import matplotlib.pyplot as plt

d = 1.0
l = 0.5
MAX_SAMPLE = 10**8
n_plot = 50
np.random.seed(42)
theta = np.random.rand(MAX_SAMPLE)*(np.pi/2)
y_s = np.random.rand(MAX_SAMPLE)*(d/2)
n_sample_list = 10**np.linspace(2,8,n_plot)
ans_list = np.zeros(n_plot)

for i, n_sample in enumerate(n_sample_list):
    n_sample = int(n_sample)
    n_sample_list[i] = n_sample
    
    ans = np.sum(y_s[:n_sample] < (l/2)*np.cos(theta)[:n_sample])/n_sample
    ans_list[i] = 1/ans
    print("n",n_sample)
    print(1/ans-np.pi)
    print(1/ans)
# (2)について
plt.figure(figsize=(12,6))
plt.subplots_adjust(wspace=0.4, hspace=0.6)
plt.subplot(1,2,1)
plt.plot(n_sample_list, ans_list, marker="o", label="$\pi(n)$")
plt.title("Sample回数(n)と円周率$\pi(n)$の変化")
plt.xscale('log')
plt.xlabel("n")
plt.ylabel("$\pi(n)$")
plt.legend()

# (3)について
plt.subplot(1,2,2)
plt.plot(n_sample_list, np.abs(ans_list-np.pi), marker="o", label="$\delta(n)=|\pi(n)-\pi|$")
C = 1.0
plt.plot(n_sample_list, C/np.sqrt(n_sample_list),color="black",linestyle="dashed",label="$1.0/\sqrt{n}$")
plt.title("Sample回数(n)と円周率の誤差$\delta(n)=|\pi(n)-\pi|$")
plt.xscale('log')
plt.yscale('log')
plt.xlabel("n")
plt.ylabel("$\delta(n)$")
plt.legend()

plt.savefig("buffon.pdf")
