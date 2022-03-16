def is_correct(s):
    stack = []

    for c in s:
        if c == "(" or c == "[" or c == "{":
            stack.append(c)
        else:
            if c == ")":
                if not stack:
                    return False
                if stack[-1] != "(":
                    return False
                else:
                    stack.pop()
            elif c == "]":
                if not stack:
                    return False
                if stack[-1] != "[":
                    return False
                else:
                    stack.pop()
            elif c == "}":
                if not stack:
                    return False
                if stack[-1] != "{":
                    return False
                else:
                    stack.pop()

    if stack:
        return False
    else:
        return True


def solution(s):
    answer = 0
    for _ in range(len(s)):
        s = s[-1] + s[: len(s) - 1]

        if is_correct(s):
            answer += 1

        # print(f"{s} : {answer}")
    return answer


if __name__ == "__main__":
    print(solution("[](){}"))
    print(solution("}]()[{"))
    print(solution("[)(]"))
    print(solution("}}}"))
