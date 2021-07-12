import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    position = []

    for _ in range(N):
        x, y = map(int, input().split())
        position.append((x, y))

    position = sorted(position)

    stack = []

    area = 0

    for x, h in position:
        print(f"({x}, {h})")
        if stack and stack[-1][1] > h:
            continue
        elif stack and stack[-1][1] < h:
            print(f"{stack[-1][1]} {h}")
            prev_x, prev_h = stack.pop()
            area += prev_h * (x-prev_x)

            print(f"더해지는 수 : {prev_h * (x-prev_x)}")
            print(f"넓이 : {area}")

            stack.append((x, h))
        else:
            stack.append((x, h))
    print(stack)
    print(area)
