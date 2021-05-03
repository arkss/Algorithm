N = input()


nums = list(map(int, input().split()))

nums = sorted(nums)

total_score = 0

while len(nums) != 1:
    n1 = nums.pop()
    n2 = nums.pop()

    nums.append(n1+n2)
    total_score += n1*n2


print(total_score)
