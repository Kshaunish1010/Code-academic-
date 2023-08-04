import numpy as np
import matplotlib.pyplot as plt
import numpy.random as nr

fc=1000
T=2/fc
def pl(t):
    return np.cos(2*3.14*fc*t)*(abs(t)<1/fc)
t=np.arange(-10/fc,50/fc,0.01/fc)
plt.plot(t,pl(t))
plt.show()

A=2*nr.randint(0,2,10)-1
print(A)
for k in range(len(A)):
     C=A[k]*pl(t-1/fc*k)
     plt.plot(t,C)
plt.show()
B=nr.randint(0,2,10)
E=(B-1)*(-1)
print(B)
for k in range(len(E)):
    D=E[k]*pl(t-2/fc*k)
    plt.plot(t,D)
plt.show()