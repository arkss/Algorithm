import sys

input = sys.stdin.readline


def calcurate_budget(arr, max_budget):
    budget_sum = 0

    for budget in arr:
        budget_sum += min(budget, max_budget)

    return budget_sum


if __name__ == "__main__":
    N = int(input())

    arr = list(map(int, input().split()))

    total_budget = int(input())

    left = 0
    right = max(arr)
    answer = 0

    while left <= right:
        mid = (left+right) // 2

        budget_sum = calcurate_budget(arr, mid)

        if budget_sum <= total_budget:
            answer = max(answer, mid)
            left = mid+1
        elif budget_sum > total_budget:
            right = mid-1

    print(answer)
