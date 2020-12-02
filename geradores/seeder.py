from random import randint, seed
from math import gcd

def list_gcd (v):
    if(len(v) == 1):
        return v[0]
    return gcd(v[0], list_gcd(v[1:len(v)]))

def generateCasetest(maxV, qtd, seedValue):
    s = set()
    seed(qtd*seedValue)
    s.add(randint(2, qtd>>2))
    while(len(s) != qtd):
        s.add(randint(2, maxV))

    return list(s)

def writeCaseTestInFile(filename, v):
    f = open(filename, "w")
    f.write("{}\n".format(len(v)))
    for x in v:
        f.write("{}\n".format(x))

vbig = generateCasetest(2**31-1, 100, 1)
if(list_gcd(vbig) == 1):
    writeCaseTestInFile("caseTestBig100", vbig)

vbig = generateCasetest(2**31-1, 500, 1)
if(list_gcd(vbig) == 1):
    writeCaseTestInFile("caseTestBig500", vbig)

vbig = generateCasetest(2**31-1, 1000, 1)
#if(list_gcd(vbig) == 1):
writeCaseTestInFile("caseTestBig1k", vbig)

for x in range(1, 4):
    vhalf = generateCasetest(2**20-1, 100, x)
    if(list_gcd(vhalf) == 1):
        writeCaseTestInFile("caseTest{}AlmostBig{}".format(x, 100), vhalf)

for x in range(1, 4):
    vhalf = generateCasetest(2**20-1, 500, x)
    if(list_gcd(vhalf) == 1):
        writeCaseTestInFile("caseTest{}AlmostBig500".format(x), vhalf)

for x in range(1, 4):
    vhalf = generateCasetest(2**20-1, 1000, x)
    ## if(list_gcd(vhalf) == 1):
    writeCaseTestInFile("caseTest{}AlmostBig1k".format(x), vhalf)

vhalf = generateCasetest(2**15-1, 100, 1)
if(list_gcd(vhalf) == 1):
    writeCaseTestInFile("caseTestHalfBig100", vhalf)

vhalf = generateCasetest(2**15-1, 500, 1)
if(list_gcd(vhalf) == 1):
    writeCaseTestInFile("caseTestHalfBig500", vhalf)

vsmal = generateCasetest(2**10-1, 100, 1)
if(list_gcd(vsmal) == 1):
    writeCaseTestInFile("caseTestSmall100", vsmal)

vsmal2 = generateCasetest(2**10-1, 500, 1)
if(list_gcd(vsmal2) == 1):
    writeCaseTestInFile("caseTestSmall500", vsmal2)