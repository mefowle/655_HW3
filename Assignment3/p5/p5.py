import numpy as np
import matplotlib.pyplot as plt

with open("Filip") as f:
    data = f.readlines()
    x = [row.split(' ')[1] for row in data]
    y = [row.split(' ')[0] for row in data]

with open("Filip") as file:
    filip = [[float(digit) for digit in line.split()] for line in file]

A = np.zeros((82,11))
b = np.zeros((82, 1))

for i in range(82):
    for j in range(11):
        if j == 0:
            A[i][j] = 1
        if j == 1:
            A[i][j] = filip[i][1]
        if j == 2:
            A[i][j] = pow(filip[i][1],2)
        if j == 3:
            A[i][j] = pow(filip[i][1],3)
        if j == 4:
            A[i][j] = pow(filip[i][1],4)
        if j == 5:
            A[i][j] = pow(filip[i][1],5)
        if j == 6:
            A[i][j] = pow(filip[i][1],6)
        if j == 7:
            A[i][j] = pow(filip[i][1],7)
        if j == 8:
            A[i][j] = pow(filip[i][1],8)
        if j == 9:
            A[i][j] = pow(filip[i][1],9)
        if j == 10:
            A[i][j] = pow(filip[i][1],10)



result = np.linalg.lstsq(A, y)


plt.plot(x, y, 'o', label = 'Original data', markersize=10)
plt.legend()
plt.show()
