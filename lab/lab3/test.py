import random

X = range(1,1001)
Y = range(1000,0,-1)
X = random.sample(range(1, 1001), 1000)
Y = random.sample(range(1, 1001), 1000)
for x in X:
    print(x,end=' ')
print()
for y in Y:
    print(y,end=' ')
print()