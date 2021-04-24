def check_palindrome(s, is_delete):
    left = 0
    right = len(s) - 1

    while left < right:
        if s[left] != s[right]:
            # 유사 회문
            if not is_delete:
                if check_palindrome(s[left:right], True) == 0 \
                        or check_palindrome(s[left+1:right+1], True) == 0:
                    return 1
            return 2

        left += 1
        right -= 1

    return 0


N = int(input())

for _ in range(N):
    s = input()

    print(check_palindrome(s, False))
