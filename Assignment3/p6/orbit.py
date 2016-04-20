import numpy as np
import matplotlib.pyplot as plt

with open("input") as file:
    orbit = [[float(digit) for digit in line.split()] for line in file]

A = np.zeros((10,5))
b = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
for i in range(10):
    for j in range(6):
        if j == 0:
            A[i][j] = orbit[1][i] * orbit[1][i]
        if j == 1:
            A[i][j] = orbit[0][i] * orbit[1][i]
        if j == 2:
            A[i][j] = orbit[0][i]
        if j == 3:
            A[i][j] = orbit[1][i]
        if j == 4:
            A[i][j] = 1
        if j == 5:
            b[i] = orbit[0][i] * orbit[0][i]


x = np.linalg.lstsq(A, b)

print x
