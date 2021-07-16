import sys

input = sys.stdin.readline


def find_idx_of_max_h(data):
    max_h = 0
    max_idx = 0

    for idx, pos in enumerate(data):
        x, h = pos
        if h > max_h:
            max_h = h
            max_idx = idx

    return max_idx


if __name__ == "__main__":
    N = int(input())

    data = []

    for _ in range(N):
        x, h = map(int, input().split())

        data.append((x, h))

    data = sorted(data)

    # print(data)

    max_h_idx = find_idx_of_max_h(data)

    # print(data[:max_h_idx])

    total_size = data[max_h_idx][1]

    # 왼쪽 계산
    max_x, max_h = data[:max_h_idx+1][0]
    for x, h in data[:max_h_idx+1]:
        if h > max_h:
            add_size = max_h * (x - max_x)
            total_size += add_size

            max_x = x
            max_h = h

    # 오른쪽 계산
    right_data = list(reversed(data[max_h_idx:]))
    max_x, max_h = right_data[0]

    for x, h in data[:max_h_idx+1]:
        if h > max_h:
            add_size = max_h * (max_x - x)
            total_size += add_size

            max_x = x
            max_h = h

    print(total_size)
