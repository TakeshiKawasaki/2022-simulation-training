from glob import glob
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import pathlib


def main():
    files = glob("*.txt")

    matplotlib.rcParams["figure.dpi"] = 1600
    ax = plt.subplot()
    for f in sorted(files):
        data = np.loadtxt(f)
        steps = np.arange(len(data))

        ax.plot(steps, data, label=pathlib.Path(f).stem)

    ax.set_xlabel("steps")
    ax.set_ylabel(r"$x$")
    ax.legend()
    plt.savefig("motion.png")


if __name__ == "__main__":
    main()
