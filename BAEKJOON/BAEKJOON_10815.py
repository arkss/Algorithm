N = int(input())
num_card = list(map(int,input().split()))
sorted_num_card = sorted(num_card)
M = int(input())

answer = list(map(int,input().split()))

for i in range(M):
    if answer[i] in num_card:
        answer[i] = 1
    else:
        answer[i] = 0

for i in answer:
    print(i,end=" ")