import sys, os
sys.path.append(os.pardir)# 引入 父目录
# 在父目录中引入
from Function.ActivationFunction import *
from Function.Gate import *
from Function.lossfunction import *
from Function.numerical import *

class SimpleNet:
	def __init__(self):
		self.W = np.random.randn(2,3) # 用高斯分布进行初始化

	def predict(self,x):
		return np.dot(x,self.W)

	def loss(self,x,t):
		z = self.predict(x)
		y = softmax(z)
		loss = corss_entropy_error(y,t)

		return loss