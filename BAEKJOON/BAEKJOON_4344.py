count = input()
count = int(count)
for i in range(count):
    L = list(map(int, input().split()))
    sub_count = L.pop(0)
    score_total = 0
    for num in L:
        score_total += num
    score_avg = score_total  / sub_count
    total = 0
    for num in L:
        if num > score_avg:
            total += 1
    print("{0:.3f}".format(total / sub_count * 100)+"%")