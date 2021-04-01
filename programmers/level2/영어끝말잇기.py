def solution(n, words):
    answer = []

    word_dict = {}

    prev_last_char = words[0][0]
    for idx, word in enumerate(words):

        if word_dict.get(word) or word[0] != prev_last_char:
            answer.append(idx % n + 1)
            answer.append(idx // n + 1)
            return answer

        word_dict[word] = 1
        prev_last_char = word[len(word) - 1]

    return [0, 0]
