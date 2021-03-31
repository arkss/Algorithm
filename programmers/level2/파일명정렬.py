def solution(files):
    split_files = []

    for file in files:
        number_idx = -1
        tail_idx = -1
        is_find_number_idx = False

        for idx, c in enumerate(file):
            if not is_find_number_idx and c.isdigit():
                number_idx = idx
                is_find_number_idx = True

            if is_find_number_idx and not c.isdigit():
                tail_idx = idx
                break

        head = file[:number_idx]
        number = ""
        tail = ""

        if tail_idx == -1:
            number = file[number_idx:]
        else:
            number = file[number_idx:tail_idx]
            tail = file[tail_idx:]

        split_files.append([head, number, tail])

    split_files = sorted(split_files, key=lambda x: (x[0].lower(), int(x[1])))

    answer = []
    for file in split_files:
        answer.append("".join(file))

    return answer
