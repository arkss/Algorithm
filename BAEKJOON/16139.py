import sys

input = sys.stdin.readline

if __name__ == "__main__":
    s = input().strip()

    alphabets = "abcdefghijklmnopqrstuvwxyz"

    # print(len(alphabets))

    dp = {}
    for alphabet in alphabets:
        dp[alphabet] = [0 for _ in range(len(s)+1)]

    for idx, c in enumerate(s):
        for alpha in alphabets:
            if alpha == c:
                dp[alpha][idx+1] = dp[alpha][idx] + 1
            else:
                dp[alpha][idx+1] = dp[alpha][idx]

    N = int(input())

    print(dp['a'])

    for i in range(N):
        alpha, sidx, eidx = input().split()
        p1 = dp[alpha][int(sidx)]
        p2 = dp[alpha][int(eidx)+1]

        print(p2-p1)
