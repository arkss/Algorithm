import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    points = []

    for _ in range(N):
        points.append(int(input()))

    points = sorted(points, reverse=True)

    answer = 1
    first_price_point = points[0] + 1
    for i in range(1, N):
        if points[i] + N >= first_price_point:
            answer += 1
        first_price_point = max(points[i] + i + 1, first_price_point)

    print(answer)
