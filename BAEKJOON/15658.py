def backtracking(cnt, operating_num):
    global max_v
    global min_v
    if cnt == N:
        # print(operating_num)
        max_v = max(max_v, operating_num)
        min_v = min(min_v, operating_num)
        return

    for i in range(len(operators_num)):
        if operators_num[i] > 0:
            operators_num[i] -= 1
            if i == 0:
                new_num = operating_num + nums[cnt]
            elif i == 1:
                new_num = operating_num - nums[cnt]
            elif i == 2:
                new_num = operating_num * nums[cnt]
            elif i == 3:
                new_num = int(operating_num / nums[cnt])
            backtracking(cnt+1, new_num)
            operators_num[i] += 1


N = int(input())
nums = list(map(int, input().split()))
operators_num = list(map(int, input().split()))

max_v = -1000000000
min_v = 1000000000


backtracking(1, nums[0])


print(max_v)
print(min_v)
