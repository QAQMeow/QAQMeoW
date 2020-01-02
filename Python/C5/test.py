import sys,os
sys.path.append(os.pardir)

from layer_naive import *

mal = MulLayer()
mol = MulLayer()
aaol = AddLayer()
mtl = MulLayer()

apple = 100
apple_num = 2
orange = 150
orange_num = 3
tax = 1.1

apple_price = mal.forward(apple,apple_num)
orange_price = mol.forward(orange,orange_num)
all_price = aaol.forward(apple_price,orange_price)
price = mtl.forward(all_price,tax)

dprice = 1

dall_price,dtax = mtl.backward(dprice)
dapple_price,dorange_prcie = aaol.backward(dall_price)
dorange,dorange_num = mol.backward(dorange_prcie)
dapple,dapple_num = mal.backward(dapple_price)

print(price)
print(dapple_price,dorange_prcie)
print(dapple_num,dapple,dorange_num,dorange,dtax)