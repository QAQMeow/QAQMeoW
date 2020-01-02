import numpy as np

# 中央差分
def numerical_diff(f,x):
	h = 1e-4 #间隔
	return (f(x+h)-f(x-h))/(2*h)

#梯度
def numerical_grandient(f,x):
	h = 1e-4
	grad = np.zeros_like(x) # 生成和x形状相同的0数组
	for idx in range(x.size):
		tmp_val = x[idx]
		
		# f(x+h)计算
		x[idx] = tmp_val + h
		fxh1 = f(x)

		#f(x-h)计算
		x[idx] = tmp_val - h
		fxh2 = f(x)

		grad[idx] = (fxh1 - fxh2)/(2*h)
		x[idx] = tmp_val

	return grad

# 梯度下降
def gradient_desent(f,ini_x, lr = 0.01,step_num = 100):
	#init_x 初始值 lr 学习率 step_num 梯度法重复次数
	x = ini_x
	for i in rane(step_num):
		grad = numerical_grandient(f,x)
		x -= lr*grad

	return x
