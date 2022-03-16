import sys

input = sys.stdin.readline


def bfs(place, i, j, size):
    visited = [[0 for _ in range(size)] for _ in range(size)]

    visited[i][j] = 1
    queue = [(i, j, 0)]

    dxs = [0, 0, 1, -1]
    dys = [-1, 1, 0, 0]

    while queue:
        x, y, dis = queue.pop()
        # print(f"{x} {y} {dis}")

        if dis == 2:
            break

        for dx, dy in zip(dxs, dys):
            nx = x + dx
            ny = y + dy

            if nx < 0 or nx >= 5 or ny < 0 or ny >= 5:
                continue

            if visited[nx][ny]:
                continue

            if place[nx][ny] == "X":
                continue

            if place[nx][ny] == "P":
                return True

            visited[nx][ny] = 1
            queue.append((nx, ny, dis + 1))

    return False


def check_distance(place):
    size = len(place)

    for i in range(size):
        for j in range(size):
            if place[i][j] == "P":
                # print(f"{i},{j}에서 수행")
                if bfs(place, i, j, size):
                    return 0

    return 1


def solution(places):
    answer = []
    for place in places:
        answer.append(check_distance(place))

    return answer


if __name__ == "__main__":
    test_case = [
        ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
        ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
        ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
        ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
        ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"],
    ]

    print(solution(test_case))
