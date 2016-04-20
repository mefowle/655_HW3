import numpy as np
import scipy.linalg as sc

with open("structure") as file:
    structure = [[float(digit) for digit in line.split()] for line in file]

with open("A") as file:
    A = [[float(digit) for digit in line.split()] for line in file]

with open("b") as file:
    b = [[float(digit) for digit in line.split()] for line in file]

c = np.linalg.solve(A,b)

P, L, U = sc.lu(structure)

np.savetxt("L", L, fmt='%.4f')
np.savetxt("U", U, fmt='%.4f')

#s is the singular value decomposition form
U, s, V = np.linalg.svd(structure, full_matrices=True)

#w is the eigenvalues
w, v = np.linalg.eig(A)

print np.amax(w)
print np.amin(w)



#PRINT ARRAY
#for row in A:
#    for val in row:
#        print '{:4}'.format(val),
#    print

#for row in b:
#    for val in row:
#        print '{:4}'.format(val),
#    print
