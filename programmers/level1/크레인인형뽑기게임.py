def solution(board, moves):

    answer = 0
    queue = []
    row_size = len(board)
    for col in moves:
        col = col - 1
        for row in range(row_size):
            if board[row][col]:
                if not queue:
                    queue.append(board[row][col])
                else:
                    if queue[-1] == board[row][col]:
                        queue.pop()
                        answer += 2
                    else:
                        queue.append(board[row][col])
                board[row][col] = 0
                break
    return answer
