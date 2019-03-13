import itertools

def mesafe(list1,list2):
    sayac=0
    for i in range(len(list1)):
        if list1[i]!=list2[i] :
            sayac += 1
    return sayac

sayilar=[]
n=16
b=7
d=3
for i in itertools.product([0,1],repeat=b):
    sayilar.append(i)
t=len(sayilar)
isaretci=0
while True:
    i=isaretci+1
    while i<t:
        if mesafe(sayilar[isaretci],sayilar[i])<d :
            sayilar.pop(i)
            t-=1
        i+=1
    print(i,t,isaretci)
    if isaretci-1==t : break
    isaretci+=1

for i in range(len(sayilar)):
    print(sayilar[i])
