import sys

input = sys.stdin.readline

N = int(input())

for _ in range(N):
    word1, word2 = input().split(' ')

    a_idxs = []
    b_idxs = []

    for idx in range(len(word1)):
        if word1[idx] != word2[idx]:
            if word1[idx] == 'a':
                a_idxs.append(idx)
            elif word1[idx] == 'b':
                b_idxs.append(idx)

    if len(a_idxs) != len(b_idxs):
        print(-1)
    else:
        move_cnt = 0

        for i in range(len(a_idxs)):
            move_cnt += abs(a_idxs[i] - b_idxs[i])

        print(move_cnt)
