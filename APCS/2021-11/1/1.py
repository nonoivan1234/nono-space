n = int(input())
l = list(map(int, input().split()))
ans = 0
for i in range (n):
    if (l[i]==0):
        if (i==0):   
            ans+=l[i+1]
        elif(i==n-1):    
            ans+=l[i-1]
        else:
            ans+=min(l[i-1], l[i+1])
print(ans)