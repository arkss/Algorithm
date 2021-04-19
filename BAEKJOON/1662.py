def decode(s):
    answer = 0
    mul_num = 1
    open_burket_cnt = 0
    open_burket_idx = -1
    close_burket_idx = -1
    has_burket = False

    for idx, c in enumerate(s):

        if c == '(':
            if open_burket_cnt == 0:
                open_burket_idx = idx
                mul_num = int(s[idx-1])
                answer -= 1
            open_burket_cnt += 1
            has_burket = True
        if c == ')':
            open_burket_cnt -= 1
            if open_burket_cnt == 0:
                close_burket_idx = idx

        if open_burket_cnt == 0 and c.isdigit():
            answer += 1

        if open_burket_idx != -1 and close_burket_idx != -1:
            answer += mul_num * decode(s[open_burket_idx+1:close_burket_idx])
            open_burket_idx = -1
            close_burket_idx = -1

    if has_burket:
        return answer
    else:
        return len(s)


input_str = input()

str_len = decode(input_str)

print(str_len)
