N = int(input())

lines = []
shortcuts = {}
shortcuts_idx = []

for _ in range(N):
    lines.append(input())


for line in lines:
    # 단어의 첫글자 확인
    line = line.upper()
    line_list = list(line.split())

    is_find = False

    for idx, word in enumerate(line_list):
        if not shortcuts.get(word[0]):
            shortcuts[word[0]] = 1
            shortcuts_idx.append((0, idx))
            is_find = True
            break

    if is_find:
        continue

    for idx, c in enumerate(line):
        if not shortcuts.get(c) and c != ' ':
            shortcuts[c] = 1
            shortcuts_idx.append((1, idx))
            break

    shortcuts_idx.append((-1, -1))

for line, idx in zip(lines, shortcuts_idx):
    if idx[0] == 0:
        for i, word in enumerate(list(line.split())):
            if i == idx[1]:
                for j, c in enumerate(word):
                    if j == 0:
                        print('[', end="")
                    print(c, end="")
                    if j == 0:
                        print(']', end="")
            else:
                print(word, end=" ")

    elif idx[0] == 1:
        for i, c in enumerate(line):
            print(c, end="")
            if i+1 == idx[1]:
                print('[', end="")
            if i == idx[1]:
                print(']', end="")

    else:
        print(line, end="")

    print()
