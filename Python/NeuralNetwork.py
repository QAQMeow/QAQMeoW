import numpy as np
import matplotlib.pyplot as plt

def step_function(x):
    return np.array(x>0,dtype = np.int)

x = np.arange(-5,5,0.01)
y = step_function(x)


def sigmoid(x):
    return 1/(1+np.exp(-x))
    
def relu(x):
    return np.maximum(0,x)

def identity_function(x):
    return x


def softmax(x):
    c = np.max(x)
    exp_x = np.exp(x - c ) #溢出修正
    sum_exp_x = np.sum(exp_x)
    y = exp_x/sum_exp_x

    return y


y1 = sigmoid(x)
y2 = relu(x)

'''
plt.plot(x,y2)
plt.plot(x,y1) 
plt.plot(x,y)
plt.ylim(-0.1,1.1)
plt.show()
'''
X = np.array([1.0,0.5])
W1 = np.array([[0.1,0.3,0.5],[0.2,0.4,0.6]])
B1 = np.array([0.1,0.2,0.3])
A1 = np.dot(X,W1)+B1
Z1 = sigmoid(A1)
W2 = np.array([[0.1,0.4],[0.2,0.5],[0.3,0.6]])
B2 = np.array([0.1,0.2])
A2 = np.dot(Z1,W2)+B2
Z2 = sigmoid(A2)
W3 = np.array([[0.1,0.3],[0.2,0.4]])
B3 = np.array([0.1,0.2])
A3 = np.dot(Z2,W3)+B3
Y = identity_function(A3)


a = np.array([0.3,2.9,4.0])
Y2 = softmax(a)
print(Y2)

print(A1)
print(Z1)
print(A2)
print(Z2)


