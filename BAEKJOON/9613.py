import sys

input = sys.stdin.readline


def cal_gcd(n1, n2):
    n1, n2 = max(n1, n2), min(n1, n2)

    while 1:
        temp = n2
        n2 = n1 % n2
        n1 = temp

        if n2 == 0:
            break

    return n1


def backtracking(arr, cnt, temp, num):
    global gcd_sum

    if cnt == 2:
        # print(temp[0], end=" ")
        # print(temp[1])
        gcd_sum += cal_gcd(temp[0], temp[1])
        return

    for i in range(num):
        if not visited[i]:
            visited[i] = 1
            temp.append(arr[i])
            backtracking(arr, cnt+1, temp, num)
            temp.pop()
            visited[i] = 0


if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        case = list(map(int, input().split()))
        num = case[0]

        visited = [0 for _ in range(num)]
        gcd_sum = 0
        backtracking(case[1:], 0, [], num)

        print(gcd_sum // 2)
