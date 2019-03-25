a=input().split()
n=int(a[0])
m=int(a[1])
k=int(a[2])
p=int(a[3])
x=int(a[4])
com=[]
min=101
minOran=1000000
index=-1
for i in range(n):
    a=input().split()
    #print(i)
    para=int(a[0])
    if(para>x):
        continue
    for j in range(m):
        #print(j,m,len(a))
        com.append(int(a[j+1]))
        if(com[j]<min):
            min=com[j]
    per=0
    for j in range(m):
        if com[j]>min+k:
            per+=min+k
        else:
            per+=com[j]
    if per>p:
        oran=float(para/per)
        if oran<minOran:
            minOran=oran
            index=i+1
if index==-1:
    print("-1")
else:
    print(index)
