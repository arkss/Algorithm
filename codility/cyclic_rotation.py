def solution(A, K):
    if len(A) == 0:
        return A

    idx = (len(A)-K) % len(A)

    answer = []

    for i in range(len(A)):
        answer.append(A[idx])
        idx = (idx + 1) % len(A)

    return answer


def solution2(A, K):
    if len(A) == 0:
        return A

    return A[-K:] + A[:-K]ㄴ
