a=5
b=7
c=a+b
print(c)
d=a*b
print(d)
e=a**b
print(e)
f=a**0.5
print(f)

import numpy as np
g=np.sqrt(a)
print(g)
x=-4
h=np.abs(x)
print(h)
i=np.log2(10)
print(i)

q=np.ones([1,10])
print(q)

w=np.array([[1,2,3],[4,5,6],[7,8,9]])
print(w)

e=np.arange(1,11)
print(e)
f=np.arange(1,10.1)
print(f)

r=np.arange(1,102,5)
print(r)

t=5*np.ones([1,10])
print(t)

A=2*np.ones([1,10])
B=np.arange(1,11)
C=B**A
print(C)

D=np.array([[1,2],[8,5]])
print(D)
E=np.array([[3,6],[9,2]])
print(E)
F=D*E
print(F)
G=np.array([[21,10],[69,58]])
print(G)

SNRdB=np.arange(1,11)
print(SNRdB)

SNR=10**(SNRdB/10)
print(SNR)

print(SNR>5)

print(SNRdB<5)