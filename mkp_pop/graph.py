import pandas as ps
import matplotlib.pyplot as plt
import numpy as np

with open("C:/projects/Visual Studio Code/C_and_Cpp/laba_mkp/other/acceleration_data.txt", "r") as f:
    ACC = f.readlines()
    f.close()

solar_activity = [75, 100, 125, 150, 175, 200, 250]
S_acc = []
T_acc = []
W_acc = []
OV_acc = []
for i in ACC:
    S_acc.append(float(i.split(" ")[0]))
    T_acc.append(float(i.split(" ")[1]))
    W_acc.append(float(i.split(" ")[2]))
    OV_acc.append(float((i.split(" ")[3]).rstrip("\n")))

plt.style.use("ggplot")
figure, ax1 = plt.subplots()
figure2, ax2 = plt.subplots()


S_array = np.asarray(S_acc).T
T_array = np.asarray(T_acc).T
W_array = np.asarray(W_acc).T
OV_array = np.asarray(OV_acc).T

ax1.plot(solar_activity, S_array, color="orange", label="S", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(solar_activity, T_array, color="pink", label="T", alpha=1, marker="s", markerfacecolor="black", markersize=1)
ax1.plot(solar_activity, W_array, color="blue", label="W", alpha=1, marker="s", markerfacecolor="black", markersize=1)

ax1.legend(loc="lower right")


ax2.plot(solar_activity, OV_array, color="brown", label="Общее ускорение", alpha=1, marker="s", markerfacecolor="black", markersize=1)

ax2.legend(loc="lower right")


plt.show()