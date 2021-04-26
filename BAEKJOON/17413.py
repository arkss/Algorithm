"""
공백을 만나면 다시 시작
<를 만나면 지금까지 내용 거꾸로 출력 및 >를 만날 때 까지 진행
"""

inputs = input()

temp = []
is_open = False

for c in inputs:
    if c == ' ' and not is_open:
        print(''.join(temp[::-1]), end=' ')
        temp.clear()
    elif c == '<':
        is_open = True
        print(''.join(temp[::-1]), end='')
        temp.clear()
        temp.append(c)

    elif c == '>':
        is_open = False
        print(''.join(temp), end='')
        temp.clear()
        print('>', end='')
    else:
        temp.append(c)

print(''.join(temp[::-1]))
