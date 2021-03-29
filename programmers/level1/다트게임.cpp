def solution(dartResult):
    
    answer = 0
    points = []
    point = 0
    areas = {'S': 1, 'D': 2, 'T' : 3}
    for idx, c in enumerate(dartResult):
        if "0"<= c <= "9":
            if idx != 0 and "0"<= dartResult[idx-1] <= "9":
                point = int(dartResult[idx-1:idx+1])

            else:
                point = int(c)
        elif areas.get(c):
            point **= areas[c]
            points.append(point)
        elif c == '*':
            points[-1] *= 2
            if len(points) > 1:
                points[-2] *= 2
        elif c == '#':
            points[-1] *= -1

    return sum(points)