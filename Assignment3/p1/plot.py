#!/usr/bin/python

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

with open("data.dat") as f:
	data = f.readlines()
	x = [row.split(' ')[0] for row in data]
	y = [row.split(' ')[1] for row in data]

fig = plt.figure(1)
plot1 = fig.add_subplot(121)
plot1.set_xlabel('h = 10 ^ -k')
plot1.set_ylabel('Relative Error')
plot1.loglog(x,y, basex=2, basey=2, c='r')
plot1.set_title("Relative Error at x = 1")

plt.show()
plt.savefig('results')
plt.close(fig)
