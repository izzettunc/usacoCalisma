from collections import deque
import itertools
def floodfill(start,map,m,n,tepeler,adjM):
    guyruk = deque([])
    guyruk.append(start)
    ff=[]
    ff=reset(ff,m,n)
    ff[start[0]][start[1]]=0
    while(len(guyruk)>0):
        temp = guyruk.popleft()
        i=temp[0]
        j=temp[1]
        if i > 0 and ff[i][j] + 1 < ff[i-1][j] and map[i-1][j]!=-1:
            ff[i-1][j]=ff[i][j] + 1
            guyruk.append([i-1,j])
        if i < m-1 and ff[i][j] + 1 < ff[i+1][j] and map[i+1][j]!=-1:
            ff[i+1][j]=ff[i][j] + 1
            guyruk.append([i+1,j])
        if j > 0 and ff[i][j] + 1 < ff[i][j-1] and map[i][j-1]!=-1:
            ff[i][j-1]=ff[i][j] + 1
            guyruk.append([i,j-1])
        if j < n-1 and ff[i][j] + 1 < ff[i][j+1] and map[i][j+1]!=-1:
            ff[i][j+1]=ff[i][j] + 1
            guyruk.append([i,j+1])

    return createAdj(ff,adjM,tepeler,start)

def pathFlood(start,map,m,n,end):
    guyruk = deque([])
    guyruk.append(start)
    ff=[]
    yon=[['' for x in range(n)] for y in range(m)]
    ff=reset(ff,m,n)
    ff[start[0]][start[1]]=0
    while(len(guyruk)>0):
        temp = guyruk.popleft()
        i=temp[0]
        j=temp[1]
        if i > 0 and ff[i][j] + 1 < ff[i-1][j] and map[i-1][j]!=-1:
            ff[i-1][j]=ff[i][j] + 1
            yon[i-1][j]=yon[i][j]+'N'
            guyruk.append([i-1,j])
        if j < n-1 and ff[i][j] + 1 < ff[i][j+1] and map[i][j+1]!=-1:
            ff[i][j+1]=ff[i][j] + 1
            yon[i][j+1]=yon[i][j]+'E'
            guyruk.append([i,j+1])
        if j > 0 and ff[i][j] + 1 < ff[i][j-1] and map[i][j-1]!=-1:
            ff[i][j-1]=ff[i][j] + 1
            yon[i][j-1]=yon[i][j]+'W'
            guyruk.append([i,j-1])
        if i < m-1 and ff[i][j] + 1 < ff[i+1][j] and map[i+1][j]!=-1:
            ff[i+1][j]=ff[i][j] + 1
            yon[i+1][j]=yon[i][j]+'S'
            guyruk.append([i+1,j])
    return yon[end[0]][end[1]]

def createAdj(ff,adjM,tepeler,start):
    index=tepeler.index(start)
    for i in range(len(tepeler)):
        adjM[index][i]=ff[tepeler[i][0]][tepeler[i][1]]
    return adjM

def reset(arr,m,n):
    arr=[[0 for x in range(n)] for y in range(m)]
    for i in range(m):
        for j in range(n):
            arr[i][j]=500
    return arr

def absolute(x):
    if(x<0):
         return x*(-1)
    else:
        return x

line=input().split()
m=int(line[0])
n=int(line[1])
k=int(line[2])
start=[]
end=[]
map=[]
ff=[]
komsuluk=[]
yemekSay=0
yemekler=[]
tumtepeler=[]
for i in range(m):
    map.append([])
    ff.append([])
    t=input()
    for j in range(n):
        if t[j]=='-' or t[j]=='^':
            map[i].append(-1)
        elif t[j]=='*':
            map[i].append(0)
        elif t[j]=='B':
            map[i].append(0)
            start.append(i)
            start.append(j)
        elif t[j]=='E':
            map[i].append(0)
            end.append(i)
            end.append(j)
        else:
            yemekler.append([i,j])
            yemekSay+=1
            map[i].append(1)
        ff[i].append(500)

if k>0:
    for i in yemekler:
        tumtepeler.append(i)
    tumtepeler.append(start)
    tumtepeler.append(end)
    adjM=[[0 for x in range(yemekSay+2)] for y in range(yemekSay+2)]

    for i in range(yemekSay+2):
        adjM=floodfill(tumtepeler[i],map,m,n,tumtepeler,adjM)

    x=[i for i in range(yemekSay)]
    minYol=500
    cevapPer=0
    for i in itertools.permutations(x,k):
        temp=adjM[yemekSay][i[0]]
        for j in range(1,k):
            temp+=adjM[i[j-1]][i[j]]
        temp+=adjM[i[k-1]][yemekSay+1]
        if temp<minYol :
            minYol=temp
            cevapPer=i
    result=""
    result+=pathFlood(start,map,m,n,tumtepeler[cevapPer[0]])
    for i in range(0,len(cevapPer)-1):
        result+=pathFlood(tumtepeler[cevapPer[i]],map,m,n,tumtepeler[cevapPer[i+1]])
    result+=pathFlood(tumtepeler[cevapPer[len(cevapPer)-1]],map,m,n,end)
    print(result)
else:
    result=pathFlood(start,map,m,n,end)
    print(result)