def solve(n,s):
    a= {"A":0,"G":0,"C":0,"T":0,"?":0}
    if (n%4):
        return 0;
    ave= n/4    
    for i in range(len(s)):
        a[s[i]]+= 1        
    t= "ACGT"
    for i in t:
        if (a[i]>ave):
            return 0;
    for i in range(len(s)):
        if (s[i]=='?'):
            for j in t:
                if (a[j]<ave):
                    a[j]+= 1
                    print(j,end="")
                    break
        else:
            print(s[i],end="")
    return 1

n= int(input())
s= input()
if (solve(n,s)):
    pass
else:
    print("="*3)    
