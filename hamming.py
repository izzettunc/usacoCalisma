"""
ID:hiy.1991
PROG:hamming
LANG:PYTHON3
"""
import itertools


def mesafe(list1, list2):
    sayac = 0
    for i in range(len(list1)):
        if list1[i] != list2[i]:
            sayac += 1
    return sayac


def btoi(dizi):
    length = len(dizi)
    power = 0
    sum = 0
    for i in range(length - 1, -1, -1):
        sum += pow(2, power) * dizi[i]
        power += 1
    return sum


sayilar = []
fi = open("hamming.in", "r")
string = fi.readline().split()
n = int(string[0])
b = int(string[1])
d = int(string[2])
for i in itertools.product([0, 1], repeat=b):
    sayilar.append(i)
t = len(sayilar)
isaretci = 0
while True:
    i = isaretci + 1
    while i < t:
        if mesafe(sayilar[isaretci], sayilar[i]) < d:
            sayilar.pop(i)
            t -= 1
            i -= 1
        i += 1
    isaretci += 1
    if isaretci == t:
        break
fo = open("hamming.out", "w")
for i in range(len(sayilar)):
    if i == n:
        break
    if ((i+1) % 10 != 0 or i == 0) and i != n - 1:
        fo.write(str(btoi(sayilar[i])) + " ")
    else:
        fo.write(str(btoi(sayilar[i])) + "\n")
