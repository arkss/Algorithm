def check_correct_brackets(brackets):
    stack = []

    for bracket in brackets:
        if bracket == ")":
            if not stack:
                return False
            stack.pop()
        else:
            stack.append(bracket)

    return True



def solution(p):
    # 1
    if not p:
        return p

    # 2
    left_cnt = 0
    right_cnt = 0
    idx = 0
    for i, bracket in enumerate(p):
        if bracket == '(':
            left_cnt += 1
        else:
            right_cnt += 1

        if left_cnt == right_cnt:
            idx = i
            break

    u = p[:idx+1]
    v = p[idx+1:]

    is_correct = check_correct_brackets(u)

    if is_correct:
        return u + solution(v)

    answer = '('
    answer += solution(v)
    answer += ')'

    for idx in range(1, len(u)-1):
        if u[idx] == '(':
            answer += ')'
        else:
            answer += '('

    return answer