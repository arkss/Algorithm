from collections import Counter

def solution(N, stages):
    unclear_cnt = Counter(stages)
    reach_cnt = [0 for _ in range(N+1)]
    
    for stage in stages:
        for i in range(1,stage+1):
            if i > N:
                break
            reach_cnt[i] += 1
            
    #print(unclear_cnt)
    #print(reach_cnt)
            
    
    temp = []
    answer = []
    
    for i in range(1,N+1):
        if reach_cnt[i]:
            temp.append((i,unclear_cnt[i]/reach_cnt[i]))
        else:
            temp.append((i,0))
    
    temp = sorted(temp, key=lambda x:(x[1]), reverse=True)
    
    
    
    for i in temp:
        answer.append(i[0])
    
    return answer

# 실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수