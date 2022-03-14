class User:
    def __init__(self, id):
        self.id = id
        self.report_ids = set()
        self.reported_count = 0

def solution(id_list, report, k):
    user_dict = init_user(id_list)

    report_user(report, user_dict)

    stop_user = get_stop_user(k, user_dict)

    answer = get_email_count(stop_user, user_dict)

    return answer


def get_email_count(stop_user, user_dict):
    answer = []
    for user in user_dict.values():
        email_count = 0
        for report_id in user.report_ids:
            if report_id in stop_user:
                email_count += 1
        answer.append(email_count)
    return answer


def get_stop_user(k, user_dict):
    stop_user = []
    for user in user_dict.values():
        if user.reported_count >= k:
            stop_user.append(user.id)
    return stop_user


def report_user(report, user_dict):
    for report_content in set(report):
        reporter, reported = report_content.split()
        user_dict[reporter].report_ids.add(reported)
        user_dict[reported].reported_count += 1


def init_user(id_list):
    user_dict = {}
    for id in id_list:
        user = User(id)
        user_dict[id] = user
    return user_dict


# assert solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"], 2) == [2, 1, 1, 0]
# assert solution(["con", "ryan"],
#                 ["ryan con", "ryan con", "ryan con", "ryan con"], 3) == [0, 0]

print(solution(["con", "ryan"],["ryan con", "ryan con", "ryan con", "ryan con"], 3))