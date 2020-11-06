import time
import os
import sys

# import torch


PATHS = ["D:\\envs\\anaconda32002",
         "D:\\envs\\anaconda32002\\DLLs",
         "D:\\envs\\anaconda32002\\lib",
         "D:\\envs\\anaconda32002\\lib\\site-packages",
         "D:\\envs\\anaconda32002\\lib\\site-packages\\win32",
         "D:\\envs\\anaconda32002\\lib\\site-packages\\win32\\lib",
         "D:\\envs\\anaconda32002\\lib\\site-packages\\Pythonwin",
         # "C:\\Users\\admin\\AppData\\Local\\JetBrains\\PyCharm2020.2\\python_stubs\\1598182711",
         ]

for i, path in enumerate(PATHS):
    sys.path.insert(i, path)

import numpy as np
import SimpleITK
print(np.array([112]))

import torch
print([torch.randn(3, 224, 224), torch.randn(3, 400, 400)])
#
print("torch.cuda.is_available: ", torch.cuda.is_available())


def Test_add(a, b):
    for each in sys.path:
        print(each)
    # os.system("pip list")
    time.sleep(2)
    return a + b


if __name__ == "__main__":
    Test_add(1, 2)
