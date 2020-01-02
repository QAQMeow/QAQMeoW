import numpy as np


#阶跃函数 
def step_function(x):
	y = x > 0
	return y.astype(np.int)

#sigmoid函数
def sigmoid(x):
	return 1/(1.0+np.exp(-x))

#ReLU函数
def relu(x):
	return np.maximum(0,x)

#softmax函数
def softmax(x):
	c = np.max(x)
	exp_x = np.exp(x-c)
	sum_exp_x = np.sum(exp_x)
	y = exp_x/sum_exp_x
	return y
