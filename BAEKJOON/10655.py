import sys


def cal_distance(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])


input = sys.stdin.readline

N = int(input())

check_points = []
distances = [0]

for _ in range(N):
    x, y = map(int, input().split())
    check_points.append((x, y))

for i in range(N-1):
    distances.append(cal_distance(check_points[i], check_points[i+1]))


max_gap = 0

for i in range(1, len(distances)-1):
    gap = distances[i] + distances[i+1] - \
        cal_distance(check_points[i-1], check_points[i+1])
    max_gap = max(max_gap, gap)

print(sum(distances)-max_gap)
