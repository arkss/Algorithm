n = int(input())

liquids = list(map(int, input().split()))

liquids.sort()

start = ans_s = 0
end = ans_e = n-1

while start < end:
    if abs(liquids[start] + liquids[end]) < abs(liquids[ans_s] + liquids[ans_e]):
        ans_s = start
        ans_e = end

    if (liquids[start] + liquids[end]) < 0:
        start += 1
    else:
        end -= 1

print(liquids[ans_s], liquids[ans_e])

