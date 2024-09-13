import numpy as np
from numpy.linalg import *
def mesure_dist(dims):
    tot = 0
    for i in range(100000):
        a, b = np.random.rand(dims), np.random.rand(dims)
        while norm(a, 2) > 1 and norm(b,2) > 1:
            a, b = np.random.rand(dims), np.random.rand(dims)
        tot += norm(a-b, 2)
    return tot / 100000

for i in range(2, 11):
    print(f"average distance for {i} dims: {mesure_dist(i)}")