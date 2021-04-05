def solution(genres, plays):
    # 장르: 재생 수
    genres_cnt_dict = {}
    # 장르: [(재생 수, 고유번호), ...]
    genres_songs_dict = {}

    for idx, (genre, play) in enumerate(zip(genres, plays)):
        if genres_cnt_dict.get(genre):
            genres_cnt_dict[genre] += play
            genres_songs_dict[genre].append((play, idx))
        else:
            genres_cnt_dict[genre] = play
            genres_songs_dict[genre] = [(play, idx)]

    sorted_genres_cnt = sorted(
        genres_cnt_dict.items(), key=lambda x: x[1], reverse=True)

    answer = []
    for genre, _ in sorted_genres_cnt:
        genres_songs = sorted(
            genres_songs_dict[genre], key=lambda x: (x[0], -x[1]), reverse=True)

        answer.append(genres_songs[0][1])

        if len(genres_songs) > 1:
            answer.append(genres_songs[1][1])

    return answer
