N = int(input())
five_count = N // 5
N %= 5
three_count = 0
while (five_count >= 0):
    if N % 3 == 0:
        three_count = N // 3
        break
        
    else:
        five_count -= 1
        N += 5
if N % 3 == 0:
    print(five_count + three_count)
else:
    print(-1) 