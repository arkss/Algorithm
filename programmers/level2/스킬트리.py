def solution(skill, skill_trees):

    answer = 0

    for skill_tree in skill_trees:
        copy_skill = skill
        for now_skill in skill_tree:
            if now_skill in copy_skill:
                if copy_skill.index(now_skill) == 0:
                    copy_skill = copy_skill[1:]
                else:
                    break
        else:
            answer += 1

    return answer
