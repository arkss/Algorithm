import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, length = map(int, input().split())

    holes = sorted(list(map(int, input().split())))

    tape_cnt = 0
    end = 0

    for hole in holes:
        if hole <= end:
            continue
        else:
            tape_cnt += 1
            end = hole + length - 1

    print(tape_cnt)
