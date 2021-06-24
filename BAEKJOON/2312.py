import sys

input = sys.stdin.readline

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N = int(input())

        rst = []
        for i in range(2, N+1):
            # if i*i > N:
            #     break

            cnt = 0
            while 1:
                if N % i == 0:
                    N = N // i
                    cnt += 1
                else:
                    break

            if cnt > 0:
                rst.append((i, cnt))

        for n, cnt in rst:
            print(f"{n} {cnt}")
