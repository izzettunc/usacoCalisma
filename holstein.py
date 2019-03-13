import itertools
fp2=open("holstein.in","r")
vCount=int(fp2.readline())
vList=[]
line=fp2.readline()
linee=line.split(" ")
for i in range(vCount):
    vList.append(int(linee[i]))
feedCount=int(fp2.readline())
feed=[]
for i in range(feedCount):
    line=fp2.readline()
    linee=line.split()
    temp=[]
    for i in range(vCount):
        temp.append(int(linee[i]))
    feed.append(temp)
combs=[]
for i in range(1,feedCount+1):
    for j in itertools.combinations(feed,i):
        #print(j)
        combs.append(j)
res=[]
for k in range(len(combs)):
    x=[0 for i in range(vCount)]
    counter=0
    for j in range(len(combs[k])):
        for i in range(vCount):
            #print(combs[k])
            x[i]+=combs[k][j][i]
    for i in range(vCount):
        if vList[i]<=x[i]:
            counter+=1
    #print(counter,x)
    if counter==vCount:
        res.append(combs[k])
for i in res:
    print(i)
