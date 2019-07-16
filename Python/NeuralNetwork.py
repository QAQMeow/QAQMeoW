import numpy as np
import matplotlib.pyplot as plt

def step_function(x):
    return np.array(x>0,dtype = np.int)

x = np.arange(-5,5,0.01)
y = step_function(x)


def sigmoid(x):
    return 1/(1+np.exp(-x))
    
y1 = sigmoid(x)


def relu(x):
    return np.maximum(0,x)

y2 = relu(x)
plt.plot(x,y2)
'''
plt.plot(x,y1) 
plt.plot(x,y)
'''
plt.ylim(-0.1,1.1)
plt.show()

