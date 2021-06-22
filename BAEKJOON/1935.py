import sys
import string

input = sys.stdin.readline

if __name__ == "__main__":
    alphabets = list(string.ascii_uppercase)

    N = int(input())

    expression = input().strip()

    value_dict = {}
    for i in range(N):
        value_dict[alphabets[i]] = int(input())

    stack = []

    for c in expression:
        if c == '+':
            stack.append(stack.pop() + stack.pop())
        elif c == '-':
            v1 = stack.pop()
            v2 = stack.pop()
            stack.append(v2-v1)
        elif c == '*':
            stack.append(stack.pop() * stack.pop())
        elif c == '/':
            v1 = stack.pop()
            v2 = stack.pop()
            stack.append(v2/v1)
        else:
            stack.append(value_dict[c])

    print(f'{stack[-1]:.2f}')
