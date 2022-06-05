import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import sys

def main():
    filepath = sys.argv[1]
    sample_number, pi_computed = np.loadtxt(filepath, delimiter=" ", unpack=True)
    
    matplotlib.rcParams["figure.dpi"] = 1600
    fig, (ax1, ax2) = plt.subplots(nrows=2)
    # (1)
    ax1.set_title(r"Computed $\pi$")
    ax1.plot(sample_number, pi_computed)
    ax1.set_xscale("log")
    ax1.set_ylabel(r"$\pi$")
    ax1.set_xlabel("Sample number")
    
    # (2)
    diff = np.abs(pi_computed - np.pi)
    ax2.set_title(r"Absolute of Difference($|\Delta \pi|$) between computed pi and true value")
    ax2.plot(sample_number, diff, label=r"$|\Delta \pi|$")
    ax2.plot(sample_number, (1/np.sqrt(sample_number)), label=r"$\frac{1}{\sqrt{n}}$")
    ax2.set_yscale("log")
    ax2.set_xscale("log")
    ax2.set_ylabel(r"$|\Delta \pi|$")
    ax2.set_xlabel(r"Sample number $n$")
    ax2.legend()
    
    plt.tight_layout()
    plt.savefig("pi.png")

if __name__ == '__main__':
    main()
    