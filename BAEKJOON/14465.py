import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, K, B = map(int, input().split())

    traffic_lights = [0 for _ in range(N+1)]

    for _ in range(B):
        broken_light = int(input())
        traffic_lights[broken_light] = 1

    start_idx = 1
    end_idx = K
    min_fix_traffic_cnt = sum(traffic_lights[start_idx:end_idx+1])
    now_fix_traffic_cnt = min_fix_traffic_cnt

    for i in range(N-K):

        if traffic_lights[start_idx] == 1:
            now_fix_traffic_cnt = now_fix_traffic_cnt-1
        start_idx += 1
        end_idx += 1

        # print(f"{start_idx} {end_idx}")
        if traffic_lights[end_idx] == 1:
            now_fix_traffic_cnt = now_fix_traffic_cnt + 1

        # print(now_fix_traffic_cnt)
        min_fix_traffic_cnt = min(now_fix_traffic_cnt, min_fix_traffic_cnt)

    print(min_fix_traffic_cnt)
