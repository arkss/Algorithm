M = int(input())

score = list(map(int, input().split()))

max_score  = max(score)
total = 0
for i in score:
    total += i/max_score * 100
avg = total / M
print(avg)