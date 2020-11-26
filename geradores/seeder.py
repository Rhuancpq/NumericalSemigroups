from random import randint, seed
from math import gcd

def list_gcd (v):
    if(len(v) == 1):
        return v[0]
    return gcd(v[0], list_gcd(v[1:len(v)]))

v1 = []
seed(100)
for x in range(100):
    v1.append(randint(2, 2**31-1))

print(list_gcd(v1))

f = open("caseTestBig", "w")
for x in v1:
    f.write("{}\n".format(x))

v2 = []
seed(50)
for x in range(100):
    v2.append(randint(2, 2**15-1))

print(list_gcd(v2))

f = open("caseTestHalfBig", "w")
for x in v2:
    f.write("{}\n".format(x))