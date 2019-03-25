cumle=str(input())
kuralsayisi=int(input())
alfabe=[chr(i) for i in range(ord('a'),ord('z')+1)]
alfabe.append(' ')
sifreler=[]
#print(alfabe)
for i in range(kuralsayisi):
    temp=[]
    line=input().split()
    temp.append(str(line[0]))
    temp.append(str(line[1]))
    sifreler.append(temp)
for i in range(kuralsayisi-1,-1,-1):
    for j in range(27):
        if alfabe[j]==sifreler[i][1]:
            alfabe[j]=sifreler[i][0]
#print(alfabe)
for i in range(len(cumle)):
    if cumle[i]!=' ':
        print(alfabe[ord(cumle[i])-97],end='')
    else:
        print(alfabe[26],end='')
