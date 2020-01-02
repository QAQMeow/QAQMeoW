import numpy as np
import matplotlib.pylab as plt

import sys, os
sys.path.append(os.pardir)# 引入 父目录
# 在父目录中引入
from TwoLayerNet import *
from SimpleNet import *

net1  = SimpleNet()
print(net1.W)

net2 = TwoLayerNet(input_size = 784,hidden_size = 100,output_size = 10)
print(net2.params['W1'].shape)

