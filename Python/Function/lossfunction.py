import numpy as np
 
#均方误差
def mean_squared_error(y,t):
	return 0.5*np.sum((y-t)**2)

#交叉熵误差
def corss_entroy_error(y,t):
	delta =1e-7 #保护值，防止-无穷
	return -np.sum(t*np.log(y+delta))