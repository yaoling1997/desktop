L= input().split()
n= int(L[0])
q= int(L[1])
a= []
ans= []
for i in range(n):
    a.append(0)
for tt in range(q):
    L= input().split()
    t= int(L[0])
    k= int(L[1])
    d= int(L[2])    
    sta= []
    for i in range(n):
        if (len(sta)>=k):
            break
        if (a[i]<=t):
            sta.append(i)
    if (len(sta)<k):
        ans.append(-1)
    else:
        sum= 0
        for x in sta:
            a[x]= t+d
            sum+= x+1
        ans.append(sum)
for x in ans:
    print(x)
