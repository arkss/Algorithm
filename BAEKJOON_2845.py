num, area = map(int,input().split())

list = list(map(int, input().split()))
for a in list:
    print(a - num*area, end=' ')


