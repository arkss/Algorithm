def cal_min_change(s):
    change_cnt = 0
    open_cnt = 0

    for c in s:
        if c == '{':
            open_cnt += 1
        else:
            # 현재 열려있는 괄호가 없는데 닫힌 괄호가 나오면 변환
            if open_cnt == 0:
                change_cnt += 1
                open_cnt += 1
            else:
                open_cnt -= 1

    change_cnt += open_cnt // 2
    return change_cnt


test_case = 1

while True:
    s = input()
    if s[0] == '-':
        break
    rst = cal_min_change(s)
    print(f'{test_case}. {rst}')
    test_case += 1
