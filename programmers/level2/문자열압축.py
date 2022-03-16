def solution(s):
    if len(s) == 1:
        return 1
    min_length = 987654321

    for i in range(1, len(s) // 2 + 1):
        cnt = 1
        now_len = 0
        prev = s[0:i]

        for idx in range(i, len(s), i):
            now = s[idx : idx + i]

            if now == prev:
                cnt += 1

            else:
                now_len += len(prev)
                if cnt != 1:
                    now_len += len(str(cnt))
                cnt = 1
            prev = now
        now_len += len(prev)
        if cnt != 1:
            now_len += len(str(cnt))

        min_length = min(min_length, now_len)

    return min_length


# aabbaccc
