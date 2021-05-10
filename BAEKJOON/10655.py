def calcurate_distance(p1, p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])


N = int(input())

check_points = []
distances = [0]

for _ in range(N):
    x, y = map(int, input().split())
    check_points.append((x, y))

for i in range(N-1):
    distances.append(calcurate_distance(check_points[i], check_points[i+1]))

min_distance_sum = 987654321

for skip_idx in range(1, N-1):
    distance_sum = 0
    skip_flag = False
    for idx in range(len(distances)):
        if skip_flag:
            skip_flag = False

        elif skip_idx == idx:
            distance_sum += calcurate_distance(
                check_points[idx-1], check_points[idx+1])
            skip_flag = True
        else:
            distance_sum += distances[idx]

    min_distance_sum = min(distance_sum, min_distance_sum)

print(min_distance_sum)
