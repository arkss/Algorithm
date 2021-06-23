import sys

input = sys.stdin.readline


def hanoi(N, start, mid, end):

    if N == 1:
        print(f'{start} {end}')
        return

    hanoi(N-1, start, end, mid)
    print(f'{start} {end}')
    hanoi(N-1, mid, start, end)


if __name__ == "__main__":
    N = int(input())

    print(2**N-1)

    if N <= 20:
        hanoi(N, 1, 2, 3)
