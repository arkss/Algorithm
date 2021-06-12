
import sys

#input = sys.stdin.readline


def time_to_minute(time):
    return int(time[:2]) * 60 + int(time[2:])


if __name__ == "__main__":
    N = int(input())

    times = [(0, 600), (1320, 1440)]

    for _ in range(N):
        s, e = map(time_to_minute, input().split())
        times.append((s-10, e+10))

    times.sort()
    max_time = 0
    end_time = 600
    for s, e in times:
        max_time = max(max_time, s-end_time)
        end_time = max(end_time, e)

    print(max_time)
