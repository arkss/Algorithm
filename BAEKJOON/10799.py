import sys

input = sys.stdin.readline

if __name__ == "__main__":
    stack = []

    pipes = input().strip()
    pipe_num = 0

    for idx, c in enumerate(pipes):
        if c == '(':
            stack.append(c)

        else:
            stack.pop()
            if pipes[idx-1] == '(':
                pipe_num += len(stack)
            else:
                pipe_num += 1

    print(pipe_num)
