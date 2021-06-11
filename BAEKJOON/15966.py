import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    arr = list(map(int, input().split()))

    dic = {}

    answer = 1

    for value in arr:
        if dic.get(value-1) is not None:
            dic[value] = dic[value-1] + 1
        else:
            dic[value] = 1

        answer = max(answer, dic[value])

    print(answer)
