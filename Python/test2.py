import sys, os
sys.path.append(os.pardir)
from dataset.mnist import load_mnist
import numpy as np
import matplotlib.pylab as plt
from PIL import Image
import pickle

def numerical_diff(f,x):
    h = 10e-5
    return (f(x+h)-f(x-h))/(2*h)

def func1(x):
    return 0.01*x**2+0.1*x

def func2(x):
    return x[0]**2+x[1]**2


def numerical_gradient(f,x):
    h = 1e-4
    grad = np.zeros_like(x)

    for idx in range(x.size):
        tmp_val = x[idx]
        
        x[idx] = tmp_val + h
        fxh1 = f(x)
        x[idx] = tmp_val - h
        fxh2 = f(x)

        grad[idx] = (fxh1 - fxh2)/(2*h)
        x[idx] = tmp_val

    return grad

def gradient_descent(f, init_x, lr = 0.01, step_num = 100):
    x = init_x

    for i in range(step_num):
        grad = numerical_gradient(f,x)
        x -= lr*grad

    return x

init_x = np.array([-3.0,4.0])

print(gradient_descent(func2,init_x,lr = 0.1,step_num = 100))

'''
plt.xlabel("x")
plt.ylabel("f(x)")
plt.plot(x,y)
plt.show()
'''
