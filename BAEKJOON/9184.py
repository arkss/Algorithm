import sys

input = sys.stdin.readline


def fuction_w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif dp[a][b][c] != -1:
        return dp[a][b][c]

    elif a > 20 or b > 20 or c > 20:
        dp[a][b][c] = fuction_w(20, 20, 20)
        return dp[a][b][c]
    elif a < b and b < c:
        dp[a][b][c] = fuction_w(a, b, c-1) + \
            fuction_w(a, b-1, c-1) - fuction_w(a, b-1, c)
        return dp[a][b][c]
    else:
        dp[a][b][c] = fuction_w(a-1, b, c) + fuction_w(a-1, b-1, c) + \
            fuction_w(a-1, b, c-1) - fuction_w(a-1, b-1, c-1)
        return dp[a][b][c]


if __name__ == "__main__":
    dp = [[[-1 for _ in range(51)] for _ in range(51)] for _ in range(51)]
    # print(dp)
    while True:
        a, b, c = map(int, input().split())

        if a == -1 and b == -1 and c == -1:
            break
        rst = fuction_w(a, b, c)
        print(f'w({a}, {b}, {c}) = {rst}')
