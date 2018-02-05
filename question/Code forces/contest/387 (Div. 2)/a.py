def solve():
    global a,b,n
    now= 1e9
    for i in range(1,n+1):
        if (n%i==0):
            if (i>n//i):
                break
            a= i
            b= n//i
            
n= int(input())
solve()
print(a,b)
