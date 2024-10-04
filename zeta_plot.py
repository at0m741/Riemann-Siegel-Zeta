import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np


file_path = 'zeta.txt'
times = []
values = []

with open(file_path, 'r') as file:
    for line in file:
        if not line.strip():
            continue
        try:
            time, value = map(float, line.split())
            times.append(time)
            values.append(value)
        except ValueError:
            print(f"Bad format in line : {line}")

times = np.array(times)
values = np.array(values)

plt.figure(figsize=(12, 12))

sns.kdeplot(x=times, y=values, fill=True, cmap='viridis', thresh=0, levels=50, alpha=0.8)

plt.scatter(times, values, c=values, cmap='viridis', s=10, edgecolor='k', alpha=0.7)

plt.title('Non-trivial zeros of the Riemann zeta function')
plt.xlabel('Temps (t)')
plt.ylabel('Valeur (Z(t))')
plt.colorbar(label='Densité')
plt.grid(True)

plt.savefig('zeta_contours.png')

plt.show()

