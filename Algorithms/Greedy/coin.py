money = [500, 100, 50, 10, 1]
number = [1, 4, 8, 12, 50]
n = int(input())
for i in range(len(money)):
    cnt = 0
    while(n>=money[i] and cnt<number[i]):
        n-=money[i];
        cnt+=1
    print(f"{money[i]}->{cnt}")
    if(n==0):    break