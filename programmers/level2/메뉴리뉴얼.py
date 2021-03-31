from itertools import combinations


def solution(orders, course):

    order_dict = {}

    for order in orders:
        order = sorted(order)
        for course_length in course:
            for comb in combinations(order, course_length):

                comb_str = "".join(comb)
                if order_dict.get(comb_str):
                    order_dict[comb_str] += 1
                else:
                    order_dict[comb_str] = 1

    max_cnts = [0 for _ in range(11)]
    max_orders = [[] for _ in range(11)]

    for key, value in order_dict.items():
        if value < 2:
            continue
        order_length = len(key)
        if max_cnts[order_length] < value:
            max_cnts[order_length] = value
            max_orders[order_length].clear()
            max_orders[order_length].append(key)
        elif max_cnts[order_length] == value:
            max_orders[order_length].append(key)

    answer = []

    for max_order in max_orders:
        for order in max_order:
            answer.append(order)

    answer = sorted(answer)

    return answer
