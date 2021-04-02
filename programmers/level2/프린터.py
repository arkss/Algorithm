def solution(priorities, location):

    printer_q = [(p, loc) for loc, p in enumerate(priorities)]
    answer = 0

    while printer_q:
        priority, loc = printer_q.pop(0)

        for docs in printer_q:
            if priority < docs[0]:
                printer_q.append((priority, loc))
                break
        else:
            answer += 1
            if loc == location:
                break

    return answer
