import numpy as np
import numpy.random as nr
import matplotlib.pyplot as plt
from scipy.stats import norm

Blocklength=10000000
SNRdB=np.arange(1,14.1,1)
SNR = 10**(SNRdB/10)
BER=np.zeros(np.size(SNRdB))
sys=nr.randint(0,2,Blocklength) #signal
noise=nr.normal(0,1,Blocklength)
for k in range(SNRdB.size):
    TxBits=np.sqrt(SNR[k])*sys
    RxBits=TxBits+noise #signal+noise
    DecBits= RxBits>(np.sqrt(SNR[k]/2))
    BER[k]=BER[k]+np.sum(DecBits!=sys)#we want count no of false hence we use != to convert false to true 
BER=BER/Blocklength
plt.yscale('log')
plt.plot(SNRdB,BER,'g-')
plt.plot(SNRdB,1-norm.cdf(np.sqrt(SNR/2)),'ro')
plt.grid(2,which='both')
plt.suptitle('ASK BER with AWGN')
plt.xlabel('SNR(dB)')
plt.ylabel('BER')
plt.show()