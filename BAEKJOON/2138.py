def push_switch(bulbs, i):
    if i-1 >= 0:
        bulbs[i-1] = '1' if bulbs[i-1] == '0' else '0'
    bulbs[i] = '1' if bulbs[i] == '0' else '0'

    if i+1 < N:
        bulbs[i+1] = '1' if bulbs[i+1] == '0' else '0'


def calcurate_not_click_zero(bulbs):
    cnt = 0
    for i in range(1, N):
        if bulbs[i-1] != goal[i-1]:
            push_switch(bulbs, i)
            cnt += 1

    if bulbs == goal:
        return cnt
    return 100000


def calcurate_click_zero(bulbs):
    cnt = 1
    bulbs[0] = '1' if bulbs[0] == '0' else '0'
    bulbs[1] = '1' if bulbs[1] == '0' else '0'

    for i in range(1, N):
        if bulbs[i-1] != goal[i-1]:
            push_switch(bulbs, i)
            cnt += 1

    if bulbs == goal:
        return cnt
    return 100000


N = int(input())

now = list(input())
goal = list(input())


cnt_not_click_zero = calcurate_not_click_zero(now[:])
cnt_click_zero = calcurate_click_zero(now[:])

answer = min(cnt_not_click_zero, cnt_click_zero)
if answer == 100000:
    print(-1)
else:
    print(answer)
