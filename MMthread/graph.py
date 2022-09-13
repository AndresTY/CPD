import numpy as np
import matplotlib.pyplot as plt

f = open("filesTest.txt", "r")
aux = ""
for x in f:
    aux += x
f.close()
tests = aux.split('\n')[:-1]

x = [i for i in range(30)]

for i in tests:
    files = 'datasheet/'+i
    data = np.loadtxt(files, delimiter='\n').astype(int)
    plt.plot(x, data/60)
    plt.xlabel('Repeticiones')
    plt.ylabel('Min')
    plt.title('rendimiento '+i+' (min vs repeticiones)')
    plt.savefig(f'graficoM/{i[0:-4]}.png')
    plt.show()
