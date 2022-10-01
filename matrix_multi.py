import numpy as np


A_2d = [[4,6,14],[6,14,36],[14,36,98]]
B_2d =  []
c = [[9],[16],[40]]
B_2d = np.linalg.inv(A_2d)
matmul_2D = np.matmul(B_2d, c)

print("A_2d: \n",c)
print("B_2d: \n",B_2d)

print("\nA_2d*B_2d = \n",matmul_2D)

#--------------------------------------




