import sys, os
sys.path.append(os.pardir)
from dataset.mnist import load_mnist
import numpy as np
from PIL import Image
import pickle
def get_data():

    (x_train,t_train),(x_test,t_test) = \
    load_mnist(normalize = True,flatten = True,one_hot_label = False)

    return x_test,t_test


def init_network():
    with open("/home/meowqaq/Python/ch03/sample_weight.pkl",'rb') as f:
        network = pickle.load(f)
    return network

def softmax(x):
    c = np.max(x)
    exp_x = np.exp(x - c ) #溢出修正
    sum_exp_x = np.sum(exp_x)
    y = exp_x/sum_exp_x

    return y
def sigmoid(x):
    return 1/(1+np.exp(-x))

def relu(x):
    return np.maximum(0,x)

def identity_function(x):
    return x

def predict(network,x):
    W1,W2,W3 = network['W1'],network['W2'],network['W3']
    b1,b2,b3 = network['b1'],network['b2'],network['b3']
    a1 = np.dot(x,W1)+b1
    z1 = sigmoid(a1)
    a2 = np.dot(z1,W2)+b2
    z2 = sigmoid(a2)
    a3 = np.dot(z2,W3)+b3
    y = softmax(a3)
    
    return y

x,t = get_data()
network = init_network()
accuracy_cnt = 0
accuracy_cnt2 = 0

for i in range(len(x)):
    y= predict(network,x[i])
    p = np.argmax(y)
    if p == t[i]:
        accuracy_cnt += 1
batch_size = 100
for i in range(0,len(x),batch_size):
    x_batch = x[i:i+batch_size]
    y_batch = predict(network,x_batch)
    p = np.argmax(y_batch,axis = 1)
    accuracy_cnt2 +=np.sum(p==t[i:i+batch_size])


print("Accuracy:"+str(float(accuracy_cnt2)/len(x)))

print("Accuracy:"+str(float(accuracy_cnt)/len(x)))
