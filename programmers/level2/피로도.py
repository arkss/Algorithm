max_clear_count = 0


def backtracking(k, dungeons, visited, clear_count):
    global max_clear_count
    max_clear_count = max(max_clear_count, clear_count)

    for idx in range(len(dungeons)):
        min_fatigue, consume_fatigue = dungeons[idx]
        if visited[idx] == 0 and k >= min_fatigue and k >= consume_fatigue:
            visited[idx] = 1
            backtracking(k - consume_fatigue, dungeons, visited, clear_count + 1)
            visited[idx] = 0


def solution(k, dungeons):
    visited = [0 for _ in range(len(dungeons))]
    backtracking(k, dungeons, visited, 0)

    return max_clear_count


k = 80
dungeons = [[80, 20], [50, 40], [30, 10]]
print(solution(k, dungeons))
