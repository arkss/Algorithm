import collections


N = int(input())

for _ in range(N):
    s = input()
    deq = collections.deque()
    stack = []
    for c in s:
        if c == '<':
            if deq:
                stack.append(deq.pop())
        elif c == '>':
            if stack:
                deq.append(stack.pop())
        elif c == '-':
            if deq:
                deq.pop()
        else:
            deq.append(c)

    while deq:
        print(deq.popleft(), end="")
    while stack:
        print(stack.pop(), end="")
    print()
